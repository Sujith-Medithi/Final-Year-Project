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
struct EventLog_R001840_4013_0
{
  int severity;
  int signature;
  int code;
  unsigned char timestamp;
  int seq;
  int facility;
  int buffer[3];
};
struct FilterState_R001840_4013_1
{
  int mode;
  int damping;
  int prev_out;
  short gain_db;
  int prev_in;
  int buffer[3];
};
struct DeviceConfig_R001840_4013_2
{
  int timeout;
  unsigned char parity;
  unsigned char stop_bits;
  int port;
  unsigned char baud_rate;
  int buffer[3];
};
union RegisterBank_R001840_4013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001840_4013_1
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
void fn_R001840_4013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_57_1 > 25)
  {
    acc_1 = ((acc_1 + (tally_57_1 * 2)) + 5) & 127;
    aux_1 ^= tally_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_57_2 > 25)
  {
    acc_2 = ((acc_2 + (tally_57_2 * 2)) + 5) & 127;
    aux_2 ^= tally_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_57_1 == tally_57_2);
}

int fn_R001840_4013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_57 > 25)
  {
    acc = ((acc + (tally_57 * 2)) + 5) & 127;
    aux ^= tally_57 & 15;
  }
  else
  {
    acc = ((acc - tally_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001840_4013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int index_reg_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_56_1)
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

  switch (index_reg_56_2)
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

  int index_reg_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_35_1 > 34)
  {
    acc_1 = ((acc_1 + (index_reg_35_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_35_2 > 34)
  {
    acc_2 = ((acc_2 + (index_reg_35_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_45_1 = local_arr_1[aux_1 % 3];
  int anchor_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_45_2 * 2)) & 127;
  int tracker_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_92_1) & 63;
  aux_2 = (aux_2 + tracker_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
  assert(index_reg_35_1 == index_reg_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_45_1 == anchor_45_2);
  assert(tracker_92_1 == tracker_92_2);
}

int fn_R001840_4013_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int index_reg_56 = (aux + st.buffer[1]) & 3;
  switch (index_reg_56)
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

  int index_reg_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_35 > 34)
  {
    acc = ((acc + (index_reg_35 * 2)) + 5) & 127;
    aux ^= index_reg_35 & 15;
  }
  else
  {
    acc = ((acc - index_reg_35) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_45 = local_arr[aux % 3];
  acc = (acc + (anchor_45 * 2)) & 127;
  int tracker_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001840_4013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st_1 = {0};
  struct DeviceConfig_R001840_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tracker_43_1 = 0;
  int tracker_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_43_1 = ((tracker_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_43_2 = ((tracker_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_43_1) & 127;
    acc_2 = (acc_2 + tracker_43_2) & 127;
  }

  int quotient_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_82_1) & 63;
  aux_2 = (aux_2 + quotient_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_17_1 > 41)
  {
    acc_1 = ((acc_1 + (offset_17_1 * 2)) + 5) & 127;
    aux_1 ^= offset_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_17_2 > 41)
  {
    acc_2 = ((acc_2 + (offset_17_2 * 2)) + 5) & 127;
    aux_2 ^= offset_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_17_1)
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

  switch (delta_17_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_43_1 == tracker_43_2);
  assert(quotient_82_1 == quotient_82_2);
  assert(offset_17_1 == offset_17_2);
  assert(delta_17_1 == delta_17_2);
}

int fn_R001840_4013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tracker_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_43 = ((tracker_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_43) & 127;
  }

  int quotient_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_82) & 63;
  acc ^= aux;
  int offset_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_17 > 41)
  {
    acc = ((acc + (offset_17 * 2)) + 5) & 127;
    aux ^= offset_17 & 15;
  }
  else
  {
    acc = ((acc - offset_17) + 11) & 127;
    aux += 3;
  }
  int delta_17 = (aux + st.buffer[1]) & 3;
  switch (delta_17)
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

void fn_R001840_4013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st_1 = {0};
  struct DeviceConfig_R001840_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int bound_35_1 = 0;
  int bound_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_35_1 = ((bound_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_35_2 = ((bound_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_35_1) & 127;
    acc_2 = (acc_2 + bound_35_2) & 127;
  }

  int tally_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_43_1)
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

  switch (tally_43_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_35_1 == bound_35_2);
  assert(tally_43_1 == tally_43_2);
}

int fn_R001840_4013_3(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int bound_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_35 = ((bound_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_35) & 127;
  }

  int tally_43 = (aux + st.buffer[1]) & 3;
  switch (tally_43)
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

void fn_R001840_4013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int bound_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_42_1 > 19)
  {
    acc_1 = ((acc_1 + (bound_42_1 * 2)) + 5) & 127;
    aux_1 ^= bound_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_42_2 > 19)
  {
    acc_2 = ((acc_2 + (bound_42_2 * 2)) + 5) & 127;
    aux_2 ^= bound_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_10_1 = 0;
  int weight_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_10_1 = ((weight_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_10_2 = ((weight_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_10_1) & 127;
    acc_2 = (acc_2 + weight_10_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_42_1 == bound_42_2);
  assert(weight_10_1 == weight_10_2);
}

int fn_R001840_4013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int bound_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_42 > 19)
  {
    acc = ((acc + (bound_42 * 2)) + 5) & 127;
    aux ^= bound_42 & 15;
  }
  else
  {
    acc = ((acc - bound_42) + 11) & 127;
    aux += 3;
  }
  int weight_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_10 = ((weight_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_10) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st_1 = {0};
  struct DeviceConfig_R001840_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int index_reg_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_45_1) & 63;
  aux_2 = (aux_2 + index_reg_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_45_1 == index_reg_45_2);
}

int fn_R001840_4013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int index_reg_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_54_1) & 63;
  aux_2 = (aux_2 + pivot_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_54_1 == pivot_54_2);
}

int fn_R001840_4013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_54) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
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
  int index_reg_48_1 = local_arr_1[aux_1 % 3];
  int index_reg_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_48_2 * 2)) & 127;
  int segment_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_49_1) & 63;
  aux_2 = (aux_2 + segment_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_12_1 > 15)
  {
    acc_1 = ((acc_1 + (metric_12_1 * 2)) + 5) & 127;
    aux_1 ^= metric_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_12_2 > 15)
  {
    acc_2 = ((acc_2 + (metric_12_2 * 2)) + 5) & 127;
    aux_2 ^= metric_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_48_1 == index_reg_48_2);
  assert(segment_49_1 == segment_49_2);
  assert(metric_12_1 == metric_12_2);
}

int fn_R001840_4013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_48 = local_arr[aux % 3];
  acc = (acc + (index_reg_48 * 2)) & 127;
  int segment_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_49) & 63;
  acc ^= aux;
  int metric_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_12 > 15)
  {
    acc = ((acc + (metric_12 * 2)) + 5) & 127;
    aux ^= metric_12 & 15;
  }
  else
  {
    acc = ((acc - metric_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001840_4013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_26_1 = local_arr_1[aux_1 % 3];
  int damping_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_26_2 * 2)) & 127;
  int residue_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_84_1) & 63;
  aux_2 = (aux_2 + residue_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_26_1 == damping_26_2);
  assert(residue_84_1 == residue_84_2);
}

