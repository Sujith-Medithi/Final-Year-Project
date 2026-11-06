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
struct EventLog_R000297_9713_0
{
  int timestamp;
  unsigned char facility;
  short signature;
  int buffer[3];
};
struct Transaction_R000297_9713_1
{
  unsigned char fee;
  unsigned char auth_code;
  unsigned char account_id;
  int rate;
  unsigned char status;
  unsigned char balance;
  int buffer[3];
};
struct Vector3D_R000297_9713_2
{
  int heading;
  unsigned char coord_y;
  short pitch;
  unsigned char coord_z;
  short norm_sq;
  int coord_x;
  int buffer[3];
};
struct MatrixBlock_R000297_9713_3
{
  short trace;
  short scale;
  int stride;
  short determinant;
  int dim;
  short density;
  int buffer[3];
};
union PacketPayload_R000297_9713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000297_9713_1
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
void fn_R000297_9713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st_1 = {0};
  struct Vector3D_R000297_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int residue_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_16_1 > 15)
  {
    acc_1 = ((acc_1 + (residue_16_1 * 2)) + 5) & 127;
    aux_1 ^= residue_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_16_2 > 15)
  {
    acc_2 = ((acc_2 + (residue_16_2 * 2)) + 5) & 127;
    aux_2 ^= residue_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_86_1) & 63;
  aux_2 = (aux_2 + pivot_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_31_1 = local_arr_1[aux_1 % 3];
  int sample_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_16_1 == residue_16_2);
  assert(pivot_86_1 == pivot_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_31_1 == sample_31_2);
}

int fn_R000297_9713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int residue_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_16 > 15)
  {
    acc = ((acc + (residue_16 * 2)) + 5) & 127;
    aux ^= residue_16 & 15;
  }
  else
  {
    acc = ((acc - residue_16) + 11) & 127;
    aux += 3;
  }
  int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_31 = local_arr[aux % 3];
  acc = (acc + (sample_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st_1 = {0};
  struct Vector3D_R000297_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_75_1) & 63;
  aux_2 = (aux_2 + parity_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_65_1 = local_arr_1[aux_1 % 3];
  int quantum_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_65_2 * 2)) & 127;
  int phase_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_50_1)
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

  switch (phase_50_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_75_1 == parity_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_65_1 == quantum_65_2);
  assert(phase_50_1 == phase_50_2);
}

int fn_R000297_9713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_65 = local_arr[aux % 3];
  acc = (acc + (quantum_65 * 2)) & 127;
  int phase_50 = (aux + st.buffer[1]) & 3;
  switch (phase_50)
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

void fn_R000297_9713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st_1 = {0};
  struct Transaction_R000297_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_41_1 = local_arr_1[aux_1 % 3];
  int threshold_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_41_2 * 2)) & 127;
  int phase_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_72_1)
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

  switch (phase_72_2)
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

  int tally_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_59_1) & 63;
  aux_2 = (aux_2 + tally_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_41_1 == threshold_41_2);
  assert(phase_72_1 == phase_72_2);
  assert(tally_59_1 == tally_59_2);
}

int fn_R000297_9713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_41 = local_arr[aux % 3];
  acc = (acc + (threshold_41 * 2)) & 127;
  int phase_72 = (aux + st.buffer[1]) & 3;
  switch (phase_72)
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

  int tally_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000297_9713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st_1 = {0};
  struct Transaction_R000297_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_36_1 = local_arr_1[aux_1 % 3];
  int stride_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_36_2 * 2)) & 127;
  int scale_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_92_1)
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

  switch (scale_92_2)
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

  int residue_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_23_1 > 21)
  {
    acc_1 = ((acc_1 + (residue_23_1 * 2)) + 5) & 127;
    aux_1 ^= residue_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_23_2 > 21)
  {
    acc_2 = ((acc_2 + (residue_23_2 * 2)) + 5) & 127;
    aux_2 ^= residue_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_73_1) & 63;
  aux_2 = (aux_2 + pivot_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_36_1 == stride_36_2);
  assert(scale_92_1 == scale_92_2);
  assert(residue_23_1 == residue_23_2);
  assert(pivot_73_1 == pivot_73_2);
}

int fn_R000297_9713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int stride_36 = local_arr[aux % 3];
  acc = (acc + (stride_36 * 2)) & 127;
  int scale_92 = (aux + st.buffer[1]) & 3;
  switch (scale_92)
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

  int residue_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_23 > 21)
  {
    acc = ((acc + (residue_23 * 2)) + 5) & 127;
    aux ^= residue_23 & 15;
  }
  else
  {
    acc = ((acc - residue_23) + 11) & 127;
    aux += 3;
  }
  int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000297_9713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st_1 = {0};
  struct Vector3D_R000297_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_15_1) & 63;
  aux_2 = (aux_2 + residue_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_51_1 > 12)
  {
    acc_1 = ((acc_1 + (margin_51_1 * 2)) + 5) & 127;
    aux_1 ^= margin_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_51_2 > 12)
  {
    acc_2 = ((acc_2 + (margin_51_2 * 2)) + 5) & 127;
    aux_2 ^= margin_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_15_1 == residue_15_2);
  assert(margin_51_1 == margin_51_2);
}

int fn_R000297_9713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_15) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_51 > 12)
  {
    acc = ((acc + (margin_51 * 2)) + 5) & 127;
    aux ^= margin_51 & 15;
  }
  else
  {
    acc = ((acc - margin_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000297_9713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st_1 = {0};
  struct Vector3D_R000297_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_89_1 = local_arr_1[aux_1 % 3];
  int threshold_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_89_2 * 2)) & 127;
  int segment_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_99_1)
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

  switch (segment_99_2)
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

  int weight_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_66_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_66_1 * 2)) + 5) & 127;
    aux_1 ^= weight_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_66_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_66_2 * 2)) + 5) & 127;
    aux_2 ^= weight_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_89_1 == threshold_89_2);
  assert(segment_99_1 == segment_99_2);
  assert(weight_66_1 == weight_66_2);
}

