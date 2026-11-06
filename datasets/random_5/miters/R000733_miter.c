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
struct MatrixBlock_R000733_3313_0
{
  int density;
  short dim;
  short scale;
  unsigned char determinant;
  int trace;
  int stride;
  int buffer[3];
};
struct Transaction_R000733_3313_1
{
  unsigned char status;
  short balance;
  short account_id;
  int buffer[3];
};
struct SensorNode_R000733_3313_2
{
  int gain;
  int reading;
  short calib;
  unsigned char offset;
  unsigned char threshold;
  int buffer[3];
};
union PacketPayload_R000733_3313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000733_3313_1
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
void fn_R000733_3313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_97_1)
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

  switch (margin_97_2)
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

  int vector_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_85_1) & 63;
  aux_2 = (aux_2 + vector_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_97_1 == margin_97_2);
  assert(vector_85_1 == vector_85_2);
}

int fn_R000733_3313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_97 = (aux + st.buffer[1]) & 3;
  switch (margin_97)
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

  int vector_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000733_3313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_77_1)
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

  switch (offset_77_2)
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
  int residue_70_1 = local_arr_1[aux_1 % 3];
  int residue_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_70_2 * 2)) & 127;
  int margin_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_74_1 > 47)
  {
    acc_1 = ((acc_1 + (margin_74_1 * 2)) + 5) & 127;
    aux_1 ^= margin_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_74_2 > 47)
  {
    acc_2 = ((acc_2 + (margin_74_2 * 2)) + 5) & 127;
    aux_2 ^= margin_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_77_1 == offset_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_70_1 == residue_70_2);
  assert(margin_74_1 == margin_74_2);
}

int fn_R000733_3313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_77 = (aux + st.buffer[1]) & 3;
  switch (offset_77)
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
  int residue_70 = local_arr[aux % 3];
  acc = (acc + (residue_70 * 2)) & 127;
  int margin_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_74 > 47)
  {
    acc = ((acc + (margin_74 * 2)) + 5) & 127;
    aux ^= margin_74 & 15;
  }
  else
  {
    acc = ((acc - margin_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_96_1 = local_arr_1[aux_1 % 3];
  int tally_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_72_1 > 23)
  {
    acc_1 = ((acc_1 + (index_reg_72_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_72_2 > 23)
  {
    acc_2 = ((acc_2 + (index_reg_72_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_56_1) & 63;
  aux_2 = (aux_2 + checksum_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_96_1 == tally_96_2);
  assert(index_reg_72_1 == index_reg_72_2);
  assert(checksum_56_1 == checksum_56_2);
}

int fn_R000733_3313_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tally_96 = local_arr[aux % 3];
  acc = (acc + (tally_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_72 > 23)
  {
    acc = ((acc + (index_reg_72 * 2)) + 5) & 127;
    aux ^= index_reg_72 & 15;
  }
  else
  {
    acc = ((acc - index_reg_72) + 11) & 127;
    aux += 3;
  }
  int checksum_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000733_3313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_79_1)
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

  switch (damping_79_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_79_1 == damping_79_2);
}

int fn_R000733_3313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_79 = (aux + st.buffer[1]) & 3;
  switch (damping_79)
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

void fn_R000733_3313_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_61_1 = local_arr_1[aux_1 % 3];
  int parity_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_61_1 == parity_61_2);
}

int fn_R000733_3313_4(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_61 = local_arr[aux % 3];
  acc = (acc + (parity_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_24_1 = local_arr_1[aux_1 % 3];
  int margin_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_24_2 * 2)) & 127;
  int pivot_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_41_1)
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

  switch (pivot_41_2)
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

  int tally_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_76_1) & 63;
  aux_2 = (aux_2 + tally_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_32_1 > 26)
  {
    acc_1 = ((acc_1 + (checksum_32_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_32_2 > 26)
  {
    acc_2 = ((acc_2 + (checksum_32_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_24_1 == margin_24_2);
  assert(pivot_41_1 == pivot_41_2);
  assert(tally_76_1 == tally_76_2);
  assert(checksum_32_1 == checksum_32_2);
}

int fn_R000733_3313_5(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int margin_24 = local_arr[aux % 3];
  acc = (acc + (margin_24 * 2)) & 127;
  int pivot_41 = (aux + st.buffer[1]) & 3;
  switch (pivot_41)
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

  int tally_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_76) & 63;
  acc ^= aux;
  int checksum_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_32 > 26)
  {
    acc = ((acc + (checksum_32 * 2)) + 5) & 127;
    aux ^= checksum_32 & 15;
  }
  else
  {
    acc = ((acc - checksum_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_69_1 = local_arr_1[aux_1 % 3];
  int anchor_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_69_2 * 2)) & 127;
  int residue_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_28_1)
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

  switch (residue_28_2)
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

  int cursor_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_35_1) & 63;
  aux_2 = (aux_2 + cursor_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_81_1 > 24)
  {
    acc_1 = ((acc_1 + (anchor_81_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_81_2 > 24)
  {
    acc_2 = ((acc_2 + (anchor_81_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_69_1 == anchor_69_2);
  assert(residue_28_1 == residue_28_2);
  assert(cursor_35_1 == cursor_35_2);
  assert(anchor_81_1 == anchor_81_2);
}

int fn_R000733_3313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int anchor_69 = local_arr[aux % 3];
  acc = (acc + (anchor_69 * 2)) & 127;
  int residue_28 = (aux + st.buffer[1]) & 3;
  switch (residue_28)
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

  int cursor_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_35) & 63;
  acc ^= aux;
  int anchor_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_81 > 24)
  {
    acc = ((acc + (anchor_81 * 2)) + 5) & 127;
    aux ^= anchor_81 & 15;
  }
  else
  {
    acc = ((acc - anchor_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_96_1 = local_arr_1[aux_1 % 3];
  int sample_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_96_1 == sample_96_2);
}

int fn_R000733_3313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int sample_96 = local_arr[aux % 3];
  acc = (acc + (sample_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_38_1 = local_arr_1[aux_1 % 3];
  int pivot_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_38_1 == pivot_38_2);
}

int fn_R000733_3313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int pivot_38 = local_arr[aux % 3];
  acc = (acc + (pivot_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int sample_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_19_1)
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

  switch (sample_19_2)
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
  int metric_63_1 = local_arr_1[aux_1 % 3];
  int metric_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_63_2 * 2)) & 127;
  int offset_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_84_1 > 20)
  {
    acc_1 = ((acc_1 + (offset_84_1 * 2)) + 5) & 127;
    aux_1 ^= offset_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_84_2 > 20)
  {
    acc_2 = ((acc_2 + (offset_84_2 * 2)) + 5) & 127;
    aux_2 ^= offset_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_84_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_19_1 == sample_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_63_1 == metric_63_2);
  assert(offset_84_1 == offset_84_2);
}

int fn_R000733_3313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int sample_19 = (aux + st.buffer[1]) & 3;
  switch (sample_19)
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
  int metric_63 = local_arr[aux % 3];
  acc = (acc + (metric_63 * 2)) & 127;
  int offset_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_84 > 20)
  {
    acc = ((acc + (offset_84 * 2)) + 5) & 127;
    aux ^= offset_84 & 15;
  }
  else
  {
    acc = ((acc - offset_84) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_98_1)
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

  switch (segment_98_2)
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

  int parity_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_61_1 > 19)
  {
    acc_1 = ((acc_1 + (parity_61_1 * 2)) + 5) & 127;
    aux_1 ^= parity_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_61_2 > 19)
  {
    acc_2 = ((acc_2 + (parity_61_2 * 2)) + 5) & 127;
    aux_2 ^= parity_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_61_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_14_1) & 63;
  aux_2 = (aux_2 + cursor_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_98_1 == segment_98_2);
  assert(parity_61_1 == parity_61_2);
  assert(cursor_14_1 == cursor_14_2);
}

int fn_R000733_3313_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_98 = (aux + st.buffer[1]) & 3;
  switch (segment_98)
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

  int parity_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_61 > 19)
  {
    acc = ((acc + (parity_61 * 2)) + 5) & 127;
    aux ^= parity_61 & 15;
  }
  else
  {
    acc = ((acc - parity_61) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000733_3313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int anchor_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_67_1)
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

  switch (anchor_67_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_16_1 = local_arr_1[aux_1 % 3];
  int delta_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_16_2 * 2)) & 127;
  int accumulator_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_22_1) & 63;
  aux_2 = (aux_2 + accumulator_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_25_1 > 17)
  {
    acc_1 = ((acc_1 + (window_25_1 * 2)) + 5) & 127;
    aux_1 ^= window_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_25_2 > 17)
  {
    acc_2 = ((acc_2 + (window_25_2 * 2)) + 5) & 127;
    aux_2 ^= window_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_67_1 == anchor_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_16_1 == delta_16_2);
  assert(accumulator_22_1 == accumulator_22_2);
  assert(window_25_1 == window_25_2);
}

int fn_R000733_3313_11(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int anchor_67 = (aux + st.buffer[1]) & 3;
  switch (anchor_67)
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

  int local_arr[3] = {4, 9, 15};
  int delta_16 = local_arr[aux % 3];
  acc = (acc + (delta_16 * 2)) & 127;
  int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_22) & 63;
  acc ^= aux;
  int window_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_25 > 17)
  {
    acc = ((acc + (window_25 * 2)) + 5) & 127;
    aux ^= window_25 & 15;
  }
  else
  {
    acc = ((acc - window_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_74_1 = local_arr_1[aux_1 % 3];
  int residue_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_74_2 * 2)) & 127;
  int residue_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_28_1 > 42)
  {
    acc_1 = ((acc_1 + (residue_28_1 * 2)) + 5) & 127;
    aux_1 ^= residue_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_28_2 > 42)
  {
    acc_2 = ((acc_2 + (residue_28_2 * 2)) + 5) & 127;
    aux_2 ^= residue_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_28_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_74_1 == residue_74_2);
  assert(residue_28_1 == residue_28_2);
}