int fn_R001840_4013_8(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int damping_26 = local_arr[aux % 3];
  acc = (acc + (damping_26 * 2)) & 127;
  int residue_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001840_4013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_75_1) & 63;
  aux_2 = (aux_2 + offset_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_26_1 = 0;
  int anchor_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_26_1 = ((anchor_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_26_2 = ((anchor_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_26_1) & 127;
    acc_2 = (acc_2 + anchor_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_75_1 == offset_75_2);
  assert(anchor_26_1 == anchor_26_2);
}

int fn_R001840_4013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_26 = ((anchor_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001840_4013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_51_1)
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

  switch (quotient_51_2)
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

  int bound_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_19_1 > 19)
  {
    acc_1 = ((acc_1 + (bound_19_1 * 2)) + 5) & 127;
    aux_1 ^= bound_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_19_2 > 19)
  {
    acc_2 = ((acc_2 + (bound_19_2 * 2)) + 5) & 127;
    aux_2 ^= bound_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_27_1 = 0;
  int metric_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_27_1 = ((metric_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_27_2 = ((metric_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_27_1) & 127;
    acc_2 = (acc_2 + metric_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_51_1 == quotient_51_2);
  assert(bound_19_1 == bound_19_2);
  assert(metric_27_1 == metric_27_2);
}

int fn_R001840_4013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_51 = (aux + st.buffer[1]) & 3;
  switch (quotient_51)
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

  int bound_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_19 > 19)
  {
    acc = ((acc + (bound_19 * 2)) + 5) & 127;
    aux ^= bound_19 & 15;
  }
  else
  {
    acc = ((acc - bound_19) + 11) & 127;
    aux += 3;
  }
  int metric_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_27 = ((metric_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001840_4013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st_1 = {0};
  struct DeviceConfig_R001840_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_74_1 = local_arr_1[aux_1 % 3];
  int pivot_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_74_2 * 2)) & 127;
  int vector_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_92_1)
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

  switch (vector_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_22_1 > 40)
  {
    acc_1 = ((acc_1 + (scale_22_1 * 2)) + 5) & 127;
    aux_1 ^= scale_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_22_2 > 40)
  {
    acc_2 = ((acc_2 + (scale_22_2 * 2)) + 5) & 127;
    aux_2 ^= scale_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_74_1 == pivot_74_2);
  assert(vector_92_1 == vector_92_2);
  assert(scale_22_1 == scale_22_2);
}

int fn_R001840_4013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int pivot_74 = local_arr[aux % 3];
  acc = (acc + (pivot_74 * 2)) & 127;
  int vector_92 = (aux + st.buffer[1]) & 3;
  switch (vector_92)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_22 > 40)
  {
    acc = ((acc + (scale_22 * 2)) + 5) & 127;
    aux ^= scale_22 & 15;
  }
  else
  {
    acc = ((acc - scale_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001840_4013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int phase_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_52_1 > 45)
  {
    acc_1 = ((acc_1 + (phase_52_1 * 2)) + 5) & 127;
    aux_1 ^= phase_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_52_2 > 45)
  {
    acc_2 = ((acc_2 + (phase_52_2 * 2)) + 5) & 127;
    aux_2 ^= phase_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_48_1) & 63;
  aux_2 = (aux_2 + sample_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_15_1 = local_arr_1[aux_1 % 3];
  int segment_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_52_1 == phase_52_2);
  assert(sample_48_1 == sample_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_15_1 == segment_15_2);
}

int fn_R001840_4013_12(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int phase_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_52 > 45)
  {
    acc = ((acc + (phase_52 * 2)) + 5) & 127;
    aux ^= phase_52 & 15;
  }
  else
  {
    acc = ((acc - phase_52) + 11) & 127;
    aux += 3;
  }
  int sample_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_15 = local_arr[aux % 3];
  acc = (acc + (segment_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int segment_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_12_1 > 37)
  {
    acc_1 = ((acc_1 + (segment_12_1 * 2)) + 5) & 127;
    aux_1 ^= segment_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_12_2 > 37)
  {
    acc_2 = ((acc_2 + (segment_12_2 * 2)) + 5) & 127;
    aux_2 ^= segment_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_95_1) & 63;
  aux_2 = (aux_2 + window_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_56_1)
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

  switch (segment_56_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_12_1 == segment_12_2);
  assert(window_95_1 == window_95_2);
  assert(segment_56_1 == segment_56_2);
}

int fn_R001840_4013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int segment_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_12 > 37)
  {
    acc = ((acc + (segment_12 * 2)) + 5) & 127;
    aux ^= segment_12 & 15;
  }
  else
  {
    acc = ((acc - segment_12) + 11) & 127;
    aux += 3;
  }
  int window_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_95) & 63;
  acc ^= aux;
  int segment_56 = (aux + st.buffer[1]) & 3;
  switch (segment_56)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int damping_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_59_1) & 63;
  aux_2 = (aux_2 + damping_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_59_1 == damping_59_2);
}