int fn_R000297_9713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int threshold_89 = local_arr[aux % 3];
  acc = (acc + (threshold_89 * 2)) & 127;
  int segment_99 = (aux + st.buffer[1]) & 3;
  switch (segment_99)
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

  int weight_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_66 > 49)
  {
    acc = ((acc + (weight_66 * 2)) + 5) & 127;
    aux ^= weight_66 & 15;
  }
  else
  {
    acc = ((acc - weight_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000297_9713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st_1 = {0};
  struct Vector3D_R000297_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_71_1 > 18)
  {
    acc_1 = ((acc_1 + (offset_71_1 * 2)) + 5) & 127;
    aux_1 ^= offset_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_71_2 > 18)
  {
    acc_2 = ((acc_2 + (offset_71_2 * 2)) + 5) & 127;
    aux_2 ^= offset_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_89_1) & 63;
  aux_2 = (aux_2 + scale_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_42_1)
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

  switch (index_reg_42_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_71_1 == offset_71_2);
  assert(scale_89_1 == scale_89_2);
  assert(index_reg_42_1 == index_reg_42_2);
}

int fn_R000297_9713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_71 > 18)
  {
    acc = ((acc + (offset_71 * 2)) + 5) & 127;
    aux ^= offset_71 & 15;
  }
  else
  {
    acc = ((acc - offset_71) + 11) & 127;
    aux += 3;
  }
  int scale_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_89) & 63;
  acc ^= aux;
  int index_reg_42 = (aux + st.buffer[1]) & 3;
  switch (index_reg_42)
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

void fn_R000297_9713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000297_9713_0 st_1 = {0};
  struct EventLog_R000297_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_23_1 > 50)
  {
    acc_1 = ((acc_1 + (anchor_23_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_23_2 > 50)
  {
    acc_2 = ((acc_2 + (anchor_23_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_12_1 = local_arr_1[aux_1 % 3];
  int segment_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_23_1 == anchor_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_12_1 == segment_12_2);
}

int fn_R000297_9713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000297_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_23 > 50)
  {
    acc = ((acc + (anchor_23 * 2)) + 5) & 127;
    aux ^= anchor_23 & 15;
  }
  else
  {
    acc = ((acc - anchor_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_12 = local_arr[aux % 3];
  acc = (acc + (segment_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st_1 = {0};
  struct Transaction_R000297_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_41_1) & 63;
  aux_2 = (aux_2 + vector_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_83_1)
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

  switch (metric_83_2)
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
  int damping_21_1 = local_arr_1[aux_1 % 3];
  int damping_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_41_1 == vector_41_2);
  assert(metric_83_1 == metric_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_21_1 == damping_21_2);
}

int fn_R000297_9713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_41) & 63;
  acc ^= aux;
  int metric_83 = (aux + st.buffer[1]) & 3;
  switch (metric_83)
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
  int damping_21 = local_arr[aux % 3];
  acc = (acc + (damping_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000297_9713_0 st_1 = {0};
  struct EventLog_R000297_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_69_1) & 63;
  aux_2 = (aux_2 + sample_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_66_1 = local_arr_1[aux_1 % 3];
  int mask_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_69_1 == sample_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_66_1 == mask_66_2);
}

int fn_R000297_9713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000297_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_69) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_66 = local_arr[aux % 3];
  acc = (acc + (mask_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st_1 = {0};
  struct Vector3D_R000297_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_65_1 = local_arr_1[aux_1 % 3];
  int margin_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_65_2 * 2)) & 127;
  int mask_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_16_1) & 63;
  aux_2 = (aux_2 + mask_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_54_1)
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

  switch (bound_54_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_65_1 == margin_65_2);
  assert(mask_16_1 == mask_16_2);
  assert(bound_54_1 == bound_54_2);
}

int fn_R000297_9713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000297_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int margin_65 = local_arr[aux % 3];
  acc = (acc + (margin_65 * 2)) & 127;
  int mask_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_16) & 63;
  acc ^= aux;
  int bound_54 = (aux + st.buffer[1]) & 3;
  switch (bound_54)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st_1 = {0};
  struct MatrixBlock_R000297_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_91_1 > 19)
  {
    acc_1 = ((acc_1 + (sample_91_1 * 2)) + 5) & 127;
    aux_1 ^= sample_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_91_2 > 19)
  {
    acc_2 = ((acc_2 + (sample_91_2 * 2)) + 5) & 127;
    aux_2 ^= sample_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_16_1)
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

  switch (threshold_16_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_91_1 == sample_91_2);
  assert(threshold_16_1 == threshold_16_2);
}

int fn_R000297_9713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_91 > 19)
  {
    acc = ((acc + (sample_91 * 2)) + 5) & 127;
    aux ^= sample_91 & 15;
  }
  else
  {
    acc = ((acc - sample_91) + 11) & 127;
    aux += 3;
  }
  int threshold_16 = (aux + st.buffer[1]) & 3;
  switch (threshold_16)
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

void fn_R000297_9713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st_1 = {0};
  struct Transaction_R000297_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_43_1 = local_arr_1[aux_1 % 3];
  int vector_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_43_1 == vector_43_2);
}

