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
struct FilterState_R001924_2413_0
{
  unsigned char gain_db;
  short cutoff;
  int prev_out;
  unsigned char prev_in;
  int mode;
  int buffer[3];
};
struct SensorNode_R001924_2413_1
{
  unsigned char offset;
  int threshold;
  int reading;
  short gain;
  unsigned char status;
  int buffer[3];
};
union TelemetryField_R001924_2413_0
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
void fn_R001924_2413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_40_1 > 33)
  {
    acc_1 = ((acc_1 + (tally_40_1 * 2)) + 5) & 127;
    aux_1 ^= tally_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_40_2 > 33)
  {
    acc_2 = ((acc_2 + (tally_40_2 * 2)) + 5) & 127;
    aux_2 ^= tally_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_96_1 = local_arr_1[aux_1 % 3];
  int margin_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_96_2 * 2)) & 127;
  int mask_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_90_1) & 63;
  aux_2 = (aux_2 + mask_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_40_1 == tally_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_96_1 == margin_96_2);
  assert(mask_90_1 == mask_90_2);
  assert(checksum_65_1 == checksum_65_2);
}

int fn_R001924_2413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_40 > 33)
  {
    acc = ((acc + (tally_40 * 2)) + 5) & 127;
    aux ^= tally_40 & 15;
  }
  else
  {
    acc = ((acc - tally_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_96 = local_arr[aux % 3];
  acc = (acc + (margin_96 * 2)) & 127;
  int mask_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_90) & 63;
  acc ^= aux;
  int checksum_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_65 = ((checksum_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001924_2413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_51_1 = local_arr_1[aux_1 % 3];
  int stride_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_51_2 * 2)) & 127;
  int factor_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_56_1)
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

  switch (factor_56_2)
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

  int quotient_40_1 = 0;
  int quotient_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_40_1 = ((quotient_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_40_2 = ((quotient_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_40_1) & 127;
    acc_2 = (acc_2 + quotient_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_51_1 == stride_51_2);
  assert(factor_56_1 == factor_56_2);
  assert(quotient_40_1 == quotient_40_2);
}

int fn_R001924_2413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int stride_51 = local_arr[aux % 3];
  acc = (acc + (stride_51 * 2)) & 127;
  int factor_56 = (aux + st.buffer[1]) & 3;
  switch (factor_56)
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

  int quotient_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_40 = ((quotient_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001924_2413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int pivot_79_1 = 0;
  int pivot_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_79_1 = ((pivot_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_79_2 = ((pivot_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_79_1) & 127;
    acc_2 = (acc_2 + pivot_79_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_38_1)
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

  switch (anchor_38_2)
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

  int pivot_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_50_1 > 41)
  {
    acc_1 = ((acc_1 + (pivot_50_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_50_2 > 41)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_79_1 == pivot_79_2);
  assert(anchor_38_1 == anchor_38_2);
  assert(pivot_50_1 == pivot_50_2);
}

int fn_R001924_2413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int pivot_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_79 = ((pivot_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_79) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_38 = (aux + st.buffer[1]) & 3;
  switch (anchor_38)
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

  int pivot_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_50 > 41)
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

void fn_R001924_2413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_85_1 = local_arr_1[aux_1 % 3];
  int residue_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_85_2 * 2)) & 127;
  int offset_77_1 = 0;
  int offset_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_77_1 = ((offset_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_77_2 = ((offset_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_77_1) & 127;
    acc_2 = (acc_2 + offset_77_2) & 127;
  }

  int tally_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_43_1)
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

  switch (tally_43_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(offset_77_1 == offset_77_2);
  assert(tally_43_1 == tally_43_2);
}

int fn_R001924_2413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_85 = local_arr[aux % 3];
  acc = (acc + (residue_85 * 2)) & 127;
  int offset_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_77 = ((offset_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_77) & 127;
  }

  int tally_43 = (aux + st.buffer[1]) & 3;
  switch (tally_43)
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

void fn_R001924_2413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_33_1) & 63;
  aux_2 = (aux_2 + mask_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_34_1 = 0;
  int parity_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_34_1 = ((parity_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_34_2 = ((parity_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_34_1) & 127;
    acc_2 = (acc_2 + parity_34_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_82_1 = local_arr_1[aux_1 % 3];
  int segment_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_33_1 == mask_33_2);
  assert(parity_34_1 == parity_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_82_1 == segment_82_2);
}

int fn_R001924_2413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_33) & 63;
  acc ^= aux;
  int parity_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_34 = ((parity_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_34) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_82 = local_arr[aux % 3];
  acc = (acc + (segment_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001924_2413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_70_1)
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

  switch (offset_70_2)
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
  int window_79_1 = local_arr_1[aux_1 % 3];
  int window_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_79_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_92_1 > 16)
  {
    acc_1 = ((acc_1 + (mask_92_1 * 2)) + 5) & 127;
    aux_1 ^= mask_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_92_2 > 16)
  {
    acc_2 = ((acc_2 + (mask_92_2 * 2)) + 5) & 127;
    aux_2 ^= mask_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_70_1 == offset_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_79_1 == window_79_2);
  assert(mask_92_1 == mask_92_2);
}

int fn_R001924_2413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_70 = (aux + st.buffer[1]) & 3;
  switch (offset_70)
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
  int window_79 = local_arr[aux % 3];
  acc = (acc + (window_79 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_92 > 16)
  {
    acc = ((acc + (mask_92 * 2)) + 5) & 127;
    aux ^= mask_92 & 15;
  }
  else
  {
    acc = ((acc - mask_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001924_2413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tally_37_1 = 0;
  int tally_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_37_1 = ((tally_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_37_2 = ((tally_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_37_1) & 127;
    acc_2 = (acc_2 + tally_37_2) & 127;
  }

  int pivot_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_78_1)
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

  switch (pivot_78_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_37_1 == tally_37_2);
  assert(pivot_78_1 == pivot_78_2);
}

int fn_R001924_2413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tally_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_37 = ((tally_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_37) & 127;
  }

  int pivot_78 = (aux + st.buffer[1]) & 3;
  switch (pivot_78)
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

void fn_R001924_2413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_17_1 = 0;
  int mask_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_17_1 = ((mask_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_17_2 = ((mask_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_17_1) & 127;
    acc_2 = (acc_2 + mask_17_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_17_1 == mask_17_2);
}

int fn_R001924_2413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_17 = ((mask_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_17) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001924_2413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_75_1) & 63;
  aux_2 = (aux_2 + residue_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
}

int fn_R001924_2413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001924_2413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_20_1)
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

  switch (quotient_20_2)
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

  int parity_51_1 = 0;
  int parity_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_51_1 = ((parity_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_51_2 = ((parity_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_51_1) & 127;
    acc_2 = (acc_2 + parity_51_2) & 127;
  }

  int bound_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_28_1) & 63;
  aux_2 = (aux_2 + bound_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_45_1 > 14)
  {
    acc_1 = ((acc_1 + (metric_45_1 * 2)) + 5) & 127;
    aux_1 ^= metric_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_45_2 > 14)
  {
    acc_2 = ((acc_2 + (metric_45_2 * 2)) + 5) & 127;
    aux_2 ^= metric_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_20_1 == quotient_20_2);
  assert(parity_51_1 == parity_51_2);
  assert(bound_28_1 == bound_28_2);
  assert(metric_45_1 == metric_45_2);
}

int fn_R001924_2413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_20 = (aux + st.buffer[1]) & 3;
  switch (quotient_20)
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

  int parity_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_51 = ((parity_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_51) & 127;
  }

  int bound_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_28) & 63;
  acc ^= aux;
  int metric_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_45 > 14)
  {
    acc = ((acc + (metric_45 * 2)) + 5) & 127;
    aux ^= metric_45 & 15;
  }
  else
  {
    acc = ((acc - metric_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001924_2413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_64_1 = local_arr_1[aux_1 % 3];
  int weight_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_64_2 * 2)) & 127;
  int threshold_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_13_1) & 63;
  aux_2 = (aux_2 + threshold_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_26_1)
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

  switch (delta_26_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_64_1 == weight_64_2);
  assert(threshold_13_1 == threshold_13_2);
  assert(delta_26_1 == delta_26_2);
}

int fn_R001924_2413_10(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int weight_64 = local_arr[aux % 3];
  acc = (acc + (weight_64 * 2)) & 127;
  int threshold_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_13) & 63;
  acc ^= aux;
  int delta_26 = (aux + st.buffer[1]) & 3;
  switch (delta_26)
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

void fn_R001924_2413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
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
  int parity_23_1 = 0;
  int parity_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_23_1 = ((parity_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_23_2 = ((parity_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_23_1) & 127;
    acc_2 = (acc_2 + parity_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_23_1 == parity_23_2);
}

int fn_R001924_2413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_23 = ((parity_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001924_2413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quotient_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_72_1) & 63;
  aux_2 = (aux_2 + quotient_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_77_1 > 28)
  {
    acc_1 = ((acc_1 + (coefficient_77_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_77_2 > 28)
  {
    acc_2 = ((acc_2 + (coefficient_77_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_72_1 == quotient_72_2);
  assert(coefficient_77_1 == coefficient_77_2);
}

int fn_R001924_2413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quotient_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_77 > 28)
  {
    acc = ((acc + (coefficient_77 * 2)) + 5) & 127;
    aux ^= coefficient_77 & 15;
  }
  else
  {
    acc = ((acc - coefficient_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001924_2413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int index_reg_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_24_1 > 15)
  {
    acc_1 = ((acc_1 + (index_reg_24_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_24_2 > 15)
  {
    acc_2 = ((acc_2 + (index_reg_24_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_68_1) & 63;
  aux_2 = (aux_2 + segment_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_24_1 == index_reg_24_2);
  assert(segment_68_1 == segment_68_2);
}

int fn_R001924_2413_13(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int index_reg_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_24 > 15)
  {
    acc = ((acc + (index_reg_24 * 2)) + 5) & 127;
    aux ^= index_reg_24 & 15;
  }
  else
  {
    acc = ((acc - index_reg_24) + 11) & 127;
    aux += 3;
  }
  int segment_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001924_2413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_27_1 > 18)
  {
    acc_1 = ((acc_1 + (phase_27_1 * 2)) + 5) & 127;
    aux_1 ^= phase_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_27_2 > 18)
  {
    acc_2 = ((acc_2 + (phase_27_2 * 2)) + 5) & 127;
    aux_2 ^= phase_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_80_1)
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

  switch (quantum_80_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_27_1 == phase_27_2);
  assert(quantum_80_1 == quantum_80_2);
}

int fn_R001924_2413_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_27 > 18)
  {
    acc = ((acc + (phase_27 * 2)) + 5) & 127;
    aux ^= phase_27 & 15;
  }
  else
  {
    acc = ((acc - phase_27) + 11) & 127;
    aux += 3;
  }
  int quantum_80 = (aux + st.buffer[1]) & 3;
  switch (quantum_80)
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

void fn_R001924_2413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_11_1 = local_arr_1[aux_1 % 3];
  int threshold_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_11_2 * 2)) & 127;
  int stride_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_86_1) & 63;
  aux_2 = (aux_2 + stride_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
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

  assert(threshold_11_1 == threshold_11_2);
  assert(stride_86_1 == stride_86_2);
}

int fn_R001924_2413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int threshold_11 = local_arr[aux % 3];
  acc = (acc + (threshold_11 * 2)) & 127;
  int stride_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001924_2413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int threshold_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_74_1)
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

  switch (threshold_74_2)
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

  int vector_24_1 = 0;
  int vector_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_24_1 = ((vector_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_24_2 = ((vector_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_24_1) & 127;
    acc_2 = (acc_2 + vector_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_74_1 == threshold_74_2);
  assert(vector_24_1 == vector_24_2);
}

int fn_R001924_2413_16(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int threshold_74 = (aux + st.buffer[1]) & 3;
  switch (threshold_74)
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

  int vector_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_24 = ((vector_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001924_2413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_98_1)
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

  switch (tally_98_2)
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

  int coefficient_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_10_1) & 63;
  aux_2 = (aux_2 + coefficient_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_33_1 > 47)
  {
    acc_1 = ((acc_1 + (cursor_33_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_33_2 > 47)
  {
    acc_2 = ((acc_2 + (cursor_33_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_85_1 = local_arr_1[aux_1 % 3];
  int checksum_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_98_1 == tally_98_2);
  assert(coefficient_10_1 == coefficient_10_2);
  assert(cursor_33_1 == cursor_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_85_1 == checksum_85_2);
}

int fn_R001924_2413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_98 = (aux + st.buffer[1]) & 3;
  switch (tally_98)
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

  int coefficient_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_10) & 63;
  acc ^= aux;
  int cursor_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_33 > 47)
  {
    acc = ((acc + (cursor_33 * 2)) + 5) & 127;
    aux ^= cursor_33 & 15;
  }
  else
  {
    acc = ((acc - cursor_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_85 = local_arr[aux % 3];
  acc = (acc + (checksum_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001924_2413_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_65_1 = local_arr_1[aux_1 % 3];
  int tracker_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_65_2 * 2)) & 127;
  int tracker_60_1 = 0;
  int tracker_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_60_1 = ((tracker_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_60_2 = ((tracker_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_60_1) & 127;
    acc_2 = (acc_2 + tracker_60_2) & 127;
  }

  int delta_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_43_1)
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

  switch (delta_43_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
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

  assert(tracker_65_1 == tracker_65_2);
  assert(tracker_60_1 == tracker_60_2);
  assert(delta_43_1 == delta_43_2);
}

int fn_R001924_2413_18(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_65 = local_arr[aux % 3];
  acc = (acc + (tracker_65 * 2)) & 127;
  int tracker_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_60 = ((tracker_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_60) & 127;
  }

  int delta_43 = (aux + st.buffer[1]) & 3;
  switch (delta_43)
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

void fn_R001924_2413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int mask_57_1 = 0;
  int mask_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_57_1 = ((mask_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_57_2 = ((mask_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_57_1) & 127;
    acc_2 = (acc_2 + mask_57_2) & 127;
  }

  int phase_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_83_1) & 63;
  aux_2 = (aux_2 + phase_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_50_1)
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

  switch (stride_50_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(phase_83_1 == phase_83_2);
  assert(stride_50_1 == stride_50_2);
}

int fn_R001924_2413_19(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int mask_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_57 = ((mask_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_57) & 127;
  }

  int phase_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_83) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_50 = (aux + st.buffer[1]) & 3;
  switch (stride_50)
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

void fn_R001924_2413_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st_1 = {0};
  struct SensorNode_R001924_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int index_reg_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_63_1)
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

  switch (index_reg_63_2)
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

  int pivot_68_1 = 0;
  int pivot_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_68_1 = ((pivot_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_68_2 = ((pivot_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_68_1) & 127;
    acc_2 = (acc_2 + pivot_68_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_63_1 == index_reg_63_2);
  assert(pivot_68_1 == pivot_68_2);
}

int fn_R001924_2413_20(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001924_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int index_reg_63 = (aux + st.buffer[1]) & 3;
  switch (index_reg_63)
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

  int pivot_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_68 = ((pivot_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_68) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001924_2413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int offset_29_1 = 0;
  int offset_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_29_1 = ((offset_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_29_2 = ((offset_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_29_1) & 127;
    acc_2 = (acc_2 + offset_29_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_42_1 = local_arr_1[aux_1 % 3];
  int phase_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_42_2 * 2)) & 127;
  int offset_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_58_1) & 63;
  aux_2 = (aux_2 + offset_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_29_1 == offset_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_42_1 == phase_42_2);
  assert(offset_58_1 == offset_58_2);
}

int fn_R001924_2413_21(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int offset_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_29 = ((offset_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_29) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_42 = local_arr[aux % 3];
  acc = (acc + (phase_42 * 2)) & 127;
  int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001924_2413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st_1 = {0};
  struct FilterState_R001924_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_93_1)
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

  switch (delta_93_2)
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

  int cursor_86_1 = 0;
  int cursor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_86_1 = ((cursor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_86_2 = ((cursor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_86_1) & 127;
    acc_2 = (acc_2 + cursor_86_2) & 127;
  }

  int mask_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_48_1) & 63;
  aux_2 = (aux_2 + mask_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_93_1 == delta_93_2);
  assert(cursor_86_1 == cursor_86_2);
  assert(mask_48_1 == mask_48_2);
}

int fn_R001924_2413_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001924_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_93 = (aux + st.buffer[1]) & 3;
  switch (delta_93)
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

  int cursor_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_86 = ((cursor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_86) & 127;
  }

  int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001924_0_1;
  int sec_r001924_0_2;
  int sec_r001924_1_1;
  int sec_r001924_1_2;
  int sec_r001924_2_1;
  int sec_r001924_2_2;
  int sec_r001924_3_1;
  int sec_r001924_3_2;
  int sec_r001924_4_1;
  int sec_r001924_4_2;
  int sec_r001924_5_1;
  int sec_r001924_5_2;
  int sec_r001924_6_1;
  int sec_r001924_6_2;
  int sec_r001924_7_1;
  int sec_r001924_7_2;
  int sec_r001924_8_1;
  int sec_r001924_8_2;
  int sec_r001924_9_1;
  int sec_r001924_9_2;
  int sec_r001924_10_1;
  int sec_r001924_10_2;
  int sec_r001924_11_1;
  int sec_r001924_11_2;
  int sec_r001924_12_1;
  int sec_r001924_12_2;
  int sec_r001924_13_1;
  int sec_r001924_13_2;
  int sec_r001924_14_1;
  int sec_r001924_14_2;
  int sec_r001924_15_1;
  int sec_r001924_15_2;
  int sec_r001924_16_1;
  int sec_r001924_16_2;
  int sec_r001924_17_1;
  int sec_r001924_17_2;
  int sec_r001924_18_1;
  int sec_r001924_18_2;
  int sec_r001924_19_1;
  int sec_r001924_19_2;
  int pub_r001924_0_1;
  int pub_r001924_0_2;
  int pub_r001924_1_1;
  int pub_r001924_1_2;
  int pub_r001924_2_1;
  int pub_r001924_2_2;
  int pub_r001924_3_1;
  int pub_r001924_3_2;
  int pub_r001924_4_1;
  int pub_r001924_4_2;
  int pub_r001924_5_1;
  int pub_r001924_5_2;
  int pub_r001924_6_1;
  int pub_r001924_6_2;
  int pub_r001924_7_1;
  int pub_r001924_7_2;
  int pub_r001924_8_1;
  int pub_r001924_8_2;
  int pub_r001924_9_1;
  int pub_r001924_9_2;
  int pub_r001924_10_1;
  int pub_r001924_10_2;
  int pub_r001924_11_1;
  int pub_r001924_11_2;
  int pub_r001924_12_1;
  int pub_r001924_12_2;
  int pub_r001924_13_1;
  int pub_r001924_13_2;
  int pub_r001924_14_1;
  int pub_r001924_14_2;
  int pub_r001924_15_1;
  int pub_r001924_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001924_0_1 >= (-100)) && (pub_r001924_0_1 <= 100));
  __CPROVER_assume((pub_r001924_0_2 >= (-100)) && (pub_r001924_0_2 <= 100));
  __CPROVER_assume((pub_r001924_1_1 >= (-100)) && (pub_r001924_1_1 <= 100));
  __CPROVER_assume((pub_r001924_1_2 >= (-100)) && (pub_r001924_1_2 <= 100));
  __CPROVER_assume((pub_r001924_2_1 >= (-100)) && (pub_r001924_2_1 <= 100));
  __CPROVER_assume((pub_r001924_2_2 >= (-100)) && (pub_r001924_2_2 <= 100));
  __CPROVER_assume((pub_r001924_3_1 >= (-100)) && (pub_r001924_3_1 <= 100));
  __CPROVER_assume((pub_r001924_3_2 >= (-100)) && (pub_r001924_3_2 <= 100));
  __CPROVER_assume((pub_r001924_4_1 >= (-100)) && (pub_r001924_4_1 <= 100));
  __CPROVER_assume((pub_r001924_4_2 >= (-100)) && (pub_r001924_4_2 <= 100));
  __CPROVER_assume((pub_r001924_5_1 >= (-100)) && (pub_r001924_5_1 <= 100));
  __CPROVER_assume((pub_r001924_5_2 >= (-100)) && (pub_r001924_5_2 <= 100));
  __CPROVER_assume((pub_r001924_6_1 >= (-100)) && (pub_r001924_6_1 <= 100));
  __CPROVER_assume((pub_r001924_6_2 >= (-100)) && (pub_r001924_6_2 <= 100));
  __CPROVER_assume((pub_r001924_7_1 >= (-100)) && (pub_r001924_7_1 <= 100));
  __CPROVER_assume((pub_r001924_7_2 >= (-100)) && (pub_r001924_7_2 <= 100));
  __CPROVER_assume((pub_r001924_8_1 >= (-100)) && (pub_r001924_8_1 <= 100));
  __CPROVER_assume((pub_r001924_8_2 >= (-100)) && (pub_r001924_8_2 <= 100));
  __CPROVER_assume((pub_r001924_9_1 >= (-100)) && (pub_r001924_9_1 <= 100));
  __CPROVER_assume((pub_r001924_9_2 >= (-100)) && (pub_r001924_9_2 <= 100));
  __CPROVER_assume((pub_r001924_10_1 >= (-100)) && (pub_r001924_10_1 <= 100));
  __CPROVER_assume((pub_r001924_10_2 >= (-100)) && (pub_r001924_10_2 <= 100));
  __CPROVER_assume((pub_r001924_11_1 >= (-100)) && (pub_r001924_11_1 <= 100));
  __CPROVER_assume((pub_r001924_11_2 >= (-100)) && (pub_r001924_11_2 <= 100));
  __CPROVER_assume((pub_r001924_12_1 >= (-100)) && (pub_r001924_12_1 <= 100));
  __CPROVER_assume((pub_r001924_12_2 >= (-100)) && (pub_r001924_12_2 <= 100));
  __CPROVER_assume((pub_r001924_13_1 >= (-100)) && (pub_r001924_13_1 <= 100));
  __CPROVER_assume((pub_r001924_13_2 >= (-100)) && (pub_r001924_13_2 <= 100));
  __CPROVER_assume((pub_r001924_14_1 >= (-100)) && (pub_r001924_14_1 <= 100));
  __CPROVER_assume((pub_r001924_14_2 >= (-100)) && (pub_r001924_14_2 <= 100));
  __CPROVER_assume((pub_r001924_15_1 >= (-100)) && (pub_r001924_15_1 <= 100));
  __CPROVER_assume((pub_r001924_15_2 >= (-100)) && (pub_r001924_15_2 <= 100));
  __CPROVER_assume((sec_r001924_0_1 >= 0) && (sec_r001924_0_1 <= 255));
  __CPROVER_assume((sec_r001924_0_2 >= 0) && (sec_r001924_0_2 <= 255));
  __CPROVER_assume((sec_r001924_1_1 >= 0) && (sec_r001924_1_1 <= 255));
  __CPROVER_assume((sec_r001924_1_2 >= 0) && (sec_r001924_1_2 <= 255));
  __CPROVER_assume((sec_r001924_2_1 >= 0) && (sec_r001924_2_1 <= 255));
  __CPROVER_assume((sec_r001924_2_2 >= 0) && (sec_r001924_2_2 <= 255));
  __CPROVER_assume((sec_r001924_3_1 >= 0) && (sec_r001924_3_1 <= 255));
  __CPROVER_assume((sec_r001924_3_2 >= 0) && (sec_r001924_3_2 <= 255));
  __CPROVER_assume((sec_r001924_4_1 >= 0) && (sec_r001924_4_1 <= 255));
  __CPROVER_assume((sec_r001924_4_2 >= 0) && (sec_r001924_4_2 <= 255));
  __CPROVER_assume((sec_r001924_5_1 >= 0) && (sec_r001924_5_1 <= 255));
  __CPROVER_assume((sec_r001924_5_2 >= 0) && (sec_r001924_5_2 <= 255));
  __CPROVER_assume((sec_r001924_6_1 >= 0) && (sec_r001924_6_1 <= 255));
  __CPROVER_assume((sec_r001924_6_2 >= 0) && (sec_r001924_6_2 <= 255));
  __CPROVER_assume((sec_r001924_7_1 >= 0) && (sec_r001924_7_1 <= 255));
  __CPROVER_assume((sec_r001924_7_2 >= 0) && (sec_r001924_7_2 <= 255));
  __CPROVER_assume((sec_r001924_8_1 >= 0) && (sec_r001924_8_1 <= 255));
  __CPROVER_assume((sec_r001924_8_2 >= 0) && (sec_r001924_8_2 <= 255));
  __CPROVER_assume((sec_r001924_9_1 >= 0) && (sec_r001924_9_1 <= 255));
  __CPROVER_assume((sec_r001924_9_2 >= 0) && (sec_r001924_9_2 <= 255));
  __CPROVER_assume((sec_r001924_10_1 >= 0) && (sec_r001924_10_1 <= 255));
  __CPROVER_assume((sec_r001924_10_2 >= 0) && (sec_r001924_10_2 <= 255));
  __CPROVER_assume((sec_r001924_11_1 >= 0) && (sec_r001924_11_1 <= 255));
  __CPROVER_assume((sec_r001924_11_2 >= 0) && (sec_r001924_11_2 <= 255));
  __CPROVER_assume((sec_r001924_12_1 >= 0) && (sec_r001924_12_1 <= 255));
  __CPROVER_assume((sec_r001924_12_2 >= 0) && (sec_r001924_12_2 <= 255));
  __CPROVER_assume((sec_r001924_13_1 >= 0) && (sec_r001924_13_1 <= 255));
  __CPROVER_assume((sec_r001924_13_2 >= 0) && (sec_r001924_13_2 <= 255));
  __CPROVER_assume((sec_r001924_14_1 >= 0) && (sec_r001924_14_1 <= 255));
  __CPROVER_assume((sec_r001924_14_2 >= 0) && (sec_r001924_14_2 <= 255));
  __CPROVER_assume((sec_r001924_15_1 >= 0) && (sec_r001924_15_1 <= 255));
  __CPROVER_assume((sec_r001924_15_2 >= 0) && (sec_r001924_15_2 <= 255));
  __CPROVER_assume((sec_r001924_16_1 >= 0) && (sec_r001924_16_1 <= 255));
  __CPROVER_assume((sec_r001924_16_2 >= 0) && (sec_r001924_16_2 <= 255));
  __CPROVER_assume((sec_r001924_17_1 >= 0) && (sec_r001924_17_1 <= 255));
  __CPROVER_assume((sec_r001924_17_2 >= 0) && (sec_r001924_17_2 <= 255));
  __CPROVER_assume((sec_r001924_18_1 >= 0) && (sec_r001924_18_1 <= 255));
  __CPROVER_assume((sec_r001924_18_2 >= 0) && (sec_r001924_18_2 <= 255));
  __CPROVER_assume((sec_r001924_19_1 >= 0) && (sec_r001924_19_1 <= 255));
  __CPROVER_assume((sec_r001924_19_2 >= 0) && (sec_r001924_19_2 <= 255));
  struct FilterState_R001924_2413_0 st_var_0_1 = {0};
  struct FilterState_R001924_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001924_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001924_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001924_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001924_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001924_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001924_0_2 + 7) & 15;
  struct SensorNode_R001924_2413_1 st_var_1_1 = {0};
  struct SensorNode_R001924_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001924_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001924_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001924_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001924_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001924_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001924_0_2 + 9) & 15;
  union TelemetryField_R001924_2413_0 u_var_1;
  union TelemetryField_R001924_2413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001924_2413_0(sec_r001924_0_1, sec_r001924_1_1, pub_r001924_2_1, pub_r001924_3_1, pub_r001924_4_1);
  int helper_flow_0_2 = fn_R001924_2413_0(sec_r001924_0_2, sec_r001924_1_2, pub_r001924_2_2, pub_r001924_3_2, pub_r001924_4_2);
  fn_R001924_2413_0_2(sec_r001924_0_1, sec_r001924_1_1, pub_r001924_2_1, pub_r001924_3_1, pub_r001924_4_1, sec_r001924_0_2, sec_r001924_1_2, pub_r001924_2_2, pub_r001924_3_2, pub_r001924_4_2);
  int helper_flow_1_1 = fn_R001924_2413_1(sec_r001924_1_1, sec_r001924_2_1, pub_r001924_3_1, pub_r001924_4_1, pub_r001924_5_1);
  int helper_flow_1_2 = fn_R001924_2413_1(sec_r001924_1_2, sec_r001924_2_2, pub_r001924_3_2, pub_r001924_4_2, pub_r001924_5_2);
  fn_R001924_2413_1_2(sec_r001924_1_1, sec_r001924_2_1, pub_r001924_3_1, pub_r001924_4_1, pub_r001924_5_1, sec_r001924_1_2, sec_r001924_2_2, pub_r001924_3_2, pub_r001924_4_2, pub_r001924_5_2);
  int helper_flow_2_1 = fn_R001924_2413_2(sec_r001924_2_1, pub_r001924_3_1, pub_r001924_4_1, pub_r001924_5_1);
  int helper_flow_2_2 = fn_R001924_2413_2(sec_r001924_2_2, pub_r001924_3_2, pub_r001924_4_2, pub_r001924_5_2);
  fn_R001924_2413_2_2(sec_r001924_2_1, pub_r001924_3_1, pub_r001924_4_1, pub_r001924_5_1, sec_r001924_2_2, pub_r001924_3_2, pub_r001924_4_2, pub_r001924_5_2);
  int helper_flow_3_1 = fn_R001924_2413_3(sec_r001924_3_1, pub_r001924_4_1, pub_r001924_5_1);
  int helper_flow_3_2 = fn_R001924_2413_3(sec_r001924_3_2, pub_r001924_4_2, pub_r001924_5_2);
  fn_R001924_2413_3_2(sec_r001924_3_1, pub_r001924_4_1, pub_r001924_5_1, sec_r001924_3_2, pub_r001924_4_2, pub_r001924_5_2);
  int helper_flow_4_1 = fn_R001924_2413_4(sec_r001924_4_1, pub_r001924_5_1, pub_r001924_6_1);
  int helper_flow_4_2 = fn_R001924_2413_4(sec_r001924_4_2, pub_r001924_5_2, pub_r001924_6_2);
  fn_R001924_2413_4_2(sec_r001924_4_1, pub_r001924_5_1, pub_r001924_6_1, sec_r001924_4_2, pub_r001924_5_2, pub_r001924_6_2);
  int helper_flow_5_1 = fn_R001924_2413_5(sec_r001924_5_1, sec_r001924_6_1, pub_r001924_7_1, pub_r001924_8_1);
  int helper_flow_5_2 = fn_R001924_2413_5(sec_r001924_5_2, sec_r001924_6_2, pub_r001924_7_2, pub_r001924_8_2);
  fn_R001924_2413_5_2(sec_r001924_5_1, sec_r001924_6_1, pub_r001924_7_1, pub_r001924_8_1, sec_r001924_5_2, sec_r001924_6_2, pub_r001924_7_2, pub_r001924_8_2);
  int helper_flow_6_1 = fn_R001924_2413_6(sec_r001924_6_1, sec_r001924_7_1, pub_r001924_8_1);
  int helper_flow_6_2 = fn_R001924_2413_6(sec_r001924_6_2, sec_r001924_7_2, pub_r001924_8_2);
  fn_R001924_2413_6_2(sec_r001924_6_1, sec_r001924_7_1, pub_r001924_8_1, sec_r001924_6_2, sec_r001924_7_2, pub_r001924_8_2);
  int helper_flow_7_1 = fn_R001924_2413_7(sec_r001924_7_1, pub_r001924_8_1, pub_r001924_9_1);
  int helper_flow_7_2 = fn_R001924_2413_7(sec_r001924_7_2, pub_r001924_8_2, pub_r001924_9_2);
  fn_R001924_2413_7_2(sec_r001924_7_1, pub_r001924_8_1, pub_r001924_9_1, sec_r001924_7_2, pub_r001924_8_2, pub_r001924_9_2);
  int stage_v_0_1 = ((pub_r001924_8_1 * 2) + 22) & 63;
  int stage_v_0_2 = ((pub_r001924_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001924_16_1 * 3) + pub_r001924_12_1) + 8) & 127;
  int stage_v_1_2 = (((sec_r001924_16_2 * 3) + pub_r001924_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001924_19_1 * 3) + pub_r001924_7_1) + 11) & 127;
  int stage_v_2_2 = (((sec_r001924_19_2 * 3) + pub_r001924_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001924_2_1 * 3) + pub_r001924_13_1) + 41) & 127;
  int stage_v_3_2 = (((sec_r001924_2_2 * 3) + pub_r001924_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001924_1_1 * 3) + pub_r001924_6_1) + 33) & 127;
  int stage_v_4_2 = (((sec_r001924_1_2 * 3) + pub_r001924_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001924_1_1 * 2) + 42) & 63;
  int stage_v_5_2 = ((pub_r001924_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001924_0_1 * 2) + 44) & 63;
  int stage_v_6_2 = ((pub_r001924_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001924_14_1 * 3) + pub_r001924_3_1) + 19) & 127;
  int stage_v_7_2 = (((sec_r001924_14_2 * 3) + pub_r001924_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((sec_r001924_0_1 * 3) + pub_r001924_1_1) + 26) & 127;
  int stage_v_8_2 = (((sec_r001924_0_2 * 3) + pub_r001924_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001924_12_1 * 3) + pub_r001924_14_1) + 45) & 127;
  int stage_v_9_2 = (((sec_r001924_12_2 * 3) + pub_r001924_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((stage_v_9_1 * 3) + pub_r001924_9_1) + 7) & 127;
  int stage_v_10_2 = (((stage_v_9_2 * 3) + pub_r001924_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((stage_v_9_1 * 3) + pub_r001924_15_1) + 35) & 127;
  int stage_v_11_2 = (((stage_v_9_2 * 3) + pub_r001924_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001924_1_1 * 2) + 46) & 63;
  int stage_v_12_2 = ((pub_r001924_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001924_8_1 * 2) + 15) & 63;
  int stage_v_13_2 = ((pub_r001924_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001924_18_1 * 3) + pub_r001924_14_1) + 21) & 127;
  int stage_v_14_2 = (((sec_r001924_18_2 * 3) + pub_r001924_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_14_1 * 3) + pub_r001924_12_1) + 41) & 127;
  int stage_v_15_2 = (((stage_v_14_2 * 3) + pub_r001924_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((sec_r001924_14_1 * 3) + pub_r001924_11_1) + 28) & 127;
  int stage_v_16_2 = (((sec_r001924_14_2 * 3) + pub_r001924_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001924_6_1 * 3) + pub_r001924_5_1) + 24) & 127;
  int stage_v_17_2 = (((sec_r001924_6_2 * 3) + pub_r001924_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((stage_v_3_1 * 3) + pub_r001924_11_1) + 4) & 127;
  int stage_v_18_2 = (((stage_v_3_2 * 3) + pub_r001924_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001924_6_1 * 2) + 24) & 63;
  int stage_v_19_2 = ((pub_r001924_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001924_14_1 * 2) + 30) & 63;
  int stage_v_20_2 = ((pub_r001924_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((helper_flow_2_1 * 3) + pub_r001924_4_1) + 18) & 127;
  int stage_v_21_2 = (((helper_flow_2_2 * 3) + pub_r001924_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((helper_flow_1_1 * 3) + pub_r001924_10_1) + 35) & 127;
  int stage_v_22_2 = (((helper_flow_1_2 * 3) + pub_r001924_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((sec_r001924_0_1 * 3) + pub_r001924_15_1) + 35) & 127;
  int stage_v_23_2 = (((sec_r001924_0_2 * 3) + pub_r001924_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((helper_flow_6_1 * 3) + pub_r001924_15_1) + 31) & 127;
  int stage_v_24_2 = (((helper_flow_6_2 * 3) + pub_r001924_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((stage_v_9_1 * 3) + pub_r001924_9_1) + 5) & 127;
  int stage_v_25_2 = (((stage_v_9_2 * 3) + pub_r001924_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001924_11_1 * 2) + 10) & 63;
  int stage_v_26_2 = ((pub_r001924_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001924_18_1 * 3) + pub_r001924_5_1) + 20) & 127;
  int stage_v_27_2 = (((sec_r001924_18_2 * 3) + pub_r001924_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((stage_v_15_1 * 3) + pub_r001924_13_1) + 25) & 127;
  int stage_v_28_2 = (((stage_v_15_2 * 3) + pub_r001924_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001924_17_1 * 3) + pub_r001924_11_1) + 44) & 127;
  int stage_v_29_2 = (((sec_r001924_17_2 * 3) + pub_r001924_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001924_7_1 * 2) + 29) & 63;
  int stage_v_30_2 = ((pub_r001924_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001924_15_1 * 2) + 47) & 63;
  int stage_v_31_2 = ((pub_r001924_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001924_10_1 * 3) + pub_r001924_7_1) + 35) & 127;
  int stage_v_32_2 = (((sec_r001924_10_2 * 3) + pub_r001924_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001924_8_1 * 3) + pub_r001924_6_1) + 12) & 127;
  int stage_v_33_2 = (((sec_r001924_8_2 * 3) + pub_r001924_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_15_1 * 3) + pub_r001924_10_1) + 6) & 127;
  int stage_v_34_2 = (((stage_v_15_2 * 3) + pub_r001924_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001924_7_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001924_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001924_11_1 * 2) + 21) & 63;
  int stage_v_36_2 = ((pub_r001924_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001924_12_1 * 2) + 33) & 63;
  int stage_v_37_2 = ((pub_r001924_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001924_12_1 * 2) + 12) & 63;
  int stage_v_38_2 = ((pub_r001924_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001924_4_1 * 3) + pub_r001924_10_1) + 4) & 127;
  int stage_v_39_2 = (((sec_r001924_4_2 * 3) + pub_r001924_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001924_5_1 * 2) + 45) & 63;
  int stage_v_40_2 = ((pub_r001924_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001924_6_1 * 3) + pub_r001924_0_1) + 44) & 127;
  int stage_v_41_2 = (((sec_r001924_6_2 * 3) + pub_r001924_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001924_11_1 * 2) + 5) & 63;
  int stage_v_42_2 = ((pub_r001924_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001924_14_1 * 3) + pub_r001924_10_1) + 38) & 127;
  int stage_v_43_2 = (((sec_r001924_14_2 * 3) + pub_r001924_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001924_7_1 * 2) + 27) & 63;
  int stage_v_44_2 = ((pub_r001924_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001924_5_1 * 2) + 38) & 63;
  int stage_v_45_2 = ((pub_r001924_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001924_11_1 * 3) + pub_r001924_6_1) + 38) & 127;
  int stage_v_46_2 = (((sec_r001924_11_2 * 3) + pub_r001924_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((stage_v_10_1 * 3) + pub_r001924_3_1) + 6) & 127;
  int stage_v_47_2 = (((stage_v_10_2 * 3) + pub_r001924_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((sec_r001924_5_1 * 3) + pub_r001924_4_1) + 36) & 127;
  int stage_v_48_2 = (((sec_r001924_5_2 * 3) + pub_r001924_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_23_1 * 3) + pub_r001924_4_1) + 36) & 127;
  int stage_v_49_2 = (((stage_v_23_2 * 3) + pub_r001924_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001924_0_1 * 2) + 16) & 63;
  int stage_v_50_2 = ((pub_r001924_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_4_1 * 3) + pub_r001924_2_1) + 32) & 127;
  int stage_v_51_2 = (((stage_v_4_2 * 3) + pub_r001924_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((helper_flow_3_1 * 3) + pub_r001924_14_1) + 25) & 127;
  int stage_v_52_2 = (((helper_flow_3_2 * 3) + pub_r001924_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((stage_v_48_1 * 3) + pub_r001924_8_1) + 28) & 127;
  int stage_v_53_2 = (((stage_v_48_2 * 3) + pub_r001924_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((stage_v_49_1 * 3) + pub_r001924_6_1) + 14) & 127;
  int stage_v_54_2 = (((stage_v_49_2 * 3) + pub_r001924_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_4_1 * 3) + pub_r001924_9_1) + 26) & 127;
  int stage_v_55_2 = (((stage_v_4_2 * 3) + pub_r001924_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((sec_r001924_11_1 * 3) + pub_r001924_15_1) + 17) & 127;
  int stage_v_56_2 = (((sec_r001924_11_2 * 3) + pub_r001924_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001924_13_1 * 2) + 11) & 63;
  int stage_v_57_2 = ((pub_r001924_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001924_0_1 * 2) + 15) & 63;
  int stage_v_58_2 = ((pub_r001924_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((helper_flow_4_1 * 3) + pub_r001924_5_1) + 16) & 127;
  int stage_v_59_2 = (((helper_flow_4_2 * 3) + pub_r001924_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001924_9_1 * 2) + 23) & 63;
  int stage_v_60_2 = ((pub_r001924_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_15_1 * 3) + pub_r001924_15_1) + 33) & 127;
  int stage_v_61_2 = (((stage_v_15_2 * 3) + pub_r001924_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001924_15_1 * 2) + 39) & 63;
  int stage_v_62_2 = ((pub_r001924_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_21_1 * 3) + pub_r001924_1_1) + 31) & 127;
  int stage_v_63_2 = (((stage_v_21_2 * 3) + pub_r001924_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001924_15_1 * 2) + 39) & 63;
  int stage_v_64_2 = ((pub_r001924_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001924_13_1 * 2) + 42) & 63;
  int stage_v_65_2 = ((pub_r001924_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001924_3_1 * 2) + 34) & 63;
  int stage_v_66_2 = ((pub_r001924_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_29_1 * 3) + pub_r001924_0_1) + 32) & 127;
  int stage_v_67_2 = (((stage_v_29_2 * 3) + pub_r001924_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_28_1 * 3) + pub_r001924_0_1) + 11) & 127;
  int stage_v_68_2 = (((stage_v_28_2 * 3) + pub_r001924_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001924_7_1 * 2) + 34) & 63;
  int stage_v_69_2 = ((pub_r001924_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001924_8_1 * 2) + 46) & 63;
  int stage_v_70_2 = ((pub_r001924_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001924_4_1 * 2) + 32) & 63;
  int stage_v_71_2 = ((pub_r001924_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001924_12_1 * 2) + 45) & 63;
  int stage_v_72_2 = ((pub_r001924_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((helper_flow_3_1 * 3) + pub_r001924_7_1) + 28) & 127;
  int stage_v_73_2 = (((helper_flow_3_2 * 3) + pub_r001924_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001924_2_1 * 2) + 6) & 63;
  int stage_v_74_2 = ((pub_r001924_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_53_1 * 3) + pub_r001924_5_1) + 44) & 127;
  int stage_v_75_2 = (((stage_v_53_2 * 3) + pub_r001924_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001924_10_1 * 2) + 47) & 63;
  int stage_v_76_2 = ((pub_r001924_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((helper_flow_0_1 * 3) + pub_r001924_13_1) + 21) & 127;
  int stage_v_77_2 = (((helper_flow_0_2 * 3) + pub_r001924_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001924_6_1 * 2) + 5) & 63;
  int stage_v_78_2 = ((pub_r001924_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_56_1 * 3) + pub_r001924_10_1) + 41) & 127;
  int stage_v_79_2 = (((stage_v_56_2 * 3) + pub_r001924_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001924_2_1 * 2) + 21) & 63;
  int stage_v_80_2 = ((pub_r001924_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001924_0_1 * 2) + 10) & 63;
  int stage_v_81_2 = ((pub_r001924_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001924_11_1 * 2) + 10) & 63;
  int stage_v_82_2 = ((pub_r001924_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001924_15_1 * 2) + 48) & 63;
  int stage_v_83_2 = ((pub_r001924_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001924_4_1 * 3) + pub_r001924_12_1) + 38) & 127;
  int stage_v_84_2 = (((sec_r001924_4_2 * 3) + pub_r001924_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_29_1 * 3) + pub_r001924_0_1) + 16) & 127;
  int stage_v_85_2 = (((stage_v_29_2 * 3) + pub_r001924_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((stage_v_28_1 * 3) + pub_r001924_7_1) + 9) & 127;
  int stage_v_86_2 = (((stage_v_28_2 * 3) + pub_r001924_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((stage_v_85_1 * 3) + pub_r001924_3_1) + 32) & 127;
  int stage_v_87_2 = (((stage_v_85_2 * 3) + pub_r001924_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001924_6_1 * 2) + 6) & 63;
  int stage_v_88_2 = ((pub_r001924_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_63_1 * 3) + pub_r001924_3_1) + 36) & 127;
  int stage_v_89_2 = (((stage_v_63_2 * 3) + pub_r001924_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_33_1 * 3) + pub_r001924_7_1) + 3) & 127;
  int stage_v_90_2 = (((stage_v_33_2 * 3) + pub_r001924_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_86_1 * 3) + pub_r001924_8_1) + 44) & 127;
  int stage_v_91_2 = (((stage_v_86_2 * 3) + pub_r001924_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_17_1 * 3) + pub_r001924_8_1) + 3) & 127;
  int stage_v_92_2 = (((stage_v_17_2 * 3) + pub_r001924_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((sec_r001924_13_1 * 3) + pub_r001924_1_1) + 44) & 127;
  int stage_v_93_2 = (((sec_r001924_13_2 * 3) + pub_r001924_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001924_15_1 * 2) + 22) & 63;
  int stage_v_94_2 = ((pub_r001924_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001924_0_1 * 2) + 23) & 63;
  int stage_v_95_2 = ((pub_r001924_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001924_0_1 * 3) + pub_r001924_1_1) + 25) & 127;
  int stage_v_96_2 = (((sec_r001924_0_2 * 3) + pub_r001924_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((stage_v_48_1 * 3) + pub_r001924_8_1) + 6) & 127;
  int stage_v_97_2 = (((stage_v_48_2 * 3) + pub_r001924_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001924_3_1 * 2) + 10) & 63;
  int stage_v_98_2 = ((pub_r001924_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_79_1 * 3) + pub_r001924_7_1) + 30) & 127;
  int stage_v_99_2 = (((stage_v_79_2 * 3) + pub_r001924_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001924_11_1 * 2) + 25) & 63;
  int stage_v_100_2 = ((pub_r001924_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_49_1 * 3) + pub_r001924_0_1) + 11) & 127;
  int stage_v_101_2 = (((stage_v_49_2 * 3) + pub_r001924_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001924_7_1 * 2) + 6) & 63;
  int stage_v_102_2 = ((pub_r001924_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_7_1 * 3) + pub_r001924_6_1) + 38) & 127;
  int stage_v_103_2 = (((stage_v_7_2 * 3) + pub_r001924_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001924_0_1 * 2) + 48) & 63;
  int stage_v_104_2 = ((pub_r001924_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_9_1 * 3) + pub_r001924_3_1) + 20) & 127;
  int stage_v_105_2 = (((stage_v_9_2 * 3) + pub_r001924_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((helper_flow_7_1 * 3) + pub_r001924_13_1) + 43) & 127;
  int stage_v_106_2 = (((helper_flow_7_2 * 3) + pub_r001924_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001924_5_1 * 2) + 15) & 63;
  int stage_v_107_2 = ((pub_r001924_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((sec_r001924_15_1 * 3) + pub_r001924_12_1) + 36) & 127;
  int stage_v_108_2 = (((sec_r001924_15_2 * 3) + pub_r001924_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((sec_r001924_18_1 * 3) + pub_r001924_9_1) + 12) & 127;
  int stage_v_109_2 = (((sec_r001924_18_2 * 3) + pub_r001924_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_68_1 * 3) + pub_r001924_9_1) + 6) & 127;
  int stage_v_110_2 = (((stage_v_68_2 * 3) + pub_r001924_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_33_1 * 3) + pub_r001924_4_1) + 35) & 127;
  int stage_v_111_2 = (((stage_v_33_2 * 3) + pub_r001924_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((sec_r001924_4_1 * 3) + pub_r001924_12_1) + 12) & 127;
  int stage_v_112_2 = (((sec_r001924_4_2 * 3) + pub_r001924_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001924_2_1 * 2) + 11) & 63;
  int stage_v_113_2 = ((pub_r001924_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_10_1 * 3) + pub_r001924_7_1) + 14) & 127;
  int stage_v_114_2 = (((stage_v_10_2 * 3) + pub_r001924_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_33_1 * 3) + pub_r001924_10_1) + 14) & 127;
  int stage_v_115_2 = (((stage_v_33_2 * 3) + pub_r001924_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001924_10_1 * 2) + 13) & 63;
  int stage_v_116_2 = ((pub_r001924_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_92_1 * 3) + pub_r001924_15_1) + 29) & 127;
  int stage_v_117_2 = (((stage_v_92_2 * 3) + pub_r001924_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((helper_flow_4_1 * 3) + pub_r001924_14_1) + 19) & 127;
  int stage_v_118_2 = (((helper_flow_4_2 * 3) + pub_r001924_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((sec_r001924_12_1 * 3) + pub_r001924_4_1) + 5) & 127;
  int stage_v_119_2 = (((sec_r001924_12_2 * 3) + pub_r001924_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((stage_v_79_1 * 3) + pub_r001924_7_1) + 33) & 127;
  int stage_v_120_2 = (((stage_v_79_2 * 3) + pub_r001924_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((helper_flow_4_1 * 3) + pub_r001924_6_1) + 30) & 127;
  int stage_v_121_2 = (((helper_flow_4_2 * 3) + pub_r001924_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_16_1 * 3) + pub_r001924_9_1) + 44) & 127;
  int stage_v_122_2 = (((stage_v_16_2 * 3) + pub_r001924_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001924_15_1 * 2) + 27) & 63;
  int stage_v_123_2 = ((pub_r001924_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001924_0_1 * 2) + 26) & 63;
  int stage_v_124_2 = ((pub_r001924_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_84_1 * 3) + pub_r001924_0_1) + 42) & 127;
  int stage_v_125_2 = (((stage_v_84_2 * 3) + pub_r001924_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_87_1 * 3) + pub_r001924_9_1) + 44) & 127;
  int stage_v_126_2 = (((stage_v_87_2 * 3) + pub_r001924_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_56_1 * 3) + pub_r001924_2_1) + 31) & 127;
  int stage_v_127_2 = (((stage_v_56_2 * 3) + pub_r001924_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_112_1 * 3) + pub_r001924_5_1) + 40) & 127;
  int stage_v_128_2 = (((stage_v_112_2 * 3) + pub_r001924_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001924_11_1 * 2) + 50) & 63;
  int stage_v_129_2 = ((pub_r001924_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((sec_r001924_6_1 * 3) + pub_r001924_0_1) + 18) & 127;
  int stage_v_130_2 = (((sec_r001924_6_2 * 3) + pub_r001924_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_11_1 * 3) + pub_r001924_8_1) + 30) & 127;
  int stage_v_131_2 = (((stage_v_11_2 * 3) + pub_r001924_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((stage_v_7_1 * 3) + pub_r001924_10_1) + 6) & 127;
  int stage_v_132_2 = (((stage_v_7_2 * 3) + pub_r001924_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = ((pub_r001924_8_1 * 2) + 39) & 63;
  int stage_v_133_2 = ((pub_r001924_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001924_1_1 * 2) + 10) & 63;
  int stage_v_134_2 = ((pub_r001924_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((sec_r001924_19_1 * 3) + pub_r001924_5_1) + 21) & 127;
  int stage_v_135_2 = (((sec_r001924_19_2 * 3) + pub_r001924_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_117_1 * 3) + pub_r001924_4_1) + 4) & 127;
  int stage_v_136_2 = (((stage_v_117_2 * 3) + pub_r001924_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_27_1 * 3) + pub_r001924_12_1) + 42) & 127;
  int stage_v_137_2 = (((stage_v_27_2 * 3) + pub_r001924_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_4_1 * 3) + pub_r001924_13_1) + 31) & 127;
  int stage_v_138_2 = (((stage_v_4_2 * 3) + pub_r001924_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((helper_flow_7_1 * 3) + pub_r001924_1_1) + 39) & 127;
  int stage_v_139_2 = (((helper_flow_7_2 * 3) + pub_r001924_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_17_1 * 3) + pub_r001924_9_1) + 23) & 127;
  int stage_v_140_2 = (((stage_v_17_2 * 3) + pub_r001924_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001924_5_1 * 2) + 11) & 63;
  int stage_v_141_2 = ((pub_r001924_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001924_2_1 * 2) + 46) & 63;
  int stage_v_142_2 = ((pub_r001924_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001924_1_1 * 2) + 15) & 63;
  int stage_v_143_2 = ((pub_r001924_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_117_1 * 3) + pub_r001924_15_1) + 17) & 127;
  int stage_v_144_2 = (((stage_v_117_2 * 3) + pub_r001924_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((helper_flow_4_1 * 3) + pub_r001924_15_1) + 33) & 127;
  int stage_v_145_2 = (((helper_flow_4_2 * 3) + pub_r001924_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_73_1 * 3) + pub_r001924_7_1) + 17) & 127;
  int stage_v_146_2 = (((stage_v_73_2 * 3) + pub_r001924_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001924_11_1 * 2) + 49) & 63;
  int stage_v_147_2 = ((pub_r001924_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((helper_flow_3_1 * 3) + pub_r001924_10_1) + 18) & 127;
  int stage_v_148_2 = (((helper_flow_3_2 * 3) + pub_r001924_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = ((pub_r001924_14_1 * 2) + 22) & 63;
  int stage_v_149_2 = ((pub_r001924_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001924_8_1 * 2) + 24) & 63;
  int stage_v_150_2 = ((pub_r001924_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001924_4_1 * 2) + 22) & 63;
  int stage_v_151_2 = ((pub_r001924_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001924_6_1 * 2) + 9) & 63;
  int stage_v_152_2 = ((pub_r001924_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001924_7_1 * 2) + 6) & 63;
  int stage_v_153_2 = ((pub_r001924_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001924_5_1 * 2) + 26) & 63;
  int stage_v_154_2 = ((pub_r001924_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_10_1 * 3) + pub_r001924_15_1) + 40) & 127;
  int stage_v_155_2 = (((stage_v_10_2 * 3) + pub_r001924_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_24_1 * 3) + pub_r001924_0_1) + 19) & 127;
  int stage_v_156_2 = (((stage_v_24_2 * 3) + pub_r001924_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001924_8_1 * 2) + 27) & 63;
  int stage_v_157_2 = ((pub_r001924_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((helper_flow_4_1 * 3) + pub_r001924_4_1) + 15) & 127;
  int stage_v_158_2 = (((helper_flow_4_2 * 3) + pub_r001924_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_119_1 * 3) + pub_r001924_14_1) + 11) & 127;
  int stage_v_159_2 = (((stage_v_119_2 * 3) + pub_r001924_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_10_1 * 3) + pub_r001924_4_1) + 25) & 127;
  int stage_v_160_2 = (((stage_v_10_2 * 3) + pub_r001924_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_52_1 * 3) + pub_r001924_13_1) + 6) & 127;
  int stage_v_161_2 = (((stage_v_52_2 * 3) + pub_r001924_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_112_1 * 3) + pub_r001924_1_1) + 31) & 127;
  int stage_v_162_2 = (((stage_v_112_2 * 3) + pub_r001924_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_111_1 * 3) + pub_r001924_6_1) + 12) & 127;
  int stage_v_163_2 = (((stage_v_111_2 * 3) + pub_r001924_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((sec_r001924_9_1 * 3) + pub_r001924_15_1) + 32) & 127;
  int stage_v_164_2 = (((sec_r001924_9_2 * 3) + pub_r001924_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001924_13_1 * 2) + 31) & 63;
  int stage_v_165_2 = ((pub_r001924_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_101_1 * 3) + pub_r001924_10_1) + 44) & 127;
  int stage_v_166_2 = (((stage_v_101_2 * 3) + pub_r001924_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001924_1_1 * 2) + 11) & 63;
  int stage_v_167_2 = ((pub_r001924_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001924_2_1 * 2) + 40) & 63;
  int stage_v_168_2 = ((pub_r001924_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001924_9_1 * 2) + 38) & 63;
  int stage_v_169_2 = ((pub_r001924_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001924_0_1 * 2) + 5) & 63;
  int stage_v_170_2 = ((pub_r001924_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_121_1 * 3) + pub_r001924_15_1) + 17) & 127;
  int stage_v_171_2 = (((stage_v_121_2 * 3) + pub_r001924_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001924_13_1 * 2) + 22) & 63;
  int stage_v_172_2 = ((pub_r001924_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001924_0_1 * 2) + 23) & 63;
  int stage_v_173_2 = ((pub_r001924_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001924_1_1 * 2) + 5) & 63;
  int stage_v_174_2 = ((pub_r001924_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001924_3_1 * 2) + 40) & 63;
  int stage_v_175_2 = ((pub_r001924_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001924_0_1 * 2) + 10) & 63;
  int stage_v_176_2 = ((pub_r001924_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((sec_r001924_0_1 * 3) + pub_r001924_13_1) + 14) & 127;
  int stage_v_177_2 = (((sec_r001924_0_2 * 3) + pub_r001924_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_33_1 * 3) + pub_r001924_4_1) + 44) & 127;
  int stage_v_178_2 = (((stage_v_33_2 * 3) + pub_r001924_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001924_3_1 * 2) + 21) & 63;
  int stage_v_179_2 = ((pub_r001924_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001924_5_1 * 2) + 21) & 63;
  int stage_v_180_2 = ((pub_r001924_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_47_1 * 3) + pub_r001924_2_1) + 7) & 127;
  int stage_v_181_2 = (((stage_v_47_2 * 3) + pub_r001924_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001924_0_1 * 2) + 31) & 63;
  int stage_v_182_2 = ((pub_r001924_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001924_6_1 * 2) + 43) & 63;
  int stage_v_183_2 = ((pub_r001924_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001924_3_1 * 2) + 12) & 63;
  int stage_v_184_2 = ((pub_r001924_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_75_1 * 3) + pub_r001924_4_1) + 20) & 127;
  int stage_v_185_2 = (((stage_v_75_2 * 3) + pub_r001924_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_146_1 * 3) + pub_r001924_2_1) + 33) & 127;
  int stage_v_186_2 = (((stage_v_146_2 * 3) + pub_r001924_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_32_1 * 3) + pub_r001924_2_1) + 42) & 127;
  int stage_v_187_2 = (((stage_v_32_2 * 3) + pub_r001924_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_2_1 * 3) + pub_r001924_7_1) + 22) & 127;
  int stage_v_188_2 = (((stage_v_2_2 * 3) + pub_r001924_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001924_5_1 * 2) + 22) & 63;
  int stage_v_189_2 = ((pub_r001924_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001924_12_1 * 2) + 17) & 63;
  int stage_v_190_2 = ((pub_r001924_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_138_1 * 3) + pub_r001924_12_1) + 9) & 127;
  int stage_v_191_2 = (((stage_v_138_2 * 3) + pub_r001924_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_118_1 * 3) + pub_r001924_5_1) + 36) & 127;
  int stage_v_192_2 = (((stage_v_118_2 * 3) + pub_r001924_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001924_7_1 * 2) + 14) & 63;
  int stage_v_193_2 = ((pub_r001924_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001924_11_1 * 2) + 50) & 63;
  int stage_v_194_2 = ((pub_r001924_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001924_0_1 * 2) + 20) & 63;
  int stage_v_195_2 = ((pub_r001924_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001924_5_1 * 3) + pub_r001924_15_1) + 6) & 127;
  int stage_v_196_2 = (((sec_r001924_5_2 * 3) + pub_r001924_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001924_12_1 * 2) + 49) & 63;
  int stage_v_197_2 = ((pub_r001924_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_14_1 * 3) + pub_r001924_15_1) + 26) & 127;
  int stage_v_198_2 = (((stage_v_14_2 * 3) + pub_r001924_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_54_1 * 3) + pub_r001924_7_1) + 25) & 127;
  int stage_v_199_2 = (((stage_v_54_2 * 3) + pub_r001924_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_10_1 * 3) + pub_r001924_6_1) + 6) & 127;
  int stage_v_200_2 = (((stage_v_10_2 * 3) + pub_r001924_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_163_1 * 3) + pub_r001924_9_1) + 41) & 127;
  int stage_v_201_2 = (((stage_v_163_2 * 3) + pub_r001924_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_128_1 * 3) + pub_r001924_15_1) + 45) & 127;
  int stage_v_202_2 = (((stage_v_128_2 * 3) + pub_r001924_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001924_2_1 * 2) + 21) & 63;
  int stage_v_203_2 = ((pub_r001924_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_155_1 * 3) + pub_r001924_5_1) + 8) & 127;
  int stage_v_204_2 = (((stage_v_155_2 * 3) + pub_r001924_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_130_1 * 3) + pub_r001924_15_1) + 44) & 127;
  int stage_v_205_2 = (((stage_v_130_2 * 3) + pub_r001924_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((sec_r001924_7_1 * 3) + pub_r001924_12_1) + 20) & 127;
  int stage_v_206_2 = (((sec_r001924_7_2 * 3) + pub_r001924_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_163_1 * 3) + pub_r001924_11_1) + 39) & 127;
  int stage_v_207_2 = (((stage_v_163_2 * 3) + pub_r001924_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001924_3_1 * 2) + 47) & 63;
  int stage_v_208_2 = ((pub_r001924_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_191_1 * 3) + pub_r001924_8_1) + 10) & 127;
  int stage_v_209_2 = (((stage_v_191_2 * 3) + pub_r001924_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_56_1 * 3) + pub_r001924_0_1) + 22) & 127;
  int stage_v_210_2 = (((stage_v_56_2 * 3) + pub_r001924_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = ((pub_r001924_4_1 * 2) + 33) & 63;
  int stage_v_211_2 = ((pub_r001924_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_188_1 * 3) + pub_r001924_10_1) + 27) & 127;
  int stage_v_212_2 = (((stage_v_188_2 * 3) + pub_r001924_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_8_1 * 3) + pub_r001924_11_1) + 7) & 127;
  int stage_v_213_2 = (((stage_v_8_2 * 3) + pub_r001924_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001924_11_1 * 2) + 26) & 63;
  int stage_v_214_2 = ((pub_r001924_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_145_1 * 3) + pub_r001924_10_1) + 12) & 127;
  int stage_v_215_2 = (((stage_v_145_2 * 3) + pub_r001924_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001924_12_1 * 2) + 41) & 63;
  int stage_v_216_2 = ((pub_r001924_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_22_1 * 3) + pub_r001924_15_1) + 3) & 127;
  int stage_v_217_2 = (((stage_v_22_2 * 3) + pub_r001924_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_52_1 * 3) + pub_r001924_4_1) + 19) & 127;
  int stage_v_218_2 = (((stage_v_52_2 * 3) + pub_r001924_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001924_2_1 * 2) + 36) & 63;
  int stage_v_219_2 = ((pub_r001924_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_9_1 * 3) + pub_r001924_0_1) + 44) & 127;
  int stage_v_220_2 = (((stage_v_9_2 * 3) + pub_r001924_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001924_4_1 * 2) + 43) & 63;
  int stage_v_221_2 = ((pub_r001924_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_48_1 * 3) + pub_r001924_15_1) + 45) & 127;
  int stage_v_222_2 = (((stage_v_48_2 * 3) + pub_r001924_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001924_9_1 * 2) + 36) & 63;
  int stage_v_223_2 = ((pub_r001924_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001924_13_1 * 2) + 7) & 63;
  int stage_v_224_2 = ((pub_r001924_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001924_15_1 * 2) + 37) & 63;
  int stage_v_225_2 = ((pub_r001924_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((sec_r001924_15_1 * 3) + pub_r001924_5_1) + 33) & 127;
  int stage_v_226_2 = (((sec_r001924_15_2 * 3) + pub_r001924_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((sec_r001924_4_1 * 3) + pub_r001924_7_1) + 21) & 127;
  int stage_v_227_2 = (((sec_r001924_4_2 * 3) + pub_r001924_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001924_9_1 * 2) + 21) & 63;
  int stage_v_228_2 = ((pub_r001924_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_51_1 * 3) + pub_r001924_3_1) + 11) & 127;
  int stage_v_229_2 = (((stage_v_51_2 * 3) + pub_r001924_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_93_1 * 3) + pub_r001924_11_1) + 23) & 127;
  int stage_v_230_2 = (((stage_v_93_2 * 3) + pub_r001924_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001924_5_1 * 2) + 12) & 63;
  int stage_v_231_2 = ((pub_r001924_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((sec_r001924_19_1 * 3) + pub_r001924_9_1) + 25) & 127;
  int stage_v_232_2 = (((sec_r001924_19_2 * 3) + pub_r001924_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_120_1 * 3) + pub_r001924_12_1) + 39) & 127;
  int stage_v_233_2 = (((stage_v_120_2 * 3) + pub_r001924_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_188_1 * 3) + pub_r001924_4_1) + 45) & 127;
  int stage_v_234_2 = (((stage_v_188_2 * 3) + pub_r001924_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001924_1_1 * 2) + 32) & 63;
  int stage_v_235_2 = ((pub_r001924_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001924_14_1 * 2) + 41) & 63;
  int stage_v_236_2 = ((pub_r001924_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((helper_flow_4_1 * 3) + pub_r001924_4_1) + 10) & 127;
  int stage_v_237_2 = (((helper_flow_4_2 * 3) + pub_r001924_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_109_1 * 3) + pub_r001924_15_1) + 45) & 127;
  int stage_v_238_2 = (((stage_v_109_2 * 3) + pub_r001924_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001924_1_1 * 2) + 12) & 63;
  int stage_v_239_2 = ((pub_r001924_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001924_2_1 * 2) + 21) & 63;
  int stage_v_240_2 = ((pub_r001924_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001924_6_1 * 2) + 39) & 63;
  int stage_v_241_2 = ((pub_r001924_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_201_1 * 3) + pub_r001924_12_1) + 15) & 127;
  int stage_v_242_2 = (((stage_v_201_2 * 3) + pub_r001924_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_18_1 * 3) + pub_r001924_1_1) + 29) & 127;
  int stage_v_243_2 = (((stage_v_18_2 * 3) + pub_r001924_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_93_1 * 3) + pub_r001924_6_1) + 33) & 127;
  int stage_v_244_2 = (((stage_v_93_2 * 3) + pub_r001924_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001924_12_1 * 2) + 39) & 63;
  int stage_v_245_2 = ((pub_r001924_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_51_1 * 3) + pub_r001924_4_1) + 21) & 127;
  int stage_v_246_2 = (((stage_v_51_2 * 3) + pub_r001924_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001924_13_1 * 2) + 29) & 63;
  int stage_v_247_2 = ((pub_r001924_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_166_1 * 3) + pub_r001924_8_1) + 22) & 127;
  int stage_v_248_2 = (((stage_v_166_2 * 3) + pub_r001924_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_213_1 * 3) + pub_r001924_5_1) + 12) & 127;
  int stage_v_249_2 = (((stage_v_213_2 * 3) + pub_r001924_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_63_1 * 3) + pub_r001924_7_1) + 25) & 127;
  int stage_v_250_2 = (((stage_v_63_2 * 3) + pub_r001924_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = ((pub_r001924_0_1 * 2) + 27) & 63;
  int stage_v_251_2 = ((pub_r001924_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_232_1 * 3) + pub_r001924_2_1) + 9) & 127;
  int stage_v_252_2 = (((stage_v_232_2 * 3) + pub_r001924_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((sec_r001924_17_1 * 3) + pub_r001924_9_1) + 29) & 127;
  int stage_v_253_2 = (((sec_r001924_17_2 * 3) + pub_r001924_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_171_1 * 3) + pub_r001924_5_1) + 5) & 127;
  int stage_v_254_2 = (((stage_v_171_2 * 3) + pub_r001924_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((sec_r001924_18_1 * 3) + pub_r001924_6_1) + 39) & 127;
  int stage_v_255_2 = (((sec_r001924_18_2 * 3) + pub_r001924_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001924_2_1 * 2) + 39) & 63;
  int stage_v_256_2 = ((pub_r001924_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_15_1 * 3) + pub_r001924_3_1) + 29) & 127;
  int stage_v_257_2 = (((stage_v_15_2 * 3) + pub_r001924_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_22_1 * 3) + pub_r001924_11_1) + 10) & 127;
  int stage_v_258_2 = (((stage_v_22_2 * 3) + pub_r001924_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_14_1 * 3) + pub_r001924_9_1) + 35) & 127;
  int stage_v_259_2 = (((stage_v_14_2 * 3) + pub_r001924_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_187_1 * 3) + pub_r001924_0_1) + 16) & 127;
  int stage_v_260_2 = (((stage_v_187_2 * 3) + pub_r001924_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_125_1 * 3) + pub_r001924_9_1) + 23) & 127;
  int stage_v_261_2 = (((stage_v_125_2 * 3) + pub_r001924_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001924_13_1 * 2) + 29) & 63;
  int stage_v_262_2 = ((pub_r001924_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001924_4_1 * 2) + 11) & 63;
  int stage_v_263_2 = ((pub_r001924_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_97_1 * 3) + pub_r001924_14_1) + 4) & 127;
  int stage_v_264_2 = (((stage_v_97_2 * 3) + pub_r001924_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_227_1 * 3) + pub_r001924_6_1) + 34) & 127;
  int stage_v_265_2 = (((stage_v_227_2 * 3) + pub_r001924_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001924_13_1 * 2) + 25) & 63;
  int stage_v_266_2 = ((pub_r001924_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((sec_r001924_9_1 * 3) + pub_r001924_8_1) + 34) & 127;
  int stage_v_267_2 = (((sec_r001924_9_2 * 3) + pub_r001924_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((sec_r001924_1_1 * 3) + pub_r001924_14_1) + 36) & 127;
  int stage_v_268_2 = (((sec_r001924_1_2 * 3) + pub_r001924_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_205_1 * 3) + pub_r001924_12_1) + 6) & 127;
  int stage_v_269_2 = (((stage_v_205_2 * 3) + pub_r001924_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_207_1 * 3) + pub_r001924_0_1) + 9) & 127;
  int stage_v_270_2 = (((stage_v_207_2 * 3) + pub_r001924_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_259_1 * 3) + pub_r001924_1_1) + 21) & 127;
  int stage_v_271_2 = (((stage_v_259_2 * 3) + pub_r001924_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001924_10_1 * 2) + 16) & 63;
  int stage_v_272_2 = ((pub_r001924_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_209_1 * 3) + pub_r001924_4_1) + 35) & 127;
  int stage_v_273_2 = (((stage_v_209_2 * 3) + pub_r001924_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_229_1 * 3) + pub_r001924_9_1) + 8) & 127;
  int stage_v_274_2 = (((stage_v_229_2 * 3) + pub_r001924_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_136_1 * 3) + pub_r001924_14_1) + 4) & 127;
  int stage_v_275_2 = (((stage_v_136_2 * 3) + pub_r001924_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001924_13_1 * 2) + 45) & 63;
  int stage_v_276_2 = ((pub_r001924_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_217_1 * 3) + pub_r001924_0_1) + 33) & 127;
  int stage_v_277_2 = (((stage_v_217_2 * 3) + pub_r001924_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001924_0_1 * 2) + 26) & 63;
  int stage_v_278_2 = ((pub_r001924_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001924_8_1 * 2) + 9) & 63;
  int stage_v_279_2 = ((pub_r001924_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_51_1 * 3) + pub_r001924_15_1) + 28) & 127;
  int stage_v_280_2 = (((stage_v_51_2 * 3) + pub_r001924_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_177_1 * 3) + pub_r001924_2_1) + 20) & 127;
  int stage_v_281_2 = (((stage_v_177_2 * 3) + pub_r001924_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_185_1 * 3) + pub_r001924_3_1) + 15) & 127;
  int stage_v_282_2 = (((stage_v_185_2 * 3) + pub_r001924_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001924_3_1 * 2) + 29) & 63;
  int stage_v_283_2 = ((pub_r001924_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001924_15_1 * 2) + 45) & 63;
  int stage_v_284_2 = ((pub_r001924_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_110_1 * 3) + pub_r001924_5_1) + 40) & 127;
  int stage_v_285_2 = (((stage_v_110_2 * 3) + pub_r001924_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_118_1 * 3) + pub_r001924_11_1) + 17) & 127;
  int stage_v_286_2 = (((stage_v_118_2 * 3) + pub_r001924_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_49_1 * 3) + pub_r001924_3_1) + 38) & 127;
  int stage_v_287_2 = (((stage_v_49_2 * 3) + pub_r001924_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_139_1 * 3) + pub_r001924_7_1) + 36) & 127;
  int stage_v_288_2 = (((stage_v_139_2 * 3) + pub_r001924_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001924_7_1 * 2) + 28) & 63;
  int stage_v_289_2 = ((pub_r001924_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_138_1 * 3) + pub_r001924_13_1) + 5) & 127;
  int stage_v_290_2 = (((stage_v_138_2 * 3) + pub_r001924_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001924_12_1 * 2) + 9) & 63;
  int stage_v_291_2 = ((pub_r001924_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_248_1 * 3) + pub_r001924_7_1) + 15) & 127;
  int stage_v_292_2 = (((stage_v_248_2 * 3) + pub_r001924_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_75_1 * 3) + pub_r001924_15_1) + 39) & 127;
  int stage_v_293_2 = (((stage_v_75_2 * 3) + pub_r001924_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_97_1 * 3) + pub_r001924_2_1) + 9) & 127;
  int stage_v_294_2 = (((stage_v_97_2 * 3) + pub_r001924_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_132_1 * 3) + pub_r001924_5_1) + 26) & 127;
  int stage_v_295_2 = (((stage_v_132_2 * 3) + pub_r001924_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001924_15_1 * 2) + 47) & 63;
  int stage_v_296_2 = ((pub_r001924_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_97_1 * 3) + pub_r001924_0_1) + 24) & 127;
  int stage_v_297_2 = (((stage_v_97_2 * 3) + pub_r001924_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_118_1 * 3) + pub_r001924_12_1) + 44) & 127;
  int stage_v_298_2 = (((stage_v_118_2 * 3) + pub_r001924_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_132_1 * 3) + pub_r001924_15_1) + 25) & 127;
  int stage_v_299_2 = (((stage_v_132_2 * 3) + pub_r001924_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001924_15_1 * 2) + 44) & 63;
  int stage_v_300_2 = ((pub_r001924_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001924_12_1 * 2) + 22) & 63;
  int stage_v_301_2 = ((pub_r001924_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_108_1 * 3) + pub_r001924_8_1) + 12) & 127;
  int stage_v_302_2 = (((stage_v_108_2 * 3) + pub_r001924_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001924_5_1 * 2) + 13) & 63;
  int stage_v_303_2 = ((pub_r001924_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_246_1 * 3) + pub_r001924_12_1) + 34) & 127;
  int stage_v_304_2 = (((stage_v_246_2 * 3) + pub_r001924_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001924_8_1 * 2) + 11) & 63;
  int stage_v_305_2 = ((pub_r001924_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_9_1 * 3) + pub_r001924_0_1) + 29) & 127;
  int stage_v_306_2 = (((stage_v_9_2 * 3) + pub_r001924_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((helper_flow_5_1 * 3) + pub_r001924_14_1) + 16) & 127;
  int stage_v_307_2 = (((helper_flow_5_2 * 3) + pub_r001924_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001924_6_1 * 2) + 48) & 63;
  int stage_v_308_2 = ((pub_r001924_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_85_1 * 3) + pub_r001924_3_1) + 25) & 127;
  int stage_v_309_2 = (((stage_v_85_2 * 3) + pub_r001924_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001924_5_1 * 2) + 29) & 63;
  int stage_v_310_2 = ((pub_r001924_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_185_1 * 3) + pub_r001924_9_1) + 12) & 127;
  int stage_v_311_2 = (((stage_v_185_2 * 3) + pub_r001924_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_233_1 * 3) + pub_r001924_5_1) + 37) & 127;
  int stage_v_312_2 = (((stage_v_233_2 * 3) + pub_r001924_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((stage_v_16_1 * 3) + pub_r001924_4_1) + 40) & 127;
  int stage_v_313_2 = (((stage_v_16_2 * 3) + pub_r001924_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001924_14_1 * 2) + 8) & 63;
  int stage_v_314_2 = ((pub_r001924_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_131_1 * 3) + pub_r001924_12_1) + 23) & 127;
  int stage_v_315_2 = (((stage_v_131_2 * 3) + pub_r001924_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_299_1 * 3) + pub_r001924_0_1) + 13) & 127;
  int stage_v_316_2 = (((stage_v_299_2 * 3) + pub_r001924_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_243_1 * 3) + pub_r001924_12_1) + 27) & 127;
  int stage_v_317_2 = (((stage_v_243_2 * 3) + pub_r001924_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001924_8_1 * 2) + 36) & 63;
  int stage_v_318_2 = ((pub_r001924_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_91_1 * 3) + pub_r001924_3_1) + 22) & 127;
  int stage_v_319_2 = (((stage_v_91_2 * 3) + pub_r001924_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_96_1 * 3) + pub_r001924_14_1) + 19) & 127;
  int stage_v_320_2 = (((stage_v_96_2 * 3) + pub_r001924_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_270_1 * 3) + pub_r001924_1_1) + 20) & 127;
  int stage_v_321_2 = (((stage_v_270_2 * 3) + pub_r001924_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_73_1 * 3) + pub_r001924_9_1) + 21) & 127;
  int stage_v_322_2 = (((stage_v_73_2 * 3) + pub_r001924_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001924_3_1 * 2) + 41) & 63;
  int stage_v_323_2 = ((pub_r001924_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001924_5_1 * 2) + 26) & 63;
  int stage_v_324_2 = ((pub_r001924_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001924_1_1 * 2) + 35) & 63;
  int stage_v_325_2 = ((pub_r001924_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001924_9_1 * 2) + 7) & 63;
  int stage_v_326_2 = ((pub_r001924_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001924_13_1 * 2) + 21) & 63;
  int stage_v_327_2 = ((pub_r001924_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_250_1 * 3) + pub_r001924_9_1) + 3) & 127;
  int stage_v_328_2 = (((stage_v_250_2 * 3) + pub_r001924_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001924_2_1 * 2) + 38) & 63;
  int stage_v_329_2 = ((pub_r001924_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_299_1 * 3) + pub_r001924_12_1) + 27) & 127;
  int stage_v_330_2 = (((stage_v_299_2 * 3) + pub_r001924_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_2_1 * 3) + pub_r001924_13_1) + 23) & 127;
  int stage_v_331_2 = (((stage_v_2_2 * 3) + pub_r001924_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = ((pub_r001924_9_1 * 2) + 44) & 63;
  int stage_v_332_2 = ((pub_r001924_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = (((stage_v_171_1 * 3) + pub_r001924_5_1) + 15) & 127;
  int stage_v_333_2 = (((stage_v_171_2 * 3) + pub_r001924_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001924_4_1 * 2) + 38) & 63;
  int stage_v_334_2 = ((pub_r001924_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((sec_r001924_18_1 * 3) + pub_r001924_8_1) + 35) & 127;
  int stage_v_335_2 = (((sec_r001924_18_2 * 3) + pub_r001924_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_258_1 * 3) + pub_r001924_10_1) + 7) & 127;
  int stage_v_336_2 = (((stage_v_258_2 * 3) + pub_r001924_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_77_1 * 3) + pub_r001924_0_1) + 22) & 127;
  int stage_v_337_2 = (((stage_v_77_2 * 3) + pub_r001924_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001924_2_1 * 2) + 18) & 63;
  int stage_v_338_2 = ((pub_r001924_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001924_8_1 * 2) + 29) & 63;
  int stage_v_339_2 = ((pub_r001924_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001924_1_1 * 2) + 25) & 63;
  int stage_v_340_2 = ((pub_r001924_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001924_13_1 * 2) + 49) & 63;
  int stage_v_341_2 = ((pub_r001924_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((stage_v_222_1 * 3) + pub_r001924_4_1) + 40) & 127;
  int stage_v_342_2 = (((stage_v_222_2 * 3) + pub_r001924_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_51_1 * 3) + pub_r001924_1_1) + 6) & 127;
  int stage_v_343_2 = (((stage_v_51_2 * 3) + pub_r001924_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001924_7_1 * 2) + 48) & 63;
  int stage_v_344_2 = ((pub_r001924_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_162_1 * 3) + pub_r001924_12_1) + 17) & 127;
  int stage_v_345_2 = (((stage_v_162_2 * 3) + pub_r001924_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_191_1 * 3) + pub_r001924_9_1) + 30) & 127;
  int stage_v_346_2 = (((stage_v_191_2 * 3) + pub_r001924_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001924_2_1 * 2) + 34) & 63;
  int stage_v_347_2 = ((pub_r001924_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_22_1 * 3) + pub_r001924_15_1) + 26) & 127;
  int stage_v_348_2 = (((stage_v_22_2 * 3) + pub_r001924_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_201_1 * 3) + pub_r001924_10_1) + 10) & 127;
  int stage_v_349_2 = (((stage_v_201_2 * 3) + pub_r001924_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_238_1 * 3) + pub_r001924_6_1) + 38) & 127;
  int stage_v_350_2 = (((stage_v_238_2 * 3) + pub_r001924_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_322_1 * 3) + pub_r001924_9_1) + 28) & 127;
  int stage_v_351_2 = (((stage_v_322_2 * 3) + pub_r001924_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001924_4_1 * 2) + 28) & 63;
  int stage_v_352_2 = ((pub_r001924_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001924_3_1 * 2) + 14) & 63;
  int stage_v_353_2 = ((pub_r001924_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_316_1 * 3) + pub_r001924_12_1) + 36) & 127;
  int stage_v_354_2 = (((stage_v_316_2 * 3) + pub_r001924_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_126_1 * 3) + pub_r001924_3_1) + 12) & 127;
  int stage_v_355_2 = (((stage_v_126_2 * 3) + pub_r001924_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_321_1 * 3) + pub_r001924_11_1) + 35) & 127;
  int stage_v_356_2 = (((stage_v_321_2 * 3) + pub_r001924_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001924_6_1 * 2) + 35) & 63;
  int stage_v_357_2 = ((pub_r001924_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_232_1 * 3) + pub_r001924_6_1) + 21) & 127;
  int stage_v_358_2 = (((stage_v_232_2 * 3) + pub_r001924_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001924_3_1 * 2) + 19) & 63;
  int stage_v_359_2 = ((pub_r001924_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001924_3_1 * 2) + 50) & 63;
  int stage_v_360_2 = ((pub_r001924_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001924_6_1 * 2) + 45) & 63;
  int stage_v_361_2 = ((pub_r001924_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001924_4_1 * 2) + 6) & 63;
  int stage_v_362_2 = ((pub_r001924_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_9_1 * 3) + pub_r001924_3_1) + 12) & 127;
  int stage_v_363_2 = (((stage_v_9_2 * 3) + pub_r001924_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001924_4_1 * 2) + 47) & 63;
  int stage_v_364_2 = ((pub_r001924_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001924_14_1 * 2) + 45) & 63;
  int stage_v_365_2 = ((pub_r001924_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_96_1 * 3) + pub_r001924_9_1) + 42) & 127;
  int stage_v_366_2 = (((stage_v_96_2 * 3) + pub_r001924_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = ((pub_r001924_14_1 * 2) + 29) & 63;
  int stage_v_367_2 = ((pub_r001924_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001924_2_1 * 2) + 19) & 63;
  int stage_v_368_2 = ((pub_r001924_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001924_10_1 * 2) + 22) & 63;
  int stage_v_369_2 = ((pub_r001924_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001924_11_1 * 2) + 10) & 63;
  int stage_v_370_2 = ((pub_r001924_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_22_1 * 3) + pub_r001924_8_1) + 5) & 127;
  int stage_v_371_2 = (((stage_v_22_2 * 3) + pub_r001924_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((sec_r001924_13_1 * 3) + pub_r001924_10_1) + 11) & 127;
  int stage_v_372_2 = (((sec_r001924_13_2 * 3) + pub_r001924_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_97_1 * 3) + pub_r001924_8_1) + 10) & 127;
  int stage_v_373_2 = (((stage_v_97_2 * 3) + pub_r001924_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001924_15_1 * 2) + 49) & 63;
  int stage_v_374_2 = ((pub_r001924_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_212_1 * 3) + pub_r001924_5_1) + 39) & 127;
  int stage_v_375_2 = (((stage_v_212_2 * 3) + pub_r001924_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_108_1 * 3) + pub_r001924_4_1) + 14) & 127;
  int stage_v_376_2 = (((stage_v_108_2 * 3) + pub_r001924_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001924_8_1 * 2) + 36) & 63;
  int stage_v_377_2 = ((pub_r001924_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((sec_r001924_6_1 * 3) + pub_r001924_8_1) + 4) & 127;
  int stage_v_378_2 = (((sec_r001924_6_2 * 3) + pub_r001924_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_7_1 * 3) + pub_r001924_15_1) + 9) & 127;
  int stage_v_379_2 = (((stage_v_7_2 * 3) + pub_r001924_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001924_15_1 * 2) + 31) & 63;
  int stage_v_380_2 = ((pub_r001924_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001924_4_1 * 2) + 45) & 63;
  int stage_v_381_2 = ((pub_r001924_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001924_1_1 * 2) + 6) & 63;
  int stage_v_382_2 = ((pub_r001924_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((stage_v_304_1 * 3) + pub_r001924_3_1) + 7) & 127;
  int stage_v_383_2 = (((stage_v_304_2 * 3) + pub_r001924_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_49_1 * 3) + pub_r001924_10_1) + 9) & 127;
  int stage_v_384_2 = (((stage_v_49_2 * 3) + pub_r001924_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001924_0_1 * 2) + 38) & 63;
  int stage_v_385_2 = ((pub_r001924_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((sec_r001924_5_1 * 3) + pub_r001924_5_1) + 24) & 127;
  int stage_v_386_2 = (((sec_r001924_5_2 * 3) + pub_r001924_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_48_1 * 3) + pub_r001924_6_1) + 12) & 127;
  int stage_v_387_2 = (((stage_v_48_2 * 3) + pub_r001924_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001924_13_1 * 2) + 15) & 63;
  int stage_v_388_2 = ((pub_r001924_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001924_8_1 * 2) + 23) & 63;
  int stage_v_389_2 = ((pub_r001924_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_93_1 * 3) + pub_r001924_12_1) + 11) & 127;
  int stage_v_390_2 = (((stage_v_93_2 * 3) + pub_r001924_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_292_1 * 3) + pub_r001924_8_1) + 38) & 127;
  int stage_v_391_2 = (((stage_v_292_2 * 3) + pub_r001924_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = ((pub_r001924_7_1 * 2) + 23) & 63;
  int stage_v_392_2 = ((pub_r001924_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001924_8_1 * 2) + 49) & 63;
  int stage_v_393_2 = ((pub_r001924_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001924_13_1 * 2) + 16) & 63;
  int stage_v_394_2 = ((pub_r001924_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001924_2_1 * 2) + 9) & 63;
  int stage_v_395_2 = ((pub_r001924_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((sec_r001924_17_1 * 3) + pub_r001924_5_1) + 35) & 127;
  int stage_v_396_2 = (((sec_r001924_17_2 * 3) + pub_r001924_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_207_1 * 3) + pub_r001924_7_1) + 20) & 127;
  int stage_v_397_2 = (((stage_v_207_2 * 3) + pub_r001924_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_306_1 * 3) + pub_r001924_13_1) + 38) & 127;
  int stage_v_398_2 = (((stage_v_306_2 * 3) + pub_r001924_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_288_1 * 3) + pub_r001924_7_1) + 43) & 127;
  int stage_v_399_2 = (((stage_v_288_2 * 3) + pub_r001924_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001924_10_1 * 2) + 42) & 63;
  int stage_v_400_2 = ((pub_r001924_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001924_11_1 * 2) + 40) & 63;
  int stage_v_401_2 = ((pub_r001924_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_132_1 * 3) + pub_r001924_8_1) + 23) & 127;
  int stage_v_402_2 = (((stage_v_132_2 * 3) + pub_r001924_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_312_1 * 3) + pub_r001924_3_1) + 3) & 127;
  int stage_v_403_2 = (((stage_v_312_2 * 3) + pub_r001924_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_229_1 * 3) + pub_r001924_15_1) + 12) & 127;
  int stage_v_404_2 = (((stage_v_229_2 * 3) + pub_r001924_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_313_1 * 3) + pub_r001924_0_1) + 36) & 127;
  int stage_v_405_2 = (((stage_v_313_2 * 3) + pub_r001924_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((helper_flow_4_1 * 3) + pub_r001924_0_1) + 6) & 127;
  int stage_v_406_2 = (((helper_flow_4_2 * 3) + pub_r001924_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001924_6_1 * 2) + 16) & 63;
  int stage_v_407_2 = ((pub_r001924_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001924_14_1 * 2) + 40) & 63;
  int stage_v_408_2 = ((pub_r001924_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = (((stage_v_25_1 * 3) + pub_r001924_8_1) + 31) & 127;
  int stage_v_409_2 = (((stage_v_25_2 * 3) + pub_r001924_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001924_5_1 * 2) + 35) & 63;
  int stage_v_410_2 = ((pub_r001924_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001924_5_1 * 2) + 49) & 63;
  int stage_v_411_2 = ((pub_r001924_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((sec_r001924_3_1 * 3) + pub_r001924_1_1) + 26) & 127;
  int stage_v_412_2 = (((sec_r001924_3_2 * 3) + pub_r001924_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001924_12_1 * 2) + 48) & 63;
  int stage_v_413_2 = ((pub_r001924_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001924_5_1 * 2) + 35) & 63;
  int stage_v_414_2 = ((pub_r001924_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_311_1 * 3) + pub_r001924_12_1) + 37) & 127;
  int stage_v_415_2 = (((stage_v_311_2 * 3) + pub_r001924_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = (((stage_v_178_1 * 3) + pub_r001924_3_1) + 21) & 127;
  int stage_v_416_2 = (((stage_v_178_2 * 3) + pub_r001924_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_355_1 * 3) + pub_r001924_9_1) + 27) & 127;
  int stage_v_417_2 = (((stage_v_355_2 * 3) + pub_r001924_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_309_1 * 3) + pub_r001924_8_1) + 7) & 127;
  int stage_v_418_2 = (((stage_v_309_2 * 3) + pub_r001924_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001924_4_1 * 2) + 40) & 63;
  int stage_v_419_2 = ((pub_r001924_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001924_6_1 * 2) + 27) & 63;
  int stage_v_420_2 = ((pub_r001924_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((stage_v_297_1 * 3) + pub_r001924_14_1) + 3) & 127;
  int stage_v_421_2 = (((stage_v_297_2 * 3) + pub_r001924_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_330_1 * 3) + pub_r001924_4_1) + 42) & 127;
  int stage_v_422_2 = (((stage_v_330_2 * 3) + pub_r001924_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001924_6_1 * 2) + 12) & 63;
  int stage_v_423_2 = ((pub_r001924_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001924_5_1 * 2) + 23) & 63;
  int stage_v_424_2 = ((pub_r001924_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_146_1 * 3) + pub_r001924_7_1) + 35) & 127;
  int stage_v_425_2 = (((stage_v_146_2 * 3) + pub_r001924_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001924_9_1 * 2) + 36) & 63;
  int stage_v_426_2 = ((pub_r001924_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_16_1 * 3) + pub_r001924_1_1) + 23) & 127;
  int stage_v_427_2 = (((stage_v_16_2 * 3) + pub_r001924_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_330_1 * 3) + pub_r001924_3_1) + 15) & 127;
  int stage_v_428_2 = (((stage_v_330_2 * 3) + pub_r001924_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((helper_flow_4_1 * 3) + pub_r001924_7_1) + 36) & 127;
  int stage_v_429_2 = (((helper_flow_4_2 * 3) + pub_r001924_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001924_14_1 * 2) + 17) & 63;
  int stage_v_430_2 = ((pub_r001924_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_244_1 * 3) + pub_r001924_11_1) + 26) & 127;
  int stage_v_431_2 = (((stage_v_244_2 * 3) + pub_r001924_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_281_1 * 3) + pub_r001924_15_1) + 36) & 127;
  int stage_v_432_2 = (((stage_v_281_2 * 3) + pub_r001924_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_331_1 * 3) + pub_r001924_0_1) + 32) & 127;
  int stage_v_433_2 = (((stage_v_331_2 * 3) + pub_r001924_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001924_7_1 * 2) + 24) & 63;
  int stage_v_434_2 = ((pub_r001924_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = (((sec_r001924_17_1 * 3) + pub_r001924_13_1) + 27) & 127;
  int stage_v_435_2 = (((sec_r001924_17_2 * 3) + pub_r001924_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001924_8_1 * 2) + 48) & 63;
  int stage_v_436_2 = ((pub_r001924_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((sec_r001924_19_1 * 3) + pub_r001924_4_1) + 27) & 127;
  int stage_v_437_2 = (((sec_r001924_19_2 * 3) + pub_r001924_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001924_2_1 * 2) + 22) & 63;
  int stage_v_438_2 = ((pub_r001924_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_320_1 * 3) + pub_r001924_0_1) + 21) & 127;
  int stage_v_439_2 = (((stage_v_320_2 * 3) + pub_r001924_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_200_1 * 3) + pub_r001924_3_1) + 8) & 127;
  int stage_v_440_2 = (((stage_v_200_2 * 3) + pub_r001924_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = ((pub_r001924_9_1 * 2) + 10) & 63;
  int stage_v_441_2 = ((pub_r001924_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((stage_v_68_1 * 3) + pub_r001924_11_1) + 25) & 127;
  int stage_v_442_2 = (((stage_v_68_2 * 3) + pub_r001924_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = (((stage_v_417_1 * 3) + pub_r001924_10_1) + 4) & 127;
  int stage_v_443_2 = (((stage_v_417_2 * 3) + pub_r001924_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = (((stage_v_118_1 * 3) + pub_r001924_8_1) + 29) & 127;
  int stage_v_444_2 = (((stage_v_118_2 * 3) + pub_r001924_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = (((stage_v_379_1 * 3) + pub_r001924_15_1) + 34) & 127;
  int stage_v_445_2 = (((stage_v_379_2 * 3) + pub_r001924_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((helper_flow_1_1 * 3) + pub_r001924_9_1) + 26) & 127;
  int stage_v_446_2 = (((helper_flow_1_2 * 3) + pub_r001924_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((stage_v_244_1 * 3) + pub_r001924_9_1) + 20) & 127;
  int stage_v_447_2 = (((stage_v_244_2 * 3) + pub_r001924_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = ((pub_r001924_11_1 * 2) + 33) & 63;
  int stage_v_448_2 = ((pub_r001924_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_229_1 * 3) + pub_r001924_13_1) + 21) & 127;
  int stage_v_449_2 = (((stage_v_229_2 * 3) + pub_r001924_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001924_11_1 * 2) + 39) & 63;
  int stage_v_450_2 = ((pub_r001924_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001924_12_1 * 2) + 5) & 63;
  int stage_v_451_2 = ((pub_r001924_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001924_9_1 * 2) + 18) & 63;
  int stage_v_452_2 = ((pub_r001924_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = (((stage_v_449_1 * 3) + pub_r001924_10_1) + 28) & 127;
  int stage_v_453_2 = (((stage_v_449_2 * 3) + pub_r001924_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = (((stage_v_387_1 * 3) + pub_r001924_3_1) + 30) & 127;
  int stage_v_454_2 = (((stage_v_387_2 * 3) + pub_r001924_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = (((stage_v_238_1 * 3) + pub_r001924_15_1) + 5) & 127;
  int stage_v_455_2 = (((stage_v_238_2 * 3) + pub_r001924_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((stage_v_93_1 * 3) + pub_r001924_6_1) + 20) & 127;
  int stage_v_456_2 = (((stage_v_93_2 * 3) + pub_r001924_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = (((stage_v_22_1 * 3) + pub_r001924_10_1) + 20) & 127;
  int stage_v_457_2 = (((stage_v_22_2 * 3) + pub_r001924_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = (((stage_v_313_1 * 3) + pub_r001924_9_1) + 12) & 127;
  int stage_v_458_2 = (((stage_v_313_2 * 3) + pub_r001924_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((stage_v_226_1 * 3) + pub_r001924_1_1) + 14) & 127;
  int stage_v_459_2 = (((stage_v_226_2 * 3) + pub_r001924_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001924_9_1 * 2) + 22) & 63;
  int stage_v_460_2 = ((pub_r001924_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001924_9_1 * 2) + 29) & 63;
  int stage_v_461_2 = ((pub_r001924_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((stage_v_122_1 * 3) + pub_r001924_0_1) + 19) & 127;
  int stage_v_462_2 = (((stage_v_122_2 * 3) + pub_r001924_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = ((pub_r001924_2_1 * 2) + 18) & 63;
  int stage_v_463_2 = ((pub_r001924_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = (((stage_v_155_1 * 3) + pub_r001924_10_1) + 3) & 127;
  int stage_v_464_2 = (((stage_v_155_2 * 3) + pub_r001924_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  int stage_v_465_1 = ((pub_r001924_4_1 * 2) + 25) & 63;
  int stage_v_465_2 = ((pub_r001924_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((stage_v_298_1 * 3) + pub_r001924_14_1) + 37) & 127;
  int stage_v_466_2 = (((stage_v_298_2 * 3) + pub_r001924_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = (((sec_r001924_2_1 * 3) + pub_r001924_13_1) + 36) & 127;
  int stage_v_467_2 = (((sec_r001924_2_2 * 3) + pub_r001924_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = ((pub_r001924_4_1 * 2) + 9) & 63;
  int stage_v_468_2 = ((pub_r001924_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001924_13_1 * 2) + 27) & 63;
  int stage_v_469_2 = ((pub_r001924_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001924_0_1 * 2) + 11) & 63;
  int stage_v_470_2 = ((pub_r001924_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = (((stage_v_9_1 * 3) + pub_r001924_11_1) + 8) & 127;
  int stage_v_471_2 = (((stage_v_9_2 * 3) + pub_r001924_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = ((pub_r001924_13_1 * 2) + 32) & 63;
  int stage_v_472_2 = ((pub_r001924_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = (((stage_v_375_1 * 3) + pub_r001924_4_1) + 42) & 127;
  int stage_v_473_2 = (((stage_v_375_2 * 3) + pub_r001924_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = (((stage_v_187_1 * 3) + pub_r001924_2_1) + 30) & 127;
  int stage_v_474_2 = (((stage_v_187_2 * 3) + pub_r001924_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((stage_v_343_1 * 3) + pub_r001924_8_1) + 12) & 127;
  int stage_v_475_2 = (((stage_v_343_2 * 3) + pub_r001924_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = ((pub_r001924_8_1 * 2) + 7) & 63;
  int stage_v_476_2 = ((pub_r001924_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = (((stage_v_55_1 * 3) + pub_r001924_6_1) + 27) & 127;
  int stage_v_477_2 = (((stage_v_55_2 * 3) + pub_r001924_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = (((stage_v_55_1 * 3) + pub_r001924_14_1) + 39) & 127;
  int stage_v_478_2 = (((stage_v_55_2 * 3) + pub_r001924_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  int stage_v_479_1 = ((pub_r001924_2_1 * 2) + 43) & 63;
  int stage_v_479_2 = ((pub_r001924_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001924_9_1 * 2) + 35) & 63;
  int stage_v_480_2 = ((pub_r001924_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001924_12_1 * 2) + 47) & 63;
  int stage_v_481_2 = ((pub_r001924_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001924_5_1 * 2) + 50) & 63;
  int stage_v_482_2 = ((pub_r001924_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001924_8_1 * 2) + 28) & 63;
  int stage_v_483_2 = ((pub_r001924_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = (((stage_v_270_1 * 3) + pub_r001924_14_1) + 8) & 127;
  int stage_v_484_2 = (((stage_v_270_2 * 3) + pub_r001924_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_484_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_484_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_484_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_484_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001924_16_1 != sec_r001924_16_2);
  __CPROVER_assume(sec_r001924_12_1 != sec_r001924_12_2);
  __CPROVER_assume(pub_r001924_11_1 == pub_r001924_11_2);
  __CPROVER_assume(sec_r001924_8_1 != sec_r001924_8_2);
  __CPROVER_assume(pub_r001924_9_1 == pub_r001924_9_2);
  __CPROVER_assume(sec_r001924_6_1 != sec_r001924_6_2);
  __CPROVER_assume(sec_r001924_7_1 != sec_r001924_7_2);
  __CPROVER_assume(pub_r001924_10_1 == pub_r001924_10_2);
  __CPROVER_assume(pub_r001924_1_1 == pub_r001924_1_2);
  __CPROVER_assume(pub_r001924_12_1 == pub_r001924_12_2);
  __CPROVER_assume(sec_r001924_3_1 != sec_r001924_3_2);
  __CPROVER_assume(sec_r001924_0_1 != sec_r001924_0_2);
  __CPROVER_assume(sec_r001924_14_1 != sec_r001924_14_2);
  __CPROVER_assume(sec_r001924_5_1 != sec_r001924_5_2);
  __CPROVER_assume(sec_r001924_11_1 != sec_r001924_11_2);
  __CPROVER_assume(sec_r001924_10_1 != sec_r001924_10_2);
  __CPROVER_assume(pub_r001924_13_1 == pub_r001924_13_2);
  __CPROVER_assume(pub_r001924_6_1 == pub_r001924_6_2);
  __CPROVER_assume(pub_r001924_15_1 == pub_r001924_15_2);
  __CPROVER_assume(sec_r001924_4_1 != sec_r001924_4_2);
  __CPROVER_assume(pub_r001924_14_1 == pub_r001924_14_2);
  __CPROVER_assume(sec_r001924_15_1 != sec_r001924_15_2);
  __CPROVER_assume(pub_r001924_3_1 == pub_r001924_3_2);
  __CPROVER_assume(sec_r001924_1_1 != sec_r001924_1_2);
  __CPROVER_assume(sec_r001924_19_1 != sec_r001924_19_2);
  __CPROVER_assume(sec_r001924_18_1 != sec_r001924_18_2);
  __CPROVER_assume(sec_r001924_13_1 != sec_r001924_13_2);
  __CPROVER_assume(pub_r001924_5_1 == pub_r001924_5_2);
  __CPROVER_assume(pub_r001924_4_1 == pub_r001924_4_2);
  __CPROVER_assume(pub_r001924_8_1 == pub_r001924_8_2);
  __CPROVER_assume(sec_r001924_17_1 != sec_r001924_17_2);
  __CPROVER_assume(sec_r001924_9_1 != sec_r001924_9_2);
  __CPROVER_assume(pub_r001924_7_1 == pub_r001924_7_2);
  __CPROVER_assume(sec_r001924_2_1 != sec_r001924_2_2);
  __CPROVER_assume(pub_r001924_2_1 == pub_r001924_2_2);
  __CPROVER_assume(pub_r001924_0_1 == pub_r001924_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.status == st_var_1_2.status);
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
}


