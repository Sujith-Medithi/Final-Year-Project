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
struct FilterState_R000927_2713_0
{
  short gain_db;
  unsigned char prev_out;
  short cutoff;
  int buffer[3];
};
struct AudioFrame_R000927_2713_1
{
  int sample_rate;
  int peak;
  short envelope;
  int channels;
  int rms;
  int buffer[3];
};
struct Transaction_R000927_2713_2
{
  unsigned char account_id;
  unsigned char auth_code;
  unsigned char fee;
  int buffer[3];
};
union RegisterBank_R000927_2713_0
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
void fn_R000927_2713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st_1 = {0};
  struct Transaction_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_81_1) & 63;
  aux_2 = (aux_2 + quantum_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_36_1 = local_arr_1[aux_1 % 3];
  int anchor_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_36_2 * 2)) & 127;
  int offset_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_55_1 > 48)
  {
    acc_1 = ((acc_1 + (offset_55_1 * 2)) + 5) & 127;
    aux_1 ^= offset_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_55_2 > 48)
  {
    acc_2 = ((acc_2 + (offset_55_2 * 2)) + 5) & 127;
    aux_2 ^= offset_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_81_1 == quantum_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_36_1 == anchor_36_2);
  assert(offset_55_1 == offset_55_2);
}

int fn_R000927_2713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_81) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_36 = local_arr[aux % 3];
  acc = (acc + (anchor_36 * 2)) & 127;
  int offset_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_55 > 48)
  {
    acc = ((acc + (offset_55 * 2)) + 5) & 127;
    aux ^= offset_55 & 15;
  }
  else
  {
    acc = ((acc - offset_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_42_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_42_1 * 2)) + 5) & 127;
    aux_1 ^= offset_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_42_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_42_2 * 2)) + 5) & 127;
    aux_2 ^= offset_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_71_1 = local_arr_1[aux_1 % 3];
  int tally_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_42_1 == offset_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_71_1 == tally_71_2);
}

int fn_R000927_2713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_42 > 26)
  {
    acc = ((acc + (offset_42 * 2)) + 5) & 127;
    aux ^= offset_42 & 15;
  }
  else
  {
    acc = ((acc - offset_42) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_71 = local_arr[aux % 3];
  acc = (acc + (tally_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int index_reg_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_34_1) & 63;
  aux_2 = (aux_2 + index_reg_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_44_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_44_1 * 2)) + 5) & 127;
    aux_1 ^= metric_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_44_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_44_2 * 2)) + 5) & 127;
    aux_2 ^= metric_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_52_1 = local_arr_1[aux_1 % 3];
  int mask_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_34_1 == index_reg_34_2);
  assert(metric_44_1 == metric_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_52_1 == mask_52_2);
}

