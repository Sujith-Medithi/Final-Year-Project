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
struct CipherContext_R001396_9613_0
{
  unsigned char iv;
  short counter;
  int nonce;
  short flags;
  int round_key;
  int tag;
  int buffer[3];
};
struct StreamBuffer_R001396_9613_1
{
  unsigned char tail;
  int head;
  short capacity;
  int checksum;
  int buffer[3];
};
struct Vector3D_R001396_9613_2
{
  int coord_x;
  int norm_sq;
  int heading;
  int coord_y;
  short coord_z;
  int pitch;
  int buffer[3];
};
struct EventLog_R001396_9613_3
{
  int severity;
  unsigned char signature;
  int timestamp;
  unsigned char seq;
  int facility;
  short code;
  int buffer[3];
};
union ColorPixel_R001396_9613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001396_9613_1
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
void fn_R001396_9613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st_1 = {0};
  struct Vector3D_R001396_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int index_reg_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_84_1)
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

  switch (index_reg_84_2)
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

  int tracker_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_17_1) & 63;
  aux_2 = (aux_2 + tracker_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_84_1 == index_reg_84_2);
  assert(tracker_17_1 == tracker_17_2);
}

int fn_R001396_9613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int index_reg_84 = (aux + st.buffer[1]) & 3;
  switch (index_reg_84)
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

  int tracker_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001396_9613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st_1 = {0};
  struct Vector3D_R001396_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int parity_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_12_1) & 63;
  aux_2 = (aux_2 + parity_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_16_1)
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

  switch (weight_16_2)
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

  int residue_37_1 = 0;
  int residue_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_37_1 = ((residue_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_37_2 = ((residue_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_37_1) & 127;
    acc_2 = (acc_2 + residue_37_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_12_1 == parity_12_2);
  assert(weight_16_1 == weight_16_2);
  assert(residue_37_1 == residue_37_2);
}

int fn_R001396_9613_1(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int parity_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_12) & 63;
  acc ^= aux;
  int weight_16 = (aux + st.buffer[1]) & 3;
  switch (weight_16)
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

  int residue_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_37 = ((residue_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_37) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st_1 = {0};
  struct Vector3D_R001396_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_64_1) & 63;
  aux_2 = (aux_2 + anchor_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_69_1 > 14)
  {
    acc_1 = ((acc_1 + (index_reg_69_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_69_2 > 14)
  {
    acc_2 = ((acc_2 + (index_reg_69_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_64_1 == anchor_64_2);
  assert(index_reg_69_1 == index_reg_69_2);
}

int fn_R001396_9613_2(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_64) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_69 > 14)
  {
    acc = ((acc + (index_reg_69 * 2)) + 5) & 127;
    aux ^= index_reg_69 & 15;
  }
  else
  {
    acc = ((acc - index_reg_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001396_9613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st_1 = {0};
  struct CipherContext_R001396_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_62_1 = local_arr_1[aux_1 % 3];
  int damping_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_62_2 * 2)) & 127;
  int residue_73_1 = 0;
  int residue_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_73_1 = ((residue_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_73_2 = ((residue_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_73_1) & 127;
    acc_2 = (acc_2 + residue_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_62_1 == damping_62_2);
  assert(residue_73_1 == residue_73_2);
}

int fn_R001396_9613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int damping_62 = local_arr[aux % 3];
  acc = (acc + (damping_62 * 2)) & 127;
  int residue_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_73 = ((residue_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st_1 = {0};
  struct EventLog_R001396_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int accumulator_35_1 = 0;
  int accumulator_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_35_1 = ((accumulator_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_35_2 = ((accumulator_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_35_1) & 127;
    acc_2 = (acc_2 + accumulator_35_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_35_1 == accumulator_35_2);
}

int fn_R001396_9613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int accumulator_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_35 = ((accumulator_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_35) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_71_1 = local_arr_1[aux_1 % 3];
  int quotient_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_71_2 * 2)) & 127;
  int threshold_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_60_1 > 11)
  {
    acc_1 = ((acc_1 + (threshold_60_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_60_2 > 11)
  {
    acc_2 = ((acc_2 + (threshold_60_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_48_1)
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

  switch (vector_48_2)
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

  int parity_75_1 = 0;
  int parity_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_75_1 = ((parity_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_75_2 = ((parity_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_75_1) & 127;
    acc_2 = (acc_2 + parity_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_71_1 == quotient_71_2);
  assert(threshold_60_1 == threshold_60_2);
  assert(vector_48_1 == vector_48_2);
  assert(parity_75_1 == parity_75_2);
}

int fn_R001396_9613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int quotient_71 = local_arr[aux % 3];
  acc = (acc + (quotient_71 * 2)) & 127;
  int threshold_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_60 > 11)
  {
    acc = ((acc + (threshold_60 * 2)) + 5) & 127;
    aux ^= threshold_60 & 15;
  }
  else
  {
    acc = ((acc - threshold_60) + 11) & 127;
    aux += 3;
  }
  int vector_48 = (aux + st.buffer[1]) & 3;
  switch (vector_48)
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

  int parity_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_75 = ((parity_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_85_1 = local_arr_1[aux_1 % 3];
  int threshold_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_85_1 == threshold_85_2);
}

int fn_R001396_9613_6(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int threshold_85 = local_arr[aux % 3];
  acc = (acc + (threshold_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st_1 = {0};
  struct CipherContext_R001396_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int bound_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_26_1)
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

  switch (bound_26_2)
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

  int tracker_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_79_1 > 16)
  {
    acc_1 = ((acc_1 + (tracker_79_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_79_2 > 16)
  {
    acc_2 = ((acc_2 + (tracker_79_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_26_1 == bound_26_2);
  assert(tracker_79_1 == tracker_79_2);
}

int fn_R001396_9613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int bound_26 = (aux + st.buffer[1]) & 3;
  switch (bound_26)
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

  int tracker_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_79 > 16)
  {
    acc = ((acc + (tracker_79 * 2)) + 5) & 127;
    aux ^= tracker_79 & 15;
  }
  else
  {
    acc = ((acc - tracker_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001396_9613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st_1 = {0};
  struct EventLog_R001396_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int weight_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_22_1)
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

  switch (weight_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_65_1 = 0;
  int mask_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_65_1 = ((mask_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_65_2 = ((mask_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_65_1) & 127;
    acc_2 = (acc_2 + mask_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_22_1 == weight_22_2);
  assert(mask_65_1 == mask_65_2);
}

int fn_R001396_9613_8(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int weight_22 = (aux + st.buffer[1]) & 3;
  switch (weight_22)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_65 = ((mask_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int margin_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_22_1 > 10)
  {
    acc_1 = ((acc_1 + (margin_22_1 * 2)) + 5) & 127;
    aux_1 ^= margin_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_22_2 > 10)
  {
    acc_2 = ((acc_2 + (margin_22_2 * 2)) + 5) & 127;
    aux_2 ^= margin_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_62_1 = 0;
  int metric_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_62_1 = ((metric_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_62_2 = ((metric_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_62_1) & 127;
    acc_2 = (acc_2 + metric_62_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_47_1 = local_arr_1[aux_1 % 3];
  int tally_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_22_1 == margin_22_2);
  assert(metric_62_1 == metric_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_47_1 == tally_47_2);
}

int fn_R001396_9613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int margin_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_22 > 10)
  {
    acc = ((acc + (margin_22 * 2)) + 5) & 127;
    aux ^= margin_22 & 15;
  }
  else
  {
    acc = ((acc - margin_22) + 11) & 127;
    aux += 3;
  }
  int metric_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_62 = ((metric_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_62) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_47 = local_arr[aux % 3];
  acc = (acc + (tally_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st_1 = {0};
  struct CipherContext_R001396_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int damping_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_59_1)
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

  switch (damping_59_2)
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

  int quotient_15_1 = 0;
  int quotient_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_15_1 = ((quotient_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_15_2 = ((quotient_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_15_1) & 127;
    acc_2 = (acc_2 + quotient_15_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_20_1 = local_arr_1[aux_1 % 3];
  int damping_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_59_1 == damping_59_2);
  assert(quotient_15_1 == quotient_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_20_1 == damping_20_2);
}

int fn_R001396_9613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int damping_59 = (aux + st.buffer[1]) & 3;
  switch (damping_59)
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

  int quotient_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_15 = ((quotient_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_15) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_20 = local_arr[aux % 3];
  acc = (acc + (damping_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int delta_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_91_1)
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

  switch (delta_91_2)
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

  int tally_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_83_1 > 49)
  {
    acc_1 = ((acc_1 + (tally_83_1 * 2)) + 5) & 127;
    aux_1 ^= tally_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_83_2 > 49)
  {
    acc_2 = ((acc_2 + (tally_83_2 * 2)) + 5) & 127;
    aux_2 ^= tally_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_45_1 = 0;
  int segment_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_45_1 = ((segment_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_45_2 = ((segment_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_45_1) & 127;
    acc_2 = (acc_2 + segment_45_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_59_1 = local_arr_1[aux_1 % 3];
  int pivot_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_91_1 == delta_91_2);
  assert(tally_83_1 == tally_83_2);
  assert(segment_45_1 == segment_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_59_1 == pivot_59_2);
}

int fn_R001396_9613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int delta_91 = (aux + st.buffer[1]) & 3;
  switch (delta_91)
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

  int tally_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_83 > 49)
  {
    acc = ((acc + (tally_83 * 2)) + 5) & 127;
    aux ^= tally_83 & 15;
  }
  else
  {
    acc = ((acc - tally_83) + 11) & 127;
    aux += 3;
  }
  int segment_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_45 = ((segment_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_45) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_59 = local_arr[aux % 3];
  acc = (acc + (pivot_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st_1 = {0};
  struct EventLog_R001396_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_85_1)
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

  switch (cursor_85_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_85_1 == cursor_85_2);
}

int fn_R001396_9613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_85 = (aux + st.buffer[1]) & 3;
  switch (cursor_85)
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

void fn_R001396_9613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_20_1) & 63;
  aux_2 = (aux_2 + segment_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 42)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 42)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_19_1 = 0;
  int threshold_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_19_1 = ((threshold_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_19_2 = ((threshold_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_19_1) & 127;
    acc_2 = (acc_2 + threshold_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_20_1 == segment_20_2);
  assert(offset_60_1 == offset_60_2);
  assert(threshold_19_1 == threshold_19_2);
}

int fn_R001396_9613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_20) & 63;
  acc ^= aux;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 42)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  int threshold_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_19 = ((threshold_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st_1 = {0};
  struct Vector3D_R001396_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_34_1 = 0;
  int accumulator_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_34_1 = ((accumulator_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_34_2 = ((accumulator_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_34_1) & 127;
    acc_2 = (acc_2 + accumulator_34_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_51_1 = local_arr_1[aux_1 % 3];
  int pivot_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_34_1 == accumulator_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_51_1 == pivot_51_2);
}

int fn_R001396_9613_14(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_34 = ((accumulator_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_34) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_51 = local_arr[aux % 3];
  acc = (acc + (pivot_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st_1 = {0};
  struct CipherContext_R001396_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_57_1)
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

  switch (window_57_2)
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

  int tally_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_44_1) & 63;
  aux_2 = (aux_2 + tally_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_12_1 = 0;
  int bound_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_12_1 = ((bound_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_12_2 = ((bound_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_12_1) & 127;
    acc_2 = (acc_2 + bound_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_57_1 == window_57_2);
  assert(tally_44_1 == tally_44_2);
  assert(bound_12_1 == bound_12_2);
}

int fn_R001396_9613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001396_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_57 = (aux + st.buffer[1]) & 3;
  switch (window_57)
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

  int tally_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_44) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_12 = ((bound_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st_1 = {0};
  struct Vector3D_R001396_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_19_1 = 0;
  int delta_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_19_1 = ((delta_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_19_2 = ((delta_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_19_1) & 127;
    acc_2 = (acc_2 + delta_19_2) & 127;
  }

  int weight_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_85_1 > 46)
  {
    acc_1 = ((acc_1 + (weight_85_1 * 2)) + 5) & 127;
    aux_1 ^= weight_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_85_2 > 46)
  {
    acc_2 = ((acc_2 + (weight_85_2 * 2)) + 5) & 127;
    aux_2 ^= weight_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(weight_85_1 == weight_85_2);
}

int fn_R001396_9613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001396_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_19 = ((delta_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_19) & 127;
  }

  int weight_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_85 > 46)
  {
    acc = ((acc + (weight_85 * 2)) + 5) & 127;
    aux ^= weight_85 & 15;
  }
  else
  {
    acc = ((acc - weight_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001396_9613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_78_1 = local_arr_1[aux_1 % 3];
  int accumulator_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_78_2 * 2)) & 127;
  int metric_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_83_1)
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

  switch (metric_83_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_78_1 == accumulator_78_2);
  assert(metric_83_1 == metric_83_2);
}

int fn_R001396_9613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_78 = local_arr[aux % 3];
  acc = (acc + (accumulator_78 * 2)) & 127;
  int metric_83 = (aux + st.buffer[1]) & 3;
  switch (metric_83)
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

void fn_R001396_9613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_26_1 > 38)
  {
    acc_1 = ((acc_1 + (factor_26_1 * 2)) + 5) & 127;
    aux_1 ^= factor_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_26_2 > 38)
  {
    acc_2 = ((acc_2 + (factor_26_2 * 2)) + 5) & 127;
    aux_2 ^= factor_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_26_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_26_1 == factor_26_2);
}

int fn_R001396_9613_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_26 > 38)
  {
    acc = ((acc + (factor_26 * 2)) + 5) & 127;
    aux ^= factor_26 & 15;
  }
  else
  {
    acc = ((acc - factor_26) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001396_9613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_39_1 = local_arr_1[aux_1 % 3];
  int window_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_39_2 * 2)) & 127;
  int tracker_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_59_1) & 63;
  aux_2 = (aux_2 + tracker_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_87_1 = 0;
  int damping_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_87_1 = ((damping_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_87_2 = ((damping_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_87_1) & 127;
    acc_2 = (acc_2 + damping_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_39_1 == window_39_2);
  assert(tracker_59_1 == tracker_59_2);
  assert(damping_87_1 == damping_87_2);
}

int fn_R001396_9613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int window_39 = local_arr[aux % 3];
  acc = (acc + (window_39 * 2)) & 127;
  int tracker_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_59) & 63;
  acc ^= aux;
  int damping_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_87 = ((damping_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_67_1) & 63;
  aux_2 = (aux_2 + tally_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_13_1 = local_arr_1[aux_1 % 3];
  int index_reg_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_13_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_67_1 = 0;
  int damping_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_67_1 = ((damping_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_67_2 = ((damping_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_67_1) & 127;
    acc_2 = (acc_2 + damping_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_67_1 == tally_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_13_1 == index_reg_13_2);
  assert(damping_67_1 == damping_67_2);
}

int fn_R001396_9613_20(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001396_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_13 = local_arr[aux % 3];
  acc = (acc + (index_reg_13 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_67 = ((damping_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001396_9613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st_1 = {0};
  struct EventLog_R001396_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_36_1) & 63;
  aux_2 = (aux_2 + coefficient_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_17_1 > 30)
  {
    acc_1 = ((acc_1 + (tracker_17_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_17_2 > 30)
  {
    acc_2 = ((acc_2 + (tracker_17_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_36_1 == coefficient_36_2);
  assert(tracker_17_1 == tracker_17_2);
}

int fn_R001396_9613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001396_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_36) & 63;
  acc ^= aux;
  int tracker_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_17 > 30)
  {
    acc = ((acc + (tracker_17 * 2)) + 5) & 127;
    aux ^= tracker_17 & 15;
  }
  else
  {
    acc = ((acc - tracker_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001396_0_1;
  int sec_r001396_0_2;
  int sec_r001396_1_1;
  int sec_r001396_1_2;
  int sec_r001396_2_1;
  int sec_r001396_2_2;
  int sec_r001396_3_1;
  int sec_r001396_3_2;
  int sec_r001396_4_1;
  int sec_r001396_4_2;
  int sec_r001396_5_1;
  int sec_r001396_5_2;
  int sec_r001396_6_1;
  int sec_r001396_6_2;
  int sec_r001396_7_1;
  int sec_r001396_7_2;
  int sec_r001396_8_1;
  int sec_r001396_8_2;
  int sec_r001396_9_1;
  int sec_r001396_9_2;
  int sec_r001396_10_1;
  int sec_r001396_10_2;
  int sec_r001396_11_1;
  int sec_r001396_11_2;
  int sec_r001396_12_1;
  int sec_r001396_12_2;
  int sec_r001396_13_1;
  int sec_r001396_13_2;
  int sec_r001396_14_1;
  int sec_r001396_14_2;
  int sec_r001396_15_1;
  int sec_r001396_15_2;
  int sec_r001396_16_1;
  int sec_r001396_16_2;
  int sec_r001396_17_1;
  int sec_r001396_17_2;
  int pub_r001396_0_1;
  int pub_r001396_0_2;
  int pub_r001396_1_1;
  int pub_r001396_1_2;
  int pub_r001396_2_1;
  int pub_r001396_2_2;
  int pub_r001396_3_1;
  int pub_r001396_3_2;
  int pub_r001396_4_1;
  int pub_r001396_4_2;
  int pub_r001396_5_1;
  int pub_r001396_5_2;
  int pub_r001396_6_1;
  int pub_r001396_6_2;
  int pub_r001396_7_1;
  int pub_r001396_7_2;
  int pub_r001396_8_1;
  int pub_r001396_8_2;
  int pub_r001396_9_1;
  int pub_r001396_9_2;
  int pub_r001396_10_1;
  int pub_r001396_10_2;
  int pub_r001396_11_1;
  int pub_r001396_11_2;
  int pub_r001396_12_1;
  int pub_r001396_12_2;
  int pub_r001396_13_1;
  int pub_r001396_13_2;
  int pub_r001396_14_1;
  int pub_r001396_14_2;
  int pub_r001396_15_1;
  int pub_r001396_15_2;
  int pub_r001396_16_1;
  int pub_r001396_16_2;
  int pub_r001396_17_1;
  int pub_r001396_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001396_0_1 >= (-100)) && (pub_r001396_0_1 <= 100));
  __CPROVER_assume((pub_r001396_0_2 >= (-100)) && (pub_r001396_0_2 <= 100));
  __CPROVER_assume((pub_r001396_1_1 >= (-100)) && (pub_r001396_1_1 <= 100));
  __CPROVER_assume((pub_r001396_1_2 >= (-100)) && (pub_r001396_1_2 <= 100));
  __CPROVER_assume((pub_r001396_2_1 >= (-100)) && (pub_r001396_2_1 <= 100));
  __CPROVER_assume((pub_r001396_2_2 >= (-100)) && (pub_r001396_2_2 <= 100));
  __CPROVER_assume((pub_r001396_3_1 >= (-100)) && (pub_r001396_3_1 <= 100));
  __CPROVER_assume((pub_r001396_3_2 >= (-100)) && (pub_r001396_3_2 <= 100));
  __CPROVER_assume((pub_r001396_4_1 >= (-100)) && (pub_r001396_4_1 <= 100));
  __CPROVER_assume((pub_r001396_4_2 >= (-100)) && (pub_r001396_4_2 <= 100));
  __CPROVER_assume((pub_r001396_5_1 >= (-100)) && (pub_r001396_5_1 <= 100));
  __CPROVER_assume((pub_r001396_5_2 >= (-100)) && (pub_r001396_5_2 <= 100));
  __CPROVER_assume((pub_r001396_6_1 >= (-100)) && (pub_r001396_6_1 <= 100));
  __CPROVER_assume((pub_r001396_6_2 >= (-100)) && (pub_r001396_6_2 <= 100));
  __CPROVER_assume((pub_r001396_7_1 >= (-100)) && (pub_r001396_7_1 <= 100));
  __CPROVER_assume((pub_r001396_7_2 >= (-100)) && (pub_r001396_7_2 <= 100));
  __CPROVER_assume((pub_r001396_8_1 >= (-100)) && (pub_r001396_8_1 <= 100));
  __CPROVER_assume((pub_r001396_8_2 >= (-100)) && (pub_r001396_8_2 <= 100));
  __CPROVER_assume((pub_r001396_9_1 >= (-100)) && (pub_r001396_9_1 <= 100));
  __CPROVER_assume((pub_r001396_9_2 >= (-100)) && (pub_r001396_9_2 <= 100));
  __CPROVER_assume((pub_r001396_10_1 >= (-100)) && (pub_r001396_10_1 <= 100));
  __CPROVER_assume((pub_r001396_10_2 >= (-100)) && (pub_r001396_10_2 <= 100));
  __CPROVER_assume((pub_r001396_11_1 >= (-100)) && (pub_r001396_11_1 <= 100));
  __CPROVER_assume((pub_r001396_11_2 >= (-100)) && (pub_r001396_11_2 <= 100));
  __CPROVER_assume((pub_r001396_12_1 >= (-100)) && (pub_r001396_12_1 <= 100));
  __CPROVER_assume((pub_r001396_12_2 >= (-100)) && (pub_r001396_12_2 <= 100));
  __CPROVER_assume((pub_r001396_13_1 >= (-100)) && (pub_r001396_13_1 <= 100));
  __CPROVER_assume((pub_r001396_13_2 >= (-100)) && (pub_r001396_13_2 <= 100));
  __CPROVER_assume((pub_r001396_14_1 >= (-100)) && (pub_r001396_14_1 <= 100));
  __CPROVER_assume((pub_r001396_14_2 >= (-100)) && (pub_r001396_14_2 <= 100));
  __CPROVER_assume((pub_r001396_15_1 >= (-100)) && (pub_r001396_15_1 <= 100));
  __CPROVER_assume((pub_r001396_15_2 >= (-100)) && (pub_r001396_15_2 <= 100));
  __CPROVER_assume((pub_r001396_16_1 >= (-100)) && (pub_r001396_16_1 <= 100));
  __CPROVER_assume((pub_r001396_16_2 >= (-100)) && (pub_r001396_16_2 <= 100));
  __CPROVER_assume((pub_r001396_17_1 >= (-100)) && (pub_r001396_17_1 <= 100));
  __CPROVER_assume((pub_r001396_17_2 >= (-100)) && (pub_r001396_17_2 <= 100));
  __CPROVER_assume((sec_r001396_0_1 >= 0) && (sec_r001396_0_1 <= 255));
  __CPROVER_assume((sec_r001396_0_2 >= 0) && (sec_r001396_0_2 <= 255));
  __CPROVER_assume((sec_r001396_1_1 >= 0) && (sec_r001396_1_1 <= 255));
  __CPROVER_assume((sec_r001396_1_2 >= 0) && (sec_r001396_1_2 <= 255));
  __CPROVER_assume((sec_r001396_2_1 >= 0) && (sec_r001396_2_1 <= 255));
  __CPROVER_assume((sec_r001396_2_2 >= 0) && (sec_r001396_2_2 <= 255));
  __CPROVER_assume((sec_r001396_3_1 >= 0) && (sec_r001396_3_1 <= 255));
  __CPROVER_assume((sec_r001396_3_2 >= 0) && (sec_r001396_3_2 <= 255));
  __CPROVER_assume((sec_r001396_4_1 >= 0) && (sec_r001396_4_1 <= 255));
  __CPROVER_assume((sec_r001396_4_2 >= 0) && (sec_r001396_4_2 <= 255));
  __CPROVER_assume((sec_r001396_5_1 >= 0) && (sec_r001396_5_1 <= 255));
  __CPROVER_assume((sec_r001396_5_2 >= 0) && (sec_r001396_5_2 <= 255));
  __CPROVER_assume((sec_r001396_6_1 >= 0) && (sec_r001396_6_1 <= 255));
  __CPROVER_assume((sec_r001396_6_2 >= 0) && (sec_r001396_6_2 <= 255));
  __CPROVER_assume((sec_r001396_7_1 >= 0) && (sec_r001396_7_1 <= 255));
  __CPROVER_assume((sec_r001396_7_2 >= 0) && (sec_r001396_7_2 <= 255));
  __CPROVER_assume((sec_r001396_8_1 >= 0) && (sec_r001396_8_1 <= 255));
  __CPROVER_assume((sec_r001396_8_2 >= 0) && (sec_r001396_8_2 <= 255));
  __CPROVER_assume((sec_r001396_9_1 >= 0) && (sec_r001396_9_1 <= 255));
  __CPROVER_assume((sec_r001396_9_2 >= 0) && (sec_r001396_9_2 <= 255));
  __CPROVER_assume((sec_r001396_10_1 >= 0) && (sec_r001396_10_1 <= 255));
  __CPROVER_assume((sec_r001396_10_2 >= 0) && (sec_r001396_10_2 <= 255));
  __CPROVER_assume((sec_r001396_11_1 >= 0) && (sec_r001396_11_1 <= 255));
  __CPROVER_assume((sec_r001396_11_2 >= 0) && (sec_r001396_11_2 <= 255));
  __CPROVER_assume((sec_r001396_12_1 >= 0) && (sec_r001396_12_1 <= 255));
  __CPROVER_assume((sec_r001396_12_2 >= 0) && (sec_r001396_12_2 <= 255));
  __CPROVER_assume((sec_r001396_13_1 >= 0) && (sec_r001396_13_1 <= 255));
  __CPROVER_assume((sec_r001396_13_2 >= 0) && (sec_r001396_13_2 <= 255));
  __CPROVER_assume((sec_r001396_14_1 >= 0) && (sec_r001396_14_1 <= 255));
  __CPROVER_assume((sec_r001396_14_2 >= 0) && (sec_r001396_14_2 <= 255));
  __CPROVER_assume((sec_r001396_15_1 >= 0) && (sec_r001396_15_1 <= 255));
  __CPROVER_assume((sec_r001396_15_2 >= 0) && (sec_r001396_15_2 <= 255));
  __CPROVER_assume((sec_r001396_16_1 >= 0) && (sec_r001396_16_1 <= 255));
  __CPROVER_assume((sec_r001396_16_2 >= 0) && (sec_r001396_16_2 <= 255));
  __CPROVER_assume((sec_r001396_17_1 >= 0) && (sec_r001396_17_1 <= 255));
  __CPROVER_assume((sec_r001396_17_2 >= 0) && (sec_r001396_17_2 <= 255));
  struct CipherContext_R001396_9613_0 st_var_0_1 = {0};
  struct CipherContext_R001396_9613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001396_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001396_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001396_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001396_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001396_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001396_0_2 + 7) & 15;
  struct StreamBuffer_R001396_9613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001396_9613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001396_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001396_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001396_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001396_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001396_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001396_0_2 + 9) & 15;
  struct Vector3D_R001396_9613_2 st_var_2_1 = {0};
  struct Vector3D_R001396_9613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001396_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001396_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001396_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001396_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001396_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001396_0_2 + 11) & 15;
  struct EventLog_R001396_9613_3 st_var_3_1 = {0};
  struct EventLog_R001396_9613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001396_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001396_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001396_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001396_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001396_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001396_0_2 + 13) & 15;
  union ColorPixel_R001396_9613_0 u_var_1;
  union ColorPixel_R001396_9613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001396_9613_0(sec_r001396_0_1, sec_r001396_1_1, pub_r001396_2_1, pub_r001396_3_1);
  int helper_flow_0_2 = fn_R001396_9613_0(sec_r001396_0_2, sec_r001396_1_2, pub_r001396_2_2, pub_r001396_3_2);
  fn_R001396_9613_0_2(sec_r001396_0_1, sec_r001396_1_1, pub_r001396_2_1, pub_r001396_3_1, sec_r001396_0_2, sec_r001396_1_2, pub_r001396_2_2, pub_r001396_3_2);
  int helper_flow_1_1 = fn_R001396_9613_1(sec_r001396_1_1, pub_r001396_2_1);
  int helper_flow_1_2 = fn_R001396_9613_1(sec_r001396_1_2, pub_r001396_2_2);
  fn_R001396_9613_1_2(sec_r001396_1_1, pub_r001396_2_1, sec_r001396_1_2, pub_r001396_2_2);
  int helper_flow_2_1 = fn_R001396_9613_2(sec_r001396_2_1, pub_r001396_3_1);
  int helper_flow_2_2 = fn_R001396_9613_2(sec_r001396_2_2, pub_r001396_3_2);
  fn_R001396_9613_2_2(sec_r001396_2_1, pub_r001396_3_1, sec_r001396_2_2, pub_r001396_3_2);
  int helper_flow_3_1 = fn_R001396_9613_3(sec_r001396_3_1, sec_r001396_4_1, pub_r001396_5_1, pub_r001396_6_1, pub_r001396_7_1);
  int helper_flow_3_2 = fn_R001396_9613_3(sec_r001396_3_2, sec_r001396_4_2, pub_r001396_5_2, pub_r001396_6_2, pub_r001396_7_2);
  fn_R001396_9613_3_2(sec_r001396_3_1, sec_r001396_4_1, pub_r001396_5_1, pub_r001396_6_1, pub_r001396_7_1, sec_r001396_3_2, sec_r001396_4_2, pub_r001396_5_2, pub_r001396_6_2, pub_r001396_7_2);
  int helper_flow_4_1 = fn_R001396_9613_4(sec_r001396_4_1, sec_r001396_5_1, pub_r001396_6_1);
  int helper_flow_4_2 = fn_R001396_9613_4(sec_r001396_4_2, sec_r001396_5_2, pub_r001396_6_2);
  fn_R001396_9613_4_2(sec_r001396_4_1, sec_r001396_5_1, pub_r001396_6_1, sec_r001396_4_2, sec_r001396_5_2, pub_r001396_6_2);
  int helper_flow_5_1 = fn_R001396_9613_5(sec_r001396_5_1, sec_r001396_6_1, pub_r001396_7_1);
  int helper_flow_5_2 = fn_R001396_9613_5(sec_r001396_5_2, sec_r001396_6_2, pub_r001396_7_2);
  fn_R001396_9613_5_2(sec_r001396_5_1, sec_r001396_6_1, pub_r001396_7_1, sec_r001396_5_2, sec_r001396_6_2, pub_r001396_7_2);
  int helper_flow_6_1 = fn_R001396_9613_6(sec_r001396_6_1, pub_r001396_7_1);
  int helper_flow_6_2 = fn_R001396_9613_6(sec_r001396_6_2, pub_r001396_7_2);
  fn_R001396_9613_6_2(sec_r001396_6_1, pub_r001396_7_1, sec_r001396_6_2, pub_r001396_7_2);
  int stage_v_0_1 = ((sec_r001396_14_1 + (pub_r001396_0_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001396_14_2 + (pub_r001396_0_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001396_10_1 + (pub_r001396_14_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001396_10_2 + (pub_r001396_14_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001396_13_1 * 2) + 46) & 63;
  int stage_v_2_2 = ((pub_r001396_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001396_16_1 + (pub_r001396_8_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001396_16_2 + (pub_r001396_8_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001396_2_1 * 2) + 22) & 63;
  int stage_v_4_2 = ((pub_r001396_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001396_3_1 * 2) + 41) & 63;
  int stage_v_5_2 = ((pub_r001396_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001396_1_1 + (pub_r001396_3_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001396_1_2 + (pub_r001396_3_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001396_10_1 * 2) + 29) & 63;
  int stage_v_7_2 = ((pub_r001396_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001396_0_1 * 2) + 10) & 63;
  int stage_v_8_2 = ((pub_r001396_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001396_16_1 * 2) + 46) & 63;
  int stage_v_9_2 = ((pub_r001396_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001396_16_1 * 2) + 26) & 63;
  int stage_v_10_2 = ((pub_r001396_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((helper_flow_4_1 + (pub_r001396_5_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_4_2 + (pub_r001396_5_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001396_16_1 * 2) + 44) & 63;
  int stage_v_12_2 = ((pub_r001396_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((helper_flow_0_1 + (pub_r001396_12_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_0_2 + (pub_r001396_12_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001396_3_1 * 2) + 30) & 63;
  int stage_v_14_2 = ((pub_r001396_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((stage_v_13_1 + (pub_r001396_0_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_13_2 + (pub_r001396_0_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_1_1 + (pub_r001396_15_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_1_2 + (pub_r001396_15_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001396_6_1 + (pub_r001396_4_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001396_6_2 + (pub_r001396_4_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((stage_v_0_1 + (pub_r001396_13_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((stage_v_0_2 + (pub_r001396_13_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((helper_flow_4_1 + (pub_r001396_6_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((helper_flow_4_2 + (pub_r001396_6_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001396_9_1 * 2) + 7) & 63;
  int stage_v_20_2 = ((pub_r001396_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((stage_v_0_1 + (pub_r001396_2_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_0_2 + (pub_r001396_2_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_13_1 + (pub_r001396_17_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_13_2 + (pub_r001396_17_2 * 2)) + 71) & 127;
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
  int stage_v_23_1 = ((stage_v_19_1 + (pub_r001396_11_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_19_2 + (pub_r001396_11_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((pub_r001396_10_1 * 2) + 39) & 63;
  int stage_v_24_2 = ((pub_r001396_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001396_12_1 * 2) + 17) & 63;
  int stage_v_25_2 = ((pub_r001396_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001396_9_1 * 2) + 37) & 63;
  int stage_v_26_2 = ((pub_r001396_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001396_16_1 * 2) + 40) & 63;
  int stage_v_27_2 = ((pub_r001396_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((stage_v_17_1 + (pub_r001396_1_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_17_2 + (pub_r001396_1_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_6_1 + (pub_r001396_3_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_6_2 + (pub_r001396_3_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001396_13_1 + (pub_r001396_15_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001396_13_2 + (pub_r001396_15_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001396_15_1 * 2) + 38) & 63;
  int stage_v_31_2 = ((pub_r001396_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_22_1 + (pub_r001396_5_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_22_2 + (pub_r001396_5_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001396_13_1 + (pub_r001396_5_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001396_13_2 + (pub_r001396_5_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001396_1_1 * 2) + 6) & 63;
  int stage_v_34_2 = ((pub_r001396_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((sec_r001396_1_1 + (pub_r001396_7_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001396_1_2 + (pub_r001396_7_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001396_4_1 * 2) + 8) & 63;
  int stage_v_36_2 = ((pub_r001396_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((sec_r001396_3_1 + (pub_r001396_9_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((sec_r001396_3_2 + (pub_r001396_9_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((sec_r001396_4_1 + (pub_r001396_10_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001396_4_2 + (pub_r001396_10_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((sec_r001396_11_1 + (pub_r001396_5_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001396_11_2 + (pub_r001396_5_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001396_7_1 * 2) + 10) & 63;
  int stage_v_40_2 = ((pub_r001396_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_38_1 + (pub_r001396_7_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_38_2 + (pub_r001396_7_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001396_17_1 * 2) + 16) & 63;
  int stage_v_42_2 = ((pub_r001396_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001396_7_1 * 2) + 42) & 63;
  int stage_v_43_2 = ((pub_r001396_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((stage_v_38_1 + (pub_r001396_0_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_38_2 + (pub_r001396_0_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001396_5_1 * 2) + 8) & 63;
  int stage_v_45_2 = ((pub_r001396_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001396_8_1 * 2) + 48) & 63;
  int stage_v_46_2 = ((pub_r001396_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_33_1 + (pub_r001396_5_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_33_2 + (pub_r001396_5_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001396_5_1 * 2) + 32) & 63;
  int stage_v_48_2 = ((pub_r001396_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((stage_v_28_1 + (pub_r001396_5_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_28_2 + (pub_r001396_5_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_16_1 + (pub_r001396_11_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_16_2 + (pub_r001396_11_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_44_1 + (pub_r001396_15_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_44_2 + (pub_r001396_15_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((stage_v_29_1 + (pub_r001396_6_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_29_2 + (pub_r001396_6_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((stage_v_51_1 + (pub_r001396_15_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_51_2 + (pub_r001396_15_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001396_14_1 * 2) + 16) & 63;
  int stage_v_54_2 = ((pub_r001396_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001396_9_1 * 2) + 17) & 63;
  int stage_v_55_2 = ((pub_r001396_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001396_5_1 * 2) + 46) & 63;
  int stage_v_56_2 = ((pub_r001396_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_0_1 + (pub_r001396_11_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_0_2 + (pub_r001396_11_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001396_4_1 * 2) + 37) & 63;
  int stage_v_58_2 = ((pub_r001396_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((helper_flow_6_1 + (pub_r001396_13_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((helper_flow_6_2 + (pub_r001396_13_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((helper_flow_1_1 + (pub_r001396_4_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((helper_flow_1_2 + (pub_r001396_4_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_19_1 + (pub_r001396_11_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_19_2 + (pub_r001396_11_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_29_1 + (pub_r001396_17_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_29_2 + (pub_r001396_17_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((helper_flow_4_1 + (pub_r001396_2_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((helper_flow_4_2 + (pub_r001396_2_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001396_1_1 + (pub_r001396_10_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001396_1_2 + (pub_r001396_10_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001396_7_1 * 2) + 19) & 63;
  int stage_v_65_2 = ((pub_r001396_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001396_9_1 * 2) + 5) & 63;
  int stage_v_66_2 = ((pub_r001396_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_41_1 + (pub_r001396_13_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_41_2 + (pub_r001396_13_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_38_1 + (pub_r001396_1_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_38_2 + (pub_r001396_1_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001396_0_1 * 2) + 37) & 63;
  int stage_v_69_2 = ((pub_r001396_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((helper_flow_4_1 + (pub_r001396_4_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((helper_flow_4_2 + (pub_r001396_4_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_15_1 + (pub_r001396_4_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_15_2 + (pub_r001396_4_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_51_1 + (pub_r001396_16_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_51_2 + (pub_r001396_16_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_30_1 + (pub_r001396_5_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_30_2 + (pub_r001396_5_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001396_13_1 * 2) + 9) & 63;
  int stage_v_74_2 = ((pub_r001396_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_67_1 + (pub_r001396_10_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_67_2 + (pub_r001396_10_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_70_1 + (pub_r001396_10_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_70_2 + (pub_r001396_10_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((helper_flow_1_1 + (pub_r001396_9_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_1_2 + (pub_r001396_9_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_70_1 + (pub_r001396_13_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_70_2 + (pub_r001396_13_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_6_1 + (pub_r001396_15_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_6_2 + (pub_r001396_15_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((pub_r001396_5_1 * 2) + 21) & 63;
  int stage_v_80_2 = ((pub_r001396_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_67_1 + (pub_r001396_6_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_67_2 + (pub_r001396_6_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((sec_r001396_8_1 + (pub_r001396_16_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((sec_r001396_8_2 + (pub_r001396_16_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_72_1 + (pub_r001396_6_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_72_2 + (pub_r001396_6_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((sec_r001396_2_1 + (pub_r001396_1_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((sec_r001396_2_2 + (pub_r001396_1_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001396_16_1 * 2) + 26) & 63;
  int stage_v_85_2 = ((pub_r001396_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((sec_r001396_17_1 + (pub_r001396_13_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((sec_r001396_17_2 + (pub_r001396_13_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((helper_flow_2_1 + (pub_r001396_9_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((helper_flow_2_2 + (pub_r001396_9_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_47_1 + (pub_r001396_2_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_47_2 + (pub_r001396_2_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((pub_r001396_13_1 * 2) + 29) & 63;
  int stage_v_89_2 = ((pub_r001396_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001396_17_1 * 2) + 27) & 63;
  int stage_v_90_2 = ((pub_r001396_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((sec_r001396_14_1 + (pub_r001396_10_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001396_14_2 + (pub_r001396_10_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((pub_r001396_8_1 * 2) + 12) & 63;
  int stage_v_92_2 = ((pub_r001396_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_39_1 + (pub_r001396_12_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_39_2 + (pub_r001396_12_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_11_1 + (pub_r001396_6_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_11_2 + (pub_r001396_6_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((sec_r001396_10_1 + (pub_r001396_10_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((sec_r001396_10_2 + (pub_r001396_10_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001396_4_1 * 2) + 48) & 63;
  int stage_v_96_2 = ((pub_r001396_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((sec_r001396_17_1 + (pub_r001396_13_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((sec_r001396_17_2 + (pub_r001396_13_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_22_1 + (pub_r001396_2_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_22_2 + (pub_r001396_2_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_68_1 + (pub_r001396_11_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_68_2 + (pub_r001396_11_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001396_14_1 * 2) + 8) & 63;
  int stage_v_100_2 = ((pub_r001396_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001396_13_1 * 2) + 21) & 63;
  int stage_v_101_2 = ((pub_r001396_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_21_1 + (pub_r001396_9_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_21_2 + (pub_r001396_9_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((pub_r001396_16_1 * 2) + 45) & 63;
  int stage_v_103_2 = ((pub_r001396_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_86_1 + (pub_r001396_14_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_86_2 + (pub_r001396_14_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((helper_flow_1_1 + (pub_r001396_4_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((helper_flow_1_2 + (pub_r001396_4_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_93_1 + (pub_r001396_7_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_93_2 + (pub_r001396_7_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001396_6_1 * 2) + 47) & 63;
  int stage_v_107_2 = ((pub_r001396_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((sec_r001396_14_1 + (pub_r001396_15_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((sec_r001396_14_2 + (pub_r001396_15_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((pub_r001396_0_1 * 2) + 41) & 63;
  int stage_v_109_2 = ((pub_r001396_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001396_6_1 * 2) + 42) & 63;
  int stage_v_110_2 = ((pub_r001396_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((sec_r001396_0_1 + (pub_r001396_0_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((sec_r001396_0_2 + (pub_r001396_0_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_15_1 + (pub_r001396_9_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_15_2 + (pub_r001396_9_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001396_16_1 * 2) + 21) & 63;
  int stage_v_113_2 = ((pub_r001396_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_38_1 + (pub_r001396_16_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_38_2 + (pub_r001396_16_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((sec_r001396_11_1 + (pub_r001396_3_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((sec_r001396_11_2 + (pub_r001396_3_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((sec_r001396_0_1 + (pub_r001396_15_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001396_0_2 + (pub_r001396_15_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001396_15_1 * 2) + 19) & 63;
  int stage_v_117_2 = ((pub_r001396_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((sec_r001396_9_1 + (pub_r001396_13_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((sec_r001396_9_2 + (pub_r001396_13_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_68_1 + (pub_r001396_0_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_68_2 + (pub_r001396_0_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001396_12_1 + (pub_r001396_1_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001396_12_2 + (pub_r001396_1_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((helper_flow_4_1 + (pub_r001396_7_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((helper_flow_4_2 + (pub_r001396_7_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_11_1 + (pub_r001396_3_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_11_2 + (pub_r001396_3_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_22_1 + (pub_r001396_3_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_22_2 + (pub_r001396_3_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001396_11_1 * 2) + 18) & 63;
  int stage_v_124_2 = ((pub_r001396_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_118_1 + (pub_r001396_8_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_118_2 + (pub_r001396_8_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_73_1 + (pub_r001396_11_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_73_2 + (pub_r001396_11_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_22_1 + (pub_r001396_1_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_22_2 + (pub_r001396_1_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_32_1 + (pub_r001396_12_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_32_2 + (pub_r001396_12_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_121_1 + (pub_r001396_12_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_121_2 + (pub_r001396_12_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((sec_r001396_3_1 + (pub_r001396_0_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((sec_r001396_3_2 + (pub_r001396_0_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((sec_r001396_8_1 + (pub_r001396_6_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((sec_r001396_8_2 + (pub_r001396_6_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((pub_r001396_15_1 * 2) + 32) & 63;
  int stage_v_132_2 = ((pub_r001396_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((sec_r001396_9_1 + (pub_r001396_3_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001396_9_2 + (pub_r001396_3_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_15_1 + (pub_r001396_7_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_15_2 + (pub_r001396_7_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_29_1 + (pub_r001396_14_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_29_2 + (pub_r001396_14_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_128_1 + (pub_r001396_11_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_128_2 + (pub_r001396_11_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_75_1 + (pub_r001396_10_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_75_2 + (pub_r001396_10_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_134_1 + (pub_r001396_17_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_134_2 + (pub_r001396_17_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((stage_v_137_1 + (pub_r001396_16_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_137_2 + (pub_r001396_16_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_111_1 + (pub_r001396_8_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_111_2 + (pub_r001396_8_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_32_1 + (pub_r001396_14_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_32_2 + (pub_r001396_14_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001396_11_1 * 2) + 30) & 63;
  int stage_v_142_2 = ((pub_r001396_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_33_1 + (pub_r001396_1_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_33_2 + (pub_r001396_1_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_99_1 + (pub_r001396_5_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_99_2 + (pub_r001396_5_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((helper_flow_2_1 + (pub_r001396_5_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((helper_flow_2_2 + (pub_r001396_5_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((pub_r001396_17_1 * 2) + 41) & 63;
  int stage_v_146_2 = ((pub_r001396_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001396_3_1 * 2) + 10) & 63;
  int stage_v_147_2 = ((pub_r001396_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001396_0_1 * 2) + 17) & 63;
  int stage_v_148_2 = ((pub_r001396_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001396_14_1 * 2) + 10) & 63;
  int stage_v_149_2 = ((pub_r001396_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_108_1 + (pub_r001396_1_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_108_2 + (pub_r001396_1_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((sec_r001396_7_1 + (pub_r001396_11_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((sec_r001396_7_2 + (pub_r001396_11_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_136_1 + (pub_r001396_11_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_136_2 + (pub_r001396_11_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_32_1 + (pub_r001396_2_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_32_2 + (pub_r001396_2_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001396_10_1 * 2) + 16) & 63;
  int stage_v_154_2 = ((pub_r001396_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_60_1 + (pub_r001396_16_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_60_2 + (pub_r001396_16_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_98_1 + (pub_r001396_5_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_98_2 + (pub_r001396_5_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001396_0_1 * 2) + 7) & 63;
  int stage_v_157_2 = ((pub_r001396_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_140_1 + (pub_r001396_7_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_140_2 + (pub_r001396_7_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_82_1 + (pub_r001396_8_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_82_2 + (pub_r001396_8_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_28_1 + (pub_r001396_2_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_28_2 + (pub_r001396_2_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_120_1 + (pub_r001396_16_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_120_2 + (pub_r001396_16_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_137_1 + (pub_r001396_9_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_137_2 + (pub_r001396_9_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_153_1 + (pub_r001396_10_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_153_2 + (pub_r001396_10_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_52_1 + (pub_r001396_11_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_52_2 + (pub_r001396_11_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001396_1_1 * 2) + 34) & 63;
  int stage_v_165_2 = ((pub_r001396_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_52_1 + (pub_r001396_14_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_52_2 + (pub_r001396_14_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_41_1 + (pub_r001396_13_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_41_2 + (pub_r001396_13_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_163_1 + (pub_r001396_15_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_163_2 + (pub_r001396_15_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001396_0_1 * 2) + 11) & 63;
  int stage_v_169_2 = ((pub_r001396_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_73_1 + (pub_r001396_3_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_73_2 + (pub_r001396_3_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_140_1 + (pub_r001396_6_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_140_2 + (pub_r001396_6_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((sec_r001396_12_1 + (pub_r001396_15_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((sec_r001396_12_2 + (pub_r001396_15_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_6_1 + (pub_r001396_4_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_6_2 + (pub_r001396_4_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_156_1 + (pub_r001396_16_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_156_2 + (pub_r001396_16_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001396_4_1 * 2) + 13) & 63;
  int stage_v_175_2 = ((pub_r001396_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001396_17_1 * 2) + 19) & 63;
  int stage_v_176_2 = ((pub_r001396_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((helper_flow_0_1 + (pub_r001396_1_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((helper_flow_0_2 + (pub_r001396_1_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_122_1 + (pub_r001396_7_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_122_2 + (pub_r001396_7_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((sec_r001396_0_1 + (pub_r001396_1_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((sec_r001396_0_2 + (pub_r001396_1_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001396_1_1 * 2) + 21) & 63;
  int stage_v_180_2 = ((pub_r001396_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001396_11_1 * 2) + 15) & 63;
  int stage_v_181_2 = ((pub_r001396_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001396_4_1 * 2) + 43) & 63;
  int stage_v_182_2 = ((pub_r001396_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_137_1 + (pub_r001396_10_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_137_2 + (pub_r001396_10_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((helper_flow_0_1 + (pub_r001396_15_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((helper_flow_0_2 + (pub_r001396_15_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_141_1 + (pub_r001396_12_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_141_2 + (pub_r001396_12_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((sec_r001396_13_1 + (pub_r001396_0_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((sec_r001396_13_2 + (pub_r001396_0_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((sec_r001396_11_1 + (pub_r001396_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((sec_r001396_11_2 + (pub_r001396_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001396_9_1 * 2) + 31) & 63;
  int stage_v_188_2 = ((pub_r001396_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_17_1 + (pub_r001396_2_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_17_2 + (pub_r001396_2_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_3_1 + (pub_r001396_3_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_3_2 + (pub_r001396_3_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_121_1 + (pub_r001396_0_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_121_2 + (pub_r001396_0_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_111_1 + (pub_r001396_8_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_111_2 + (pub_r001396_8_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_94_1 + (pub_r001396_8_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_94_2 + (pub_r001396_8_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001396_6_1 * 2) + 17) & 63;
  int stage_v_194_2 = ((pub_r001396_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_11_1 + (pub_r001396_14_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_11_2 + (pub_r001396_14_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001396_17_1 * 2) + 21) & 63;
  int stage_v_196_2 = ((pub_r001396_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_32_1 + (pub_r001396_15_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_32_2 + (pub_r001396_15_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_37_1 + (pub_r001396_4_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_37_2 + (pub_r001396_4_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_163_1 + (pub_r001396_16_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_163_2 + (pub_r001396_16_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001396_11_1 * 2) + 18) & 63;
  int stage_v_200_2 = ((pub_r001396_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((sec_r001396_16_1 + (pub_r001396_14_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001396_16_2 + (pub_r001396_14_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001396_11_1 * 2) + 18) & 63;
  int stage_v_202_2 = ((pub_r001396_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((sec_r001396_12_1 + (pub_r001396_7_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001396_12_2 + (pub_r001396_7_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((sec_r001396_4_1 + (pub_r001396_12_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((sec_r001396_4_2 + (pub_r001396_12_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001396_14_1 * 2) + 49) & 63;
  int stage_v_205_2 = ((pub_r001396_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((sec_r001396_8_1 + (pub_r001396_1_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((sec_r001396_8_2 + (pub_r001396_1_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((pub_r001396_9_1 * 2) + 46) & 63;
  int stage_v_207_2 = ((pub_r001396_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_127_1 + (pub_r001396_0_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_127_2 + (pub_r001396_0_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_127_1 + (pub_r001396_16_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_127_2 + (pub_r001396_16_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_75_1 + (pub_r001396_6_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_75_2 + (pub_r001396_6_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_129_1 + (pub_r001396_1_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_129_2 + (pub_r001396_1_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001396_1_1 * 2) + 44) & 63;
  int stage_v_212_2 = ((pub_r001396_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_126_1 + (pub_r001396_11_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_126_2 + (pub_r001396_11_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_81_1 + (pub_r001396_12_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_81_2 + (pub_r001396_12_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_16_1 + (pub_r001396_14_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_16_2 + (pub_r001396_14_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_152_1 + (pub_r001396_14_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_152_2 + (pub_r001396_14_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((pub_r001396_17_1 * 2) + 45) & 63;
  int stage_v_217_2 = ((pub_r001396_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001396_16_1 * 2) + 39) & 63;
  int stage_v_218_2 = ((pub_r001396_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001396_11_1 * 2) + 38) & 63;
  int stage_v_219_2 = ((pub_r001396_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001396_16_1 * 2) + 45) & 63;
  int stage_v_220_2 = ((pub_r001396_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_19_1 + (pub_r001396_11_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_19_2 + (pub_r001396_11_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001396_7_1 == pub_r001396_7_2);
  __CPROVER_assume(sec_r001396_6_1 != sec_r001396_6_2);
  __CPROVER_assume(pub_r001396_13_1 == pub_r001396_13_2);
  __CPROVER_assume(sec_r001396_8_1 != sec_r001396_8_2);
  __CPROVER_assume(sec_r001396_14_1 != sec_r001396_14_2);
  __CPROVER_assume(pub_r001396_16_1 == pub_r001396_16_2);
  __CPROVER_assume(sec_r001396_17_1 != sec_r001396_17_2);
  __CPROVER_assume(sec_r001396_16_1 != sec_r001396_16_2);
  __CPROVER_assume(pub_r001396_5_1 == pub_r001396_5_2);
  __CPROVER_assume(sec_r001396_5_1 != sec_r001396_5_2);
  __CPROVER_assume(pub_r001396_10_1 == pub_r001396_10_2);
  __CPROVER_assume(pub_r001396_8_1 == pub_r001396_8_2);
  __CPROVER_assume(sec_r001396_13_1 != sec_r001396_13_2);
  __CPROVER_assume(sec_r001396_4_1 != sec_r001396_4_2);
  __CPROVER_assume(pub_r001396_15_1 == pub_r001396_15_2);
  __CPROVER_assume(sec_r001396_11_1 != sec_r001396_11_2);
  __CPROVER_assume(pub_r001396_3_1 == pub_r001396_3_2);
  __CPROVER_assume(sec_r001396_15_1 != sec_r001396_15_2);
  __CPROVER_assume(pub_r001396_14_1 == pub_r001396_14_2);
  __CPROVER_assume(pub_r001396_12_1 == pub_r001396_12_2);
  __CPROVER_assume(sec_r001396_1_1 != sec_r001396_1_2);
  __CPROVER_assume(sec_r001396_2_1 != sec_r001396_2_2);
  __CPROVER_assume(sec_r001396_10_1 != sec_r001396_10_2);
  __CPROVER_assume(pub_r001396_2_1 == pub_r001396_2_2);
  __CPROVER_assume(pub_r001396_17_1 == pub_r001396_17_2);
  __CPROVER_assume(sec_r001396_12_1 != sec_r001396_12_2);
  __CPROVER_assume(pub_r001396_9_1 == pub_r001396_9_2);
  __CPROVER_assume(pub_r001396_11_1 == pub_r001396_11_2);
  __CPROVER_assume(sec_r001396_9_1 != sec_r001396_9_2);
  __CPROVER_assume(sec_r001396_0_1 != sec_r001396_0_2);
  __CPROVER_assume(sec_r001396_7_1 != sec_r001396_7_2);
  __CPROVER_assume(pub_r001396_1_1 == pub_r001396_1_2);
  __CPROVER_assume(sec_r001396_3_1 != sec_r001396_3_2);
  __CPROVER_assume(pub_r001396_0_1 == pub_r001396_0_2);
  __CPROVER_assume(pub_r001396_4_1 == pub_r001396_4_2);
  __CPROVER_assume(pub_r001396_6_1 == pub_r001396_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.code == st_var_3_2.code);
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
}


