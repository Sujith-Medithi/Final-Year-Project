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
struct FilterState_R001146_4613_0
{
  int cutoff;
  int gain_db;
  int prev_in;
  int buffer[3];
};
struct Vector3D_R001146_4613_1
{
  int coord_z;
  int norm_sq;
  short coord_y;
  int heading;
  unsigned char coord_x;
  int buffer[3];
};
struct StreamBuffer_R001146_4613_2
{
  unsigned char state;
  int tail;
  unsigned char checksum;
  int buffer[3];
};
union PacketPayload_R001146_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001146_4613_1
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
void fn_R001146_4613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st_1 = {0};
  struct Vector3D_R001146_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_53_1 > 30)
  {
    acc_1 = ((acc_1 + (tally_53_1 * 2)) + 5) & 127;
    aux_1 ^= tally_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_53_2 > 30)
  {
    acc_2 = ((acc_2 + (tally_53_2 * 2)) + 5) & 127;
    aux_2 ^= tally_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_82_1) & 63;
  aux_2 = (aux_2 + mask_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_53_1 == tally_53_2);
  assert(mask_82_1 == mask_82_2);
}

int fn_R001146_4613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_53 > 30)
  {
    acc = ((acc + (tally_53 * 2)) + 5) & 127;
    aux ^= tally_53 & 15;
  }
  else
  {
    acc = ((acc - tally_53) + 11) & 127;
    aux += 3;
  }
  int mask_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001146_4613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st_1 = {0};
  struct FilterState_R001146_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_86_1)
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

  switch (offset_86_2)
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

  int threshold_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_36_1 > 44)
  {
    acc_1 = ((acc_1 + (threshold_36_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_36_2 > 44)
  {
    acc_2 = ((acc_2 + (threshold_36_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_42_1 = 0;
  int index_reg_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_42_1 = ((index_reg_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_42_2 = ((index_reg_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_42_1) & 127;
    acc_2 = (acc_2 + index_reg_42_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_86_1 == offset_86_2);
  assert(threshold_36_1 == threshold_36_2);
  assert(index_reg_42_1 == index_reg_42_2);
}

int fn_R001146_4613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_86 = (aux + st.buffer[1]) & 3;
  switch (offset_86)
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

  int threshold_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_36 > 44)
  {
    acc = ((acc + (threshold_36 * 2)) + 5) & 127;
    aux ^= threshold_36 & 15;
  }
  else
  {
    acc = ((acc - threshold_36) + 11) & 127;
    aux += 3;
  }
  int index_reg_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_42 = ((index_reg_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_42) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int factor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_23_1)
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

  switch (factor_23_2)
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

  int checksum_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_97_1 > 18)
  {
    acc_1 = ((acc_1 + (checksum_97_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_97_2 > 18)
  {
    acc_2 = ((acc_2 + (checksum_97_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_23_1 == factor_23_2);
  assert(checksum_97_1 == checksum_97_2);
}

int fn_R001146_4613_2(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int factor_23 = (aux + st.buffer[1]) & 3;
  switch (factor_23)
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

  int checksum_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_97 > 18)
  {
    acc = ((acc + (checksum_97 * 2)) + 5) & 127;
    aux ^= checksum_97 & 15;
  }
  else
  {
    acc = ((acc - checksum_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001146_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_68_1 = local_arr_1[aux_1 % 3];
  int parity_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_68_2 * 2)) & 127;
  int window_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_44_1 > 48)
  {
    acc_1 = ((acc_1 + (window_44_1 * 2)) + 5) & 127;
    aux_1 ^= window_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_44_2 > 48)
  {
    acc_2 = ((acc_2 + (window_44_2 * 2)) + 5) & 127;
    aux_2 ^= window_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_68_1 == parity_68_2);
  assert(window_44_1 == window_44_2);
}

int fn_R001146_4613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_68 = local_arr[aux % 3];
  acc = (acc + (parity_68 * 2)) & 127;
  int window_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_44 > 48)
  {
    acc = ((acc + (window_44 * 2)) + 5) & 127;
    aux ^= window_44 & 15;
  }
  else
  {
    acc = ((acc - window_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001146_4613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tally_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_96_1) & 63;
  aux_2 = (aux_2 + tally_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_77_1 = local_arr_1[aux_1 % 3];
  int phase_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_77_2 * 2)) & 127;
  int factor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_15_1)
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

  switch (factor_15_2)
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

  int mask_69_1 = 0;
  int mask_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_69_1 = ((mask_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_69_2 = ((mask_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_69_1) & 127;
    acc_2 = (acc_2 + mask_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_96_1 == tally_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_77_1 == phase_77_2);
  assert(factor_15_1 == factor_15_2);
  assert(mask_69_1 == mask_69_2);
}

int fn_R001146_4613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tally_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_77 = local_arr[aux % 3];
  acc = (acc + (phase_77 * 2)) & 127;
  int factor_15 = (aux + st.buffer[1]) & 3;
  switch (factor_15)
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

  int mask_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_69 = ((mask_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001146_4613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st_1 = {0};
  struct Vector3D_R001146_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int checksum_87_1 = 0;
  int checksum_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_87_1 = ((checksum_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_87_2 = ((checksum_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_87_1) & 127;
    acc_2 = (acc_2 + checksum_87_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_17_1) & 63;
  aux_2 = (aux_2 + cursor_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_65_1)
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

  switch (scale_65_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_87_1 == checksum_87_2);
  assert(cursor_17_1 == cursor_17_2);
  assert(scale_65_1 == scale_65_2);
}

int fn_R001146_4613_5(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int checksum_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_87 = ((checksum_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_87) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_17) & 63;
  acc ^= aux;
  int scale_65 = (aux + st.buffer[1]) & 3;
  switch (scale_65)
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

void fn_R001146_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st_1 = {0};
  struct Vector3D_R001146_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_67_1) & 63;
  aux_2 = (aux_2 + offset_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_56_1)
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

  switch (stride_56_2)
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
  int scale_16_1 = local_arr_1[aux_1 % 3];
  int scale_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_67_1 == offset_67_2);
  assert(stride_56_1 == stride_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_16_1 == scale_16_2);
}

int fn_R001146_4613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_67) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_56 = (aux + st.buffer[1]) & 3;
  switch (stride_56)
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
  int scale_16 = local_arr[aux % 3];
  acc = (acc + (scale_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_52_1)
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

  switch (metric_52_2)
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
  int offset_68_1 = local_arr_1[aux_1 % 3];
  int offset_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_68_2 * 2)) & 127;
  int tally_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_99_1 > 22)
  {
    acc_1 = ((acc_1 + (tally_99_1 * 2)) + 5) & 127;
    aux_1 ^= tally_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_99_2 > 22)
  {
    acc_2 = ((acc_2 + (tally_99_2 * 2)) + 5) & 127;
    aux_2 ^= tally_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_52_1 == metric_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_68_1 == offset_68_2);
  assert(tally_99_1 == tally_99_2);
}

int fn_R001146_4613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_52 = (aux + st.buffer[1]) & 3;
  switch (metric_52)
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
  int offset_68 = local_arr[aux % 3];
  acc = (acc + (offset_68 * 2)) & 127;
  int tally_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_99 > 22)
  {
    acc = ((acc + (tally_99 * 2)) + 5) & 127;
    aux ^= tally_99 & 15;
  }
  else
  {
    acc = ((acc - tally_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001146_4613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st_1 = {0};
  struct FilterState_R001146_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_70_1)
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

  switch (margin_70_2)
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

  int segment_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_11_1) & 63;
  aux_2 = (aux_2 + segment_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_70_1 == margin_70_2);
  assert(segment_11_1 == segment_11_2);
}

int fn_R001146_4613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_70 = (aux + st.buffer[1]) & 3;
  switch (margin_70)
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

  int segment_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tracker_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_69_1) & 63;
  aux_2 = (aux_2 + tracker_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_10_1 > 37)
  {
    acc_1 = ((acc_1 + (sample_10_1 * 2)) + 5) & 127;
    aux_1 ^= sample_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_10_2 > 37)
  {
    acc_2 = ((acc_2 + (sample_10_2 * 2)) + 5) & 127;
    aux_2 ^= sample_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_40_1 = 0;
  int accumulator_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_40_1 = ((accumulator_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_40_2 = ((accumulator_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_40_1) & 127;
    acc_2 = (acc_2 + accumulator_40_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_69_1 == tracker_69_2);
  assert(sample_10_1 == sample_10_2);
  assert(accumulator_40_1 == accumulator_40_2);
}

int fn_R001146_4613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tracker_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_69) & 63;
  acc ^= aux;
  int sample_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_10 > 37)
  {
    acc = ((acc + (sample_10 * 2)) + 5) & 127;
    aux ^= sample_10 & 15;
  }
  else
  {
    acc = ((acc - sample_10) + 11) & 127;
    aux += 3;
  }
  int accumulator_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_40 = ((accumulator_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_40) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st_1 = {0};
  struct Vector3D_R001146_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_97_1)
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

  switch (stride_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_97_1 == stride_97_2);
}

int fn_R001146_4613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_97 = (aux + st.buffer[1]) & 3;
  switch (stride_97)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_57_1 = 0;
  int tally_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_57_1 = ((tally_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_57_2 = ((tally_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_57_1) & 127;
    acc_2 = (acc_2 + tally_57_2) & 127;
  }

  int delta_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_99_1)
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

  switch (delta_99_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_57_1 == tally_57_2);
  assert(delta_99_1 == delta_99_2);
}

int fn_R001146_4613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_57 = ((tally_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_57) & 127;
  }

  int delta_99 = (aux + st.buffer[1]) & 3;
  switch (delta_99)
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

void fn_R001146_4613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st_1 = {0};
  struct FilterState_R001146_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int residue_98_1 = 0;
  int residue_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_98_1 = ((residue_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_98_2 = ((residue_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_98_1) & 127;
    acc_2 = (acc_2 + residue_98_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_99_1 = local_arr_1[aux_1 % 3];
  int bound_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_98_1 == residue_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_99_1 == bound_99_2);
}

int fn_R001146_4613_12(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int residue_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_98 = ((residue_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_98) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_99 = local_arr[aux % 3];
  acc = (acc + (bound_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_39_1 > 30)
  {
    acc_1 = ((acc_1 + (metric_39_1 * 2)) + 5) & 127;
    aux_1 ^= metric_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_39_2 > 30)
  {
    acc_2 = ((acc_2 + (metric_39_2 * 2)) + 5) & 127;
    aux_2 ^= metric_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_58_1 = 0;
  int parity_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_58_1 = ((parity_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_58_2 = ((parity_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_58_1) & 127;
    acc_2 = (acc_2 + parity_58_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_39_1 == metric_39_2);
  assert(parity_58_1 == parity_58_2);
}

int fn_R001146_4613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_39 > 30)
  {
    acc = ((acc + (metric_39 * 2)) + 5) & 127;
    aux ^= metric_39 & 15;
  }
  else
  {
    acc = ((acc - metric_39) + 11) & 127;
    aux += 3;
  }
  int parity_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_58 = ((parity_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_58) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001146_4613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st_1 = {0};
  struct FilterState_R001146_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_85_1 = 0;
  int phase_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_85_1 = ((phase_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_85_2 = ((phase_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_85_1) & 127;
    acc_2 = (acc_2 + phase_85_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_36_1 = local_arr_1[aux_1 % 3];
  int margin_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_85_1 == phase_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_36_1 == margin_36_2);
}

int fn_R001146_4613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_85 = ((phase_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_85) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int margin_36 = local_arr[aux % 3];
  acc = (acc + (margin_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st_1 = {0};
  struct Vector3D_R001146_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int checksum_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_19_1 > 17)
  {
    acc_1 = ((acc_1 + (checksum_19_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_19_2 > 17)
  {
    acc_2 = ((acc_2 + (checksum_19_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_34_1) & 63;
  aux_2 = (aux_2 + metric_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_16_1 = local_arr_1[aux_1 % 3];
  int window_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_19_1 == checksum_19_2);
  assert(metric_34_1 == metric_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_16_1 == window_16_2);
}

int fn_R001146_4613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001146_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int checksum_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_19 > 17)
  {
    acc = ((acc + (checksum_19 * 2)) + 5) & 127;
    aux ^= checksum_19 & 15;
  }
  else
  {
    acc = ((acc - checksum_19) + 11) & 127;
    aux += 3;
  }
  int metric_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_34) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_16 = local_arr[aux % 3];
  acc = (acc + (window_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001146_4613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st_1 = {0};
  struct FilterState_R001146_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_65_1) & 63;
  aux_2 = (aux_2 + mask_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_29_1 > 45)
  {
    acc_1 = ((acc_1 + (quotient_29_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_29_2 > 45)
  {
    acc_2 = ((acc_2 + (quotient_29_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(quotient_29_1 == quotient_29_2);
}

int fn_R001146_4613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001146_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_65) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_29 > 45)
  {
    acc = ((acc + (quotient_29 * 2)) + 5) & 127;
    aux ^= quotient_29 & 15;
  }
  else
  {
    acc = ((acc - quotient_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001146_4613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quantum_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_25_1 > 28)
  {
    acc_1 = ((acc_1 + (quantum_25_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_25_2 > 28)
  {
    acc_2 = ((acc_2 + (quantum_25_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_55_1 = local_arr_1[aux_1 % 3];
  int weight_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_55_2 * 2)) & 127;
  int accumulator_62_1 = 0;
  int accumulator_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_62_1 = ((accumulator_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_62_2 = ((accumulator_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_62_1) & 127;
    acc_2 = (acc_2 + accumulator_62_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_25_1 == quantum_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_55_1 == weight_55_2);
  assert(accumulator_62_1 == accumulator_62_2);
}

int fn_R001146_4613_17(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quantum_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_25 > 28)
  {
    acc = ((acc + (quantum_25 * 2)) + 5) & 127;
    aux ^= quantum_25 & 15;
  }
  else
  {
    acc = ((acc - quantum_25) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_55 = local_arr[aux % 3];
  acc = (acc + (weight_55 * 2)) & 127;
  int accumulator_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_62 = ((accumulator_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_62) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001146_4613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_57_1 > 48)
  {
    acc_1 = ((acc_1 + (checksum_57_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_57_2 > 48)
  {
    acc_2 = ((acc_2 + (checksum_57_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_54_1) & 63;
  aux_2 = (aux_2 + offset_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_57_1 == checksum_57_2);
  assert(offset_54_1 == offset_54_2);
}

int fn_R001146_4613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001146_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_57 > 48)
  {
    acc = ((acc + (checksum_57 * 2)) + 5) & 127;
    aux ^= checksum_57 & 15;
  }
  else
  {
    acc = ((acc - checksum_57) + 11) & 127;
    aux += 3;
  }
  int offset_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001146_0_1;
  int sec_r001146_0_2;
  int sec_r001146_1_1;
  int sec_r001146_1_2;
  int sec_r001146_2_1;
  int sec_r001146_2_2;
  int sec_r001146_3_1;
  int sec_r001146_3_2;
  int sec_r001146_4_1;
  int sec_r001146_4_2;
  int sec_r001146_5_1;
  int sec_r001146_5_2;
  int sec_r001146_6_1;
  int sec_r001146_6_2;
  int sec_r001146_7_1;
  int sec_r001146_7_2;
  int sec_r001146_8_1;
  int sec_r001146_8_2;
  int sec_r001146_9_1;
  int sec_r001146_9_2;
  int sec_r001146_10_1;
  int sec_r001146_10_2;
  int sec_r001146_11_1;
  int sec_r001146_11_2;
  int sec_r001146_12_1;
  int sec_r001146_12_2;
  int sec_r001146_13_1;
  int sec_r001146_13_2;
  int sec_r001146_14_1;
  int sec_r001146_14_2;
  int sec_r001146_15_1;
  int sec_r001146_15_2;
  int sec_r001146_16_1;
  int sec_r001146_16_2;
  int sec_r001146_17_1;
  int sec_r001146_17_2;
  int sec_r001146_18_1;
  int sec_r001146_18_2;
  int sec_r001146_19_1;
  int sec_r001146_19_2;
  int sec_r001146_20_1;
  int sec_r001146_20_2;
  int sec_r001146_21_1;
  int sec_r001146_21_2;
  int sec_r001146_22_1;
  int sec_r001146_22_2;
  int pub_r001146_0_1;
  int pub_r001146_0_2;
  int pub_r001146_1_1;
  int pub_r001146_1_2;
  int pub_r001146_2_1;
  int pub_r001146_2_2;
  int pub_r001146_3_1;
  int pub_r001146_3_2;
  int pub_r001146_4_1;
  int pub_r001146_4_2;
  int pub_r001146_5_1;
  int pub_r001146_5_2;
  int pub_r001146_6_1;
  int pub_r001146_6_2;
  int pub_r001146_7_1;
  int pub_r001146_7_2;
  int pub_r001146_8_1;
  int pub_r001146_8_2;
  int pub_r001146_9_1;
  int pub_r001146_9_2;
  int pub_r001146_10_1;
  int pub_r001146_10_2;
  int pub_r001146_11_1;
  int pub_r001146_11_2;
  int pub_r001146_12_1;
  int pub_r001146_12_2;
  int pub_r001146_13_1;
  int pub_r001146_13_2;
  int pub_r001146_14_1;
  int pub_r001146_14_2;
  int pub_r001146_15_1;
  int pub_r001146_15_2;
  int pub_r001146_16_1;
  int pub_r001146_16_2;
  int pub_r001146_17_1;
  int pub_r001146_17_2;
  int pub_r001146_18_1;
  int pub_r001146_18_2;
  int pub_r001146_19_1;
  int pub_r001146_19_2;
  int pub_r001146_20_1;
  int pub_r001146_20_2;
  int pub_r001146_21_1;
  int pub_r001146_21_2;
  int pub_r001146_22_1;
  int pub_r001146_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001146_0_1 >= (-100)) && (pub_r001146_0_1 <= 100));
  __CPROVER_assume((pub_r001146_0_2 >= (-100)) && (pub_r001146_0_2 <= 100));
  __CPROVER_assume((pub_r001146_1_1 >= (-100)) && (pub_r001146_1_1 <= 100));
  __CPROVER_assume((pub_r001146_1_2 >= (-100)) && (pub_r001146_1_2 <= 100));
  __CPROVER_assume((pub_r001146_2_1 >= (-100)) && (pub_r001146_2_1 <= 100));
  __CPROVER_assume((pub_r001146_2_2 >= (-100)) && (pub_r001146_2_2 <= 100));
  __CPROVER_assume((pub_r001146_3_1 >= (-100)) && (pub_r001146_3_1 <= 100));
  __CPROVER_assume((pub_r001146_3_2 >= (-100)) && (pub_r001146_3_2 <= 100));
  __CPROVER_assume((pub_r001146_4_1 >= (-100)) && (pub_r001146_4_1 <= 100));
  __CPROVER_assume((pub_r001146_4_2 >= (-100)) && (pub_r001146_4_2 <= 100));
  __CPROVER_assume((pub_r001146_5_1 >= (-100)) && (pub_r001146_5_1 <= 100));
  __CPROVER_assume((pub_r001146_5_2 >= (-100)) && (pub_r001146_5_2 <= 100));
  __CPROVER_assume((pub_r001146_6_1 >= (-100)) && (pub_r001146_6_1 <= 100));
  __CPROVER_assume((pub_r001146_6_2 >= (-100)) && (pub_r001146_6_2 <= 100));
  __CPROVER_assume((pub_r001146_7_1 >= (-100)) && (pub_r001146_7_1 <= 100));
  __CPROVER_assume((pub_r001146_7_2 >= (-100)) && (pub_r001146_7_2 <= 100));
  __CPROVER_assume((pub_r001146_8_1 >= (-100)) && (pub_r001146_8_1 <= 100));
  __CPROVER_assume((pub_r001146_8_2 >= (-100)) && (pub_r001146_8_2 <= 100));
  __CPROVER_assume((pub_r001146_9_1 >= (-100)) && (pub_r001146_9_1 <= 100));
  __CPROVER_assume((pub_r001146_9_2 >= (-100)) && (pub_r001146_9_2 <= 100));
  __CPROVER_assume((pub_r001146_10_1 >= (-100)) && (pub_r001146_10_1 <= 100));
  __CPROVER_assume((pub_r001146_10_2 >= (-100)) && (pub_r001146_10_2 <= 100));
  __CPROVER_assume((pub_r001146_11_1 >= (-100)) && (pub_r001146_11_1 <= 100));
  __CPROVER_assume((pub_r001146_11_2 >= (-100)) && (pub_r001146_11_2 <= 100));
  __CPROVER_assume((pub_r001146_12_1 >= (-100)) && (pub_r001146_12_1 <= 100));
  __CPROVER_assume((pub_r001146_12_2 >= (-100)) && (pub_r001146_12_2 <= 100));
  __CPROVER_assume((pub_r001146_13_1 >= (-100)) && (pub_r001146_13_1 <= 100));
  __CPROVER_assume((pub_r001146_13_2 >= (-100)) && (pub_r001146_13_2 <= 100));
  __CPROVER_assume((pub_r001146_14_1 >= (-100)) && (pub_r001146_14_1 <= 100));
  __CPROVER_assume((pub_r001146_14_2 >= (-100)) && (pub_r001146_14_2 <= 100));
  __CPROVER_assume((pub_r001146_15_1 >= (-100)) && (pub_r001146_15_1 <= 100));
  __CPROVER_assume((pub_r001146_15_2 >= (-100)) && (pub_r001146_15_2 <= 100));
  __CPROVER_assume((pub_r001146_16_1 >= (-100)) && (pub_r001146_16_1 <= 100));
  __CPROVER_assume((pub_r001146_16_2 >= (-100)) && (pub_r001146_16_2 <= 100));
  __CPROVER_assume((pub_r001146_17_1 >= (-100)) && (pub_r001146_17_1 <= 100));
  __CPROVER_assume((pub_r001146_17_2 >= (-100)) && (pub_r001146_17_2 <= 100));
  __CPROVER_assume((pub_r001146_18_1 >= (-100)) && (pub_r001146_18_1 <= 100));
  __CPROVER_assume((pub_r001146_18_2 >= (-100)) && (pub_r001146_18_2 <= 100));
  __CPROVER_assume((pub_r001146_19_1 >= (-100)) && (pub_r001146_19_1 <= 100));
  __CPROVER_assume((pub_r001146_19_2 >= (-100)) && (pub_r001146_19_2 <= 100));
  __CPROVER_assume((pub_r001146_20_1 >= (-100)) && (pub_r001146_20_1 <= 100));
  __CPROVER_assume((pub_r001146_20_2 >= (-100)) && (pub_r001146_20_2 <= 100));
  __CPROVER_assume((pub_r001146_21_1 >= (-100)) && (pub_r001146_21_1 <= 100));
  __CPROVER_assume((pub_r001146_21_2 >= (-100)) && (pub_r001146_21_2 <= 100));
  __CPROVER_assume((pub_r001146_22_1 >= (-100)) && (pub_r001146_22_1 <= 100));
  __CPROVER_assume((pub_r001146_22_2 >= (-100)) && (pub_r001146_22_2 <= 100));
  __CPROVER_assume((sec_r001146_0_1 >= 0) && (sec_r001146_0_1 <= 255));
  __CPROVER_assume((sec_r001146_0_2 >= 0) && (sec_r001146_0_2 <= 255));
  __CPROVER_assume((sec_r001146_1_1 >= 0) && (sec_r001146_1_1 <= 255));
  __CPROVER_assume((sec_r001146_1_2 >= 0) && (sec_r001146_1_2 <= 255));
  __CPROVER_assume((sec_r001146_2_1 >= 0) && (sec_r001146_2_1 <= 255));
  __CPROVER_assume((sec_r001146_2_2 >= 0) && (sec_r001146_2_2 <= 255));
  __CPROVER_assume((sec_r001146_3_1 >= 0) && (sec_r001146_3_1 <= 255));
  __CPROVER_assume((sec_r001146_3_2 >= 0) && (sec_r001146_3_2 <= 255));
  __CPROVER_assume((sec_r001146_4_1 >= 0) && (sec_r001146_4_1 <= 255));
  __CPROVER_assume((sec_r001146_4_2 >= 0) && (sec_r001146_4_2 <= 255));
  __CPROVER_assume((sec_r001146_5_1 >= 0) && (sec_r001146_5_1 <= 255));
  __CPROVER_assume((sec_r001146_5_2 >= 0) && (sec_r001146_5_2 <= 255));
  __CPROVER_assume((sec_r001146_6_1 >= 0) && (sec_r001146_6_1 <= 255));
  __CPROVER_assume((sec_r001146_6_2 >= 0) && (sec_r001146_6_2 <= 255));
  __CPROVER_assume((sec_r001146_7_1 >= 0) && (sec_r001146_7_1 <= 255));
  __CPROVER_assume((sec_r001146_7_2 >= 0) && (sec_r001146_7_2 <= 255));
  __CPROVER_assume((sec_r001146_8_1 >= 0) && (sec_r001146_8_1 <= 255));
  __CPROVER_assume((sec_r001146_8_2 >= 0) && (sec_r001146_8_2 <= 255));
  __CPROVER_assume((sec_r001146_9_1 >= 0) && (sec_r001146_9_1 <= 255));
  __CPROVER_assume((sec_r001146_9_2 >= 0) && (sec_r001146_9_2 <= 255));
  __CPROVER_assume((sec_r001146_10_1 >= 0) && (sec_r001146_10_1 <= 255));
  __CPROVER_assume((sec_r001146_10_2 >= 0) && (sec_r001146_10_2 <= 255));
  __CPROVER_assume((sec_r001146_11_1 >= 0) && (sec_r001146_11_1 <= 255));
  __CPROVER_assume((sec_r001146_11_2 >= 0) && (sec_r001146_11_2 <= 255));
  __CPROVER_assume((sec_r001146_12_1 >= 0) && (sec_r001146_12_1 <= 255));
  __CPROVER_assume((sec_r001146_12_2 >= 0) && (sec_r001146_12_2 <= 255));
  __CPROVER_assume((sec_r001146_13_1 >= 0) && (sec_r001146_13_1 <= 255));
  __CPROVER_assume((sec_r001146_13_2 >= 0) && (sec_r001146_13_2 <= 255));
  __CPROVER_assume((sec_r001146_14_1 >= 0) && (sec_r001146_14_1 <= 255));
  __CPROVER_assume((sec_r001146_14_2 >= 0) && (sec_r001146_14_2 <= 255));
  __CPROVER_assume((sec_r001146_15_1 >= 0) && (sec_r001146_15_1 <= 255));
  __CPROVER_assume((sec_r001146_15_2 >= 0) && (sec_r001146_15_2 <= 255));
  __CPROVER_assume((sec_r001146_16_1 >= 0) && (sec_r001146_16_1 <= 255));
  __CPROVER_assume((sec_r001146_16_2 >= 0) && (sec_r001146_16_2 <= 255));
  __CPROVER_assume((sec_r001146_17_1 >= 0) && (sec_r001146_17_1 <= 255));
  __CPROVER_assume((sec_r001146_17_2 >= 0) && (sec_r001146_17_2 <= 255));
  __CPROVER_assume((sec_r001146_18_1 >= 0) && (sec_r001146_18_1 <= 255));
  __CPROVER_assume((sec_r001146_18_2 >= 0) && (sec_r001146_18_2 <= 255));
  __CPROVER_assume((sec_r001146_19_1 >= 0) && (sec_r001146_19_1 <= 255));
  __CPROVER_assume((sec_r001146_19_2 >= 0) && (sec_r001146_19_2 <= 255));
  __CPROVER_assume((sec_r001146_20_1 >= 0) && (sec_r001146_20_1 <= 255));
  __CPROVER_assume((sec_r001146_20_2 >= 0) && (sec_r001146_20_2 <= 255));
  __CPROVER_assume((sec_r001146_21_1 >= 0) && (sec_r001146_21_1 <= 255));
  __CPROVER_assume((sec_r001146_21_2 >= 0) && (sec_r001146_21_2 <= 255));
  __CPROVER_assume((sec_r001146_22_1 >= 0) && (sec_r001146_22_1 <= 255));
  __CPROVER_assume((sec_r001146_22_2 >= 0) && (sec_r001146_22_2 <= 255));
  struct FilterState_R001146_4613_0 st_var_0_1 = {0};
  struct FilterState_R001146_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001146_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001146_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001146_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001146_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001146_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001146_0_2 + 7) & 15;
  struct Vector3D_R001146_4613_1 st_var_1_1 = {0};
  struct Vector3D_R001146_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001146_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001146_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001146_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001146_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001146_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001146_0_2 + 9) & 15;
  struct StreamBuffer_R001146_4613_2 st_var_2_1 = {0};
  struct StreamBuffer_R001146_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001146_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001146_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001146_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001146_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001146_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001146_0_2 + 11) & 15;
  union PacketPayload_R001146_4613_0 u_var_1;
  union PacketPayload_R001146_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001146_4613_0(sec_r001146_0_1, sec_r001146_1_1, pub_r001146_2_1);
  int helper_flow_0_2 = fn_R001146_4613_0(sec_r001146_0_2, sec_r001146_1_2, pub_r001146_2_2);
  fn_R001146_4613_0_2(sec_r001146_0_1, sec_r001146_1_1, pub_r001146_2_1, sec_r001146_0_2, sec_r001146_1_2, pub_r001146_2_2);
  int helper_flow_1_1 = fn_R001146_4613_1(sec_r001146_1_1, sec_r001146_2_1, pub_r001146_3_1, pub_r001146_4_1);
  int helper_flow_1_2 = fn_R001146_4613_1(sec_r001146_1_2, sec_r001146_2_2, pub_r001146_3_2, pub_r001146_4_2);
  fn_R001146_4613_1_2(sec_r001146_1_1, sec_r001146_2_1, pub_r001146_3_1, pub_r001146_4_1, sec_r001146_1_2, sec_r001146_2_2, pub_r001146_3_2, pub_r001146_4_2);
  int helper_flow_2_1 = fn_R001146_4613_2(sec_r001146_2_1, sec_r001146_3_1);
  int helper_flow_2_2 = fn_R001146_4613_2(sec_r001146_2_2, sec_r001146_3_2);
  fn_R001146_4613_2_2(sec_r001146_2_1, sec_r001146_3_1, sec_r001146_2_2, sec_r001146_3_2);
  int helper_flow_3_1 = fn_R001146_4613_3(sec_r001146_3_1, pub_r001146_4_1, pub_r001146_5_1, pub_r001146_6_1);
  int helper_flow_3_2 = fn_R001146_4613_3(sec_r001146_3_2, pub_r001146_4_2, pub_r001146_5_2, pub_r001146_6_2);
  fn_R001146_4613_3_2(sec_r001146_3_1, pub_r001146_4_1, pub_r001146_5_1, pub_r001146_6_1, sec_r001146_3_2, pub_r001146_4_2, pub_r001146_5_2, pub_r001146_6_2);
  int helper_flow_4_1 = fn_R001146_4613_4(sec_r001146_4_1, pub_r001146_5_1, pub_r001146_6_1, pub_r001146_7_1);
  int helper_flow_4_2 = fn_R001146_4613_4(sec_r001146_4_2, pub_r001146_5_2, pub_r001146_6_2, pub_r001146_7_2);
  fn_R001146_4613_4_2(sec_r001146_4_1, pub_r001146_5_1, pub_r001146_6_1, pub_r001146_7_1, sec_r001146_4_2, pub_r001146_5_2, pub_r001146_6_2, pub_r001146_7_2);
  int helper_flow_5_1 = fn_R001146_4613_5(sec_r001146_5_1, pub_r001146_6_1);
  int helper_flow_5_2 = fn_R001146_4613_5(sec_r001146_5_2, pub_r001146_6_2);
  fn_R001146_4613_5_2(sec_r001146_5_1, pub_r001146_6_1, sec_r001146_5_2, pub_r001146_6_2);
  int helper_flow_6_1 = fn_R001146_4613_6(sec_r001146_6_1, sec_r001146_7_1, pub_r001146_8_1, pub_r001146_9_1, pub_r001146_10_1);
  int helper_flow_6_2 = fn_R001146_4613_6(sec_r001146_6_2, sec_r001146_7_2, pub_r001146_8_2, pub_r001146_9_2, pub_r001146_10_2);
  fn_R001146_4613_6_2(sec_r001146_6_1, sec_r001146_7_1, pub_r001146_8_1, pub_r001146_9_1, pub_r001146_10_1, sec_r001146_6_2, sec_r001146_7_2, pub_r001146_8_2, pub_r001146_9_2, pub_r001146_10_2);
  int helper_flow_7_1 = fn_R001146_4613_7(sec_r001146_7_1, sec_r001146_8_1, pub_r001146_9_1, pub_r001146_10_1, pub_r001146_11_1);
  int helper_flow_7_2 = fn_R001146_4613_7(sec_r001146_7_2, sec_r001146_8_2, pub_r001146_9_2, pub_r001146_10_2, pub_r001146_11_2);
  fn_R001146_4613_7_2(sec_r001146_7_1, sec_r001146_8_1, pub_r001146_9_1, pub_r001146_10_1, pub_r001146_11_1, sec_r001146_7_2, sec_r001146_8_2, pub_r001146_9_2, pub_r001146_10_2, pub_r001146_11_2);
  int stage_v_0_1 = ((sec_r001146_5_1 + (pub_r001146_8_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001146_5_2 + (pub_r001146_8_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001146_0_1 + (pub_r001146_16_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001146_0_2 + (pub_r001146_16_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001146_0_1 * 2) + 22) & 63;
  int stage_v_2_2 = ((pub_r001146_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((stage_v_0_1 + (pub_r001146_4_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((stage_v_0_2 + (pub_r001146_4_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001146_14_1 * 2) + 50) & 63;
  int stage_v_4_2 = ((pub_r001146_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_3_1 + (pub_r001146_21_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_3_2 + (pub_r001146_21_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001146_9_1 * 2) + 15) & 63;
  int stage_v_6_2 = ((pub_r001146_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001146_11_1 * 2) + 20) & 63;
  int stage_v_7_2 = ((pub_r001146_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001146_22_1 + (pub_r001146_1_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001146_22_2 + (pub_r001146_1_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((helper_flow_5_1 + (pub_r001146_19_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((helper_flow_5_2 + (pub_r001146_19_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((sec_r001146_14_1 + (pub_r001146_20_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001146_14_2 + (pub_r001146_20_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001146_11_1 + (pub_r001146_18_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001146_11_2 + (pub_r001146_18_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001146_9_1 + (pub_r001146_12_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001146_9_2 + (pub_r001146_12_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001146_17_1 * 2) + 7) & 63;
  int stage_v_13_2 = ((pub_r001146_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001146_6_1 + (pub_r001146_19_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001146_6_2 + (pub_r001146_19_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001146_5_1 * 2) + 38) & 63;
  int stage_v_15_2 = ((pub_r001146_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((helper_flow_6_1 + (pub_r001146_17_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((helper_flow_6_2 + (pub_r001146_17_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001146_21_1 + (pub_r001146_22_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001146_21_2 + (pub_r001146_22_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001146_18_1 * 2) + 28) & 63;
  int stage_v_18_2 = ((pub_r001146_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001146_11_1 * 2) + 20) & 63;
  int stage_v_19_2 = ((pub_r001146_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001146_15_1 * 2) + 24) & 63;
  int stage_v_20_2 = ((pub_r001146_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001146_15_1 * 2) + 39) & 63;
  int stage_v_21_2 = ((pub_r001146_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((stage_v_5_1 + (pub_r001146_14_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_5_2 + (pub_r001146_14_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((sec_r001146_19_1 + (pub_r001146_7_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001146_19_2 + (pub_r001146_7_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_0_1 + (pub_r001146_15_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_0_2 + (pub_r001146_15_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_5_1 + (pub_r001146_10_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_5_2 + (pub_r001146_10_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((sec_r001146_20_1 + (pub_r001146_17_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001146_20_2 + (pub_r001146_17_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((helper_flow_4_1 + (pub_r001146_14_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((helper_flow_4_2 + (pub_r001146_14_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001146_12_1 * 2) + 17) & 63;
  int stage_v_28_2 = ((pub_r001146_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((stage_v_12_1 + (pub_r001146_8_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_12_2 + (pub_r001146_8_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001146_1_1 + (pub_r001146_3_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001146_1_2 + (pub_r001146_3_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001146_1_1 * 2) + 48) & 63;
  int stage_v_31_2 = ((pub_r001146_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((helper_flow_6_1 + (pub_r001146_11_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((helper_flow_6_2 + (pub_r001146_11_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_17_1 + (pub_r001146_5_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_17_2 + (pub_r001146_5_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_16_1 + (pub_r001146_11_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_16_2 + (pub_r001146_11_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((pub_r001146_1_1 * 2) + 38) & 63;
  int stage_v_35_2 = ((pub_r001146_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001146_21_1 * 2) + 49) & 63;
  int stage_v_36_2 = ((pub_r001146_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_11_1 + (pub_r001146_22_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_11_2 + (pub_r001146_22_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001146_18_1 * 2) + 39) & 63;
  int stage_v_38_2 = ((pub_r001146_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001146_17_1 * 2) + 24) & 63;
  int stage_v_39_2 = ((pub_r001146_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((helper_flow_4_1 + (pub_r001146_1_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((helper_flow_4_2 + (pub_r001146_1_2 * 2)) + 125) & 127;
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
  int stage_v_41_1 = ((stage_v_16_1 + (pub_r001146_12_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_16_2 + (pub_r001146_12_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((sec_r001146_21_1 + (pub_r001146_8_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001146_21_2 + (pub_r001146_8_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001146_16_1 * 2) + 43) & 63;
  int stage_v_43_2 = ((pub_r001146_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((helper_flow_2_1 + (pub_r001146_5_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((helper_flow_2_2 + (pub_r001146_5_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001146_20_1 + (pub_r001146_0_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001146_20_2 + (pub_r001146_0_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_14_1 + (pub_r001146_1_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_14_2 + (pub_r001146_1_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001146_0_1 * 2) + 9) & 63;
  int stage_v_47_2 = ((pub_r001146_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_26_1 + (pub_r001146_2_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_26_2 + (pub_r001146_2_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((pub_r001146_22_1 * 2) + 7) & 63;
  int stage_v_49_2 = ((pub_r001146_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001146_21_1 * 2) + 7) & 63;
  int stage_v_50_2 = ((pub_r001146_21_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001146_1_1 * 2) + 47) & 63;
  int stage_v_51_2 = ((pub_r001146_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((sec_r001146_17_1 + (pub_r001146_14_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001146_17_2 + (pub_r001146_14_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001146_4_1 * 2) + 7) & 63;
  int stage_v_53_2 = ((pub_r001146_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_11_1 + (pub_r001146_18_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_11_2 + (pub_r001146_18_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001146_15_1 * 2) + 9) & 63;
  int stage_v_55_2 = ((pub_r001146_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001146_4_1 * 2) + 50) & 63;
  int stage_v_56_2 = ((pub_r001146_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_12_1 + (pub_r001146_20_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_12_2 + (pub_r001146_20_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_33_1 + (pub_r001146_19_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_33_2 + (pub_r001146_19_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001146_4_1 * 2) + 45) & 63;
  int stage_v_59_2 = ((pub_r001146_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001146_14_1 * 2) + 5) & 63;
  int stage_v_60_2 = ((pub_r001146_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((sec_r001146_13_1 + (pub_r001146_12_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001146_13_2 + (pub_r001146_12_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001146_17_1 * 2) + 18) & 63;
  int stage_v_62_2 = ((pub_r001146_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001146_20_1 * 2) + 29) & 63;
  int stage_v_63_2 = ((pub_r001146_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001146_1_1 + (pub_r001146_5_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001146_1_2 + (pub_r001146_5_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001146_20_1 + (pub_r001146_22_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001146_20_2 + (pub_r001146_22_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((sec_r001146_5_1 + (pub_r001146_21_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((sec_r001146_5_2 + (pub_r001146_21_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_45_1 + (pub_r001146_2_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_45_2 + (pub_r001146_2_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001146_9_1 * 2) + 24) & 63;
  int stage_v_68_2 = ((pub_r001146_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001146_15_1 * 2) + 25) & 63;
  int stage_v_69_2 = ((pub_r001146_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_42_1 + (pub_r001146_11_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_42_2 + (pub_r001146_11_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_29_1 + (pub_r001146_15_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_29_2 + (pub_r001146_15_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_64_1 + (pub_r001146_15_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_64_2 + (pub_r001146_15_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001146_2_1 * 2) + 29) & 63;
  int stage_v_73_2 = ((pub_r001146_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001146_15_1 * 2) + 12) & 63;
  int stage_v_74_2 = ((pub_r001146_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001146_17_1 * 2) + 42) & 63;
  int stage_v_75_2 = ((pub_r001146_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((helper_flow_4_1 + (pub_r001146_11_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((helper_flow_4_2 + (pub_r001146_11_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((helper_flow_2_1 + (pub_r001146_1_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_2_2 + (pub_r001146_1_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_32_1 + (pub_r001146_10_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_32_2 + (pub_r001146_10_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001146_8_1 * 2) + 18) & 63;
  int stage_v_79_2 = ((pub_r001146_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_52_1 + (pub_r001146_5_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_52_2 + (pub_r001146_5_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((sec_r001146_7_1 + (pub_r001146_2_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((sec_r001146_7_2 + (pub_r001146_2_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001146_20_1 * 2) + 37) & 63;
  int stage_v_82_2 = ((pub_r001146_20_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((stage_v_48_1 + (pub_r001146_20_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_48_2 + (pub_r001146_20_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((helper_flow_2_1 + (pub_r001146_15_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((helper_flow_2_2 + (pub_r001146_15_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_57_1 + (pub_r001146_10_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_57_2 + (pub_r001146_10_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001146_20_1 * 2) + 31) & 63;
  int stage_v_86_2 = ((pub_r001146_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001146_15_1 * 2) + 11) & 63;
  int stage_v_87_2 = ((pub_r001146_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001146_22_1 * 2) + 47) & 63;
  int stage_v_88_2 = ((pub_r001146_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001146_22_1 * 2) + 13) & 63;
  int stage_v_89_2 = ((pub_r001146_22_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((sec_r001146_7_1 + (pub_r001146_6_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((sec_r001146_7_2 + (pub_r001146_6_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_14_1 + (pub_r001146_22_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_14_2 + (pub_r001146_22_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_52_1 + (pub_r001146_4_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_52_2 + (pub_r001146_4_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((helper_flow_4_1 + (pub_r001146_11_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((helper_flow_4_2 + (pub_r001146_11_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((sec_r001146_5_1 + (pub_r001146_12_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001146_5_2 + (pub_r001146_12_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((sec_r001146_6_1 + (pub_r001146_22_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((sec_r001146_6_2 + (pub_r001146_22_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001146_17_1 + (pub_r001146_13_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001146_17_2 + (pub_r001146_13_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001146_1_1 * 2) + 49) & 63;
  int stage_v_97_2 = ((pub_r001146_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001146_12_1 * 2) + 27) & 63;
  int stage_v_98_2 = ((pub_r001146_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_80_1 + (pub_r001146_16_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_80_2 + (pub_r001146_16_2 * 2)) + 302) & 127;
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
  int stage_v_100_1 = ((sec_r001146_7_1 + (pub_r001146_13_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((sec_r001146_7_2 + (pub_r001146_13_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((sec_r001146_10_1 + (pub_r001146_8_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((sec_r001146_10_2 + (pub_r001146_8_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_46_1 + (pub_r001146_12_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_46_2 + (pub_r001146_12_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_27_1 + (pub_r001146_17_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_27_2 + (pub_r001146_17_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_94_1 + (pub_r001146_19_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_94_2 + (pub_r001146_19_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_91_1 + (pub_r001146_19_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_91_2 + (pub_r001146_19_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001146_8_1 * 2) + 20) & 63;
  int stage_v_106_2 = ((pub_r001146_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001146_21_1 * 2) + 21) & 63;
  int stage_v_107_2 = ((pub_r001146_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_12_1 + (pub_r001146_1_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_12_2 + (pub_r001146_1_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_83_1 + (pub_r001146_2_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_83_2 + (pub_r001146_2_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001146_10_1 * 2) + 34) & 63;
  int stage_v_110_2 = ((pub_r001146_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001146_2_1 * 2) + 16) & 63;
  int stage_v_111_2 = ((pub_r001146_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((stage_v_14_1 + (pub_r001146_17_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_14_2 + (pub_r001146_17_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_100_1 + (pub_r001146_5_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_100_2 + (pub_r001146_5_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_14_1 + (pub_r001146_2_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_14_2 + (pub_r001146_2_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((sec_r001146_22_1 + (pub_r001146_4_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((sec_r001146_22_2 + (pub_r001146_4_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((pub_r001146_16_1 * 2) + 18) & 63;
  int stage_v_116_2 = ((pub_r001146_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001146_17_1 * 2) + 8) & 63;
  int stage_v_117_2 = ((pub_r001146_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001146_2_1 * 2) + 20) & 63;
  int stage_v_118_2 = ((pub_r001146_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((stage_v_93_1 + (pub_r001146_4_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_93_2 + (pub_r001146_4_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001146_7_1 + (pub_r001146_17_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001146_7_2 + (pub_r001146_17_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((sec_r001146_21_1 + (pub_r001146_5_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((sec_r001146_21_2 + (pub_r001146_5_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((pub_r001146_8_1 * 2) + 49) & 63;
  int stage_v_122_2 = ((pub_r001146_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((stage_v_76_1 + (pub_r001146_8_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_76_2 + (pub_r001146_8_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_112_1 + (pub_r001146_14_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_112_2 + (pub_r001146_14_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((helper_flow_2_1 + (pub_r001146_22_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((helper_flow_2_2 + (pub_r001146_22_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((sec_r001146_10_1 + (pub_r001146_12_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((sec_r001146_10_2 + (pub_r001146_12_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001146_1_1 * 2) + 18) & 63;
  int stage_v_127_2 = ((pub_r001146_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((sec_r001146_9_1 + (pub_r001146_2_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((sec_r001146_9_2 + (pub_r001146_2_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001146_18_1 * 2) + 5) & 63;
  int stage_v_129_2 = ((pub_r001146_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_99_1 + (pub_r001146_12_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_99_2 + (pub_r001146_12_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_61_1 + (pub_r001146_19_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_61_2 + (pub_r001146_19_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_23_1 + (pub_r001146_10_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_23_2 + (pub_r001146_10_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001146_3_1 * 2) + 48) & 63;
  int stage_v_133_2 = ((pub_r001146_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001146_2_1 * 2) + 22) & 63;
  int stage_v_134_2 = ((pub_r001146_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001146_2_1 * 2) + 12) & 63;
  int stage_v_135_2 = ((pub_r001146_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_120_1 + (pub_r001146_9_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_120_2 + (pub_r001146_9_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_41_1 + (pub_r001146_15_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_41_2 + (pub_r001146_15_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_42_1 + (pub_r001146_13_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_42_2 + (pub_r001146_13_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((sec_r001146_13_1 + (pub_r001146_4_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001146_13_2 + (pub_r001146_4_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_80_1 + (pub_r001146_1_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_80_2 + (pub_r001146_1_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_132_1 + (pub_r001146_1_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_132_2 + (pub_r001146_1_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_115_1 + (pub_r001146_3_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_115_2 + (pub_r001146_3_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001146_12_1 * 2) + 30) & 63;
  int stage_v_143_2 = ((pub_r001146_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001146_19_1 * 2) + 33) & 63;
  int stage_v_144_2 = ((pub_r001146_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_24_1 + (pub_r001146_0_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_24_2 + (pub_r001146_0_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_96_1 + (pub_r001146_6_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_96_2 + (pub_r001146_6_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_3_1 + (pub_r001146_20_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_3_2 + (pub_r001146_20_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((sec_r001146_9_1 + (pub_r001146_16_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((sec_r001146_9_2 + (pub_r001146_16_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((sec_r001146_0_1 + (pub_r001146_5_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((sec_r001146_0_2 + (pub_r001146_5_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_1_1 + (pub_r001146_4_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_1_2 + (pub_r001146_4_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_91_1 + (pub_r001146_6_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_91_2 + (pub_r001146_6_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_121_1 + (pub_r001146_21_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_121_2 + (pub_r001146_21_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_81_1 + (pub_r001146_15_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_81_2 + (pub_r001146_15_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((helper_flow_3_1 + (pub_r001146_8_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((helper_flow_3_2 + (pub_r001146_8_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_119_1 + (pub_r001146_13_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_119_2 + (pub_r001146_13_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_17_1 + (pub_r001146_11_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_17_2 + (pub_r001146_11_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001146_7_1 * 2) + 46) & 63;
  int stage_v_157_2 = ((pub_r001146_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_154_1 + (pub_r001146_4_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_154_2 + (pub_r001146_4_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001146_10_1 * 2) + 5) & 63;
  int stage_v_159_2 = ((pub_r001146_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((helper_flow_4_1 + (pub_r001146_6_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((helper_flow_4_2 + (pub_r001146_6_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((sec_r001146_22_1 + (pub_r001146_3_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((sec_r001146_22_2 + (pub_r001146_3_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001146_20_1 * 2) + 18) & 63;
  int stage_v_162_2 = ((pub_r001146_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((helper_flow_7_1 + (pub_r001146_12_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((helper_flow_7_2 + (pub_r001146_12_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_108_1 + (pub_r001146_11_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_108_2 + (pub_r001146_11_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001146_8_1 * 2) + 44) & 63;
  int stage_v_165_2 = ((pub_r001146_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001146_16_1 * 2) + 24) & 63;
  int stage_v_166_2 = ((pub_r001146_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001146_21_1 * 2) + 40) & 63;
  int stage_v_167_2 = ((pub_r001146_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((sec_r001146_4_1 + (pub_r001146_12_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((sec_r001146_4_2 + (pub_r001146_12_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((sec_r001146_0_1 + (pub_r001146_4_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((sec_r001146_0_2 + (pub_r001146_4_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_16_1 + (pub_r001146_22_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_16_2 + (pub_r001146_22_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001146_1_1 * 2) + 31) & 63;
  int stage_v_171_2 = ((pub_r001146_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_64_1 + (pub_r001146_20_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_64_2 + (pub_r001146_20_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_70_1 + (pub_r001146_16_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_70_2 + (pub_r001146_16_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_70_1 + (pub_r001146_19_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_70_2 + (pub_r001146_19_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_131_1 + (pub_r001146_5_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_131_2 + (pub_r001146_5_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_140_1 + (pub_r001146_17_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_140_2 + (pub_r001146_17_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001146_3_1 * 2) + 8) & 63;
  int stage_v_177_2 = ((pub_r001146_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((sec_r001146_7_1 + (pub_r001146_14_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((sec_r001146_7_2 + (pub_r001146_14_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_70_1 + (pub_r001146_15_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_70_2 + (pub_r001146_15_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((helper_flow_7_1 + (pub_r001146_0_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((helper_flow_7_2 + (pub_r001146_0_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001146_14_1 * 2) + 50) & 63;
  int stage_v_181_2 = ((pub_r001146_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_153_1 + (pub_r001146_5_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_153_2 + (pub_r001146_5_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_90_1 + (pub_r001146_5_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_90_2 + (pub_r001146_5_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((sec_r001146_4_1 + (pub_r001146_21_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((sec_r001146_4_2 + (pub_r001146_21_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((sec_r001146_2_1 + (pub_r001146_4_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((sec_r001146_2_2 + (pub_r001146_4_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((sec_r001146_21_1 + (pub_r001146_8_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((sec_r001146_21_2 + (pub_r001146_8_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((pub_r001146_15_1 * 2) + 32) & 63;
  int stage_v_187_2 = ((pub_r001146_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001146_20_1 * 2) + 36) & 63;
  int stage_v_188_2 = ((pub_r001146_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((sec_r001146_0_1 + (pub_r001146_18_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((sec_r001146_0_2 + (pub_r001146_18_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_3_1 + (pub_r001146_3_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_3_2 + (pub_r001146_3_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_113_1 + (pub_r001146_4_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_113_2 + (pub_r001146_4_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001146_22_1 * 2) + 16) & 63;
  int stage_v_192_2 = ((pub_r001146_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_8_1 + (pub_r001146_12_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_8_2 + (pub_r001146_12_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_24_1 + (pub_r001146_11_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_24_2 + (pub_r001146_11_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_112_1 + (pub_r001146_15_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_112_2 + (pub_r001146_15_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_9_1 + (pub_r001146_7_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_9_2 + (pub_r001146_7_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_33_1 + (pub_r001146_12_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_33_2 + (pub_r001146_12_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001146_0_1 * 2) + 40) & 63;
  int stage_v_198_2 = ((pub_r001146_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_1_1 + (pub_r001146_13_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_1_2 + (pub_r001146_13_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_67_1 + (pub_r001146_14_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_67_2 + (pub_r001146_14_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001146_19_1 * 2) + 31) & 63;
  int stage_v_201_2 = ((pub_r001146_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_182_1 + (pub_r001146_6_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_182_2 + (pub_r001146_6_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((sec_r001146_3_1 + (pub_r001146_0_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001146_3_2 + (pub_r001146_0_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_169_1 + (pub_r001146_3_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_169_2 + (pub_r001146_3_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_112_1 + (pub_r001146_15_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_112_2 + (pub_r001146_15_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001146_19_1 * 2) + 12) & 63;
  int stage_v_206_2 = ((pub_r001146_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001146_10_1 * 2) + 39) & 63;
  int stage_v_207_2 = ((pub_r001146_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001146_20_1 * 2) + 10) & 63;
  int stage_v_208_2 = ((pub_r001146_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_149_1 + (pub_r001146_5_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_149_2 + (pub_r001146_5_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001146_7_1 * 2) + 39) & 63;
  int stage_v_210_2 = ((pub_r001146_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((sec_r001146_14_1 + (pub_r001146_13_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((sec_r001146_14_2 + (pub_r001146_13_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_42_1 + (pub_r001146_8_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_42_2 + (pub_r001146_8_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((pub_r001146_5_1 * 2) + 40) & 63;
  int stage_v_213_2 = ((pub_r001146_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((helper_flow_3_1 + (pub_r001146_0_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((helper_flow_3_2 + (pub_r001146_0_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001146_20_1 * 2) + 28) & 63;
  int stage_v_215_2 = ((pub_r001146_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_149_1 + (pub_r001146_15_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_149_2 + (pub_r001146_15_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_185_1 + (pub_r001146_6_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_185_2 + (pub_r001146_6_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((pub_r001146_7_1 * 2) + 50) & 63;
  int stage_v_218_2 = ((pub_r001146_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001146_8_1 * 2) + 13) & 63;
  int stage_v_219_2 = ((pub_r001146_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001146_16_1 * 2) + 5) & 63;
  int stage_v_220_2 = ((pub_r001146_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_77_1 + (pub_r001146_1_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_77_2 + (pub_r001146_1_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((pub_r001146_8_1 * 2) + 13) & 63;
  int stage_v_222_2 = ((pub_r001146_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((stage_v_57_1 + (pub_r001146_3_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_57_2 + (pub_r001146_3_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((sec_r001146_19_1 + (pub_r001146_15_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((sec_r001146_19_2 + (pub_r001146_15_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001146_20_1 == pub_r001146_20_2);
  __CPROVER_assume(pub_r001146_19_1 == pub_r001146_19_2);
  __CPROVER_assume(sec_r001146_22_1 != sec_r001146_22_2);
  __CPROVER_assume(sec_r001146_7_1 != sec_r001146_7_2);
  __CPROVER_assume(sec_r001146_3_1 != sec_r001146_3_2);
  __CPROVER_assume(pub_r001146_14_1 == pub_r001146_14_2);
  __CPROVER_assume(sec_r001146_10_1 != sec_r001146_10_2);
  __CPROVER_assume(sec_r001146_4_1 != sec_r001146_4_2);
  __CPROVER_assume(pub_r001146_7_1 == pub_r001146_7_2);
  __CPROVER_assume(pub_r001146_8_1 == pub_r001146_8_2);
  __CPROVER_assume(pub_r001146_18_1 == pub_r001146_18_2);
  __CPROVER_assume(sec_r001146_14_1 != sec_r001146_14_2);
  __CPROVER_assume(pub_r001146_6_1 == pub_r001146_6_2);
  __CPROVER_assume(pub_r001146_2_1 == pub_r001146_2_2);
  __CPROVER_assume(pub_r001146_13_1 == pub_r001146_13_2);
  __CPROVER_assume(sec_r001146_0_1 != sec_r001146_0_2);
  __CPROVER_assume(pub_r001146_3_1 == pub_r001146_3_2);
  __CPROVER_assume(sec_r001146_6_1 != sec_r001146_6_2);
  __CPROVER_assume(pub_r001146_22_1 == pub_r001146_22_2);
  __CPROVER_assume(sec_r001146_8_1 != sec_r001146_8_2);
  __CPROVER_assume(sec_r001146_5_1 != sec_r001146_5_2);
  __CPROVER_assume(sec_r001146_12_1 != sec_r001146_12_2);
  __CPROVER_assume(sec_r001146_16_1 != sec_r001146_16_2);
  __CPROVER_assume(pub_r001146_17_1 == pub_r001146_17_2);
  __CPROVER_assume(sec_r001146_2_1 != sec_r001146_2_2);
  __CPROVER_assume(pub_r001146_12_1 == pub_r001146_12_2);
  __CPROVER_assume(sec_r001146_9_1 != sec_r001146_9_2);
  __CPROVER_assume(pub_r001146_9_1 == pub_r001146_9_2);
  __CPROVER_assume(pub_r001146_10_1 == pub_r001146_10_2);
  __CPROVER_assume(sec_r001146_13_1 != sec_r001146_13_2);
  __CPROVER_assume(sec_r001146_11_1 != sec_r001146_11_2);
  __CPROVER_assume(sec_r001146_17_1 != sec_r001146_17_2);
  __CPROVER_assume(pub_r001146_11_1 == pub_r001146_11_2);
  __CPROVER_assume(pub_r001146_16_1 == pub_r001146_16_2);
  __CPROVER_assume(sec_r001146_15_1 != sec_r001146_15_2);
  __CPROVER_assume(sec_r001146_1_1 != sec_r001146_1_2);
  __CPROVER_assume(sec_r001146_20_1 != sec_r001146_20_2);
  __CPROVER_assume(pub_r001146_1_1 == pub_r001146_1_2);
  __CPROVER_assume(pub_r001146_21_1 == pub_r001146_21_2);
  __CPROVER_assume(pub_r001146_15_1 == pub_r001146_15_2);
  __CPROVER_assume(pub_r001146_4_1 == pub_r001146_4_2);
  __CPROVER_assume(pub_r001146_0_1 == pub_r001146_0_2);
  __CPROVER_assume(sec_r001146_18_1 != sec_r001146_18_2);
  __CPROVER_assume(sec_r001146_21_1 != sec_r001146_21_2);
  __CPROVER_assume(pub_r001146_5_1 == pub_r001146_5_2);
  __CPROVER_assume(sec_r001146_19_1 != sec_r001146_19_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
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
}