int fn_R001840_4013_14(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int damping_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_59) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int scale_32_1 = 0;
  int scale_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_32_1 = ((scale_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_32_2 = ((scale_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_32_1) & 127;
    acc_2 = (acc_2 + scale_32_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_56_1 = local_arr_1[aux_1 % 3];
  int scale_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_32_1 == scale_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_56_1 == scale_56_2);
}

int fn_R001840_4013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int scale_32 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_32 = ((scale_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_32) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_56 = local_arr[aux % 3];
  acc = (acc + (scale_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st_1 = {0};
  struct DeviceConfig_R001840_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_67_1 = 0;
  int factor_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_67_1 = ((factor_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_67_2 = ((factor_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_67_1) & 127;
    acc_2 = (acc_2 + factor_67_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_67_1 == factor_67_2);
}

int fn_R001840_4013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001840_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_67 = ((factor_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_67) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int index_reg_46_1 = 0;
  int index_reg_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_46_1 = ((index_reg_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_46_2 = ((index_reg_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_46_1) & 127;
    acc_2 = (acc_2 + index_reg_46_2) & 127;
  }

  int cursor_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_27_1)
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

  switch (cursor_27_2)
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
  int margin_21_1 = local_arr_1[aux_1 % 3];
  int margin_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_46_1 == index_reg_46_2);
  assert(cursor_27_1 == cursor_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_21_1 == margin_21_2);
}

int fn_R001840_4013_17(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int index_reg_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_46 = ((index_reg_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_46) & 127;
  }

  int cursor_27 = (aux + st.buffer[1]) & 3;
  switch (cursor_27)
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
  int margin_21 = local_arr[aux % 3];
  acc = (acc + (margin_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_88_1 = local_arr_1[aux_1 % 3];
  int margin_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_88_2 * 2)) & 127;
  int threshold_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_20_1 > 15)
  {
    acc_1 = ((acc_1 + (threshold_20_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_20_2 > 15)
  {
    acc_2 = ((acc_2 + (threshold_20_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_88_1 == margin_88_2);
  assert(threshold_20_1 == threshold_20_2);
}

int fn_R001840_4013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int margin_88 = local_arr[aux % 3];
  acc = (acc + (margin_88 * 2)) & 127;
  int threshold_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_20 > 15)
  {
    acc = ((acc + (threshold_20 * 2)) + 5) & 127;
    aux ^= threshold_20 & 15;
  }
  else
  {
    acc = ((acc - threshold_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001840_4013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quantum_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_84_1) & 63;
  aux_2 = (aux_2 + quantum_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_43_1 = 0;
  int residue_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_43_1 = ((residue_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_43_2 = ((residue_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_43_1) & 127;
    acc_2 = (acc_2 + residue_43_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_15_1)
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

  switch (pivot_15_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_84_1 == quantum_84_2);
  assert(residue_43_1 == residue_43_2);
  assert(pivot_15_1 == pivot_15_2);
}

int fn_R001840_4013_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quantum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_84) & 63;
  acc ^= aux;
  int residue_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_43 = ((residue_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_43) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_15 = (aux + st.buffer[1]) & 3;
  switch (pivot_15)
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

void fn_R001840_4013_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int index_reg_78_1 = 0;
  int index_reg_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_78_1 = ((index_reg_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_78_2 = ((index_reg_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_78_1) & 127;
    acc_2 = (acc_2 + index_reg_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_16_1)
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

  switch (vector_16_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_78_1 == index_reg_78_2);
  assert(vector_16_1 == vector_16_2);
}

int fn_R001840_4013_20(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int index_reg_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_78 = ((index_reg_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_16 = (aux + st.buffer[1]) & 3;
  switch (vector_16)
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

void fn_R001840_4013_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_84_1 > 10)
  {
    acc_1 = ((acc_1 + (vector_84_1 * 2)) + 5) & 127;
    aux_1 ^= vector_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_84_2 > 10)
  {
    acc_2 = ((acc_2 + (vector_84_2 * 2)) + 5) & 127;
    aux_2 ^= vector_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_93_1 = 0;
  int tracker_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_93_1 = ((tracker_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_93_2 = ((tracker_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_93_1) & 127;
    acc_2 = (acc_2 + tracker_93_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_90_1 = local_arr_1[aux_1 % 3];
  int accumulator_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_84_1 == vector_84_2);
  assert(tracker_93_1 == tracker_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_90_1 == accumulator_90_2);
}

int fn_R001840_4013_21(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_84 > 10)
  {
    acc = ((acc + (vector_84 * 2)) + 5) & 127;
    aux ^= vector_84 & 15;
  }
  else
  {
    acc = ((acc - vector_84) + 11) & 127;
    aux += 3;
  }
  int tracker_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_93 = ((tracker_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_93) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int accumulator_90 = local_arr[aux % 3];
  acc = (acc + (accumulator_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001840_4013_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st_1 = {0};
  struct FilterState_R001840_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int metric_41_1 = 0;
  int metric_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_41_1 = ((metric_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_41_2 = ((metric_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_41_1) & 127;
    acc_2 = (acc_2 + metric_41_2) & 127;
  }

  int window_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_72_1 > 26)
  {
    acc_1 = ((acc_1 + (window_72_1 * 2)) + 5) & 127;
    aux_1 ^= window_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_72_2 > 26)
  {
    acc_2 = ((acc_2 + (window_72_2 * 2)) + 5) & 127;
    aux_2 ^= window_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_41_1 == metric_41_2);
  assert(window_72_1 == window_72_2);
}

int fn_R001840_4013_22(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001840_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int metric_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_41 = ((metric_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_41) & 127;
  }

  int window_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_72 > 26)
  {
    acc = ((acc + (window_72 * 2)) + 5) & 127;
    aux ^= window_72 & 15;
  }
  else
  {
    acc = ((acc - window_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001840_4013_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st_1 = {0};
  struct EventLog_R001840_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_78_1 = 0;
  int offset_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_78_1 = ((offset_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_78_2 = ((offset_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_78_1) & 127;
    acc_2 = (acc_2 + offset_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_15_1)
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

  switch (index_reg_15_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_78_1 == offset_78_2);
  assert(index_reg_15_1 == index_reg_15_2);
}

int fn_R001840_4013_23(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001840_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_78 = ((offset_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_15 = (aux + st.buffer[1]) & 3;
  switch (index_reg_15)
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

void main()
{
  int sec_r001840_0_1;
  int sec_r001840_0_2;
  int sec_r001840_1_1;
  int sec_r001840_1_2;
  int sec_r001840_2_1;
  int sec_r001840_2_2;
  int sec_r001840_3_1;
  int sec_r001840_3_2;
  int sec_r001840_4_1;
  int sec_r001840_4_2;
  int sec_r001840_5_1;
  int sec_r001840_5_2;
  int sec_r001840_6_1;
  int sec_r001840_6_2;
  int sec_r001840_7_1;
  int sec_r001840_7_2;
  int sec_r001840_8_1;
  int sec_r001840_8_2;
  int sec_r001840_9_1;
  int sec_r001840_9_2;
  int sec_r001840_10_1;
  int sec_r001840_10_2;
  int sec_r001840_11_1;
  int sec_r001840_11_2;
  int sec_r001840_12_1;
  int sec_r001840_12_2;
  int sec_r001840_13_1;
  int sec_r001840_13_2;
  int sec_r001840_14_1;
  int sec_r001840_14_2;
  int sec_r001840_15_1;
  int sec_r001840_15_2;
  int sec_r001840_16_1;
  int sec_r001840_16_2;
  int sec_r001840_17_1;
  int sec_r001840_17_2;
  int pub_r001840_0_1;
  int pub_r001840_0_2;
  int pub_r001840_1_1;
  int pub_r001840_1_2;
  int pub_r001840_2_1;
  int pub_r001840_2_2;
  int pub_r001840_3_1;
  int pub_r001840_3_2;
  int pub_r001840_4_1;
  int pub_r001840_4_2;
  int pub_r001840_5_1;
  int pub_r001840_5_2;
  int pub_r001840_6_1;
  int pub_r001840_6_2;
  int pub_r001840_7_1;
  int pub_r001840_7_2;
  int pub_r001840_8_1;
  int pub_r001840_8_2;
  int pub_r001840_9_1;
  int pub_r001840_9_2;
  int pub_r001840_10_1;
  int pub_r001840_10_2;
  int pub_r001840_11_1;
  int pub_r001840_11_2;
  int pub_r001840_12_1;
  int pub_r001840_12_2;
  int pub_r001840_13_1;
  int pub_r001840_13_2;
  int pub_r001840_14_1;
  int pub_r001840_14_2;
  int pub_r001840_15_1;
  int pub_r001840_15_2;
  int pub_r001840_16_1;
  int pub_r001840_16_2;
  int pub_r001840_17_1;
  int pub_r001840_17_2;
  int pub_r001840_18_1;
  int pub_r001840_18_2;
  int pub_r001840_19_1;
  int pub_r001840_19_2;
  int pub_r001840_20_1;
  int pub_r001840_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001840_0_1 >= (-100)) && (pub_r001840_0_1 <= 100));
  __CPROVER_assume((pub_r001840_0_2 >= (-100)) && (pub_r001840_0_2 <= 100));
  __CPROVER_assume((pub_r001840_1_1 >= (-100)) && (pub_r001840_1_1 <= 100));
  __CPROVER_assume((pub_r001840_1_2 >= (-100)) && (pub_r001840_1_2 <= 100));
  __CPROVER_assume((pub_r001840_2_1 >= (-100)) && (pub_r001840_2_1 <= 100));
  __CPROVER_assume((pub_r001840_2_2 >= (-100)) && (pub_r001840_2_2 <= 100));
  __CPROVER_assume((pub_r001840_3_1 >= (-100)) && (pub_r001840_3_1 <= 100));
  __CPROVER_assume((pub_r001840_3_2 >= (-100)) && (pub_r001840_3_2 <= 100));
  __CPROVER_assume((pub_r001840_4_1 >= (-100)) && (pub_r001840_4_1 <= 100));
  __CPROVER_assume((pub_r001840_4_2 >= (-100)) && (pub_r001840_4_2 <= 100));
  __CPROVER_assume((pub_r001840_5_1 >= (-100)) && (pub_r001840_5_1 <= 100));
  __CPROVER_assume((pub_r001840_5_2 >= (-100)) && (pub_r001840_5_2 <= 100));
  __CPROVER_assume((pub_r001840_6_1 >= (-100)) && (pub_r001840_6_1 <= 100));
  __CPROVER_assume((pub_r001840_6_2 >= (-100)) && (pub_r001840_6_2 <= 100));
  __CPROVER_assume((pub_r001840_7_1 >= (-100)) && (pub_r001840_7_1 <= 100));
  __CPROVER_assume((pub_r001840_7_2 >= (-100)) && (pub_r001840_7_2 <= 100));
  __CPROVER_assume((pub_r001840_8_1 >= (-100)) && (pub_r001840_8_1 <= 100));
  __CPROVER_assume((pub_r001840_8_2 >= (-100)) && (pub_r001840_8_2 <= 100));
  __CPROVER_assume((pub_r001840_9_1 >= (-100)) && (pub_r001840_9_1 <= 100));
  __CPROVER_assume((pub_r001840_9_2 >= (-100)) && (pub_r001840_9_2 <= 100));
  __CPROVER_assume((pub_r001840_10_1 >= (-100)) && (pub_r001840_10_1 <= 100));
  __CPROVER_assume((pub_r001840_10_2 >= (-100)) && (pub_r001840_10_2 <= 100));
  __CPROVER_assume((pub_r001840_11_1 >= (-100)) && (pub_r001840_11_1 <= 100));
  __CPROVER_assume((pub_r001840_11_2 >= (-100)) && (pub_r001840_11_2 <= 100));
  __CPROVER_assume((pub_r001840_12_1 >= (-100)) && (pub_r001840_12_1 <= 100));
  __CPROVER_assume((pub_r001840_12_2 >= (-100)) && (pub_r001840_12_2 <= 100));
  __CPROVER_assume((pub_r001840_13_1 >= (-100)) && (pub_r001840_13_1 <= 100));
  __CPROVER_assume((pub_r001840_13_2 >= (-100)) && (pub_r001840_13_2 <= 100));
  __CPROVER_assume((pub_r001840_14_1 >= (-100)) && (pub_r001840_14_1 <= 100));
  __CPROVER_assume((pub_r001840_14_2 >= (-100)) && (pub_r001840_14_2 <= 100));
  __CPROVER_assume((pub_r001840_15_1 >= (-100)) && (pub_r001840_15_1 <= 100));
  __CPROVER_assume((pub_r001840_15_2 >= (-100)) && (pub_r001840_15_2 <= 100));
  __CPROVER_assume((pub_r001840_16_1 >= (-100)) && (pub_r001840_16_1 <= 100));
  __CPROVER_assume((pub_r001840_16_2 >= (-100)) && (pub_r001840_16_2 <= 100));
  __CPROVER_assume((pub_r001840_17_1 >= (-100)) && (pub_r001840_17_1 <= 100));
  __CPROVER_assume((pub_r001840_17_2 >= (-100)) && (pub_r001840_17_2 <= 100));
  __CPROVER_assume((pub_r001840_18_1 >= (-100)) && (pub_r001840_18_1 <= 100));
  __CPROVER_assume((pub_r001840_18_2 >= (-100)) && (pub_r001840_18_2 <= 100));
  __CPROVER_assume((pub_r001840_19_1 >= (-100)) && (pub_r001840_19_1 <= 100));
  __CPROVER_assume((pub_r001840_19_2 >= (-100)) && (pub_r001840_19_2 <= 100));
  __CPROVER_assume((pub_r001840_20_1 >= (-100)) && (pub_r001840_20_1 <= 100));
  __CPROVER_assume((pub_r001840_20_2 >= (-100)) && (pub_r001840_20_2 <= 100));
  __CPROVER_assume((sec_r001840_0_1 >= 0) && (sec_r001840_0_1 <= 255));
  __CPROVER_assume((sec_r001840_0_2 >= 0) && (sec_r001840_0_2 <= 255));
  __CPROVER_assume((sec_r001840_1_1 >= 0) && (sec_r001840_1_1 <= 255));
  __CPROVER_assume((sec_r001840_1_2 >= 0) && (sec_r001840_1_2 <= 255));
  __CPROVER_assume((sec_r001840_2_1 >= 0) && (sec_r001840_2_1 <= 255));
  __CPROVER_assume((sec_r001840_2_2 >= 0) && (sec_r001840_2_2 <= 255));
  __CPROVER_assume((sec_r001840_3_1 >= 0) && (sec_r001840_3_1 <= 255));
  __CPROVER_assume((sec_r001840_3_2 >= 0) && (sec_r001840_3_2 <= 255));
  __CPROVER_assume((sec_r001840_4_1 >= 0) && (sec_r001840_4_1 <= 255));
  __CPROVER_assume((sec_r001840_4_2 >= 0) && (sec_r001840_4_2 <= 255));
  __CPROVER_assume((sec_r001840_5_1 >= 0) && (sec_r001840_5_1 <= 255));
  __CPROVER_assume((sec_r001840_5_2 >= 0) && (sec_r001840_5_2 <= 255));
  __CPROVER_assume((sec_r001840_6_1 >= 0) && (sec_r001840_6_1 <= 255));
  __CPROVER_assume((sec_r001840_6_2 >= 0) && (sec_r001840_6_2 <= 255));
  __CPROVER_assume((sec_r001840_7_1 >= 0) && (sec_r001840_7_1 <= 255));
  __CPROVER_assume((sec_r001840_7_2 >= 0) && (sec_r001840_7_2 <= 255));
  __CPROVER_assume((sec_r001840_8_1 >= 0) && (sec_r001840_8_1 <= 255));
  __CPROVER_assume((sec_r001840_8_2 >= 0) && (sec_r001840_8_2 <= 255));
  __CPROVER_assume((sec_r001840_9_1 >= 0) && (sec_r001840_9_1 <= 255));
  __CPROVER_assume((sec_r001840_9_2 >= 0) && (sec_r001840_9_2 <= 255));
  __CPROVER_assume((sec_r001840_10_1 >= 0) && (sec_r001840_10_1 <= 255));
  __CPROVER_assume((sec_r001840_10_2 >= 0) && (sec_r001840_10_2 <= 255));
  __CPROVER_assume((sec_r001840_11_1 >= 0) && (sec_r001840_11_1 <= 255));
  __CPROVER_assume((sec_r001840_11_2 >= 0) && (sec_r001840_11_2 <= 255));
  __CPROVER_assume((sec_r001840_12_1 >= 0) && (sec_r001840_12_1 <= 255));
  __CPROVER_assume((sec_r001840_12_2 >= 0) && (sec_r001840_12_2 <= 255));
  __CPROVER_assume((sec_r001840_13_1 >= 0) && (sec_r001840_13_1 <= 255));
  __CPROVER_assume((sec_r001840_13_2 >= 0) && (sec_r001840_13_2 <= 255));
  __CPROVER_assume((sec_r001840_14_1 >= 0) && (sec_r001840_14_1 <= 255));
  __CPROVER_assume((sec_r001840_14_2 >= 0) && (sec_r001840_14_2 <= 255));
  __CPROVER_assume((sec_r001840_15_1 >= 0) && (sec_r001840_15_1 <= 255));
  __CPROVER_assume((sec_r001840_15_2 >= 0) && (sec_r001840_15_2 <= 255));
  __CPROVER_assume((sec_r001840_16_1 >= 0) && (sec_r001840_16_1 <= 255));
  __CPROVER_assume((sec_r001840_16_2 >= 0) && (sec_r001840_16_2 <= 255));
  __CPROVER_assume((sec_r001840_17_1 >= 0) && (sec_r001840_17_1 <= 255));
  __CPROVER_assume((sec_r001840_17_2 >= 0) && (sec_r001840_17_2 <= 255));
  struct EventLog_R001840_4013_0 st_var_0_1 = {0};
  struct EventLog_R001840_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001840_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001840_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001840_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001840_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001840_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001840_0_2 + 7) & 15;
  struct FilterState_R001840_4013_1 st_var_1_1 = {0};
  struct FilterState_R001840_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001840_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001840_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001840_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001840_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001840_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001840_0_2 + 9) & 15;
  struct DeviceConfig_R001840_4013_2 st_var_2_1 = {0};
  struct DeviceConfig_R001840_4013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001840_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001840_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001840_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001840_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001840_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001840_0_2 + 11) & 15;
  union RegisterBank_R001840_4013_0 u_var_1;
  union RegisterBank_R001840_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001840_4013_0(sec_r001840_0_1, sec_r001840_1_1, pub_r001840_2_1, pub_r001840_3_1, pub_r001840_4_1);
  int helper_flow_0_2 = fn_R001840_4013_0(sec_r001840_0_2, sec_r001840_1_2, pub_r001840_2_2, pub_r001840_3_2, pub_r001840_4_2);
  fn_R001840_4013_0_2(sec_r001840_0_1, sec_r001840_1_1, pub_r001840_2_1, pub_r001840_3_1, pub_r001840_4_1, sec_r001840_0_2, sec_r001840_1_2, pub_r001840_2_2, pub_r001840_3_2, pub_r001840_4_2);
  int helper_flow_1_1 = fn_R001840_4013_1(sec_r001840_1_1, sec_r001840_2_1, pub_r001840_3_1, pub_r001840_4_1, pub_r001840_5_1);
  int helper_flow_1_2 = fn_R001840_4013_1(sec_r001840_1_2, sec_r001840_2_2, pub_r001840_3_2, pub_r001840_4_2, pub_r001840_5_2);
  fn_R001840_4013_1_2(sec_r001840_1_1, sec_r001840_2_1, pub_r001840_3_1, pub_r001840_4_1, pub_r001840_5_1, sec_r001840_1_2, sec_r001840_2_2, pub_r001840_3_2, pub_r001840_4_2, pub_r001840_5_2);
  int helper_flow_2_1 = fn_R001840_4013_2(sec_r001840_2_1, pub_r001840_3_1, pub_r001840_4_1);
  int helper_flow_2_2 = fn_R001840_4013_2(sec_r001840_2_2, pub_r001840_3_2, pub_r001840_4_2);
  fn_R001840_4013_2_2(sec_r001840_2_1, pub_r001840_3_1, pub_r001840_4_1, sec_r001840_2_2, pub_r001840_3_2, pub_r001840_4_2);
  int helper_flow_3_1 = fn_R001840_4013_3(sec_r001840_3_1, pub_r001840_4_1);
  int helper_flow_3_2 = fn_R001840_4013_3(sec_r001840_3_2, pub_r001840_4_2);
  fn_R001840_4013_3_2(sec_r001840_3_1, pub_r001840_4_1, sec_r001840_3_2, pub_r001840_4_2);
  int helper_flow_4_1 = fn_R001840_4013_4(sec_r001840_4_1, pub_r001840_5_1, pub_r001840_6_1, pub_r001840_7_1, pub_r001840_8_1);
  int helper_flow_4_2 = fn_R001840_4013_4(sec_r001840_4_2, pub_r001840_5_2, pub_r001840_6_2, pub_r001840_7_2, pub_r001840_8_2);
  fn_R001840_4013_4_2(sec_r001840_4_1, pub_r001840_5_1, pub_r001840_6_1, pub_r001840_7_1, pub_r001840_8_1, sec_r001840_4_2, pub_r001840_5_2, pub_r001840_6_2, pub_r001840_7_2, pub_r001840_8_2);
  int helper_flow_5_1 = fn_R001840_4013_5(sec_r001840_5_1, pub_r001840_6_1, pub_r001840_7_1, pub_r001840_8_1, pub_r001840_9_1);
  int helper_flow_5_2 = fn_R001840_4013_5(sec_r001840_5_2, pub_r001840_6_2, pub_r001840_7_2, pub_r001840_8_2, pub_r001840_9_2);
  fn_R001840_4013_5_2(sec_r001840_5_1, pub_r001840_6_1, pub_r001840_7_1, pub_r001840_8_1, pub_r001840_9_1, sec_r001840_5_2, pub_r001840_6_2, pub_r001840_7_2, pub_r001840_8_2, pub_r001840_9_2);
  int helper_flow_6_1 = fn_R001840_4013_6(sec_r001840_6_1, sec_r001840_7_1, pub_r001840_8_1);
  int helper_flow_6_2 = fn_R001840_4013_6(sec_r001840_6_2, sec_r001840_7_2, pub_r001840_8_2);
  fn_R001840_4013_6_2(sec_r001840_6_1, sec_r001840_7_1, pub_r001840_8_1, sec_r001840_6_2, sec_r001840_7_2, pub_r001840_8_2);
  int helper_flow_7_1 = fn_R001840_4013_7(sec_r001840_7_1, sec_r001840_8_1, pub_r001840_9_1);
  int helper_flow_7_2 = fn_R001840_4013_7(sec_r001840_7_2, sec_r001840_8_2, pub_r001840_9_2);
  fn_R001840_4013_7_2(sec_r001840_7_1, sec_r001840_8_1, pub_r001840_9_1, sec_r001840_7_2, sec_r001840_8_2, pub_r001840_9_2);
  int helper_flow_8_1 = fn_R001840_4013_8(sec_r001840_8_1, pub_r001840_9_1);
  int helper_flow_8_2 = fn_R001840_4013_8(sec_r001840_8_2, pub_r001840_9_2);
  fn_R001840_4013_8_2(sec_r001840_8_1, pub_r001840_9_1, sec_r001840_8_2, pub_r001840_9_2);
  int helper_flow_9_1 = fn_R001840_4013_9(sec_r001840_9_1, sec_r001840_10_1, pub_r001840_11_1, pub_r001840_12_1, pub_r001840_13_1);
  int helper_flow_9_2 = fn_R001840_4013_9(sec_r001840_9_2, sec_r001840_10_2, pub_r001840_11_2, pub_r001840_12_2, pub_r001840_13_2);
  fn_R001840_4013_9_2(sec_r001840_9_1, sec_r001840_10_1, pub_r001840_11_1, pub_r001840_12_1, pub_r001840_13_1, sec_r001840_9_2, sec_r001840_10_2, pub_r001840_11_2, pub_r001840_12_2, pub_r001840_13_2);
  int helper_flow_10_1 = fn_R001840_4013_10(sec_r001840_10_1, pub_r001840_11_1, pub_r001840_12_1, pub_r001840_13_1, pub_r001840_14_1);
  int helper_flow_10_2 = fn_R001840_4013_10(sec_r001840_10_2, pub_r001840_11_2, pub_r001840_12_2, pub_r001840_13_2, pub_r001840_14_2);
  fn_R001840_4013_10_2(sec_r001840_10_1, pub_r001840_11_1, pub_r001840_12_1, pub_r001840_13_1, pub_r001840_14_1, sec_r001840_10_2, pub_r001840_11_2, pub_r001840_12_2, pub_r001840_13_2, pub_r001840_14_2);
  int helper_flow_11_1 = fn_R001840_4013_11(sec_r001840_11_1, sec_r001840_12_1, pub_r001840_13_1);
  int helper_flow_11_2 = fn_R001840_4013_11(sec_r001840_11_2, sec_r001840_12_2, pub_r001840_13_2);
  fn_R001840_4013_11_2(sec_r001840_11_1, sec_r001840_12_1, pub_r001840_13_1, sec_r001840_11_2, sec_r001840_12_2, pub_r001840_13_2);
  int stage_v_0_1 = (((sec_r001840_15_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_0_2 = (((sec_r001840_15_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_0_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((pub_r001840_13_1 * 2) + 22) & 63;
  int stage_v_1_2 = ((pub_r001840_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001840_10_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_2_2 = (((sec_r001840_10_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_2_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((pub_r001840_7_1 * 2) + 9) & 63;
  int stage_v_3_2 = ((pub_r001840_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001840_10_1 * 2) + 18) & 63;
  int stage_v_4_2 = ((pub_r001840_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001840_13_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_5_2 = (((sec_r001840_13_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_5_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((pub_r001840_15_1 * 2) + 15) & 63;
  int stage_v_6_2 = ((pub_r001840_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_7_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_7_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001840_9_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_8_2 = (((sec_r001840_9_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_8_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001840_8_1 ^ 0x2A) * 2) + pub_r001840_0_1) & 127;
  int stage_v_9_2 = (((sec_r001840_8_2 ^ 0x2A) * 2) + pub_r001840_0_2) & 127;
  if (stage_v_9_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((pub_r001840_17_1 * 2) + 35) & 63;
  int stage_v_10_2 = ((pub_r001840_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_11_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_11_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001840_16_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_12_2 = (((sec_r001840_16_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_12_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_13_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_13_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((pub_r001840_14_1 * 2) + 27) & 63;
  int stage_v_14_2 = ((pub_r001840_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_15_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_15_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((pub_r001840_0_1 * 2) + 12) & 63;
  int stage_v_16_2 = ((pub_r001840_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001840_7_1 * 2) + 31) & 63;
  int stage_v_17_2 = ((pub_r001840_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_18_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_18_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_19_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_19_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_20_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_20_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_21_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_21_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_22_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_22_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((sec_r001840_0_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_23_2 = (((sec_r001840_0_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_23_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_24_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_24_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_25_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_25_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001840_16_1 ^ 0x2A) * 2) + pub_r001840_20_1) & 127;
  int stage_v_26_2 = (((sec_r001840_16_2 ^ 0x2A) * 2) + pub_r001840_20_2) & 127;
  if (stage_v_26_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_27_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_27_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001840_1_1 * 2) + 21) & 63;
  int stage_v_28_2 = ((pub_r001840_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((sec_r001840_7_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_29_2 = (((sec_r001840_7_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_29_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_30_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_30_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_31_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_31_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001840_4_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_32_2 = (((sec_r001840_4_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_32_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_33_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_33_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_34_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_35_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_35_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_36_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_36_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_37_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_37_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_38_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_38_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((pub_r001840_5_1 * 2) + 48) & 63;
  int stage_v_39_2 = ((pub_r001840_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_40_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_40_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((sec_r001840_16_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_41_2 = (((sec_r001840_16_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_41_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_42_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_42_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((sec_r001840_17_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_43_2 = (((sec_r001840_17_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_43_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_44_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_44_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_45_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_45_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_46_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_46_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((sec_r001840_3_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_47_2 = (((sec_r001840_3_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_47_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((sec_r001840_4_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_48_2 = (((sec_r001840_4_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_48_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_49_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_49_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_50_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_50_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((pub_r001840_8_1 * 2) + 14) & 63;
  int stage_v_51_2 = ((pub_r001840_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_52_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_52_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((sec_r001840_3_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_53_2 = (((sec_r001840_3_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_53_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_54_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_54_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_55_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_55_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((pub_r001840_20_1 * 2) + 27) & 63;
  int stage_v_56_2 = ((pub_r001840_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001840_9_1 * 2) + 13) & 63;
  int stage_v_57_2 = ((pub_r001840_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_58_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_58_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001840_5_1) & 127;
  int stage_v_59_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001840_5_2) & 127;
  if (stage_v_59_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001840_8_1 * 2) + 24) & 63;
  int stage_v_60_2 = ((pub_r001840_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_61_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_61_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_62_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_62_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001840_5_1) & 127;
  int stage_v_63_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001840_5_2) & 127;
  if (stage_v_63_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_64_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_64_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_65_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_65_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001840_0_1) & 127;
  int stage_v_66_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001840_0_2) & 127;
  if (stage_v_66_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_67_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_67_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_68_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_68_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((pub_r001840_0_1 * 2) + 5) & 63;
  int stage_v_69_2 = ((pub_r001840_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001840_8_1 * 2) + 6) & 63;
  int stage_v_70_2 = ((pub_r001840_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001840_12_1 * 2) + 22) & 63;
  int stage_v_71_2 = ((pub_r001840_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001840_3_1 * 2) + 34) & 63;
  int stage_v_72_2 = ((pub_r001840_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001840_20_1) & 127;
  int stage_v_73_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001840_20_2) & 127;
  if (stage_v_73_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_74_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_74_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_75_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_75_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_76_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_76_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((sec_r001840_3_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_77_2 = (((sec_r001840_3_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_77_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_78_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_78_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_79_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_79_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_80_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_80_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_81_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_81_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_82_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_82_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_83_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_83_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_84_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_84_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001840_11_1 * 2) + 11) & 63;
  int stage_v_85_2 = ((pub_r001840_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_86_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_86_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((pub_r001840_17_1 * 2) + 38) & 63;
  int stage_v_87_2 = ((pub_r001840_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_88_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_88_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((pub_r001840_16_1 * 2) + 39) & 63;
  int stage_v_89_2 = ((pub_r001840_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_90_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_90_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_91_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_91_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_92_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_92_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_93_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_93_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001840_8_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_94_2 = (((sec_r001840_8_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_94_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001840_9_1 * 2) + 24) & 63;
  int stage_v_95_2 = ((pub_r001840_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_96_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_96_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_97_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_97_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_98_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_98_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_99_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_99_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001840_5_1) & 127;
  int stage_v_100_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001840_5_2) & 127;
  if (stage_v_100_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_101_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_101_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_102_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_102_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_103_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_103_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_104_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_104_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_105_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_105_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((pub_r001840_7_1 * 2) + 23) & 63;
  int stage_v_106_2 = ((pub_r001840_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((sec_r001840_14_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_107_2 = (((sec_r001840_14_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_107_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((pub_r001840_0_1 * 2) + 36) & 63;
  int stage_v_108_2 = ((pub_r001840_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_109_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_109_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((sec_r001840_13_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_110_2 = (((sec_r001840_13_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_110_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((pub_r001840_16_1 * 2) + 32) & 63;
  int stage_v_111_2 = ((pub_r001840_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001840_3_1 * 2) + 19) & 63;
  int stage_v_112_2 = ((pub_r001840_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_113_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_113_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((pub_r001840_20_1 * 2) + 27) & 63;
  int stage_v_114_2 = ((pub_r001840_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001840_2_1 * 2) + 36) & 63;
  int stage_v_115_2 = ((pub_r001840_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_116_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_116_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_117_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_117_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_118_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_118_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((pub_r001840_0_1 * 2) + 6) & 63;
  int stage_v_119_2 = ((pub_r001840_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_120_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_120_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_121_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_121_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_122_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_122_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_123_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_123_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_124_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_124_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_125_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_125_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001840_0_1) & 127;
  int stage_v_126_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001840_0_2) & 127;
  if (stage_v_126_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_127_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_127_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((sec_r001840_15_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_128_2 = (((sec_r001840_15_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_128_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001840_13_1 * 2) + 21) & 63;
  int stage_v_129_2 = ((pub_r001840_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((sec_r001840_16_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_130_2 = (((sec_r001840_16_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_130_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_131_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_131_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001840_5_1) & 127;
  int stage_v_132_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001840_5_2) & 127;
  if (stage_v_132_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((sec_r001840_17_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_133_2 = (((sec_r001840_17_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_133_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((pub_r001840_10_1 * 2) + 28) & 63;
  int stage_v_134_2 = ((pub_r001840_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_135_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_135_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_136_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_136_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001840_13_1 * 2) + 20) & 63;
  int stage_v_137_2 = ((pub_r001840_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_138_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_138_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_139_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_139_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_140_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_140_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_141_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_141_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((pub_r001840_5_1 * 2) + 48) & 63;
  int stage_v_142_2 = ((pub_r001840_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_143_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_143_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_144_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_144_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_145_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_145_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_146_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_146_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001840_0_1) & 127;
  int stage_v_147_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001840_0_2) & 127;
  if (stage_v_147_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_148_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_148_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001840_7_1 * 2) + 26) & 63;
  int stage_v_149_2 = ((pub_r001840_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_150_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_150_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_151_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_151_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_152_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_152_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((pub_r001840_7_1 * 2) + 36) & 63;
  int stage_v_153_2 = ((pub_r001840_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_154_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_154_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_155_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_155_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((sec_r001840_4_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_156_2 = (((sec_r001840_4_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_156_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_157_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_157_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((sec_r001840_1_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_158_2 = (((sec_r001840_1_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_158_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_159_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_159_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001840_15_1 * 2) + 19) & 63;
  int stage_v_160_2 = ((pub_r001840_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_161_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_161_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_162_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_162_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001840_9_1 * 2) + 42) & 63;
  int stage_v_163_2 = ((pub_r001840_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_164_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_164_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_165_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_165_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_166_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_166_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((pub_r001840_7_1 * 2) + 18) & 63;
  int stage_v_167_2 = ((pub_r001840_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_168_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_168_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_169_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_169_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_170_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_170_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001840_8_1 * 2) + 42) & 63;
  int stage_v_171_2 = ((pub_r001840_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_172_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_172_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_173_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_173_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_174_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_174_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001840_20_1) & 127;
  int stage_v_175_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001840_20_2) & 127;
  if (stage_v_175_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((pub_r001840_4_1 * 2) + 39) & 63;
  int stage_v_176_2 = ((pub_r001840_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_177_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_177_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_178_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_178_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001840_10_1 * 2) + 42) & 63;
  int stage_v_179_2 = ((pub_r001840_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001840_20_1 * 2) + 33) & 63;
  int stage_v_180_2 = ((pub_r001840_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_181_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_181_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001840_17_1 * 2) + 34) & 63;
  int stage_v_182_2 = ((pub_r001840_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001840_5_1 * 2) + 41) & 63;
  int stage_v_183_2 = ((pub_r001840_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_184_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_184_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_185_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_185_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_186_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_186_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_187_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_187_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001840_15_1) & 127;
  int stage_v_188_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001840_15_2) & 127;
  if (stage_v_188_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_189_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_189_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_190_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_190_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001840_0_1 * 2) + 47) & 63;
  int stage_v_191_2 = ((pub_r001840_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_181_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_192_2 = (((stage_v_181_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_192_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_193_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_193_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_177_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_194_2 = (((stage_v_177_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_194_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_195_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_195_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_196_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_196_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_197_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_197_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001840_0_1) & 127;
  int stage_v_198_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001840_0_2) & 127;
  if (stage_v_198_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001840_4_1 * 2) + 20) & 63;
  int stage_v_199_2 = ((pub_r001840_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_200_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_200_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_201_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_201_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((sec_r001840_5_1 ^ 0x2A) * 2) + pub_r001840_18_1) & 127;
  int stage_v_202_2 = (((sec_r001840_5_2 ^ 0x2A) * 2) + pub_r001840_18_2) & 127;
  if (stage_v_202_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_188_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_203_2 = (((stage_v_188_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_203_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((pub_r001840_20_1 * 2) + 26) & 63;
  int stage_v_204_2 = ((pub_r001840_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((sec_r001840_7_1 ^ 0x2A) * 2) + pub_r001840_20_1) & 127;
  int stage_v_205_2 = (((sec_r001840_7_2 ^ 0x2A) * 2) + pub_r001840_20_2) & 127;
  if (stage_v_205_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_206_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_206_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((sec_r001840_10_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_207_2 = (((sec_r001840_10_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_207_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001840_2_1) & 127;
  int stage_v_208_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001840_2_2) & 127;
  if (stage_v_208_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001840_5_1) & 127;
  int stage_v_209_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001840_5_2) & 127;
  if (stage_v_209_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001840_4_1 * 2) + 41) & 63;
  int stage_v_210_2 = ((pub_r001840_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001840_18_1 * 2) + 14) & 63;
  int stage_v_211_2 = ((pub_r001840_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((sec_r001840_17_1 ^ 0x2A) * 2) + pub_r001840_20_1) & 127;
  int stage_v_212_2 = (((sec_r001840_17_2 ^ 0x2A) * 2) + pub_r001840_20_2) & 127;
  if (stage_v_212_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_213_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_213_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_208_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_214_2 = (((stage_v_208_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_214_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001840_6_1) & 127;
  int stage_v_215_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001840_6_2) & 127;
  if (stage_v_215_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((pub_r001840_10_1 * 2) + 23) & 63;
  int stage_v_216_2 = ((pub_r001840_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((sec_r001840_2_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_217_2 = (((sec_r001840_2_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_217_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001840_10_1) & 127;
  int stage_v_218_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001840_10_2) & 127;
  if (stage_v_218_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_219_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_219_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001840_16_1 * 2) + 38) & 63;
  int stage_v_220_2 = ((pub_r001840_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((sec_r001840_5_1 ^ 0x2A) * 2) + pub_r001840_17_1) & 127;
  int stage_v_221_2 = (((sec_r001840_5_2 ^ 0x2A) * 2) + pub_r001840_17_2) & 127;
  if (stage_v_221_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_222_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_222_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((sec_r001840_7_1 ^ 0x2A) * 2) + pub_r001840_12_1) & 127;
  int stage_v_223_2 = (((sec_r001840_7_2 ^ 0x2A) * 2) + pub_r001840_12_2) & 127;
  if (stage_v_223_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((sec_r001840_15_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_224_2 = (((sec_r001840_15_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_224_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((stage_v_202_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_225_2 = (((stage_v_202_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_225_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_226_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_226_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((pub_r001840_4_1 * 2) + 39) & 63;
  int stage_v_227_2 = ((pub_r001840_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_228_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_228_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_197_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_229_2 = (((stage_v_197_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_229_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001840_1_1) & 127;
  int stage_v_230_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001840_1_2) & 127;
  if (stage_v_230_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_231_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_231_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001840_7_1) & 127;
  int stage_v_232_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001840_7_2) & 127;
  if (stage_v_232_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001840_19_1) & 127;
  int stage_v_233_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001840_19_2) & 127;
  if (stage_v_233_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((pub_r001840_10_1 * 2) + 7) & 63;
  int stage_v_234_2 = ((pub_r001840_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001840_3_1) & 127;
  int stage_v_235_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001840_3_2) & 127;
  if (stage_v_235_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001840_9_1) & 127;
  int stage_v_236_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001840_9_2) & 127;
  if (stage_v_236_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_237_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_237_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_238_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_238_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = (((stage_v_110_1 ^ 0x2A) * 2) + pub_r001840_0_1) & 127;
  int stage_v_239_2 = (((stage_v_110_2 ^ 0x2A) * 2) + pub_r001840_0_2) & 127;
  if (stage_v_239_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = (((stage_v_203_1 ^ 0x2A) * 2) + pub_r001840_14_1) & 127;
  int stage_v_240_2 = (((stage_v_203_2 ^ 0x2A) * 2) + pub_r001840_14_2) & 127;
  if (stage_v_240_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = (((sec_r001840_17_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_241_2 = (((sec_r001840_17_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_241_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001840_8_1) & 127;
  int stage_v_242_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001840_8_2) & 127;
  if (stage_v_242_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((pub_r001840_6_1 * 2) + 43) & 63;
  int stage_v_243_2 = ((pub_r001840_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((sec_r001840_1_1 ^ 0x2A) * 2) + pub_r001840_13_1) & 127;
  int stage_v_244_2 = (((sec_r001840_1_2 ^ 0x2A) * 2) + pub_r001840_13_2) & 127;
  if (stage_v_244_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
  }
  if (stage_v_244_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((pub_r001840_3_1 * 2) + 14) & 63;
  int stage_v_245_2 = ((pub_r001840_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001840_4_1) & 127;
  int stage_v_246_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001840_4_2) & 127;
  if (stage_v_246_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001840_11_1) & 127;
  int stage_v_247_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001840_11_2) & 127;
  if (stage_v_247_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
  }
  if (stage_v_247_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001840_16_1) & 127;
  int stage_v_248_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001840_16_2) & 127;
  if (stage_v_248_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
  }
  if (stage_v_248_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((pub_r001840_13_1 * 2) + 17) & 63;
  int stage_v_249_2 = ((pub_r001840_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001840_17_1 != sec_r001840_17_2);
  __CPROVER_assume(pub_r001840_10_1 == pub_r001840_10_2);
  __CPROVER_assume(pub_r001840_11_1 == pub_r001840_11_2);
  __CPROVER_assume(sec_r001840_12_1 != sec_r001840_12_2);
  __CPROVER_assume(pub_r001840_2_1 == pub_r001840_2_2);
  __CPROVER_assume(pub_r001840_5_1 == pub_r001840_5_2);
  __CPROVER_assume(pub_r001840_8_1 == pub_r001840_8_2);
  __CPROVER_assume(pub_r001840_4_1 == pub_r001840_4_2);
  __CPROVER_assume(sec_r001840_11_1 != sec_r001840_11_2);
  __CPROVER_assume(pub_r001840_16_1 == pub_r001840_16_2);
  __CPROVER_assume(sec_r001840_10_1 != sec_r001840_10_2);
  __CPROVER_assume(pub_r001840_20_1 == pub_r001840_20_2);
  __CPROVER_assume(sec_r001840_16_1 != sec_r001840_16_2);
  __CPROVER_assume(sec_r001840_5_1 != sec_r001840_5_2);
  __CPROVER_assume(sec_r001840_7_1 != sec_r001840_7_2);
  __CPROVER_assume(sec_r001840_9_1 != sec_r001840_9_2);
  __CPROVER_assume(pub_r001840_0_1 == pub_r001840_0_2);
  __CPROVER_assume(sec_r001840_14_1 != sec_r001840_14_2);
  __CPROVER_assume(pub_r001840_15_1 == pub_r001840_15_2);
  __CPROVER_assume(pub_r001840_7_1 == pub_r001840_7_2);
  __CPROVER_assume(sec_r001840_1_1 != sec_r001840_1_2);
  __CPROVER_assume(pub_r001840_3_1 == pub_r001840_3_2);
  __CPROVER_assume(pub_r001840_6_1 == pub_r001840_6_2);
  __CPROVER_assume(sec_r001840_3_1 != sec_r001840_3_2);
  __CPROVER_assume(pub_r001840_1_1 == pub_r001840_1_2);
  __CPROVER_assume(sec_r001840_15_1 != sec_r001840_15_2);
  __CPROVER_assume(pub_r001840_19_1 == pub_r001840_19_2);
  __CPROVER_assume(sec_r001840_8_1 != sec_r001840_8_2);
  __CPROVER_assume(pub_r001840_12_1 == pub_r001840_12_2);
  __CPROVER_assume(sec_r001840_13_1 != sec_r001840_13_2);
  __CPROVER_assume(pub_r001840_14_1 == pub_r001840_14_2);
  __CPROVER_assume(pub_r001840_17_1 == pub_r001840_17_2);
  __CPROVER_assume(sec_r001840_6_1 != sec_r001840_6_2);
  __CPROVER_assume(pub_r001840_18_1 == pub_r001840_18_2);
  __CPROVER_assume(sec_r001840_0_1 != sec_r001840_0_2);
  __CPROVER_assume(sec_r001840_2_1 != sec_r001840_2_2);
  __CPROVER_assume(pub_r001840_9_1 == pub_r001840_9_2);
  __CPROVER_assume(sec_r001840_4_1 != sec_r001840_4_2);
  __CPROVER_assume(pub_r001840_13_1 == pub_r001840_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.port == st_var_2_2.port);
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
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
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
}