int fn_R000297_9713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_43 = local_arr[aux % 3];
  acc = (acc + (vector_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st_1 = {0};
  struct MatrixBlock_R000297_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_10_1)
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

  switch (quantum_10_2)
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

  int pivot_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_48_1 > 24)
  {
    acc_1 = ((acc_1 + (pivot_48_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_48_2 > 24)
  {
    acc_2 = ((acc_2 + (pivot_48_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_10_1 == quantum_10_2);
  assert(pivot_48_1 == pivot_48_2);
}

int fn_R000297_9713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_10 = (aux + st.buffer[1]) & 3;
  switch (quantum_10)
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

  int pivot_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_48 > 24)
  {
    acc = ((acc + (pivot_48 * 2)) + 5) & 127;
    aux ^= pivot_48 & 15;
  }
  else
  {
    acc = ((acc - pivot_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000297_9713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st_1 = {0};
  struct MatrixBlock_R000297_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_91_1)
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

  switch (margin_91_2)
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

  int phase_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_59_1 > 36)
  {
    acc_1 = ((acc_1 + (phase_59_1 * 2)) + 5) & 127;
    aux_1 ^= phase_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_59_2 > 36)
  {
    acc_2 = ((acc_2 + (phase_59_2 * 2)) + 5) & 127;
    aux_2 ^= phase_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(phase_59_1 == phase_59_2);
}

int fn_R000297_9713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_91 = (aux + st.buffer[1]) & 3;
  switch (margin_91)
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

  int phase_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_59 > 36)
  {
    acc = ((acc + (phase_59 * 2)) + 5) & 127;
    aux ^= phase_59 & 15;
  }
  else
  {
    acc = ((acc - phase_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000297_9713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st_1 = {0};
  struct MatrixBlock_R000297_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_63_1) & 63;
  aux_2 = (aux_2 + accumulator_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_58_1)
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

  switch (mask_58_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_63_1 == accumulator_63_2);
  assert(mask_58_1 == mask_58_2);
}

int fn_R000297_9713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000297_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_63) & 63;
  acc ^= aux;
  int mask_58 = (aux + st.buffer[1]) & 3;
  switch (mask_58)
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

void fn_R000297_9713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000297_9713_0 st_1 = {0};
  struct EventLog_R000297_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_83_1)
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

  switch (factor_83_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_83_1 == factor_83_2);
}

int fn_R000297_9713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000297_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_83 = (aux + st.buffer[1]) & 3;
  switch (factor_83)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000297_9713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st_1 = {0};
  struct Transaction_R000297_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_84_1 = local_arr_1[aux_1 % 3];
  int accumulator_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_84_2 * 2)) & 127;
  int index_reg_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_16_1 > 30)
  {
    acc_1 = ((acc_1 + (index_reg_16_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_16_2 > 30)
  {
    acc_2 = ((acc_2 + (index_reg_16_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_58_1) & 63;
  aux_2 = (aux_2 + stride_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_84_1 == accumulator_84_2);
  assert(index_reg_16_1 == index_reg_16_2);
  assert(stride_58_1 == stride_58_2);
}

int fn_R000297_9713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000297_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int accumulator_84 = local_arr[aux % 3];
  acc = (acc + (accumulator_84 * 2)) & 127;
  int index_reg_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_16 > 30)
  {
    acc = ((acc + (index_reg_16 * 2)) + 5) & 127;
    aux ^= index_reg_16 & 15;
  }
  else
  {
    acc = ((acc - index_reg_16) + 11) & 127;
    aux += 3;
  }
  int stride_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000297_0_1;
  int sec_r000297_0_2;
  int sec_r000297_1_1;
  int sec_r000297_1_2;
  int sec_r000297_2_1;
  int sec_r000297_2_2;
  int sec_r000297_3_1;
  int sec_r000297_3_2;
  int sec_r000297_4_1;
  int sec_r000297_4_2;
  int sec_r000297_5_1;
  int sec_r000297_5_2;
  int sec_r000297_6_1;
  int sec_r000297_6_2;
  int sec_r000297_7_1;
  int sec_r000297_7_2;
  int sec_r000297_8_1;
  int sec_r000297_8_2;
  int sec_r000297_9_1;
  int sec_r000297_9_2;
  int sec_r000297_10_1;
  int sec_r000297_10_2;
  int sec_r000297_11_1;
  int sec_r000297_11_2;
  int sec_r000297_12_1;
  int sec_r000297_12_2;
  int sec_r000297_13_1;
  int sec_r000297_13_2;
  int sec_r000297_14_1;
  int sec_r000297_14_2;
  int sec_r000297_15_1;
  int sec_r000297_15_2;
  int sec_r000297_16_1;
  int sec_r000297_16_2;
  int sec_r000297_17_1;
  int sec_r000297_17_2;
  int sec_r000297_18_1;
  int sec_r000297_18_2;
  int pub_r000297_0_1;
  int pub_r000297_0_2;
  int pub_r000297_1_1;
  int pub_r000297_1_2;
  int pub_r000297_2_1;
  int pub_r000297_2_2;
  int pub_r000297_3_1;
  int pub_r000297_3_2;
  int pub_r000297_4_1;
  int pub_r000297_4_2;
  int pub_r000297_5_1;
  int pub_r000297_5_2;
  int pub_r000297_6_1;
  int pub_r000297_6_2;
  int pub_r000297_7_1;
  int pub_r000297_7_2;
  int pub_r000297_8_1;
  int pub_r000297_8_2;
  int pub_r000297_9_1;
  int pub_r000297_9_2;
  int pub_r000297_10_1;
  int pub_r000297_10_2;
  int pub_r000297_11_1;
  int pub_r000297_11_2;
  int pub_r000297_12_1;
  int pub_r000297_12_2;
  int pub_r000297_13_1;
  int pub_r000297_13_2;
  int pub_r000297_14_1;
  int pub_r000297_14_2;
  int pub_r000297_15_1;
  int pub_r000297_15_2;
  int pub_r000297_16_1;
  int pub_r000297_16_2;
  int pub_r000297_17_1;
  int pub_r000297_17_2;
  int pub_r000297_18_1;
  int pub_r000297_18_2;
  int pub_r000297_19_1;
  int pub_r000297_19_2;
  int pub_r000297_20_1;
  int pub_r000297_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000297_0_1 >= (-100)) && (pub_r000297_0_1 <= 100));
  __CPROVER_assume((pub_r000297_0_2 >= (-100)) && (pub_r000297_0_2 <= 100));
  __CPROVER_assume((pub_r000297_1_1 >= (-100)) && (pub_r000297_1_1 <= 100));
  __CPROVER_assume((pub_r000297_1_2 >= (-100)) && (pub_r000297_1_2 <= 100));
  __CPROVER_assume((pub_r000297_2_1 >= (-100)) && (pub_r000297_2_1 <= 100));
  __CPROVER_assume((pub_r000297_2_2 >= (-100)) && (pub_r000297_2_2 <= 100));
  __CPROVER_assume((pub_r000297_3_1 >= (-100)) && (pub_r000297_3_1 <= 100));
  __CPROVER_assume((pub_r000297_3_2 >= (-100)) && (pub_r000297_3_2 <= 100));
  __CPROVER_assume((pub_r000297_4_1 >= (-100)) && (pub_r000297_4_1 <= 100));
  __CPROVER_assume((pub_r000297_4_2 >= (-100)) && (pub_r000297_4_2 <= 100));
  __CPROVER_assume((pub_r000297_5_1 >= (-100)) && (pub_r000297_5_1 <= 100));
  __CPROVER_assume((pub_r000297_5_2 >= (-100)) && (pub_r000297_5_2 <= 100));
  __CPROVER_assume((pub_r000297_6_1 >= (-100)) && (pub_r000297_6_1 <= 100));
  __CPROVER_assume((pub_r000297_6_2 >= (-100)) && (pub_r000297_6_2 <= 100));
  __CPROVER_assume((pub_r000297_7_1 >= (-100)) && (pub_r000297_7_1 <= 100));
  __CPROVER_assume((pub_r000297_7_2 >= (-100)) && (pub_r000297_7_2 <= 100));
  __CPROVER_assume((pub_r000297_8_1 >= (-100)) && (pub_r000297_8_1 <= 100));
  __CPROVER_assume((pub_r000297_8_2 >= (-100)) && (pub_r000297_8_2 <= 100));
  __CPROVER_assume((pub_r000297_9_1 >= (-100)) && (pub_r000297_9_1 <= 100));
  __CPROVER_assume((pub_r000297_9_2 >= (-100)) && (pub_r000297_9_2 <= 100));
  __CPROVER_assume((pub_r000297_10_1 >= (-100)) && (pub_r000297_10_1 <= 100));
  __CPROVER_assume((pub_r000297_10_2 >= (-100)) && (pub_r000297_10_2 <= 100));
  __CPROVER_assume((pub_r000297_11_1 >= (-100)) && (pub_r000297_11_1 <= 100));
  __CPROVER_assume((pub_r000297_11_2 >= (-100)) && (pub_r000297_11_2 <= 100));
  __CPROVER_assume((pub_r000297_12_1 >= (-100)) && (pub_r000297_12_1 <= 100));
  __CPROVER_assume((pub_r000297_12_2 >= (-100)) && (pub_r000297_12_2 <= 100));
  __CPROVER_assume((pub_r000297_13_1 >= (-100)) && (pub_r000297_13_1 <= 100));
  __CPROVER_assume((pub_r000297_13_2 >= (-100)) && (pub_r000297_13_2 <= 100));
  __CPROVER_assume((pub_r000297_14_1 >= (-100)) && (pub_r000297_14_1 <= 100));
  __CPROVER_assume((pub_r000297_14_2 >= (-100)) && (pub_r000297_14_2 <= 100));
  __CPROVER_assume((pub_r000297_15_1 >= (-100)) && (pub_r000297_15_1 <= 100));
  __CPROVER_assume((pub_r000297_15_2 >= (-100)) && (pub_r000297_15_2 <= 100));
  __CPROVER_assume((pub_r000297_16_1 >= (-100)) && (pub_r000297_16_1 <= 100));
  __CPROVER_assume((pub_r000297_16_2 >= (-100)) && (pub_r000297_16_2 <= 100));
  __CPROVER_assume((pub_r000297_17_1 >= (-100)) && (pub_r000297_17_1 <= 100));
  __CPROVER_assume((pub_r000297_17_2 >= (-100)) && (pub_r000297_17_2 <= 100));
  __CPROVER_assume((pub_r000297_18_1 >= (-100)) && (pub_r000297_18_1 <= 100));
  __CPROVER_assume((pub_r000297_18_2 >= (-100)) && (pub_r000297_18_2 <= 100));
  __CPROVER_assume((pub_r000297_19_1 >= (-100)) && (pub_r000297_19_1 <= 100));
  __CPROVER_assume((pub_r000297_19_2 >= (-100)) && (pub_r000297_19_2 <= 100));
  __CPROVER_assume((pub_r000297_20_1 >= (-100)) && (pub_r000297_20_1 <= 100));
  __CPROVER_assume((pub_r000297_20_2 >= (-100)) && (pub_r000297_20_2 <= 100));
  __CPROVER_assume((sec_r000297_0_1 >= 0) && (sec_r000297_0_1 <= 255));
  __CPROVER_assume((sec_r000297_0_2 >= 0) && (sec_r000297_0_2 <= 255));
  __CPROVER_assume((sec_r000297_1_1 >= 0) && (sec_r000297_1_1 <= 255));
  __CPROVER_assume((sec_r000297_1_2 >= 0) && (sec_r000297_1_2 <= 255));
  __CPROVER_assume((sec_r000297_2_1 >= 0) && (sec_r000297_2_1 <= 255));
  __CPROVER_assume((sec_r000297_2_2 >= 0) && (sec_r000297_2_2 <= 255));
  __CPROVER_assume((sec_r000297_3_1 >= 0) && (sec_r000297_3_1 <= 255));
  __CPROVER_assume((sec_r000297_3_2 >= 0) && (sec_r000297_3_2 <= 255));
  __CPROVER_assume((sec_r000297_4_1 >= 0) && (sec_r000297_4_1 <= 255));
  __CPROVER_assume((sec_r000297_4_2 >= 0) && (sec_r000297_4_2 <= 255));
  __CPROVER_assume((sec_r000297_5_1 >= 0) && (sec_r000297_5_1 <= 255));
  __CPROVER_assume((sec_r000297_5_2 >= 0) && (sec_r000297_5_2 <= 255));
  __CPROVER_assume((sec_r000297_6_1 >= 0) && (sec_r000297_6_1 <= 255));
  __CPROVER_assume((sec_r000297_6_2 >= 0) && (sec_r000297_6_2 <= 255));
  __CPROVER_assume((sec_r000297_7_1 >= 0) && (sec_r000297_7_1 <= 255));
  __CPROVER_assume((sec_r000297_7_2 >= 0) && (sec_r000297_7_2 <= 255));
  __CPROVER_assume((sec_r000297_8_1 >= 0) && (sec_r000297_8_1 <= 255));
  __CPROVER_assume((sec_r000297_8_2 >= 0) && (sec_r000297_8_2 <= 255));
  __CPROVER_assume((sec_r000297_9_1 >= 0) && (sec_r000297_9_1 <= 255));
  __CPROVER_assume((sec_r000297_9_2 >= 0) && (sec_r000297_9_2 <= 255));
  __CPROVER_assume((sec_r000297_10_1 >= 0) && (sec_r000297_10_1 <= 255));
  __CPROVER_assume((sec_r000297_10_2 >= 0) && (sec_r000297_10_2 <= 255));
  __CPROVER_assume((sec_r000297_11_1 >= 0) && (sec_r000297_11_1 <= 255));
  __CPROVER_assume((sec_r000297_11_2 >= 0) && (sec_r000297_11_2 <= 255));
  __CPROVER_assume((sec_r000297_12_1 >= 0) && (sec_r000297_12_1 <= 255));
  __CPROVER_assume((sec_r000297_12_2 >= 0) && (sec_r000297_12_2 <= 255));
  __CPROVER_assume((sec_r000297_13_1 >= 0) && (sec_r000297_13_1 <= 255));
  __CPROVER_assume((sec_r000297_13_2 >= 0) && (sec_r000297_13_2 <= 255));
  __CPROVER_assume((sec_r000297_14_1 >= 0) && (sec_r000297_14_1 <= 255));
  __CPROVER_assume((sec_r000297_14_2 >= 0) && (sec_r000297_14_2 <= 255));
  __CPROVER_assume((sec_r000297_15_1 >= 0) && (sec_r000297_15_1 <= 255));
  __CPROVER_assume((sec_r000297_15_2 >= 0) && (sec_r000297_15_2 <= 255));
  __CPROVER_assume((sec_r000297_16_1 >= 0) && (sec_r000297_16_1 <= 255));
  __CPROVER_assume((sec_r000297_16_2 >= 0) && (sec_r000297_16_2 <= 255));
  __CPROVER_assume((sec_r000297_17_1 >= 0) && (sec_r000297_17_1 <= 255));
  __CPROVER_assume((sec_r000297_17_2 >= 0) && (sec_r000297_17_2 <= 255));
  __CPROVER_assume((sec_r000297_18_1 >= 0) && (sec_r000297_18_1 <= 255));
  __CPROVER_assume((sec_r000297_18_2 >= 0) && (sec_r000297_18_2 <= 255));
  struct EventLog_R000297_9713_0 st_var_0_1 = {0};
  struct EventLog_R000297_9713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000297_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000297_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000297_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000297_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000297_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000297_0_2 + 7) & 15;
  struct Transaction_R000297_9713_1 st_var_1_1 = {0};
  struct Transaction_R000297_9713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000297_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000297_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000297_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000297_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000297_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000297_0_2 + 9) & 15;
  struct Vector3D_R000297_9713_2 st_var_2_1 = {0};
  struct Vector3D_R000297_9713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000297_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000297_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000297_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000297_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000297_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000297_0_2 + 11) & 15;
  struct MatrixBlock_R000297_9713_3 st_var_3_1 = {0};
  struct MatrixBlock_R000297_9713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000297_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000297_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000297_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000297_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000297_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000297_0_2 + 13) & 15;
  union PacketPayload_R000297_9713_0 u_var_1;
  union PacketPayload_R000297_9713_0 u_var_2;
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
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

  switch (stage_v_3_2)
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
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 45)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 45)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 32)
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
  if (stage_v_12_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 32)
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
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
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
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 30)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 30)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 48)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 48)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 55)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 55)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 28)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 28)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 46)
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
  if (stage_v_42_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 46)
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
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 45)
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
  if (stage_v_44_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 45)
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
  int stage_v_45_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (50 & 31);
  int stage_v_45_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (50 & 31);
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= (stage_v_45_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_45_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 47) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 34)
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
  if (stage_v_48_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 34)
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
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 55) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 53)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 53)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 43)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 43)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 31)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 31)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 52)
    {
      chk_sum_1 ^= stage_v_68_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_68_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 52)
    {
      chk_sum_2 ^= stage_v_68_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (st_var_3_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_3_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
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

  switch (stage_v_71_2)
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

  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000297_4_1 & 1) != 0)
  {
    if ((sec_r000297_7_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000297_13_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000297_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000297_13_1 + 7) & 127;
  }
  if ((sec_r000297_4_2 & 1) != 0)
  {
    if ((sec_r000297_7_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000297_13_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000297_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000297_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000297_7_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000297_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000297_7_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000297_7_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000297_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000297_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000297_18_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000297_20_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000297_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000297_20_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000297_18_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000297_20_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000297_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000297_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000297_7_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000297_1_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000297_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000297_1_1 + 7) & 127;
  }
  if ((sec_r000297_7_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000297_1_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000297_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000297_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000297_10_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000297_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000297_10_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000297_10_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000297_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000297_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000297_5_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000297_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000297_5_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000297_5_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000297_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000297_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000297_7_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000297_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000297_7_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000297_7_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000297_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000297_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000297_5_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000297_13_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000297_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000297_13_1 + 7) & 127;
  }
  if ((sec_r000297_5_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000297_13_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000297_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000297_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000297_6_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000297_14_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000297_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000297_14_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000297_6_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000297_14_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000297_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000297_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000297_7_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000297_19_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000297_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000297_19_1 + 7) & 127;
  }
  if ((sec_r000297_7_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000297_19_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000297_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000297_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000297_3_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000297_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000297_3_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000297_3_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000297_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000297_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000297_9_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000297_9_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000297_6_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000297_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000297_6_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000297_6_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000297_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000297_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000297_11_1 & 1) != 0)
  {
    if ((sec_r000297_7_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000297_19_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000297_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000297_19_1 + 7) & 127;
  }
  if ((sec_r000297_11_2 & 1) != 0)
  {
    if ((sec_r000297_7_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000297_19_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000297_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000297_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000297_9_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000297_14_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000297_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000297_14_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000297_9_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000297_14_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000297_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000297_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000297_13_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000297_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000297_13_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000297_13_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000297_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000297_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000297_18_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000297_18_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000297_13_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((sec_r000297_13_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000297_6_1 & 1) != 0)
  {
    if ((sec_r000297_3_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000297_18_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000297_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000297_18_1 + 7) & 127;
  }
  if ((sec_r000297_6_2 & 1) != 0)
  {
    if ((sec_r000297_3_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000297_18_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000297_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000297_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000297_12_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000297_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000297_12_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000297_12_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000297_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000297_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000297_15_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((sec_r000297_15_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000297_18_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000297_18_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000297_19_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000297_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000297_19_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000297_19_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000297_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000297_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000297_12_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000297_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000297_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000297_16_1 + 7) & 127;
  }
  if ((sec_r000297_12_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000297_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000297_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000297_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000297_9_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000297_11_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000297_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000297_11_1 + 7) & 127;
  }
  if ((sec_r000297_9_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000297_11_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000297_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000297_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000297_9_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000297_2_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000297_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000297_2_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000297_9_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000297_2_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000297_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000297_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000297_8_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000297_20_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000297_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000297_20_1 + 7) & 127;
  }
  if ((sec_r000297_8_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000297_20_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000297_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000297_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000297_1_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000297_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000297_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000297_0_1 + 7) & 127;
  }
  if ((sec_r000297_1_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000297_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000297_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000297_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000297_2_1 & 1) != 0)
  {
    if ((sec_r000297_18_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000297_8_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000297_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000297_8_1 + 7) & 127;
  }
  if ((sec_r000297_2_2 & 1) != 0)
  {
    if ((sec_r000297_18_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000297_8_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000297_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000297_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000297_5_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000297_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000297_5_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000297_5_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000297_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000297_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000297_12_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000297_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000297_12_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000297_12_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000297_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000297_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000297_15_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000297_15_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000297_10_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000297_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000297_10_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000297_10_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000297_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000297_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000297_1_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000297_15_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000297_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000297_15_1 + 7) & 127;
  }
  if ((sec_r000297_1_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000297_15_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000297_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000297_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000297_16_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000297_16_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000297_7_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000297_7_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000297_0_1 & 1) != 0)
  {
    if ((sec_r000297_7_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((sec_r000297_0_2 & 1) != 0)
  {
    if ((sec_r000297_7_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000297_0_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000297_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000297_0_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000297_0_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000297_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000297_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000297_17_1 & 1) != 0)
  {
    if ((sec_r000297_3_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000297_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000297_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000297_12_1 + 7) & 127;
  }
  if ((sec_r000297_17_2 & 1) != 0)
  {
    if ((sec_r000297_3_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000297_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000297_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000297_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000297_10_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000297_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000297_10_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000297_10_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000297_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000297_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000297_5_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000297_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000297_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000297_5_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000297_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000297_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000297_18_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000297_14_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000297_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000297_14_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000297_18_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000297_14_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000297_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000297_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000297_13_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000297_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000297_13_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000297_13_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000297_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000297_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000297_19_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000297_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000297_19_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000297_19_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000297_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000297_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000297_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000297_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000297_11_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000297_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000297_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000297_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000297_8_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000297_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000297_8_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000297_8_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000297_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000297_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000297_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000297_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000297_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000297_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000297_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000297_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000297_2_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000297_6_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000297_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000297_6_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000297_2_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000297_6_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000297_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000297_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000297_5_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000297_5_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000297_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000297_1_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000297_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000297_1_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000297_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000297_1_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000297_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000297_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000297_5_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000297_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000297_5_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000297_5_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000297_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000297_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000297_3_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000297_15_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000297_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000297_15_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000297_3_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000297_15_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000297_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000297_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000297_8_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000297_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000297_8_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000297_8_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000297_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000297_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000297_1_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000297_2_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000297_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000297_2_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000297_1_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000297_2_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000297_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000297_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000297_5_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000297_12_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000297_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000297_12_1 + 7) & 127;
  }
  if ((sec_r000297_5_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000297_12_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000297_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000297_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000297_16_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000297_0_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000297_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000297_0_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000297_16_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000297_0_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000297_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000297_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000297_15_1 & 1) != 0)
  {
    if ((sec_r000297_16_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000297_8_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000297_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000297_8_1 + 7) & 127;
  }
  if ((sec_r000297_15_2 & 1) != 0)
  {
    if ((sec_r000297_16_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000297_8_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000297_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000297_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000297_12_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000297_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000297_12_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000297_12_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000297_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000297_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000297_14_1 & 1) != 0)
  {
    if ((sec_r000297_16_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000297_20_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000297_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000297_20_1 + 7) & 127;
  }
  if ((sec_r000297_14_2 & 1) != 0)
  {
    if ((sec_r000297_16_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000297_20_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000297_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000297_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000297_6_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000297_5_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000297_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000297_5_1 + 7) & 127;
  }
  if ((sec_r000297_6_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000297_5_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000297_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000297_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000297_3_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000297_3_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000297_3_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000297_14_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000297_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000297_14_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000297_3_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000297_14_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000297_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000297_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000297_4_1 & 1) != 0)
  {
    if ((sec_r000297_13_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000297_7_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000297_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000297_7_1 + 7) & 127;
  }
  if ((sec_r000297_4_2 & 1) != 0)
  {
    if ((sec_r000297_13_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000297_7_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000297_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000297_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000297_13_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000297_11_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000297_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000297_11_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000297_13_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000297_11_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000297_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000297_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000297_15_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000297_5_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000297_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000297_5_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000297_15_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000297_5_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000297_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000297_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000297_16_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000297_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000297_16_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000297_16_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000297_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000297_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000297_1_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000297_1_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000297_12_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000297_6_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000297_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000297_6_1 + 7) & 127;
  }
  if ((sec_r000297_12_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000297_6_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000297_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000297_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000297_11_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000297_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000297_11_1 + 7) & 127;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000297_11_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000297_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000297_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000297_6_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000297_6_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000297_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000297_6_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000297_6_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000297_6_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000297_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000297_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000297_3_1 & 1) != 0)
  {
    if ((sec_r000297_5_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000297_15_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000297_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000297_15_1 + 7) & 127;
  }
  if ((sec_r000297_3_2 & 1) != 0)
  {
    if ((sec_r000297_5_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000297_15_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000297_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000297_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000297_6_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000297_11_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000297_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000297_11_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000297_6_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000297_11_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000297_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000297_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((sec_r000297_11_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000297_3_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000297_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000297_3_1 + 7) & 127;
  }
  if ((sec_r000297_11_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000297_3_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000297_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000297_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000297_7_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000297_7_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r000297_15_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000297_1_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000297_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000297_1_1 + 7) & 127;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r000297_15_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000297_1_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000297_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000297_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000297_14_1 & 1) != 0)
  {
    if ((sec_r000297_16_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000297_14_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000297_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000297_14_1 + 7) & 127;
  }
  if ((sec_r000297_14_2 & 1) != 0)
  {
    if ((sec_r000297_16_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000297_14_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000297_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000297_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000297_8_1 & 1) != 0)
  {
    if ((sec_r000297_1_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000297_2_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000297_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000297_2_1 + 7) & 127;
  }
  if ((sec_r000297_8_2 & 1) != 0)
  {
    if ((sec_r000297_1_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000297_2_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000297_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000297_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000297_1_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000297_1_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000297_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000297_1_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000297_1_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000297_1_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000297_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000297_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000297_17_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000297_17_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000297_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000297_17_1 + 7) & 127;
  }
  if ((sec_r000297_17_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000297_17_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000297_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000297_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000297_13_1 & 1) != 0)
  {
    if ((sec_r000297_2_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000297_10_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000297_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000297_10_1 + 7) & 127;
  }
  if ((sec_r000297_13_2 & 1) != 0)
  {
    if ((sec_r000297_2_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000297_10_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000297_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000297_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r000297_15_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000297_14_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000297_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000297_14_1 + 7) & 127;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((sec_r000297_15_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000297_14_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000297_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000297_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000297_20_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000297_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000297_20_1 + 7) & 127;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000297_20_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000297_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000297_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((sec_r000297_4_1 & 1) != 0)
  {
    if ((sec_r000297_4_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000297_20_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000297_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000297_20_1 + 7) & 127;
  }
  if ((sec_r000297_4_2 & 1) != 0)
  {
    if ((sec_r000297_4_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000297_20_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000297_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000297_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((sec_r000297_1_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000297_15_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000297_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000297_15_1 + 7) & 127;
  }
  if ((sec_r000297_1_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000297_15_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000297_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000297_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((sec_r000297_1_1 & 1) != 0)
  {
    if ((sec_r000297_12_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((sec_r000297_1_2 & 1) != 0)
  {
    if ((sec_r000297_12_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000297_16_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000297_10_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000297_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000297_10_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000297_16_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000297_10_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000297_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000297_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000297_0_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000297_6_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000297_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000297_6_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000297_0_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000297_6_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000297_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000297_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((sec_r000297_8_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_168_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_168_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((sec_r000297_8_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_168_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_168_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_169_1 = (pub_r000297_7_1 + 31) & 127;
    }
    else
    {
      stage_v_169_1 = (pub_r000297_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_1 = (pub_r000297_7_1 + 7) & 127;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_169_2 = (pub_r000297_7_2 + 31) & 127;
    }
    else
    {
      stage_v_169_2 = (pub_r000297_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_2 = (pub_r000297_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000297_17_1 & 2) != 0)
    {
      stage_v_170_1 = (pub_r000297_13_1 + 31) & 127;
    }
    else
    {
      stage_v_170_1 = (pub_r000297_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_1 = (pub_r000297_13_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000297_17_2 & 2) != 0)
    {
      stage_v_170_2 = (pub_r000297_13_2 + 31) & 127;
    }
    else
    {
      stage_v_170_2 = (pub_r000297_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_2 = (pub_r000297_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((sec_r000297_8_1 & 2) != 0)
    {
      stage_v_171_1 = (pub_r000297_9_1 + 31) & 127;
    }
    else
    {
      stage_v_171_1 = (pub_r000297_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_1 = (pub_r000297_9_1 + 7) & 127;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((sec_r000297_8_2 & 2) != 0)
    {
      stage_v_171_2 = (pub_r000297_9_2 + 31) & 127;
    }
    else
    {
      stage_v_171_2 = (pub_r000297_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_2 = (pub_r000297_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000297_10_1 & 2) != 0)
    {
      stage_v_172_1 = (pub_r000297_12_1 + 31) & 127;
    }
    else
    {
      stage_v_172_1 = (pub_r000297_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_1 = (pub_r000297_12_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000297_10_2 & 2) != 0)
    {
      stage_v_172_2 = (pub_r000297_12_2 + 31) & 127;
    }
    else
    {
      stage_v_172_2 = (pub_r000297_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_2 = (pub_r000297_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000297_15_1 & 2) != 0)
    {
      stage_v_173_1 = (pub_r000297_6_1 + 31) & 127;
    }
    else
    {
      stage_v_173_1 = (pub_r000297_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_173_1 = (pub_r000297_6_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000297_15_2 & 2) != 0)
    {
      stage_v_173_2 = (pub_r000297_6_2 + 31) & 127;
    }
    else
    {
      stage_v_173_2 = (pub_r000297_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_173_2 = (pub_r000297_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((sec_r000297_14_1 & 2) != 0)
    {
      stage_v_174_1 = (pub_r000297_4_1 + 31) & 127;
    }
    else
    {
      stage_v_174_1 = (pub_r000297_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_174_1 = (pub_r000297_4_1 + 7) & 127;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((sec_r000297_14_2 & 2) != 0)
    {
      stage_v_174_2 = (pub_r000297_4_2 + 31) & 127;
    }
    else
    {
      stage_v_174_2 = (pub_r000297_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_174_2 = (pub_r000297_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000297_19_1 == pub_r000297_19_2);
  __CPROVER_assume(pub_r000297_0_1 == pub_r000297_0_2);
  __CPROVER_assume(sec_r000297_6_1 != sec_r000297_6_2);
  __CPROVER_assume(sec_r000297_10_1 != sec_r000297_10_2);
  __CPROVER_assume(sec_r000297_1_1 != sec_r000297_1_2);
  __CPROVER_assume(pub_r000297_3_1 == pub_r000297_3_2);
  __CPROVER_assume(pub_r000297_2_1 == pub_r000297_2_2);
  __CPROVER_assume(pub_r000297_7_1 == pub_r000297_7_2);
  __CPROVER_assume(sec_r000297_14_1 != sec_r000297_14_2);
  __CPROVER_assume(pub_r000297_9_1 == pub_r000297_9_2);
  __CPROVER_assume(sec_r000297_18_1 != sec_r000297_18_2);
  __CPROVER_assume(sec_r000297_3_1 != sec_r000297_3_2);
  __CPROVER_assume(pub_r000297_4_1 == pub_r000297_4_2);
  __CPROVER_assume(sec_r000297_4_1 != sec_r000297_4_2);
  __CPROVER_assume(pub_r000297_11_1 == pub_r000297_11_2);
  __CPROVER_assume(sec_r000297_11_1 != sec_r000297_11_2);
  __CPROVER_assume(pub_r000297_10_1 == pub_r000297_10_2);
  __CPROVER_assume(pub_r000297_15_1 == pub_r000297_15_2);
  __CPROVER_assume(pub_r000297_14_1 == pub_r000297_14_2);
  __CPROVER_assume(pub_r000297_20_1 == pub_r000297_20_2);
  __CPROVER_assume(pub_r000297_13_1 == pub_r000297_13_2);
  __CPROVER_assume(pub_r000297_1_1 == pub_r000297_1_2);
  __CPROVER_assume(sec_r000297_9_1 != sec_r000297_9_2);
  __CPROVER_assume(pub_r000297_18_1 == pub_r000297_18_2);
  __CPROVER_assume(pub_r000297_5_1 == pub_r000297_5_2);
  __CPROVER_assume(pub_r000297_8_1 == pub_r000297_8_2);
  __CPROVER_assume(sec_r000297_12_1 != sec_r000297_12_2);
  __CPROVER_assume(pub_r000297_16_1 == pub_r000297_16_2);
  __CPROVER_assume(sec_r000297_15_1 != sec_r000297_15_2);
  __CPROVER_assume(pub_r000297_17_1 == pub_r000297_17_2);
  __CPROVER_assume(sec_r000297_16_1 != sec_r000297_16_2);
  __CPROVER_assume(sec_r000297_8_1 != sec_r000297_8_2);
  __CPROVER_assume(sec_r000297_2_1 != sec_r000297_2_2);
  __CPROVER_assume(sec_r000297_0_1 != sec_r000297_0_2);
  __CPROVER_assume(pub_r000297_12_1 == pub_r000297_12_2);
  __CPROVER_assume(sec_r000297_5_1 != sec_r000297_5_2);
  __CPROVER_assume(sec_r000297_13_1 != sec_r000297_13_2);
  __CPROVER_assume(sec_r000297_17_1 != sec_r000297_17_2);
  __CPROVER_assume(sec_r000297_7_1 != sec_r000297_7_2);
  __CPROVER_assume(pub_r000297_6_1 == pub_r000297_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.density == st_var_3_2.density);
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
}