int fn_R000733_3313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int residue_74 = local_arr[aux % 3];
  acc = (acc + (residue_74 * 2)) & 127;
  int residue_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_28 > 42)
  {
    acc = ((acc + (residue_28 * 2)) + 5) & 127;
    aux ^= residue_28 & 15;
  }
  else
  {
    acc = ((acc - residue_28) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int vector_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_68_1 > 31)
  {
    acc_1 = ((acc_1 + (vector_68_1 * 2)) + 5) & 127;
    aux_1 ^= vector_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_68_2 > 31)
  {
    acc_2 = ((acc_2 + (vector_68_2 * 2)) + 5) & 127;
    aux_2 ^= vector_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_68_1 == vector_68_2);
}

int fn_R000733_3313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int vector_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_68 > 31)
  {
    acc = ((acc + (vector_68 * 2)) + 5) & 127;
    aux ^= vector_68 & 15;
  }
  else
  {
    acc = ((acc - vector_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st_1 = {0};
  struct Transaction_R000733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_71_1 = local_arr_1[aux_1 % 3];
  int offset_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_71_2 * 2)) & 127;
  int phase_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_36_1) & 63;
  aux_2 = (aux_2 + phase_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_71_1 == offset_71_2);
  assert(phase_36_1 == phase_36_2);
}

int fn_R000733_3313_14(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int offset_71 = local_arr[aux % 3];
  acc = (acc + (offset_71 * 2)) & 127;
  int phase_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_36) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000733_3313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_51_1) & 63;
  aux_2 = (aux_2 + factor_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_66_1 > 44)
  {
    acc_1 = ((acc_1 + (segment_66_1 * 2)) + 5) & 127;
    aux_1 ^= segment_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_66_2 > 44)
  {
    acc_2 = ((acc_2 + (segment_66_2 * 2)) + 5) & 127;
    aux_2 ^= segment_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_51_1 == factor_51_2);
  assert(segment_66_1 == segment_66_2);
}

int fn_R000733_3313_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_51) & 63;
  acc ^= aux;
  int segment_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_66 > 44)
  {
    acc = ((acc + (segment_66 * 2)) + 5) & 127;
    aux ^= segment_66 & 15;
  }
  else
  {
    acc = ((acc - segment_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_26_1 > 38)
  {
    acc_1 = ((acc_1 + (delta_26_1 * 2)) + 5) & 127;
    aux_1 ^= delta_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_26_2 > 38)
  {
    acc_2 = ((acc_2 + (delta_26_2 * 2)) + 5) & 127;
    aux_2 ^= delta_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_26_1 == delta_26_2);
}

int fn_R000733_3313_16(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_26 > 38)
  {
    acc = ((acc + (delta_26 * 2)) + 5) & 127;
    aux ^= delta_26 & 15;
  }
  else
  {
    acc = ((acc - delta_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_77_1 > 29)
  {
    acc_1 = ((acc_1 + (damping_77_1 * 2)) + 5) & 127;
    aux_1 ^= damping_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_77_2 > 29)
  {
    acc_2 = ((acc_2 + (damping_77_2 * 2)) + 5) & 127;
    aux_2 ^= damping_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_74_1 = local_arr_1[aux_1 % 3];
  int vector_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_77_1 == damping_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_74_1 == vector_74_2);
}

int fn_R000733_3313_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_77 > 29)
  {
    acc = ((acc + (damping_77 * 2)) + 5) & 127;
    aux ^= damping_77 & 15;
  }
  else
  {
    acc = ((acc - damping_77) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_74 = local_arr[aux % 3];
  acc = (acc + (vector_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int index_reg_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_45_1) & 63;
  aux_2 = (aux_2 + index_reg_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_35_1 > 38)
  {
    acc_1 = ((acc_1 + (margin_35_1 * 2)) + 5) & 127;
    aux_1 ^= margin_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_35_2 > 38)
  {
    acc_2 = ((acc_2 + (margin_35_2 * 2)) + 5) & 127;
    aux_2 ^= margin_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_23_1 = local_arr_1[aux_1 % 3];
  int vector_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_45_1 == index_reg_45_2);
  assert(margin_35_1 == margin_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_23_1 == vector_23_2);
}

int fn_R000733_3313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int index_reg_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_45) & 63;
  acc ^= aux;
  int margin_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_35 > 38)
  {
    acc = ((acc + (margin_35 * 2)) + 5) & 127;
    aux ^= margin_35 & 15;
  }
  else
  {
    acc = ((acc - margin_35) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_23 = local_arr[aux % 3];
  acc = (acc + (vector_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_86_1 > 26)
  {
    acc_1 = ((acc_1 + (margin_86_1 * 2)) + 5) & 127;
    aux_1 ^= margin_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_86_2 > 26)
  {
    acc_2 = ((acc_2 + (margin_86_2 * 2)) + 5) & 127;
    aux_2 ^= margin_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_13_1 = local_arr_1[aux_1 % 3];
  int residue_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_13_2 * 2)) & 127;
  int accumulator_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_58_1) & 63;
  aux_2 = (aux_2 + accumulator_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_86_1 == margin_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_13_1 == residue_13_2);
  assert(accumulator_58_1 == accumulator_58_2);
}

int fn_R000733_3313_19(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_86 > 26)
  {
    acc = ((acc + (margin_86 * 2)) + 5) & 127;
    aux ^= margin_86 & 15;
  }
  else
  {
    acc = ((acc - margin_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_13 = local_arr[aux % 3];
  acc = (acc + (residue_13 * 2)) & 127;
  int accumulator_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000733_3313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st_1 = {0};
  struct SensorNode_R000733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int delta_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_10_1) & 63;
  aux_2 = (aux_2 + delta_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_14_1)
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

  switch (phase_14_2)
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
  int metric_32_1 = local_arr_1[aux_1 % 3];
  int metric_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_10_1 == delta_10_2);
  assert(phase_14_1 == phase_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_32_1 == metric_32_2);
}

int fn_R000733_3313_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int delta_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_10) & 63;
  acc ^= aux;
  int phase_14 = (aux + st.buffer[1]) & 3;
  switch (phase_14)
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
  int metric_32 = local_arr[aux % 3];
  acc = (acc + (metric_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000733_3313_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int weight_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_93_1) & 63;
  aux_2 = (aux_2 + weight_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_83_1)
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

  switch (tracker_83_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_27_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_27_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_27_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_27_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_93_1 == weight_93_2);
  assert(tracker_83_1 == tracker_83_2);
  assert(pivot_27_1 == pivot_27_2);
}

int fn_R000733_3313_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int weight_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_93) & 63;
  acc ^= aux;
  int tracker_83 = (aux + st.buffer[1]) & 3;
  switch (tracker_83)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_27 > 42)
  {
    acc = ((acc + (pivot_27 * 2)) + 5) & 127;
    aux ^= pivot_27 & 15;
  }
  else
  {
    acc = ((acc - pivot_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000733_3313_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_39_1)
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

  switch (tally_39_2)
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

  int factor_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_28_1 > 14)
  {
    acc_1 = ((acc_1 + (factor_28_1 * 2)) + 5) & 127;
    aux_1 ^= factor_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_28_2 > 14)
  {
    acc_2 = ((acc_2 + (factor_28_2 * 2)) + 5) & 127;
    aux_2 ^= factor_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_61_1) & 63;
  aux_2 = (aux_2 + scale_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_89_1 = local_arr_1[aux_1 % 3];
  int delta_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_39_1 == tally_39_2);
  assert(factor_28_1 == factor_28_2);
  assert(scale_61_1 == scale_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_89_1 == delta_89_2);
}