int fn_R000927_2713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int index_reg_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_34) & 63;
  acc ^= aux;
  int metric_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_44 > 16)
  {
    acc = ((acc + (metric_44 * 2)) + 5) & 127;
    aux ^= metric_44 & 15;
  }
  else
  {
    acc = ((acc - metric_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_52 = local_arr[aux % 3];
  acc = (acc + (mask_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int checksum_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_37_1 > 22)
  {
    acc_1 = ((acc_1 + (checksum_37_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_37_2 > 22)
  {
    acc_2 = ((acc_2 + (checksum_37_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_64_1 = local_arr_1[aux_1 % 3];
  int anchor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_64_2 * 2)) & 127;
  int scale_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_83_1) & 63;
  aux_2 = (aux_2 + scale_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_37_1 == checksum_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_64_1 == anchor_64_2);
  assert(scale_83_1 == scale_83_2);
}

int fn_R000927_2713_3(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int checksum_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_37 > 22)
  {
    acc = ((acc + (checksum_37 * 2)) + 5) & 127;
    aux ^= checksum_37 & 15;
  }
  else
  {
    acc = ((acc - checksum_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_64 = local_arr[aux % 3];
  acc = (acc + (anchor_64 * 2)) & 127;
  int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_21_1) & 63;
  aux_2 = (aux_2 + factor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_85_1 > 29)
  {
    acc_1 = ((acc_1 + (checksum_85_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_85_2 > 29)
  {
    acc_2 = ((acc_2 + (checksum_85_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_21_1 == factor_21_2);
  assert(checksum_85_1 == checksum_85_2);
}

int fn_R000927_2713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_21) & 63;
  acc ^= aux;
  int checksum_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_85 > 29)
  {
    acc = ((acc + (checksum_85 * 2)) + 5) & 127;
    aux ^= checksum_85 & 15;
  }
  else
  {
    acc = ((acc - checksum_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st_1 = {0};
  struct Transaction_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tracker_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_53_1 > 22)
  {
    acc_1 = ((acc_1 + (tracker_53_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_53_2 > 22)
  {
    acc_2 = ((acc_2 + (tracker_53_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_60_1)
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

  switch (tracker_60_2)
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

  int segment_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_18_1) & 63;
  aux_2 = (aux_2 + segment_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_53_1 == tracker_53_2);
  assert(tracker_60_1 == tracker_60_2);
  assert(segment_18_1 == segment_18_2);
}

int fn_R000927_2713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tracker_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_53 > 22)
  {
    acc = ((acc + (tracker_53 * 2)) + 5) & 127;
    aux ^= tracker_53 & 15;
  }
  else
  {
    acc = ((acc - tracker_53) + 11) & 127;
    aux += 3;
  }
  int tracker_60 = (aux + st.buffer[1]) & 3;
  switch (tracker_60)
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

  int segment_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_42_1) & 63;
  aux_2 = (aux_2 + coefficient_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_27_1)
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

  switch (coefficient_27_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_42_1 == coefficient_42_2);
  assert(coefficient_27_1 == coefficient_27_2);
}

int fn_R000927_2713_6(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_42) & 63;
  acc ^= aux;
  int coefficient_27 = (aux + st.buffer[1]) & 3;
  switch (coefficient_27)
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

void fn_R000927_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int scale_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_25_1)
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

  switch (scale_25_2)
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
  int quantum_20_1 = local_arr_1[aux_1 % 3];
  int quantum_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_20_2 * 2)) & 127;
  int segment_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_92_1) & 63;
  aux_2 = (aux_2 + segment_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_35_1 > 32)
  {
    acc_1 = ((acc_1 + (accumulator_35_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_35_2 > 32)
  {
    acc_2 = ((acc_2 + (accumulator_35_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_25_1 == scale_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_20_1 == quantum_20_2);
  assert(segment_92_1 == segment_92_2);
  assert(accumulator_35_1 == accumulator_35_2);
}

int fn_R000927_2713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int scale_25 = (aux + st.buffer[1]) & 3;
  switch (scale_25)
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
  int quantum_20 = local_arr[aux % 3];
  acc = (acc + (quantum_20 * 2)) & 127;
  int segment_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_92) & 63;
  acc ^= aux;
  int accumulator_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_35 > 32)
  {
    acc = ((acc + (accumulator_35 * 2)) + 5) & 127;
    aux ^= accumulator_35 & 15;
  }
  else
  {
    acc = ((acc - accumulator_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_81_1) & 63;
  aux_2 = (aux_2 + damping_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_62_1 = local_arr_1[aux_1 % 3];
  int index_reg_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_62_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_81_1 == damping_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R000927_2713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_81) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_62 = local_arr[aux % 3];
  acc = (acc + (index_reg_62 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st_1 = {0};
  struct Transaction_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tracker_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_70_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_70_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_70_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_70_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_70_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_70_1 == tracker_70_2);
}

int fn_R000927_2713_9(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tracker_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_70 > 50)
  {
    acc = ((acc + (tracker_70 * 2)) + 5) & 127;
    aux ^= tracker_70 & 15;
  }
  else
  {
    acc = ((acc - tracker_70) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_90_1 = local_arr_1[aux_1 % 3];
  int factor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_90_1 == factor_90_2);
}

int fn_R000927_2713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int factor_90 = local_arr[aux % 3];
  acc = (acc + (factor_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_22_1 = local_arr_1[aux_1 % 3];
  int checksum_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_22_2 * 2)) & 127;
  int stride_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_16_1) & 63;
  aux_2 = (aux_2 + stride_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_22_1 == checksum_22_2);
  assert(stride_16_1 == stride_16_2);
}

int fn_R000927_2713_11(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_22 = local_arr[aux % 3];
  acc = (acc + (checksum_22 * 2)) & 127;
  int stride_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st_1 = {0};
  struct Transaction_R000927_2713_2 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_89_1 = local_arr_1[aux_1 % 3];
  int parity_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_89_2 * 2)) & 127;
  int delta_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_94_1) & 63;
  aux_2 = (aux_2 + delta_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_83_1 > 33)
  {
    acc_1 = ((acc_1 + (margin_83_1 * 2)) + 5) & 127;
    aux_1 ^= margin_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_83_2 > 33)
  {
    acc_2 = ((acc_2 + (margin_83_2 * 2)) + 5) & 127;
    aux_2 ^= margin_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_89_1 == parity_89_2);
  assert(delta_94_1 == delta_94_2);
  assert(margin_83_1 == margin_83_2);
}

int fn_R000927_2713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_89 = local_arr[aux % 3];
  acc = (acc + (parity_89 * 2)) & 127;
  int delta_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_94) & 63;
  acc ^= aux;
  int margin_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_83 > 33)
  {
    acc = ((acc + (margin_83 * 2)) + 5) & 127;
    aux ^= margin_83 & 15;
  }
  else
  {
    acc = ((acc - margin_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_92_1) & 63;
  aux_2 = (aux_2 + offset_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_41_1 = local_arr_1[aux_1 % 3];
  int bound_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_92_1 == offset_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_41_1 == bound_41_2);
}

int fn_R000927_2713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_92) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_41 = local_arr[aux % 3];
  acc = (acc + (bound_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st_1 = {0};
  struct Transaction_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_78_1)
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

  switch (pivot_78_2)
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

  int cursor_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_79_1) & 63;
  aux_2 = (aux_2 + cursor_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_78_1 == pivot_78_2);
  assert(cursor_79_1 == cursor_79_2);
}

int fn_R000927_2713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_78 = (aux + st.buffer[1]) & 3;
  switch (pivot_78)
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

  int cursor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_79) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_45_1 = local_arr_1[aux_1 % 3];
  int offset_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_45_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_30_1 > 25)
  {
    acc_1 = ((acc_1 + (anchor_30_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_30_2 > 25)
  {
    acc_2 = ((acc_2 + (anchor_30_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_45_1 == offset_45_2);
  assert(anchor_30_1 == anchor_30_2);
}

int fn_R000927_2713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int offset_45 = local_arr[aux % 3];
  acc = (acc + (offset_45 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_30 > 25)
  {
    acc = ((acc + (anchor_30 * 2)) + 5) & 127;
    aux ^= anchor_30 & 15;
  }
  else
  {
    acc = ((acc - anchor_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st_1 = {0};
  struct Transaction_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_50_1 = local_arr_1[aux_1 % 3];
  int cursor_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_50_2 * 2)) & 127;
  int segment_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_14_1) & 63;
  aux_2 = (aux_2 + segment_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(segment_14_1 == segment_14_2);
}

int fn_R000927_2713_16(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int cursor_50 = local_arr[aux % 3];
  acc = (acc + (cursor_50 * 2)) & 127;
  int segment_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_81_1)
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

  switch (window_81_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_88_1) & 63;
  aux_2 = (aux_2 + factor_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_22_1 > 40)
  {
    acc_1 = ((acc_1 + (mask_22_1 * 2)) + 5) & 127;
    aux_1 ^= mask_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_22_2 > 40)
  {
    acc_2 = ((acc_2 + (mask_22_2 * 2)) + 5) & 127;
    aux_2 ^= mask_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_81_1 == window_81_2);
  assert(factor_88_1 == factor_88_2);
  assert(mask_22_1 == mask_22_2);
}

int fn_R000927_2713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_81 = (aux + st.buffer[1]) & 3;
  switch (window_81)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_88) & 63;
  acc ^= aux;
  int mask_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_22 > 40)
  {
    acc = ((acc + (mask_22 * 2)) + 5) & 127;
    aux ^= mask_22 & 15;
  }
  else
  {
    acc = ((acc - mask_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_26_1 > 26)
  {
    acc_1 = ((acc_1 + (mask_26_1 * 2)) + 5) & 127;
    aux_1 ^= mask_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_26_2 > 26)
  {
    acc_2 = ((acc_2 + (mask_26_2 * 2)) + 5) & 127;
    aux_2 ^= mask_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_80_1)
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

  switch (coefficient_80_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_26_1 == mask_26_2);
  assert(coefficient_80_1 == coefficient_80_2);
}

int fn_R000927_2713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_26 > 26)
  {
    acc = ((acc + (mask_26 * 2)) + 5) & 127;
    aux ^= mask_26 & 15;
  }
  else
  {
    acc = ((acc - mask_26) + 11) & 127;
    aux += 3;
  }
  int coefficient_80 = (aux + st.buffer[1]) & 3;
  switch (coefficient_80)
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

void fn_R000927_2713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int coefficient_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_86_1)
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

  switch (coefficient_86_2)
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

  int parity_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_12_1) & 63;
  aux_2 = (aux_2 + parity_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_86_1 == coefficient_86_2);
  assert(parity_12_1 == parity_12_2);
}

int fn_R000927_2713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int coefficient_86 = (aux + st.buffer[1]) & 3;
  switch (coefficient_86)
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

  int parity_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int cursor_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_50_1) & 63;
  aux_2 = (aux_2 + cursor_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_48_1)
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

  switch (parity_48_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(parity_48_1 == parity_48_2);
}

int fn_R000927_2713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int cursor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_50) & 63;
  acc ^= aux;
  int parity_48 = (aux + st.buffer[1]) & 3;
  switch (parity_48)
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

void fn_R000927_2713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st_1 = {0};
  struct AudioFrame_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int bound_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_22_1)
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

  switch (bound_22_2)
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

  int index_reg_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_82_1 > 20)
  {
    acc_1 = ((acc_1 + (index_reg_82_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_82_2 > 20)
  {
    acc_2 = ((acc_2 + (index_reg_82_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_51_1) & 63;
  aux_2 = (aux_2 + vector_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_93_1 = local_arr_1[aux_1 % 3];
  int threshold_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_22_1 == bound_22_2);
  assert(index_reg_82_1 == index_reg_82_2);
  assert(vector_51_1 == vector_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_93_1 == threshold_93_2);
}

int fn_R000927_2713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int bound_22 = (aux + st.buffer[1]) & 3;
  switch (bound_22)
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

  int index_reg_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_82 > 20)
  {
    acc = ((acc + (index_reg_82 * 2)) + 5) & 127;
    aux ^= index_reg_82 & 15;
  }
  else
  {
    acc = ((acc - index_reg_82) + 11) & 127;
    aux += 3;
  }
  int vector_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_51) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_93 = local_arr[aux % 3];
  acc = (acc + (threshold_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_87_1)
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

  switch (residue_87_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_92_1 = local_arr_1[aux_1 % 3];
  int cursor_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_87_1 == residue_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_92_1 == cursor_92_2);
}

int fn_R000927_2713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_87 = (aux + st.buffer[1]) & 3;
  switch (residue_87)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_92 = local_arr[aux % 3];
  acc = (acc + (cursor_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st_1 = {0};
  struct FilterState_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int scale_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_91_1)
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

  switch (scale_91_2)
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

  int window_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_97_1 > 23)
  {
    acc_1 = ((acc_1 + (window_97_1 * 2)) + 5) & 127;
    aux_1 ^= window_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_97_2 > 23)
  {
    acc_2 = ((acc_2 + (window_97_2 * 2)) + 5) & 127;
    aux_2 ^= window_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_91_1 == scale_91_2);
  assert(window_97_1 == window_97_2);
}

int fn_R000927_2713_23(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int scale_91 = (aux + st.buffer[1]) & 3;
  switch (scale_91)
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

  int window_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_97 > 23)
  {
    acc = ((acc + (window_97 * 2)) + 5) & 127;
    aux ^= window_97 & 15;
  }
  else
  {
    acc = ((acc - window_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000927_0_1;
  int sec_r000927_0_2;
  int sec_r000927_1_1;
  int sec_r000927_1_2;
  int sec_r000927_2_1;
  int sec_r000927_2_2;
  int sec_r000927_3_1;
  int sec_r000927_3_2;
  int sec_r000927_4_1;
  int sec_r000927_4_2;
  int sec_r000927_5_1;
  int sec_r000927_5_2;
  int sec_r000927_6_1;
  int sec_r000927_6_2;
  int sec_r000927_7_1;
  int sec_r000927_7_2;
  int sec_r000927_8_1;
  int sec_r000927_8_2;
  int sec_r000927_9_1;
  int sec_r000927_9_2;
  int sec_r000927_10_1;
  int sec_r000927_10_2;
  int sec_r000927_11_1;
  int sec_r000927_11_2;
  int sec_r000927_12_1;
  int sec_r000927_12_2;
  int sec_r000927_13_1;
  int sec_r000927_13_2;
  int sec_r000927_14_1;
  int sec_r000927_14_2;
  int sec_r000927_15_1;
  int sec_r000927_15_2;
  int sec_r000927_16_1;
  int sec_r000927_16_2;
  int sec_r000927_17_1;
  int sec_r000927_17_2;
  int sec_r000927_18_1;
  int sec_r000927_18_2;
  int sec_r000927_19_1;
  int sec_r000927_19_2;
  int sec_r000927_20_1;
  int sec_r000927_20_2;
  int sec_r000927_21_1;
  int sec_r000927_21_2;
  int sec_r000927_22_1;
  int sec_r000927_22_2;
  int sec_r000927_23_1;
  int sec_r000927_23_2;
  int pub_r000927_0_1;
  int pub_r000927_0_2;
  int pub_r000927_1_1;
  int pub_r000927_1_2;
  int pub_r000927_2_1;
  int pub_r000927_2_2;
  int pub_r000927_3_1;
  int pub_r000927_3_2;
  int pub_r000927_4_1;
  int pub_r000927_4_2;
  int pub_r000927_5_1;
  int pub_r000927_5_2;
  int pub_r000927_6_1;
  int pub_r000927_6_2;
  int pub_r000927_7_1;
  int pub_r000927_7_2;
  int pub_r000927_8_1;
  int pub_r000927_8_2;
  int pub_r000927_9_1;
  int pub_r000927_9_2;
  int pub_r000927_10_1;
  int pub_r000927_10_2;
  int pub_r000927_11_1;
  int pub_r000927_11_2;
  int pub_r000927_12_1;
  int pub_r000927_12_2;
  int pub_r000927_13_1;
  int pub_r000927_13_2;
  int pub_r000927_14_1;
  int pub_r000927_14_2;
  int pub_r000927_15_1;
  int pub_r000927_15_2;
  int pub_r000927_16_1;
  int pub_r000927_16_2;
  int pub_r000927_17_1;
  int pub_r000927_17_2;
  int pub_r000927_18_1;
  int pub_r000927_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000927_0_1 >= (-100)) && (pub_r000927_0_1 <= 100));
  __CPROVER_assume((pub_r000927_0_2 >= (-100)) && (pub_r000927_0_2 <= 100));
  __CPROVER_assume((pub_r000927_1_1 >= (-100)) && (pub_r000927_1_1 <= 100));
  __CPROVER_assume((pub_r000927_1_2 >= (-100)) && (pub_r000927_1_2 <= 100));
  __CPROVER_assume((pub_r000927_2_1 >= (-100)) && (pub_r000927_2_1 <= 100));
  __CPROVER_assume((pub_r000927_2_2 >= (-100)) && (pub_r000927_2_2 <= 100));
  __CPROVER_assume((pub_r000927_3_1 >= (-100)) && (pub_r000927_3_1 <= 100));
  __CPROVER_assume((pub_r000927_3_2 >= (-100)) && (pub_r000927_3_2 <= 100));
  __CPROVER_assume((pub_r000927_4_1 >= (-100)) && (pub_r000927_4_1 <= 100));
  __CPROVER_assume((pub_r000927_4_2 >= (-100)) && (pub_r000927_4_2 <= 100));
  __CPROVER_assume((pub_r000927_5_1 >= (-100)) && (pub_r000927_5_1 <= 100));
  __CPROVER_assume((pub_r000927_5_2 >= (-100)) && (pub_r000927_5_2 <= 100));
  __CPROVER_assume((pub_r000927_6_1 >= (-100)) && (pub_r000927_6_1 <= 100));
  __CPROVER_assume((pub_r000927_6_2 >= (-100)) && (pub_r000927_6_2 <= 100));
  __CPROVER_assume((pub_r000927_7_1 >= (-100)) && (pub_r000927_7_1 <= 100));
  __CPROVER_assume((pub_r000927_7_2 >= (-100)) && (pub_r000927_7_2 <= 100));
  __CPROVER_assume((pub_r000927_8_1 >= (-100)) && (pub_r000927_8_1 <= 100));
  __CPROVER_assume((pub_r000927_8_2 >= (-100)) && (pub_r000927_8_2 <= 100));
  __CPROVER_assume((pub_r000927_9_1 >= (-100)) && (pub_r000927_9_1 <= 100));
  __CPROVER_assume((pub_r000927_9_2 >= (-100)) && (pub_r000927_9_2 <= 100));
  __CPROVER_assume((pub_r000927_10_1 >= (-100)) && (pub_r000927_10_1 <= 100));
  __CPROVER_assume((pub_r000927_10_2 >= (-100)) && (pub_r000927_10_2 <= 100));
  __CPROVER_assume((pub_r000927_11_1 >= (-100)) && (pub_r000927_11_1 <= 100));
  __CPROVER_assume((pub_r000927_11_2 >= (-100)) && (pub_r000927_11_2 <= 100));
  __CPROVER_assume((pub_r000927_12_1 >= (-100)) && (pub_r000927_12_1 <= 100));
  __CPROVER_assume((pub_r000927_12_2 >= (-100)) && (pub_r000927_12_2 <= 100));
  __CPROVER_assume((pub_r000927_13_1 >= (-100)) && (pub_r000927_13_1 <= 100));
  __CPROVER_assume((pub_r000927_13_2 >= (-100)) && (pub_r000927_13_2 <= 100));
  __CPROVER_assume((pub_r000927_14_1 >= (-100)) && (pub_r000927_14_1 <= 100));
  __CPROVER_assume((pub_r000927_14_2 >= (-100)) && (pub_r000927_14_2 <= 100));
  __CPROVER_assume((pub_r000927_15_1 >= (-100)) && (pub_r000927_15_1 <= 100));
  __CPROVER_assume((pub_r000927_15_2 >= (-100)) && (pub_r000927_15_2 <= 100));
  __CPROVER_assume((pub_r000927_16_1 >= (-100)) && (pub_r000927_16_1 <= 100));
  __CPROVER_assume((pub_r000927_16_2 >= (-100)) && (pub_r000927_16_2 <= 100));
  __CPROVER_assume((pub_r000927_17_1 >= (-100)) && (pub_r000927_17_1 <= 100));
  __CPROVER_assume((pub_r000927_17_2 >= (-100)) && (pub_r000927_17_2 <= 100));
  __CPROVER_assume((pub_r000927_18_1 >= (-100)) && (pub_r000927_18_1 <= 100));
  __CPROVER_assume((pub_r000927_18_2 >= (-100)) && (pub_r000927_18_2 <= 100));
  __CPROVER_assume((sec_r000927_0_1 >= 0) && (sec_r000927_0_1 <= 255));
  __CPROVER_assume((sec_r000927_0_2 >= 0) && (sec_r000927_0_2 <= 255));
  __CPROVER_assume((sec_r000927_1_1 >= 0) && (sec_r000927_1_1 <= 255));
  __CPROVER_assume((sec_r000927_1_2 >= 0) && (sec_r000927_1_2 <= 255));
  __CPROVER_assume((sec_r000927_2_1 >= 0) && (sec_r000927_2_1 <= 255));
  __CPROVER_assume((sec_r000927_2_2 >= 0) && (sec_r000927_2_2 <= 255));
  __CPROVER_assume((sec_r000927_3_1 >= 0) && (sec_r000927_3_1 <= 255));
  __CPROVER_assume((sec_r000927_3_2 >= 0) && (sec_r000927_3_2 <= 255));
  __CPROVER_assume((sec_r000927_4_1 >= 0) && (sec_r000927_4_1 <= 255));
  __CPROVER_assume((sec_r000927_4_2 >= 0) && (sec_r000927_4_2 <= 255));
  __CPROVER_assume((sec_r000927_5_1 >= 0) && (sec_r000927_5_1 <= 255));
  __CPROVER_assume((sec_r000927_5_2 >= 0) && (sec_r000927_5_2 <= 255));
  __CPROVER_assume((sec_r000927_6_1 >= 0) && (sec_r000927_6_1 <= 255));
  __CPROVER_assume((sec_r000927_6_2 >= 0) && (sec_r000927_6_2 <= 255));
  __CPROVER_assume((sec_r000927_7_1 >= 0) && (sec_r000927_7_1 <= 255));
  __CPROVER_assume((sec_r000927_7_2 >= 0) && (sec_r000927_7_2 <= 255));
  __CPROVER_assume((sec_r000927_8_1 >= 0) && (sec_r000927_8_1 <= 255));
  __CPROVER_assume((sec_r000927_8_2 >= 0) && (sec_r000927_8_2 <= 255));
  __CPROVER_assume((sec_r000927_9_1 >= 0) && (sec_r000927_9_1 <= 255));
  __CPROVER_assume((sec_r000927_9_2 >= 0) && (sec_r000927_9_2 <= 255));
  __CPROVER_assume((sec_r000927_10_1 >= 0) && (sec_r000927_10_1 <= 255));
  __CPROVER_assume((sec_r000927_10_2 >= 0) && (sec_r000927_10_2 <= 255));
  __CPROVER_assume((sec_r000927_11_1 >= 0) && (sec_r000927_11_1 <= 255));
  __CPROVER_assume((sec_r000927_11_2 >= 0) && (sec_r000927_11_2 <= 255));
  __CPROVER_assume((sec_r000927_12_1 >= 0) && (sec_r000927_12_1 <= 255));
  __CPROVER_assume((sec_r000927_12_2 >= 0) && (sec_r000927_12_2 <= 255));
  __CPROVER_assume((sec_r000927_13_1 >= 0) && (sec_r000927_13_1 <= 255));
  __CPROVER_assume((sec_r000927_13_2 >= 0) && (sec_r000927_13_2 <= 255));
  __CPROVER_assume((sec_r000927_14_1 >= 0) && (sec_r000927_14_1 <= 255));
  __CPROVER_assume((sec_r000927_14_2 >= 0) && (sec_r000927_14_2 <= 255));
  __CPROVER_assume((sec_r000927_15_1 >= 0) && (sec_r000927_15_1 <= 255));
  __CPROVER_assume((sec_r000927_15_2 >= 0) && (sec_r000927_15_2 <= 255));
  __CPROVER_assume((sec_r000927_16_1 >= 0) && (sec_r000927_16_1 <= 255));
  __CPROVER_assume((sec_r000927_16_2 >= 0) && (sec_r000927_16_2 <= 255));
  __CPROVER_assume((sec_r000927_17_1 >= 0) && (sec_r000927_17_1 <= 255));
  __CPROVER_assume((sec_r000927_17_2 >= 0) && (sec_r000927_17_2 <= 255));
  __CPROVER_assume((sec_r000927_18_1 >= 0) && (sec_r000927_18_1 <= 255));
  __CPROVER_assume((sec_r000927_18_2 >= 0) && (sec_r000927_18_2 <= 255));
  __CPROVER_assume((sec_r000927_19_1 >= 0) && (sec_r000927_19_1 <= 255));
  __CPROVER_assume((sec_r000927_19_2 >= 0) && (sec_r000927_19_2 <= 255));
  __CPROVER_assume((sec_r000927_20_1 >= 0) && (sec_r000927_20_1 <= 255));
  __CPROVER_assume((sec_r000927_20_2 >= 0) && (sec_r000927_20_2 <= 255));
  __CPROVER_assume((sec_r000927_21_1 >= 0) && (sec_r000927_21_1 <= 255));
  __CPROVER_assume((sec_r000927_21_2 >= 0) && (sec_r000927_21_2 <= 255));
  __CPROVER_assume((sec_r000927_22_1 >= 0) && (sec_r000927_22_1 <= 255));
  __CPROVER_assume((sec_r000927_22_2 >= 0) && (sec_r000927_22_2 <= 255));
  __CPROVER_assume((sec_r000927_23_1 >= 0) && (sec_r000927_23_1 <= 255));
  __CPROVER_assume((sec_r000927_23_2 >= 0) && (sec_r000927_23_2 <= 255));
  struct FilterState_R000927_2713_0 st_var_0_1 = {0};
  struct FilterState_R000927_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000927_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000927_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000927_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000927_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000927_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000927_0_2 + 7) & 15;
  struct AudioFrame_R000927_2713_1 st_var_1_1 = {0};
  struct AudioFrame_R000927_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000927_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000927_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000927_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000927_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000927_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000927_0_2 + 9) & 15;
  struct Transaction_R000927_2713_2 st_var_2_1 = {0};
  struct Transaction_R000927_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000927_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000927_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000927_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000927_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000927_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000927_0_2 + 11) & 15;
  union RegisterBank_R000927_2713_0 u_var_1;
  union RegisterBank_R000927_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 30)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 30)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_7_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 31)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 31)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 25)
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
  if (stage_v_13_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 25)
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
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 17) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 35)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 35)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = (st_var_1_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_1_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (st_var_1_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_1_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 30)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 30)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_38_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = ((st_var_1_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_1_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 39)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 39)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 48) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 44)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 44)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 47)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 47)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000927_22_1 & 1) != 0)
  {
    if ((sec_r000927_21_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000927_18_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000927_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000927_18_1 + 7) & 127;
  }
  if ((sec_r000927_22_2 & 1) != 0)
  {
    if ((sec_r000927_21_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000927_18_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000927_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000927_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000927_17_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000927_17_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000927_10_1 & 1) != 0)
  {
    if ((sec_r000927_7_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000927_5_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000927_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000927_5_1 + 7) & 127;
  }
  if ((sec_r000927_10_2 & 1) != 0)
  {
    if ((sec_r000927_7_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000927_5_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000927_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000927_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000927_17_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000927_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000927_17_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000927_17_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000927_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000927_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000927_12_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000927_1_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000927_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000927_1_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000927_12_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000927_1_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000927_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000927_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000927_8_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000927_6_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000927_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000927_6_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000927_8_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000927_6_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000927_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000927_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000927_18_1 & 1) != 0)
  {
    if ((sec_r000927_20_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000927_15_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000927_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000927_15_1 + 7) & 127;
  }
  if ((sec_r000927_18_2 & 1) != 0)
  {
    if ((sec_r000927_20_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000927_15_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000927_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000927_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000927_12_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000927_12_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000927_8_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000927_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000927_8_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000927_8_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000927_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000927_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000927_3_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000927_3_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000927_0_1 & 1) != 0)
  {
    if ((sec_r000927_3_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((sec_r000927_0_2 & 1) != 0)
  {
    if ((sec_r000927_3_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000927_21_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000927_6_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000927_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000927_6_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000927_21_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000927_6_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000927_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000927_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000927_13_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000927_7_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000927_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000927_7_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000927_13_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000927_7_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000927_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000927_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000927_20_1 & 1) != 0)
  {
    if ((sec_r000927_23_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000927_18_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000927_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000927_18_1 + 7) & 127;
  }
  if ((sec_r000927_20_2 & 1) != 0)
  {
    if ((sec_r000927_23_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000927_18_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000927_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000927_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000927_20_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000927_20_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000927_2_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000927_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000927_2_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000927_2_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000927_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000927_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000927_18_1 & 1) != 0)
  {
    if ((sec_r000927_19_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((sec_r000927_18_2 & 1) != 0)
  {
    if ((sec_r000927_19_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000927_17_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000927_17_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000927_21_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000927_15_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000927_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000927_15_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000927_21_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000927_15_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000927_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000927_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000927_10_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000927_13_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000927_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000927_13_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000927_10_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000927_13_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000927_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000927_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000927_11_1 & 1) != 0)
  {
    if ((sec_r000927_21_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000927_4_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000927_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000927_4_1 + 7) & 127;
  }
  if ((sec_r000927_11_2 & 1) != 0)
  {
    if ((sec_r000927_21_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000927_4_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000927_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000927_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000927_8_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000927_4_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000927_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000927_4_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000927_8_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000927_4_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000927_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000927_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000927_15_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000927_15_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000927_15_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000927_11_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000927_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000927_11_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000927_15_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000927_11_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000927_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000927_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000927_23_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000927_18_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000927_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000927_18_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000927_23_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000927_18_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000927_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000927_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000927_18_1 & 1) != 0)
  {
    if ((sec_r000927_7_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000927_17_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000927_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000927_17_1 + 7) & 127;
  }
  if ((sec_r000927_18_2 & 1) != 0)
  {
    if ((sec_r000927_7_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000927_17_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000927_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000927_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000927_4_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000927_18_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000927_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000927_18_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000927_4_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000927_18_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000927_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000927_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000927_17_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000927_17_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000927_23_1 & 1) != 0)
  {
    if ((sec_r000927_13_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000927_17_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000927_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000927_17_1 + 7) & 127;
  }
  if ((sec_r000927_23_2 & 1) != 0)
  {
    if ((sec_r000927_13_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000927_17_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000927_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000927_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000927_2_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000927_2_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000927_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000927_2_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000927_2_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000927_2_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000927_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000927_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000927_4_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000927_4_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000927_6_1 & 1) != 0)
  {
    if ((sec_r000927_8_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((sec_r000927_6_2 & 1) != 0)
  {
    if ((sec_r000927_8_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000927_18_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000927_6_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000927_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000927_6_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000927_18_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000927_6_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000927_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000927_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000927_14_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000927_5_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000927_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000927_5_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000927_14_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000927_5_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000927_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000927_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000927_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000927_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000927_16_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000927_7_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000927_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000927_7_1 + 7) & 127;
  }
  if ((sec_r000927_16_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000927_7_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000927_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000927_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000927_17_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000927_1_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000927_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000927_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000927_17_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000927_1_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000927_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000927_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000927_8_1 & 1) != 0)
  {
    if ((sec_r000927_0_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((sec_r000927_8_2 & 1) != 0)
  {
    if ((sec_r000927_0_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000927_4_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000927_6_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000927_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000927_6_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000927_4_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000927_6_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000927_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000927_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000927_6_1 & 1) != 0)
  {
    if ((sec_r000927_6_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((sec_r000927_6_2 & 1) != 0)
  {
    if ((sec_r000927_6_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000927_11_1 & 1) != 0)
  {
    if ((sec_r000927_13_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((sec_r000927_11_2 & 1) != 0)
  {
    if ((sec_r000927_13_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000927_23_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000927_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000927_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000927_12_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000927_23_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000927_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000927_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000927_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000927_12_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000927_17_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000927_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000927_17_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000927_12_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000927_17_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000927_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000927_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000927_20_1 & 1) != 0)
  {
    if ((sec_r000927_12_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((sec_r000927_20_2 & 1) != 0)
  {
    if ((sec_r000927_12_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000927_9_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000927_11_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000927_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000927_11_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000927_9_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000927_11_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000927_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000927_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000927_14_1 & 1) != 0)
  {
    if ((sec_r000927_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((sec_r000927_14_2 & 1) != 0)
  {
    if ((sec_r000927_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000927_4_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000927_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000927_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000927_15_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000927_4_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000927_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000927_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000927_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000927_6_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000927_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000927_6_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000927_6_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000927_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000927_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000927_7_1 & 1) != 0)
  {
    if ((sec_r000927_2_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000927_9_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000927_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000927_9_1 + 7) & 127;
  }
  if ((sec_r000927_7_2 & 1) != 0)
  {
    if ((sec_r000927_2_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000927_9_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000927_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000927_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000927_5_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000927_9_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000927_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000927_9_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000927_5_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000927_9_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000927_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000927_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000927_16_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000927_8_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000927_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000927_8_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000927_16_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000927_8_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000927_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000927_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000927_0_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000927_0_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000927_18_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000927_6_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000927_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000927_6_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000927_18_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000927_6_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000927_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000927_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000927_11_1 & 1) != 0)
  {
    if ((sec_r000927_9_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000927_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000927_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000927_12_1 + 7) & 127;
  }
  if ((sec_r000927_11_2 & 1) != 0)
  {
    if ((sec_r000927_9_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000927_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000927_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000927_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000927_5_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000927_15_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000927_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000927_15_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000927_5_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000927_15_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000927_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000927_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000927_23_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000927_15_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000927_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000927_15_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000927_23_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000927_15_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000927_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000927_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000927_14_1 & 1) != 0)
  {
    if ((sec_r000927_12_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000927_12_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000927_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000927_12_1 + 7) & 127;
  }
  if ((sec_r000927_14_2 & 1) != 0)
  {
    if ((sec_r000927_12_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000927_12_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000927_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000927_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000927_6_1 & 1) != 0)
  {
    if ((sec_r000927_23_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000927_8_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000927_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000927_8_1 + 7) & 127;
  }
  if ((sec_r000927_6_2 & 1) != 0)
  {
    if ((sec_r000927_23_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000927_8_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000927_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000927_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000927_18_1 & 1) != 0)
  {
    if ((sec_r000927_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((sec_r000927_18_2 & 1) != 0)
  {
    if ((sec_r000927_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000927_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000927_11_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000927_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000927_11_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000927_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000927_11_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000927_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000927_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000927_18_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000927_8_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000927_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000927_8_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000927_18_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000927_8_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000927_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000927_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000927_5_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((sec_r000927_5_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000927_8_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000927_8_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000927_8_1 & 1) != 0)
  {
    if ((sec_r000927_19_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((sec_r000927_8_2 & 1) != 0)
  {
    if ((sec_r000927_19_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000927_11_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000927_4_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000927_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000927_4_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000927_11_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000927_4_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000927_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000927_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000927_23_1 & 1) != 0)
  {
    if ((sec_r000927_20_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000927_13_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000927_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000927_13_1 + 7) & 127;
  }
  if ((sec_r000927_23_2 & 1) != 0)
  {
    if ((sec_r000927_20_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000927_13_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000927_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000927_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000927_15_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000927_9_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000927_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000927_9_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000927_15_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000927_9_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000927_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000927_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000927_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000927_7_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000927_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000927_7_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000927_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000927_7_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000927_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000927_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000927_5_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000927_1_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000927_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000927_1_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000927_5_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000927_1_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000927_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000927_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000927_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000927_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000927_16_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000927_7_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000927_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000927_7_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000927_16_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000927_7_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000927_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000927_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000927_6_1 & 1) != 0)
  {
    if ((sec_r000927_13_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000927_8_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000927_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000927_8_1 + 7) & 127;
  }
  if ((sec_r000927_6_2 & 1) != 0)
  {
    if ((sec_r000927_13_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000927_8_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000927_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000927_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000927_8_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000927_5_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000927_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000927_5_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000927_8_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000927_5_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000927_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000927_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000927_19_1 & 1) != 0)
  {
    if ((sec_r000927_16_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((sec_r000927_19_2 & 1) != 0)
  {
    if ((sec_r000927_16_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000927_21_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000927_2_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000927_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000927_2_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000927_21_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000927_2_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000927_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000927_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000927_22_1 & 1) != 0)
  {
    if ((sec_r000927_23_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000927_8_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000927_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000927_8_1 + 7) & 127;
  }
  if ((sec_r000927_22_2 & 1) != 0)
  {
    if ((sec_r000927_23_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000927_8_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000927_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000927_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000927_18_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000927_10_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000927_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000927_10_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000927_18_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000927_10_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000927_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000927_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000927_15_1 & 1) != 0)
  {
    if ((sec_r000927_5_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000927_9_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000927_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000927_9_1 + 7) & 127;
  }
  if ((sec_r000927_15_2 & 1) != 0)
  {
    if ((sec_r000927_5_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000927_9_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000927_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000927_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000927_13_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000927_17_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000927_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000927_17_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000927_13_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000927_17_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000927_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000927_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000927_16_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000927_7_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000927_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000927_7_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000927_16_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000927_7_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000927_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000927_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000927_15_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000927_16_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000927_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000927_16_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000927_15_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000927_16_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000927_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000927_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000927_3_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000927_12_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000927_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000927_12_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000927_3_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000927_12_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000927_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000927_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000927_0_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000927_14_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000927_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000927_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000927_0_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000927_14_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000927_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000927_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000927_0_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000927_0_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000927_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000927_0_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000927_0_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000927_0_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000927_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000927_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000927_16_1 & 1) != 0)
  {
    if ((sec_r000927_11_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000927_18_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000927_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000927_18_1 + 7) & 127;
  }
  if ((sec_r000927_16_2 & 1) != 0)
  {
    if ((sec_r000927_11_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000927_18_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000927_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000927_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000927_3_1 & 1) != 0)
  {
    if ((sec_r000927_1_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000927_3_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000927_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000927_3_1 + 7) & 127;
  }
  if ((sec_r000927_3_2 & 1) != 0)
  {
    if ((sec_r000927_1_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000927_3_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000927_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000927_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000927_11_1 == pub_r000927_11_2);
  __CPROVER_assume(sec_r000927_21_1 != sec_r000927_21_2);
  __CPROVER_assume(sec_r000927_15_1 != sec_r000927_15_2);
  __CPROVER_assume(sec_r000927_7_1 != sec_r000927_7_2);
  __CPROVER_assume(sec_r000927_23_1 != sec_r000927_23_2);
  __CPROVER_assume(pub_r000927_4_1 == pub_r000927_4_2);
  __CPROVER_assume(sec_r000927_9_1 != sec_r000927_9_2);
  __CPROVER_assume(sec_r000927_13_1 != sec_r000927_13_2);
  __CPROVER_assume(sec_r000927_0_1 != sec_r000927_0_2);
  __CPROVER_assume(sec_r000927_5_1 != sec_r000927_5_2);
  __CPROVER_assume(sec_r000927_12_1 != sec_r000927_12_2);
  __CPROVER_assume(sec_r000927_17_1 != sec_r000927_17_2);
  __CPROVER_assume(pub_r000927_15_1 == pub_r000927_15_2);
  __CPROVER_assume(pub_r000927_13_1 == pub_r000927_13_2);
  __CPROVER_assume(pub_r000927_14_1 == pub_r000927_14_2);
  __CPROVER_assume(sec_r000927_4_1 != sec_r000927_4_2);
  __CPROVER_assume(sec_r000927_18_1 != sec_r000927_18_2);
  __CPROVER_assume(pub_r000927_18_1 == pub_r000927_18_2);
  __CPROVER_assume(sec_r000927_2_1 != sec_r000927_2_2);
  __CPROVER_assume(sec_r000927_22_1 != sec_r000927_22_2);
  __CPROVER_assume(pub_r000927_1_1 == pub_r000927_1_2);
  __CPROVER_assume(sec_r000927_1_1 != sec_r000927_1_2);
  __CPROVER_assume(pub_r000927_0_1 == pub_r000927_0_2);
  __CPROVER_assume(pub_r000927_8_1 == pub_r000927_8_2);
  __CPROVER_assume(sec_r000927_3_1 != sec_r000927_3_2);
  __CPROVER_assume(sec_r000927_19_1 != sec_r000927_19_2);
  __CPROVER_assume(pub_r000927_5_1 == pub_r000927_5_2);
  __CPROVER_assume(pub_r000927_10_1 == pub_r000927_10_2);
  __CPROVER_assume(sec_r000927_16_1 != sec_r000927_16_2);
  __CPROVER_assume(sec_r000927_6_1 != sec_r000927_6_2);
  __CPROVER_assume(sec_r000927_10_1 != sec_r000927_10_2);
  __CPROVER_assume(pub_r000927_2_1 == pub_r000927_2_2);
  __CPROVER_assume(pub_r000927_3_1 == pub_r000927_3_2);
  __CPROVER_assume(pub_r000927_12_1 == pub_r000927_12_2);
  __CPROVER_assume(sec_r000927_8_1 != sec_r000927_8_2);
  __CPROVER_assume(sec_r000927_14_1 != sec_r000927_14_2);
  __CPROVER_assume(pub_r000927_9_1 == pub_r000927_9_2);
  __CPROVER_assume(pub_r000927_17_1 == pub_r000927_17_2);
  __CPROVER_assume(sec_r000927_11_1 != sec_r000927_11_2);
  __CPROVER_assume(pub_r000927_7_1 == pub_r000927_7_2);
  __CPROVER_assume(sec_r000927_20_1 != sec_r000927_20_2);
  __CPROVER_assume(pub_r000927_16_1 == pub_r000927_16_2);
  __CPROVER_assume(pub_r000927_6_1 == pub_r000927_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.fee == st_var_2_2.fee);
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
}