int fn_R000733_3313_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_39 = (aux + st.buffer[1]) & 3;
  switch (tally_39)
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

  int factor_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_28 > 14)
  {
    acc = ((acc + (factor_28 * 2)) + 5) & 127;
    aux ^= factor_28 & 15;
  }
  else
  {
    acc = ((acc - factor_28) + 11) & 127;
    aux += 3;
  }
  int scale_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_61) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_89 = local_arr[aux % 3];
  acc = (acc + (delta_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000733_0_1;
  int sec_r000733_0_2;
  int sec_r000733_1_1;
  int sec_r000733_1_2;
  int sec_r000733_2_1;
  int sec_r000733_2_2;
  int sec_r000733_3_1;
  int sec_r000733_3_2;
  int sec_r000733_4_1;
  int sec_r000733_4_2;
  int sec_r000733_5_1;
  int sec_r000733_5_2;
  int sec_r000733_6_1;
  int sec_r000733_6_2;
  int sec_r000733_7_1;
  int sec_r000733_7_2;
  int sec_r000733_8_1;
  int sec_r000733_8_2;
  int sec_r000733_9_1;
  int sec_r000733_9_2;
  int sec_r000733_10_1;
  int sec_r000733_10_2;
  int sec_r000733_11_1;
  int sec_r000733_11_2;
  int sec_r000733_12_1;
  int sec_r000733_12_2;
  int sec_r000733_13_1;
  int sec_r000733_13_2;
  int sec_r000733_14_1;
  int sec_r000733_14_2;
  int sec_r000733_15_1;
  int sec_r000733_15_2;
  int sec_r000733_16_1;
  int sec_r000733_16_2;
  int sec_r000733_17_1;
  int sec_r000733_17_2;
  int sec_r000733_18_1;
  int sec_r000733_18_2;
  int pub_r000733_0_1;
  int pub_r000733_0_2;
  int pub_r000733_1_1;
  int pub_r000733_1_2;
  int pub_r000733_2_1;
  int pub_r000733_2_2;
  int pub_r000733_3_1;
  int pub_r000733_3_2;
  int pub_r000733_4_1;
  int pub_r000733_4_2;
  int pub_r000733_5_1;
  int pub_r000733_5_2;
  int pub_r000733_6_1;
  int pub_r000733_6_2;
  int pub_r000733_7_1;
  int pub_r000733_7_2;
  int pub_r000733_8_1;
  int pub_r000733_8_2;
  int pub_r000733_9_1;
  int pub_r000733_9_2;
  int pub_r000733_10_1;
  int pub_r000733_10_2;
  int pub_r000733_11_1;
  int pub_r000733_11_2;
  int pub_r000733_12_1;
  int pub_r000733_12_2;
  int pub_r000733_13_1;
  int pub_r000733_13_2;
  int pub_r000733_14_1;
  int pub_r000733_14_2;
  int pub_r000733_15_1;
  int pub_r000733_15_2;
  int pub_r000733_16_1;
  int pub_r000733_16_2;
  int pub_r000733_17_1;
  int pub_r000733_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000733_0_1 >= (-100)) && (pub_r000733_0_1 <= 100));
  __CPROVER_assume((pub_r000733_0_2 >= (-100)) && (pub_r000733_0_2 <= 100));
  __CPROVER_assume((pub_r000733_1_1 >= (-100)) && (pub_r000733_1_1 <= 100));
  __CPROVER_assume((pub_r000733_1_2 >= (-100)) && (pub_r000733_1_2 <= 100));
  __CPROVER_assume((pub_r000733_2_1 >= (-100)) && (pub_r000733_2_1 <= 100));
  __CPROVER_assume((pub_r000733_2_2 >= (-100)) && (pub_r000733_2_2 <= 100));
  __CPROVER_assume((pub_r000733_3_1 >= (-100)) && (pub_r000733_3_1 <= 100));
  __CPROVER_assume((pub_r000733_3_2 >= (-100)) && (pub_r000733_3_2 <= 100));
  __CPROVER_assume((pub_r000733_4_1 >= (-100)) && (pub_r000733_4_1 <= 100));
  __CPROVER_assume((pub_r000733_4_2 >= (-100)) && (pub_r000733_4_2 <= 100));
  __CPROVER_assume((pub_r000733_5_1 >= (-100)) && (pub_r000733_5_1 <= 100));
  __CPROVER_assume((pub_r000733_5_2 >= (-100)) && (pub_r000733_5_2 <= 100));
  __CPROVER_assume((pub_r000733_6_1 >= (-100)) && (pub_r000733_6_1 <= 100));
  __CPROVER_assume((pub_r000733_6_2 >= (-100)) && (pub_r000733_6_2 <= 100));
  __CPROVER_assume((pub_r000733_7_1 >= (-100)) && (pub_r000733_7_1 <= 100));
  __CPROVER_assume((pub_r000733_7_2 >= (-100)) && (pub_r000733_7_2 <= 100));
  __CPROVER_assume((pub_r000733_8_1 >= (-100)) && (pub_r000733_8_1 <= 100));
  __CPROVER_assume((pub_r000733_8_2 >= (-100)) && (pub_r000733_8_2 <= 100));
  __CPROVER_assume((pub_r000733_9_1 >= (-100)) && (pub_r000733_9_1 <= 100));
  __CPROVER_assume((pub_r000733_9_2 >= (-100)) && (pub_r000733_9_2 <= 100));
  __CPROVER_assume((pub_r000733_10_1 >= (-100)) && (pub_r000733_10_1 <= 100));
  __CPROVER_assume((pub_r000733_10_2 >= (-100)) && (pub_r000733_10_2 <= 100));
  __CPROVER_assume((pub_r000733_11_1 >= (-100)) && (pub_r000733_11_1 <= 100));
  __CPROVER_assume((pub_r000733_11_2 >= (-100)) && (pub_r000733_11_2 <= 100));
  __CPROVER_assume((pub_r000733_12_1 >= (-100)) && (pub_r000733_12_1 <= 100));
  __CPROVER_assume((pub_r000733_12_2 >= (-100)) && (pub_r000733_12_2 <= 100));
  __CPROVER_assume((pub_r000733_13_1 >= (-100)) && (pub_r000733_13_1 <= 100));
  __CPROVER_assume((pub_r000733_13_2 >= (-100)) && (pub_r000733_13_2 <= 100));
  __CPROVER_assume((pub_r000733_14_1 >= (-100)) && (pub_r000733_14_1 <= 100));
  __CPROVER_assume((pub_r000733_14_2 >= (-100)) && (pub_r000733_14_2 <= 100));
  __CPROVER_assume((pub_r000733_15_1 >= (-100)) && (pub_r000733_15_1 <= 100));
  __CPROVER_assume((pub_r000733_15_2 >= (-100)) && (pub_r000733_15_2 <= 100));
  __CPROVER_assume((pub_r000733_16_1 >= (-100)) && (pub_r000733_16_1 <= 100));
  __CPROVER_assume((pub_r000733_16_2 >= (-100)) && (pub_r000733_16_2 <= 100));
  __CPROVER_assume((pub_r000733_17_1 >= (-100)) && (pub_r000733_17_1 <= 100));
  __CPROVER_assume((pub_r000733_17_2 >= (-100)) && (pub_r000733_17_2 <= 100));
  __CPROVER_assume((sec_r000733_0_1 >= 0) && (sec_r000733_0_1 <= 255));
  __CPROVER_assume((sec_r000733_0_2 >= 0) && (sec_r000733_0_2 <= 255));
  __CPROVER_assume((sec_r000733_1_1 >= 0) && (sec_r000733_1_1 <= 255));
  __CPROVER_assume((sec_r000733_1_2 >= 0) && (sec_r000733_1_2 <= 255));
  __CPROVER_assume((sec_r000733_2_1 >= 0) && (sec_r000733_2_1 <= 255));
  __CPROVER_assume((sec_r000733_2_2 >= 0) && (sec_r000733_2_2 <= 255));
  __CPROVER_assume((sec_r000733_3_1 >= 0) && (sec_r000733_3_1 <= 255));
  __CPROVER_assume((sec_r000733_3_2 >= 0) && (sec_r000733_3_2 <= 255));
  __CPROVER_assume((sec_r000733_4_1 >= 0) && (sec_r000733_4_1 <= 255));
  __CPROVER_assume((sec_r000733_4_2 >= 0) && (sec_r000733_4_2 <= 255));
  __CPROVER_assume((sec_r000733_5_1 >= 0) && (sec_r000733_5_1 <= 255));
  __CPROVER_assume((sec_r000733_5_2 >= 0) && (sec_r000733_5_2 <= 255));
  __CPROVER_assume((sec_r000733_6_1 >= 0) && (sec_r000733_6_1 <= 255));
  __CPROVER_assume((sec_r000733_6_2 >= 0) && (sec_r000733_6_2 <= 255));
  __CPROVER_assume((sec_r000733_7_1 >= 0) && (sec_r000733_7_1 <= 255));
  __CPROVER_assume((sec_r000733_7_2 >= 0) && (sec_r000733_7_2 <= 255));
  __CPROVER_assume((sec_r000733_8_1 >= 0) && (sec_r000733_8_1 <= 255));
  __CPROVER_assume((sec_r000733_8_2 >= 0) && (sec_r000733_8_2 <= 255));
  __CPROVER_assume((sec_r000733_9_1 >= 0) && (sec_r000733_9_1 <= 255));
  __CPROVER_assume((sec_r000733_9_2 >= 0) && (sec_r000733_9_2 <= 255));
  __CPROVER_assume((sec_r000733_10_1 >= 0) && (sec_r000733_10_1 <= 255));
  __CPROVER_assume((sec_r000733_10_2 >= 0) && (sec_r000733_10_2 <= 255));
  __CPROVER_assume((sec_r000733_11_1 >= 0) && (sec_r000733_11_1 <= 255));
  __CPROVER_assume((sec_r000733_11_2 >= 0) && (sec_r000733_11_2 <= 255));
  __CPROVER_assume((sec_r000733_12_1 >= 0) && (sec_r000733_12_1 <= 255));
  __CPROVER_assume((sec_r000733_12_2 >= 0) && (sec_r000733_12_2 <= 255));
  __CPROVER_assume((sec_r000733_13_1 >= 0) && (sec_r000733_13_1 <= 255));
  __CPROVER_assume((sec_r000733_13_2 >= 0) && (sec_r000733_13_2 <= 255));
  __CPROVER_assume((sec_r000733_14_1 >= 0) && (sec_r000733_14_1 <= 255));
  __CPROVER_assume((sec_r000733_14_2 >= 0) && (sec_r000733_14_2 <= 255));
  __CPROVER_assume((sec_r000733_15_1 >= 0) && (sec_r000733_15_1 <= 255));
  __CPROVER_assume((sec_r000733_15_2 >= 0) && (sec_r000733_15_2 <= 255));
  __CPROVER_assume((sec_r000733_16_1 >= 0) && (sec_r000733_16_1 <= 255));
  __CPROVER_assume((sec_r000733_16_2 >= 0) && (sec_r000733_16_2 <= 255));
  __CPROVER_assume((sec_r000733_17_1 >= 0) && (sec_r000733_17_1 <= 255));
  __CPROVER_assume((sec_r000733_17_2 >= 0) && (sec_r000733_17_2 <= 255));
  __CPROVER_assume((sec_r000733_18_1 >= 0) && (sec_r000733_18_1 <= 255));
  __CPROVER_assume((sec_r000733_18_2 >= 0) && (sec_r000733_18_2 <= 255));
  struct MatrixBlock_R000733_3313_0 st_var_0_1 = {0};
  struct MatrixBlock_R000733_3313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000733_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000733_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000733_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000733_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000733_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000733_0_2 + 7) & 15;
  struct Transaction_R000733_3313_1 st_var_1_1 = {0};
  struct Transaction_R000733_3313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000733_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000733_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000733_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000733_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000733_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000733_0_2 + 9) & 15;
  struct SensorNode_R000733_3313_2 st_var_2_1 = {0};
  struct SensorNode_R000733_3313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000733_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000733_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000733_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000733_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000733_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000733_0_2 + 11) & 15;
  union PacketPayload_R000733_3313_0 u_var_1;
  union PacketPayload_R000733_3313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 36)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 36)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 48)
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
  if (stage_v_3_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 48)
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
  int stage_v_4_1 = (st_var_1_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_1_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 33)
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
  if (stage_v_5_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 33)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 9) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 33)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 33)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 41)
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
  if (stage_v_14_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 41)
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
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 55)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 55)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 22) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 44)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 44)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 29) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 43)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 43)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 41) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 39)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 39)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 50)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 50)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (st_var_2_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_2_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 32)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 32)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 34)
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
  if (stage_v_51_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 34)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (st_var_2_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_2_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 54)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 54)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (st_var_1_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_1_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 66) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 69) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 70) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
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

  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 44)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 44)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int sub_step_73_1 = ((sec_r000733_11_1 + pub_r000733_3_1) + 7) & 127;
  int sub_step_73_2 = ((sec_r000733_11_2 + pub_r000733_3_2) + 7) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000733_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((sub_step_73_1 + pub_r000733_10_1) + 24) & 127;
  int sub_step_74_2 = ((sub_step_73_2 + pub_r000733_10_2) + 24) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000733_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((sub_step_74_1 + pub_r000733_5_1) + 12) & 127;
  int sub_step_75_2 = ((sub_step_74_2 + pub_r000733_5_2) + 12) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000733_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_75_1 & 15;
  st_var_0_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((stage_v_74_1 + pub_r000733_9_1) + 25) & 127;
  int sub_step_76_2 = ((stage_v_74_2 + pub_r000733_9_2) + 25) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000733_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_76_1 & 15;
  st_var_1_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((sub_step_73_1 + pub_r000733_17_1) + 16) & 127;
  int sub_step_77_2 = ((sub_step_73_2 + pub_r000733_17_2) + 16) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000733_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_77_1 & 15;
  st_var_2_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((stage_v_74_1 + pub_r000733_9_1) + 24) & 127;
  int sub_step_78_2 = ((stage_v_74_2 + pub_r000733_9_2) + 24) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000733_17_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000733_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_78_1 & 15;
  st_var_0_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((sub_step_74_1 + pub_r000733_14_1) + 21) & 127;
  int sub_step_79_2 = ((sub_step_74_2 + pub_r000733_14_2) + 21) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000733_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_79_1 & 15;
  st_var_1_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sec_r000733_16_1 + pub_r000733_10_1) + 20) & 127;
  int sub_step_80_2 = ((sec_r000733_16_2 + pub_r000733_10_2) + 20) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000733_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_80_1 & 15;
  st_var_2_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sub_step_78_1 + pub_r000733_13_1) + 8) & 127;
  int sub_step_81_2 = ((sub_step_78_2 + pub_r000733_13_2) + 8) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000733_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_81_1 & 15;
  st_var_0_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((stage_v_75_1 + pub_r000733_4_1) + 20) & 127;
  int sub_step_82_2 = ((stage_v_75_2 + pub_r000733_4_2) + 20) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000733_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_82_1 & 15;
  st_var_1_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((stage_v_80_1 + pub_r000733_15_1) + 13) & 127;
  int sub_step_83_2 = ((stage_v_80_2 + pub_r000733_15_2) + 13) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000733_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_83_1 & 15;
  st_var_2_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((sub_step_75_1 + pub_r000733_12_1) + 7) & 127;
  int sub_step_84_2 = ((sub_step_75_2 + pub_r000733_12_2) + 7) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000733_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((stage_v_79_1 + pub_r000733_3_1) + 21) & 127;
  int sub_step_85_2 = ((stage_v_79_2 + pub_r000733_3_2) + 21) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000733_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((stage_v_84_1 + pub_r000733_9_1) + 8) & 127;
  int sub_step_86_2 = ((stage_v_84_2 + pub_r000733_9_2) + 8) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000733_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((stage_v_74_1 + pub_r000733_1_1) + 11) & 127;
  int sub_step_87_2 = ((stage_v_74_2 + pub_r000733_1_2) + 11) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000733_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_87_1 & 15;
  st_var_0_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((stage_v_85_1 + pub_r000733_9_1) + 25) & 127;
  int sub_step_88_2 = ((stage_v_85_2 + pub_r000733_9_2) + 25) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000733_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_88_1 & 15;
  st_var_1_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((sub_step_78_1 + pub_r000733_16_1) + 25) & 127;
  int sub_step_89_2 = ((sub_step_78_2 + pub_r000733_16_2) + 25) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000733_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_89_1 & 15;
  st_var_2_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((stage_v_84_1 + pub_r000733_3_1) + 17) & 127;
  int sub_step_90_2 = ((stage_v_84_2 + pub_r000733_3_2) + 17) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000733_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_90_1 & 15;
  st_var_0_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((stage_v_82_1 + pub_r000733_2_1) + 35) & 127;
  int sub_step_91_2 = ((stage_v_82_2 + pub_r000733_2_2) + 35) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000733_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_91_1 & 15;
  st_var_1_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sec_r000733_3_1 + pub_r000733_15_1) + 25) & 127;
  int sub_step_92_2 = ((sec_r000733_3_2 + pub_r000733_15_2) + 25) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000733_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_92_1 & 15;
  st_var_2_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sec_r000733_17_1 + pub_r000733_4_1) + 6) & 127;
  int sub_step_93_2 = ((sec_r000733_17_2 + pub_r000733_4_2) + 6) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000733_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_93_1 & 15;
  st_var_0_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((sub_step_84_1 + pub_r000733_8_1) + 29) & 127;
  int sub_step_94_2 = ((sub_step_84_2 + pub_r000733_8_2) + 29) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000733_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_94_1 & 15;
  st_var_1_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sub_step_82_1 + pub_r000733_5_1) + 15) & 127;
  int sub_step_95_2 = ((sub_step_82_2 + pub_r000733_5_2) + 15) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000733_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_95_1 & 15;
  st_var_2_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sub_step_80_1 + pub_r000733_10_1) + 27) & 127;
  int sub_step_96_2 = ((sub_step_80_2 + pub_r000733_10_2) + 27) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000733_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((stage_v_76_1 + pub_r000733_15_1) + 6) & 127;
  int sub_step_97_2 = ((stage_v_76_2 + pub_r000733_15_2) + 6) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000733_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sub_step_92_1 + pub_r000733_14_1) + 6) & 127;
  int sub_step_98_2 = ((sub_step_92_2 + pub_r000733_14_2) + 6) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000733_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sec_r000733_14_1 + pub_r000733_0_1) + 34) & 127;
  int sub_step_99_2 = ((sec_r000733_14_2 + pub_r000733_0_2) + 34) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000733_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_99_1 & 15;
  st_var_0_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((stage_v_81_1 + pub_r000733_5_1) + 10) & 127;
  int sub_step_100_2 = ((stage_v_81_2 + pub_r000733_5_2) + 10) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000733_17_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000733_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_100_1 & 15;
  st_var_1_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sub_step_79_1 + pub_r000733_14_1) + 8) & 127;
  int sub_step_101_2 = ((sub_step_79_2 + pub_r000733_14_2) + 8) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000733_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_101_1 & 15;
  st_var_2_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((sec_r000733_16_1 + pub_r000733_14_1) + 21) & 127;
  int sub_step_102_2 = ((sec_r000733_16_2 + pub_r000733_14_2) + 21) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000733_17_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000733_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_102_1 & 15;
  st_var_0_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sec_r000733_9_1 + pub_r000733_13_1) + 30) & 127;
  int sub_step_103_2 = ((sec_r000733_9_2 + pub_r000733_13_2) + 30) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000733_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_103_1 & 15;
  st_var_1_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((sub_step_79_1 + pub_r000733_11_1) + 5) & 127;
  int sub_step_104_2 = ((sub_step_79_2 + pub_r000733_11_2) + 5) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000733_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_104_1 & 15;
  st_var_2_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sec_r000733_9_1 + pub_r000733_9_1) + 23) & 127;
  int sub_step_105_2 = ((sec_r000733_9_2 + pub_r000733_9_2) + 23) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000733_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_105_1 & 15;
  st_var_0_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sub_step_104_1 + pub_r000733_16_1) + 23) & 127;
  int sub_step_106_2 = ((sub_step_104_2 + pub_r000733_16_2) + 23) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000733_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_106_1 & 15;
  st_var_1_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000733_15_1 + pub_r000733_7_1) + 31) & 127;
  int sub_step_107_2 = ((sec_r000733_15_2 + pub_r000733_7_2) + 31) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000733_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_107_1 & 15;
  st_var_2_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sec_r000733_11_1 + pub_r000733_16_1) + 20) & 127;
  int sub_step_108_2 = ((sec_r000733_11_2 + pub_r000733_16_2) + 20) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000733_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sub_step_76_1 + pub_r000733_7_1) + 22) & 127;
  int sub_step_109_2 = ((sub_step_76_2 + pub_r000733_7_2) + 22) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000733_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((stage_v_78_1 + pub_r000733_7_1) + 10) & 127;
  int sub_step_110_2 = ((stage_v_78_2 + pub_r000733_7_2) + 10) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000733_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((stage_v_76_1 + pub_r000733_10_1) + 33) & 127;
  int sub_step_111_2 = ((stage_v_76_2 + pub_r000733_10_2) + 33) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000733_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_111_1 & 15;
  st_var_0_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((stage_v_90_1 + pub_r000733_16_1) + 29) & 127;
  int sub_step_112_2 = ((stage_v_90_2 + pub_r000733_16_2) + 29) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000733_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_112_1 & 15;
  st_var_1_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((stage_v_92_1 + pub_r000733_15_1) + 21) & 127;
  int sub_step_113_2 = ((stage_v_92_2 + pub_r000733_15_2) + 21) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000733_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_113_1 & 15;
  st_var_2_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((sec_r000733_7_1 + pub_r000733_13_1) + 35) & 127;
  int sub_step_114_2 = ((sec_r000733_7_2 + pub_r000733_13_2) + 35) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000733_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_114_1 & 15;
  st_var_0_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_106_1 + pub_r000733_2_1) + 31) & 127;
  int sub_step_115_2 = ((sub_step_106_2 + pub_r000733_2_2) + 31) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000733_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_115_1 & 15;
  st_var_1_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((stage_v_73_1 + pub_r000733_15_1) + 9) & 127;
  int sub_step_116_2 = ((stage_v_73_2 + pub_r000733_15_2) + 9) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000733_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_116_1 & 15;
  st_var_2_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((stage_v_82_1 + pub_r000733_0_1) + 8) & 127;
  int sub_step_117_2 = ((stage_v_82_2 + pub_r000733_0_2) + 8) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000733_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_117_1 & 15;
  st_var_0_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sec_r000733_13_1 + pub_r000733_1_1) + 25) & 127;
  int sub_step_118_2 = ((sec_r000733_13_2 + pub_r000733_1_2) + 25) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000733_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_118_1 & 15;
  st_var_1_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((sub_step_110_1 + pub_r000733_9_1) + 24) & 127;
  int sub_step_119_2 = ((sub_step_110_2 + pub_r000733_9_2) + 24) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000733_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_119_1 & 15;
  st_var_2_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sec_r000733_15_1 + pub_r000733_0_1) + 24) & 127;
  int sub_step_120_2 = ((sec_r000733_15_2 + pub_r000733_0_2) + 24) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000733_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((stage_v_99_1 + pub_r000733_3_1) + 17) & 127;
  int sub_step_121_2 = ((stage_v_99_2 + pub_r000733_3_2) + 17) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000733_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000733_5_1 + pub_r000733_4_1) + 9) & 127;
  int sub_step_122_2 = ((sec_r000733_5_2 + pub_r000733_4_2) + 9) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000733_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sec_r000733_12_1 + pub_r000733_1_1) + 18) & 127;
  int sub_step_123_2 = ((sec_r000733_12_2 + pub_r000733_1_2) + 18) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000733_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_123_1 & 15;
  st_var_0_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((stage_v_81_1 + pub_r000733_13_1) + 7) & 127;
  int sub_step_124_2 = ((stage_v_81_2 + pub_r000733_13_2) + 7) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000733_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_124_1 & 15;
  st_var_1_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((stage_v_110_1 + pub_r000733_0_1) + 9) & 127;
  int sub_step_125_2 = ((stage_v_110_2 + pub_r000733_0_2) + 9) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000733_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_125_1 & 15;
  st_var_2_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((sub_step_125_1 + pub_r000733_1_1) + 31) & 127;
  int sub_step_126_2 = ((sub_step_125_2 + pub_r000733_1_2) + 31) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000733_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_126_1 & 15;
  st_var_0_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sub_step_116_1 + pub_r000733_11_1) + 11) & 127;
  int sub_step_127_2 = ((sub_step_116_2 + pub_r000733_11_2) + 11) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000733_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_127_1 & 15;
  st_var_1_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((sub_step_80_1 + pub_r000733_5_1) + 32) & 127;
  int sub_step_128_2 = ((sub_step_80_2 + pub_r000733_5_2) + 32) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000733_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_128_1 & 15;
  st_var_2_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((stage_v_110_1 + pub_r000733_15_1) + 33) & 127;
  int sub_step_129_2 = ((stage_v_110_2 + pub_r000733_15_2) + 33) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000733_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_129_1 & 15;
  st_var_0_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((stage_v_105_1 + pub_r000733_11_1) + 33) & 127;
  int sub_step_130_2 = ((stage_v_105_2 + pub_r000733_11_2) + 33) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000733_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_130_1 & 15;
  st_var_1_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((stage_v_85_1 + pub_r000733_7_1) + 28) & 127;
  int sub_step_131_2 = ((stage_v_85_2 + pub_r000733_7_2) + 28) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000733_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_131_1 & 15;
  st_var_2_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((sub_step_95_1 + pub_r000733_11_1) + 17) & 127;
  int sub_step_132_2 = ((sub_step_95_2 + pub_r000733_11_2) + 17) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000733_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sec_r000733_17_1 + pub_r000733_8_1) + 28) & 127;
  int sub_step_133_2 = ((sec_r000733_17_2 + pub_r000733_8_2) + 28) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000733_4_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000733_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((stage_v_93_1 + pub_r000733_12_1) + 26) & 127;
  int sub_step_134_2 = ((stage_v_93_2 + pub_r000733_12_2) + 26) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000733_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sub_step_132_1 + pub_r000733_17_1) + 34) & 127;
  int sub_step_135_2 = ((sub_step_132_2 + pub_r000733_17_2) + 34) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000733_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_135_1 & 15;
  st_var_0_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sec_r000733_10_1 + pub_r000733_13_1) + 28) & 127;
  int sub_step_136_2 = ((sec_r000733_10_2 + pub_r000733_13_2) + 28) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000733_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_136_1 & 15;
  st_var_1_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((sec_r000733_10_1 + pub_r000733_16_1) + 22) & 127;
  int sub_step_137_2 = ((sec_r000733_10_2 + pub_r000733_16_2) + 22) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000733_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_137_1 & 15;
  st_var_2_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((sec_r000733_11_1 + pub_r000733_4_1) + 33) & 127;
  int sub_step_138_2 = ((sec_r000733_11_2 + pub_r000733_4_2) + 33) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000733_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_138_1 & 15;
  st_var_0_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sub_step_97_1 + pub_r000733_14_1) + 26) & 127;
  int sub_step_139_2 = ((sub_step_97_2 + pub_r000733_14_2) + 26) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000733_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_139_1 & 15;
  st_var_1_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sec_r000733_12_1 + pub_r000733_9_1) + 30) & 127;
  int sub_step_140_2 = ((sec_r000733_12_2 + pub_r000733_9_2) + 30) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000733_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_140_1 & 15;
  st_var_2_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sec_r000733_11_1 + pub_r000733_12_1) + 7) & 127;
  int sub_step_141_2 = ((sec_r000733_11_2 + pub_r000733_12_2) + 7) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000733_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_141_1 & 15;
  st_var_0_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sec_r000733_11_1 + pub_r000733_5_1) + 15) & 127;
  int sub_step_142_2 = ((sec_r000733_11_2 + pub_r000733_5_2) + 15) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000733_2_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000733_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_142_1 & 15;
  st_var_1_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sub_step_138_1 + pub_r000733_15_1) + 22) & 127;
  int sub_step_143_2 = ((sub_step_138_2 + pub_r000733_15_2) + 22) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000733_4_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000733_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_143_1 & 15;
  st_var_2_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sub_step_89_1 + pub_r000733_11_1) + 29) & 127;
  int sub_step_144_2 = ((sub_step_89_2 + pub_r000733_11_2) + 29) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000733_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sec_r000733_13_1 + pub_r000733_9_1) + 35) & 127;
  int sub_step_145_2 = ((sec_r000733_13_2 + pub_r000733_9_2) + 35) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000733_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((stage_v_83_1 + pub_r000733_5_1) + 29) & 127;
  int sub_step_146_2 = ((stage_v_83_2 + pub_r000733_5_2) + 29) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000733_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sec_r000733_8_1 + pub_r000733_3_1) + 7) & 127;
  int sub_step_147_2 = ((sec_r000733_8_2 + pub_r000733_3_2) + 7) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000733_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_147_1 & 15;
  st_var_0_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((sub_step_75_1 + pub_r000733_1_1) + 33) & 127;
  int sub_step_148_2 = ((sub_step_75_2 + pub_r000733_1_2) + 33) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000733_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_148_1 & 15;
  st_var_1_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sub_step_85_1 + pub_r000733_2_1) + 6) & 127;
  int sub_step_149_2 = ((sub_step_85_2 + pub_r000733_2_2) + 6) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000733_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_149_1 & 15;
  st_var_2_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((stage_v_113_1 + pub_r000733_0_1) + 27) & 127;
  int sub_step_150_2 = ((stage_v_113_2 + pub_r000733_0_2) + 27) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000733_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_150_1 & 15;
  st_var_0_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sec_r000733_15_1 + pub_r000733_0_1) + 11) & 127;
  int sub_step_151_2 = ((sec_r000733_15_2 + pub_r000733_0_2) + 11) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000733_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_151_1 & 15;
  st_var_1_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((stage_v_122_1 + pub_r000733_7_1) + 35) & 127;
  int sub_step_152_2 = ((stage_v_122_2 + pub_r000733_7_2) + 35) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000733_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_152_1 & 15;
  st_var_2_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sub_step_109_1 + pub_r000733_12_1) + 27) & 127;
  int sub_step_153_2 = ((sub_step_109_2 + pub_r000733_12_2) + 27) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000733_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_153_1 & 15;
  st_var_0_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((stage_v_124_1 + pub_r000733_14_1) + 29) & 127;
  int sub_step_154_2 = ((stage_v_124_2 + pub_r000733_14_2) + 29) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000733_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_154_1 & 15;
  st_var_1_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((stage_v_153_1 + pub_r000733_6_1) + 27) & 127;
  int sub_step_155_2 = ((stage_v_153_2 + pub_r000733_6_2) + 27) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000733_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_155_1 & 15;
  st_var_2_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((stage_v_97_1 + pub_r000733_14_1) + 8) & 127;
  int sub_step_156_2 = ((stage_v_97_2 + pub_r000733_14_2) + 8) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000733_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sub_step_73_1 + pub_r000733_10_1) + 7) & 127;
  int sub_step_157_2 = ((sub_step_73_2 + pub_r000733_10_2) + 7) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000733_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sub_step_103_1 + pub_r000733_9_1) + 28) & 127;
  int sub_step_158_2 = ((sub_step_103_2 + pub_r000733_9_2) + 28) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000733_4_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000733_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sub_step_78_1 + pub_r000733_7_1) + 29) & 127;
  int sub_step_159_2 = ((sub_step_78_2 + pub_r000733_7_2) + 29) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000733_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_159_1 & 15;
  st_var_0_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((stage_v_155_1 + pub_r000733_16_1) + 35) & 127;
  int sub_step_160_2 = ((stage_v_155_2 + pub_r000733_16_2) + 35) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000733_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_160_1 & 15;
  st_var_1_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sec_r000733_16_1 + pub_r000733_12_1) + 26) & 127;
  int sub_step_161_2 = ((sec_r000733_16_2 + pub_r000733_12_2) + 26) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000733_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_161_1 & 15;
  st_var_2_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((stage_v_76_1 + pub_r000733_8_1) + 17) & 127;
  int sub_step_162_2 = ((stage_v_76_2 + pub_r000733_8_2) + 17) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000733_4_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000733_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_162_1 & 15;
  st_var_0_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sub_step_118_1 + pub_r000733_7_1) + 7) & 127;
  int sub_step_163_2 = ((sub_step_118_2 + pub_r000733_7_2) + 7) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000733_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_163_1 & 15;
  st_var_1_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((stage_v_125_1 + pub_r000733_12_1) + 8) & 127;
  int sub_step_164_2 = ((stage_v_125_2 + pub_r000733_12_2) + 8) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000733_17_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000733_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_164_1 & 15;
  st_var_2_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((sub_step_129_1 + pub_r000733_12_1) + 11) & 127;
  int sub_step_165_2 = ((sub_step_129_2 + pub_r000733_12_2) + 11) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000733_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_165_1 & 15;
  st_var_0_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((sub_step_91_1 + pub_r000733_10_1) + 31) & 127;
  int sub_step_166_2 = ((sub_step_91_2 + pub_r000733_10_2) + 31) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000733_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_166_1 & 15;
  st_var_1_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((stage_v_127_1 + pub_r000733_16_1) + 23) & 127;
  int sub_step_167_2 = ((stage_v_127_2 + pub_r000733_16_2) + 23) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000733_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_167_1 & 15;
  st_var_2_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((stage_v_162_1 + pub_r000733_3_1) + 20) & 127;
  int sub_step_168_2 = ((stage_v_162_2 + pub_r000733_3_2) + 20) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000733_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sec_r000733_6_1 + pub_r000733_8_1) + 35) & 127;
  int sub_step_169_2 = ((sec_r000733_6_2 + pub_r000733_8_2) + 35) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000733_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((stage_v_100_1 + pub_r000733_2_1) + 20) & 127;
  int sub_step_170_2 = ((stage_v_100_2 + pub_r000733_2_2) + 20) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000733_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sec_r000733_17_1 + pub_r000733_9_1) + 18) & 127;
  int sub_step_171_2 = ((sec_r000733_17_2 + pub_r000733_9_2) + 18) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000733_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_171_1 & 15;
  st_var_0_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sub_step_93_1 + pub_r000733_6_1) + 15) & 127;
  int sub_step_172_2 = ((sub_step_93_2 + pub_r000733_6_2) + 15) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000733_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_172_1 & 15;
  st_var_1_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sub_step_109_1 + pub_r000733_8_1) + 8) & 127;
  int sub_step_173_2 = ((sub_step_109_2 + pub_r000733_8_2) + 8) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000733_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_173_1 & 15;
  st_var_2_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((stage_v_167_1 + pub_r000733_10_1) + 33) & 127;
  int sub_step_174_2 = ((stage_v_167_2 + pub_r000733_10_2) + 33) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000733_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_174_1 & 15;
  st_var_0_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((sec_r000733_6_1 + pub_r000733_4_1) + 28) & 127;
  int sub_step_175_2 = ((sec_r000733_6_2 + pub_r000733_4_2) + 28) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000733_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_175_1 & 15;
  st_var_1_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000733_14_1 + pub_r000733_4_1) + 18) & 127;
  int sub_step_176_2 = ((sec_r000733_14_2 + pub_r000733_4_2) + 18) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000733_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_176_1 & 15;
  st_var_2_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((stage_v_161_1 + pub_r000733_6_1) + 28) & 127;
  int sub_step_177_2 = ((stage_v_161_2 + pub_r000733_6_2) + 28) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000733_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_177_1 & 15;
  st_var_0_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sec_r000733_16_1 + pub_r000733_10_1) + 21) & 127;
  int sub_step_178_2 = ((sec_r000733_16_2 + pub_r000733_10_2) + 21) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000733_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_178_1 & 15;
  st_var_1_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((stage_v_81_1 + pub_r000733_17_1) + 20) & 127;
  int sub_step_179_2 = ((stage_v_81_2 + pub_r000733_17_2) + 20) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000733_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_179_1 & 15;
  st_var_2_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((stage_v_131_1 + pub_r000733_1_1) + 16) & 127;
  int sub_step_180_2 = ((stage_v_131_2 + pub_r000733_1_2) + 16) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000733_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sec_r000733_4_1 + pub_r000733_6_1) + 24) & 127;
  int sub_step_181_2 = ((sec_r000733_4_2 + pub_r000733_6_2) + 24) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000733_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((stage_v_83_1 + pub_r000733_3_1) + 10) & 127;
  int sub_step_182_2 = ((stage_v_83_2 + pub_r000733_3_2) + 10) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000733_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((stage_v_109_1 + pub_r000733_16_1) + 22) & 127;
  int sub_step_183_2 = ((stage_v_109_2 + pub_r000733_16_2) + 22) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000733_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_183_1 & 15;
  st_var_0_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_95_1 + pub_r000733_3_1) + 23) & 127;
  int sub_step_184_2 = ((sub_step_95_2 + pub_r000733_3_2) + 23) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000733_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_184_1 & 15;
  st_var_1_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sec_r000733_8_1 + pub_r000733_4_1) + 18) & 127;
  int sub_step_185_2 = ((sec_r000733_8_2 + pub_r000733_4_2) + 18) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000733_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_185_1 & 15;
  st_var_2_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sub_step_83_1 + pub_r000733_14_1) + 7) & 127;
  int sub_step_186_2 = ((sub_step_83_2 + pub_r000733_14_2) + 7) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000733_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_186_1 & 15;
  st_var_0_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((sec_r000733_3_1 + pub_r000733_12_1) + 10) & 127;
  int sub_step_187_2 = ((sec_r000733_3_2 + pub_r000733_12_2) + 10) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000733_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_187_1 & 15;
  st_var_1_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_151_1 + pub_r000733_2_1) + 32) & 127;
  int sub_step_188_2 = ((sub_step_151_2 + pub_r000733_2_2) + 32) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000733_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_188_1 & 15;
  st_var_2_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((stage_v_98_1 + pub_r000733_15_1) + 13) & 127;
  int sub_step_189_2 = ((stage_v_98_2 + pub_r000733_15_2) + 13) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000733_2_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000733_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_189_1 & 15;
  st_var_0_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((stage_v_76_1 + pub_r000733_5_1) + 8) & 127;
  int sub_step_190_2 = ((stage_v_76_2 + pub_r000733_5_2) + 8) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000733_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_190_1 & 15;
  st_var_1_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sec_r000733_1_1 + pub_r000733_7_1) + 12) & 127;
  int sub_step_191_2 = ((sec_r000733_1_2 + pub_r000733_7_2) + 12) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000733_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_191_1 & 15;
  st_var_2_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sub_step_83_1 + pub_r000733_1_1) + 19) & 127;
  int sub_step_192_2 = ((sub_step_83_2 + pub_r000733_1_2) + 19) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000733_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000733_2_1 + pub_r000733_0_1) + 18) & 127;
  int sub_step_193_2 = ((sec_r000733_2_2 + pub_r000733_0_2) + 18) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000733_9_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000733_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((sub_step_166_1 + pub_r000733_11_1) + 21) & 127;
  int sub_step_194_2 = ((sub_step_166_2 + pub_r000733_11_2) + 21) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000733_16_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000733_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sub_step_93_1 + pub_r000733_16_1) + 11) & 127;
  int sub_step_195_2 = ((sub_step_93_2 + pub_r000733_16_2) + 11) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000733_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_195_1 & 15;
  st_var_0_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sub_step_101_1 + pub_r000733_12_1) + 12) & 127;
  int sub_step_196_2 = ((sub_step_101_2 + pub_r000733_12_2) + 12) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000733_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_196_1 & 15;
  st_var_1_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sec_r000733_17_1 + pub_r000733_1_1) + 30) & 127;
  int sub_step_197_2 = ((sec_r000733_17_2 + pub_r000733_1_2) + 30) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000733_2_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000733_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_197_1 & 15;
  st_var_2_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sec_r000733_6_1 + pub_r000733_2_1) + 13) & 127;
  int sub_step_198_2 = ((sec_r000733_6_2 + pub_r000733_2_2) + 13) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000733_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_198_1 & 15;
  st_var_0_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((stage_v_115_1 + pub_r000733_1_1) + 26) & 127;
  int sub_step_199_2 = ((stage_v_115_2 + pub_r000733_1_2) + 26) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000733_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_199_1 & 15;
  st_var_1_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sub_step_97_1 + pub_r000733_1_1) + 23) & 127;
  int sub_step_200_2 = ((sub_step_97_2 + pub_r000733_1_2) + 23) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000733_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_200_1 & 15;
  st_var_2_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sec_r000733_5_1 + pub_r000733_15_1) + 30) & 127;
  int sub_step_201_2 = ((sec_r000733_5_2 + pub_r000733_15_2) + 30) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000733_13_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000733_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_201_1 & 15;
  st_var_0_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sec_r000733_12_1 + pub_r000733_4_1) + 23) & 127;
  int sub_step_202_2 = ((sec_r000733_12_2 + pub_r000733_4_2) + 23) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000733_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_202_1 & 15;
  st_var_1_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sub_step_139_1 + pub_r000733_11_1) + 13) & 127;
  int sub_step_203_2 = ((sub_step_139_2 + pub_r000733_11_2) + 13) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000733_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_203_1 & 15;
  st_var_2_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((stage_v_154_1 + pub_r000733_2_1) + 13) & 127;
  int sub_step_204_2 = ((stage_v_154_2 + pub_r000733_2_2) + 13) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000733_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sub_step_191_1 + pub_r000733_1_1) + 30) & 127;
  int sub_step_205_2 = ((sub_step_191_2 + pub_r000733_1_2) + 30) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000733_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((stage_v_99_1 + pub_r000733_15_1) + 20) & 127;
  int sub_step_206_2 = ((stage_v_99_2 + pub_r000733_15_2) + 20) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000733_6_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000733_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((stage_v_194_1 + pub_r000733_7_1) + 15) & 127;
  int sub_step_207_2 = ((stage_v_194_2 + pub_r000733_7_2) + 15) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000733_5_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000733_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_207_1 & 15;
  st_var_0_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((stage_v_95_1 + pub_r000733_15_1) + 31) & 127;
  int sub_step_208_2 = ((stage_v_95_2 + pub_r000733_15_2) + 31) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000733_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_208_1 & 15;
  st_var_1_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((stage_v_198_1 + pub_r000733_17_1) + 7) & 127;
  int sub_step_209_2 = ((stage_v_198_2 + pub_r000733_17_2) + 7) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000733_8_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000733_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_209_1 & 15;
  st_var_2_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((sub_step_185_1 + pub_r000733_6_1) + 33) & 127;
  int sub_step_210_2 = ((sub_step_185_2 + pub_r000733_6_2) + 33) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000733_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_210_1 & 15;
  st_var_0_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000733_5_1 + pub_r000733_5_1) + 25) & 127;
  int sub_step_211_2 = ((sec_r000733_5_2 + pub_r000733_5_2) + 25) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000733_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_211_1 & 15;
  st_var_1_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((stage_v_113_1 + pub_r000733_15_1) + 19) & 127;
  int sub_step_212_2 = ((stage_v_113_2 + pub_r000733_15_2) + 19) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000733_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_212_1 & 15;
  st_var_2_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((stage_v_116_1 + pub_r000733_4_1) + 34) & 127;
  int sub_step_213_2 = ((stage_v_116_2 + pub_r000733_4_2) + 34) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000733_4_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000733_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_213_1 & 15;
  st_var_0_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((sec_r000733_10_1 + pub_r000733_5_1) + 21) & 127;
  int sub_step_214_2 = ((sec_r000733_10_2 + pub_r000733_5_2) + 21) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000733_17_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000733_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_214_1 & 15;
  st_var_1_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sub_step_159_1 + pub_r000733_17_1) + 8) & 127;
  int sub_step_215_2 = ((sub_step_159_2 + pub_r000733_17_2) + 8) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000733_11_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000733_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_215_1 & 15;
  st_var_2_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sec_r000733_14_1 + pub_r000733_11_1) + 21) & 127;
  int sub_step_216_2 = ((sec_r000733_14_2 + pub_r000733_11_2) + 21) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000733_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sec_r000733_3_1 + pub_r000733_10_1) + 22) & 127;
  int sub_step_217_2 = ((sec_r000733_3_2 + pub_r000733_10_2) + 22) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000733_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((sec_r000733_11_1 + pub_r000733_15_1) + 24) & 127;
  int sub_step_218_2 = ((sec_r000733_11_2 + pub_r000733_15_2) + 24) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000733_14_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000733_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000733_17_1 + pub_r000733_6_1) + 20) & 127;
  int sub_step_219_2 = ((sec_r000733_17_2 + pub_r000733_6_2) + 20) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000733_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_219_1 & 15;
  st_var_0_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((stage_v_112_1 + pub_r000733_7_1) + 31) & 127;
  int sub_step_220_2 = ((stage_v_112_2 + pub_r000733_7_2) + 31) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000733_17_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000733_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_220_1 & 15;
  st_var_1_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sec_r000733_0_1 + pub_r000733_1_1) + 14) & 127;
  int sub_step_221_2 = ((sec_r000733_0_2 + pub_r000733_1_2) + 14) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000733_3_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000733_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_221_1 & 15;
  st_var_2_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((stage_v_102_1 + pub_r000733_11_1) + 12) & 127;
  int sub_step_222_2 = ((stage_v_102_2 + pub_r000733_11_2) + 12) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000733_7_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000733_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_222_1 & 15;
  st_var_0_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((stage_v_104_1 + pub_r000733_8_1) + 35) & 127;
  int sub_step_223_2 = ((stage_v_104_2 + pub_r000733_8_2) + 35) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000733_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_223_1 & 15;
  st_var_1_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((stage_v_124_1 + pub_r000733_4_1) + 22) & 127;
  int sub_step_224_2 = ((stage_v_124_2 + pub_r000733_4_2) + 22) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000733_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_224_1 & 15;
  st_var_2_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((stage_v_142_1 + pub_r000733_17_1) + 16) & 127;
  int sub_step_225_2 = ((stage_v_142_2 + pub_r000733_17_2) + 16) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000733_15_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000733_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_225_1 & 15;
  st_var_0_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sec_r000733_15_1 + pub_r000733_7_1) + 10) & 127;
  int sub_step_226_2 = ((sec_r000733_15_2 + pub_r000733_7_2) + 10) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000733_12_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000733_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_226_1 & 15;
  st_var_1_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sec_r000733_3_1 + pub_r000733_15_1) + 11) & 127;
  int sub_step_227_2 = ((sec_r000733_3_2 + pub_r000733_15_2) + 11) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000733_0_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000733_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_227_1 & 15;
  st_var_2_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((sec_r000733_18_1 + pub_r000733_11_1) + 22) & 127;
  int sub_step_228_2 = ((sec_r000733_18_2 + pub_r000733_11_2) + 22) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000733_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((sub_step_224_1 + pub_r000733_0_1) + 7) & 127;
  int sub_step_229_2 = ((sub_step_224_2 + pub_r000733_0_2) + 7) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000733_1_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000733_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sec_r000733_2_1 + pub_r000733_1_1) + 30) & 127;
  int sub_step_230_2 = ((sec_r000733_2_2 + pub_r000733_1_2) + 30) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000733_10_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000733_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000733_11_1 == pub_r000733_11_2);
  __CPROVER_assume(pub_r000733_17_1 == pub_r000733_17_2);
  __CPROVER_assume(sec_r000733_6_1 != sec_r000733_6_2);
  __CPROVER_assume(sec_r000733_14_1 != sec_r000733_14_2);
  __CPROVER_assume(pub_r000733_4_1 == pub_r000733_4_2);
  __CPROVER_assume(sec_r000733_18_1 != sec_r000733_18_2);
  __CPROVER_assume(pub_r000733_5_1 == pub_r000733_5_2);
  __CPROVER_assume(pub_r000733_2_1 == pub_r000733_2_2);
  __CPROVER_assume(sec_r000733_12_1 != sec_r000733_12_2);
  __CPROVER_assume(pub_r000733_12_1 == pub_r000733_12_2);
  __CPROVER_assume(sec_r000733_11_1 != sec_r000733_11_2);
  __CPROVER_assume(sec_r000733_2_1 != sec_r000733_2_2);
  __CPROVER_assume(pub_r000733_0_1 == pub_r000733_0_2);
  __CPROVER_assume(pub_r000733_9_1 == pub_r000733_9_2);
  __CPROVER_assume(sec_r000733_3_1 != sec_r000733_3_2);
  __CPROVER_assume(sec_r000733_10_1 != sec_r000733_10_2);
  __CPROVER_assume(pub_r000733_1_1 == pub_r000733_1_2);
  __CPROVER_assume(pub_r000733_6_1 == pub_r000733_6_2);
  __CPROVER_assume(pub_r000733_3_1 == pub_r000733_3_2);
  __CPROVER_assume(pub_r000733_7_1 == pub_r000733_7_2);
  __CPROVER_assume(pub_r000733_13_1 == pub_r000733_13_2);
  __CPROVER_assume(sec_r000733_7_1 != sec_r000733_7_2);
  __CPROVER_assume(sec_r000733_9_1 != sec_r000733_9_2);
  __CPROVER_assume(sec_r000733_1_1 != sec_r000733_1_2);
  __CPROVER_assume(sec_r000733_4_1 != sec_r000733_4_2);
  __CPROVER_assume(sec_r000733_8_1 != sec_r000733_8_2);
  __CPROVER_assume(sec_r000733_5_1 != sec_r000733_5_2);
  __CPROVER_assume(sec_r000733_16_1 != sec_r000733_16_2);
  __CPROVER_assume(pub_r000733_8_1 == pub_r000733_8_2);
  __CPROVER_assume(pub_r000733_10_1 == pub_r000733_10_2);
  __CPROVER_assume(sec_r000733_13_1 != sec_r000733_13_2);
  __CPROVER_assume(sec_r000733_15_1 != sec_r000733_15_2);
  __CPROVER_assume(pub_r000733_15_1 == pub_r000733_15_2);
  __CPROVER_assume(pub_r000733_14_1 == pub_r000733_14_2);
  __CPROVER_assume(pub_r000733_16_1 == pub_r000733_16_2);
  __CPROVER_assume(sec_r000733_17_1 != sec_r000733_17_2);
  __CPROVER_assume(sec_r000733_0_1 != sec_r000733_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
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
  assert(sub_step_73_1 == sub_step_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(sub_step_74_1 == sub_step_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(sub_step_75_1 == sub_step_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(sub_step_76_1 == sub_step_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(sub_step_77_1 == sub_step_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(sub_step_78_1 == sub_step_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(sub_step_79_1 == sub_step_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(sub_step_80_1 == sub_step_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(sub_step_81_1 == sub_step_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(sub_step_82_1 == sub_step_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(sub_step_83_1 == sub_step_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(sub_step_84_1 == sub_step_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(sub_step_85_1 == sub_step_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(sub_step_86_1 == sub_step_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(sub_step_87_1 == sub_step_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(sub_step_88_1 == sub_step_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(sub_step_89_1 == sub_step_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(sub_step_226_1 == sub_step_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(sub_step_227_1 == sub_step_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(sub_step_228_1 == sub_step_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(sub_step_229_1 == sub_step_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(sub_step_230_1 == sub_step_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
}


