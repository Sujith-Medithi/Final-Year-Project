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
struct Transaction_R001570_7013_0
{
  int rate;
  int auth_code;
  int fee;
  int account_id;
  short balance;
  unsigned char status;
  int buffer[3];
};
struct SensorNode_R001570_7013_1
{
  unsigned char reading;
  int gain;
  int status;
  int buffer[3];
};
struct AudioFrame_R001570_7013_2
{
  int channels;
  short envelope;
  int peak;
  int sample_rate;
  int gain;
  int buffer[3];
};
struct Vector3D_R001570_7013_3
{
  short coord_z;
  int norm_sq;
  int coord_y;
  int buffer[3];
};
union PacketPayload_R001570_7013_0
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
void fn_R001570_7013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_61_1 > 15)
  {
    acc_1 = ((acc_1 + (quotient_61_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_61_2 > 15)
  {
    acc_2 = ((acc_2 + (quotient_61_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_48_1)
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

  switch (delta_48_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_61_1 == quotient_61_2);
  assert(delta_48_1 == delta_48_2);
}

int fn_R001570_7013_0(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_61 > 15)
  {
    acc = ((acc + (quotient_61 * 2)) + 5) & 127;
    aux ^= quotient_61 & 15;
  }
  else
  {
    acc = ((acc - quotient_61) + 11) & 127;
    aux += 3;
  }
  int delta_48 = (aux + st.buffer[1]) & 3;
  switch (delta_48)
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

void fn_R001570_7013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st_1 = {0};
  struct SensorNode_R001570_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_54_1 = local_arr_1[aux_1 % 3];
  int cursor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_54_2 * 2)) & 127;
  int stride_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_74_1 > 42)
  {
    acc_1 = ((acc_1 + (stride_74_1 * 2)) + 5) & 127;
    aux_1 ^= stride_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_74_2 > 42)
  {
    acc_2 = ((acc_2 + (stride_74_2 * 2)) + 5) & 127;
    aux_2 ^= stride_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(cursor_54_1 == cursor_54_2);
  assert(stride_74_1 == stride_74_2);
}

int fn_R001570_7013_1(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int cursor_54 = local_arr[aux % 3];
  acc = (acc + (cursor_54 * 2)) & 127;
  int stride_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_74 > 42)
  {
    acc = ((acc + (stride_74 * 2)) + 5) & 127;
    aux ^= stride_74 & 15;
  }
  else
  {
    acc = ((acc - stride_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_21_1) & 63;
  aux_2 = (aux_2 + cursor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_64_1 > 10)
  {
    acc_1 = ((acc_1 + (residue_64_1 * 2)) + 5) & 127;
    aux_1 ^= residue_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_64_2 > 10)
  {
    acc_2 = ((acc_2 + (residue_64_2 * 2)) + 5) & 127;
    aux_2 ^= residue_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_60_1 = local_arr_1[aux_1 % 3];
  int damping_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_21_1 == cursor_21_2);
  assert(residue_64_1 == residue_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_60_1 == damping_60_2);
}

int fn_R001570_7013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_64 > 10)
  {
    acc = ((acc + (residue_64 * 2)) + 5) & 127;
    aux ^= residue_64 & 15;
  }
  else
  {
    acc = ((acc - residue_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_60 = local_arr[aux % 3];
  acc = (acc + (damping_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st_1 = {0};
  struct Vector3D_R001570_7013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int stride_47_1 = 0;
  int stride_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_47_1 = ((stride_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_47_2 = ((stride_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_47_1) & 127;
    acc_2 = (acc_2 + stride_47_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_59_1 = local_arr_1[aux_1 % 3];
  int parity_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_59_2 * 2)) & 127;
  int tally_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_32_1) & 63;
  aux_2 = (aux_2 + tally_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_47_1 == stride_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_59_1 == parity_59_2);
  assert(tally_32_1 == tally_32_2);
}

int fn_R001570_7013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int stride_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_47 = ((stride_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_47) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_59 = local_arr[aux % 3];
  acc = (acc + (parity_59 * 2)) & 127;
  int tally_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001570_7013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_36_1 = local_arr_1[aux_1 % 3];
  int damping_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_75_1 > 16)
  {
    acc_1 = ((acc_1 + (bound_75_1 * 2)) + 5) & 127;
    aux_1 ^= bound_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_75_2 > 16)
  {
    acc_2 = ((acc_2 + (bound_75_2 * 2)) + 5) & 127;
    aux_2 ^= bound_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_36_1 == damping_36_2);
  assert(bound_75_1 == bound_75_2);
}

int fn_R001570_7013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int damping_36 = local_arr[aux % 3];
  acc = (acc + (damping_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_75 > 16)
  {
    acc = ((acc + (bound_75 * 2)) + 5) & 127;
    aux ^= bound_75 & 15;
  }
  else
  {
    acc = ((acc - bound_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001570_7013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_65_1 = local_arr_1[aux_1 % 3];
  int metric_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_65_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_29_1)
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

  switch (quotient_29_2)
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

  int index_reg_71_1 = 0;
  int index_reg_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_71_1 = ((index_reg_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_71_2 = ((index_reg_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_71_1) & 127;
    acc_2 = (acc_2 + index_reg_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_65_1 == metric_65_2);
  assert(quotient_29_1 == quotient_29_2);
  assert(index_reg_71_1 == index_reg_71_2);
}

int fn_R001570_7013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int metric_65 = local_arr[aux % 3];
  acc = (acc + (metric_65 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_29 = (aux + st.buffer[1]) & 3;
  switch (quotient_29)
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

  int index_reg_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_71 = ((index_reg_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001570_7013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_25_1 = 0;
  int sample_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_25_1 = ((sample_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_25_2 = ((sample_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_25_1) & 127;
    acc_2 = (acc_2 + sample_25_2) & 127;
  }

  int bound_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_70_1) & 63;
  aux_2 = (aux_2 + bound_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(bound_70_1 == bound_70_2);
}

int fn_R001570_7013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_25 = ((sample_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_25) & 127;
  }

  int bound_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001570_7013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_76_1 = local_arr_1[aux_1 % 3];
  int delta_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_76_2 * 2)) & 127;
  int segment_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_84_1 > 28)
  {
    acc_1 = ((acc_1 + (segment_84_1 * 2)) + 5) & 127;
    aux_1 ^= segment_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_84_2 > 28)
  {
    acc_2 = ((acc_2 + (segment_84_2 * 2)) + 5) & 127;
    aux_2 ^= segment_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_12_1)
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

  switch (damping_12_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_76_1 == delta_76_2);
  assert(segment_84_1 == segment_84_2);
  assert(damping_12_1 == damping_12_2);
}

int fn_R001570_7013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int delta_76 = local_arr[aux % 3];
  acc = (acc + (delta_76 * 2)) & 127;
  int segment_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_84 > 28)
  {
    acc = ((acc + (segment_84 * 2)) + 5) & 127;
    aux ^= segment_84 & 15;
  }
  else
  {
    acc = ((acc - segment_84) + 11) & 127;
    aux += 3;
  }
  int damping_12 = (aux + st.buffer[1]) & 3;
  switch (damping_12)
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
  return (acc + aux) & 255;
}

void fn_R001570_7013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_24_1 > 28)
  {
    acc_1 = ((acc_1 + (cursor_24_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_24_2 > 28)
  {
    acc_2 = ((acc_2 + (cursor_24_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_92_1) & 63;
  aux_2 = (aux_2 + accumulator_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_24_1 == cursor_24_2);
  assert(accumulator_92_1 == accumulator_92_2);
}

int fn_R001570_7013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_24 > 28)
  {
    acc = ((acc + (cursor_24 * 2)) + 5) & 127;
    aux ^= cursor_24 & 15;
  }
  else
  {
    acc = ((acc - cursor_24) + 11) & 127;
    aux += 3;
  }
  int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001570_7013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st_1 = {0};
  struct Vector3D_R001570_7013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quantum_80_1 = 0;
  int quantum_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_80_1 = ((quantum_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_80_2 = ((quantum_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_80_1) & 127;
    acc_2 = (acc_2 + quantum_80_2) & 127;
  }

  int coefficient_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_85_1)
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

  switch (coefficient_85_2)
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

  int mask_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_14_1) & 63;
  aux_2 = (aux_2 + mask_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_29_1 = local_arr_1[aux_1 % 3];
  int weight_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_80_1 == quantum_80_2);
  assert(coefficient_85_1 == coefficient_85_2);
  assert(mask_14_1 == mask_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_29_1 == weight_29_2);
}

int fn_R001570_7013_9(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quantum_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_80 = ((quantum_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_80) & 127;
  }

  int coefficient_85 = (aux + st.buffer[1]) & 3;
  switch (coefficient_85)
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

  int mask_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_14) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_29 = local_arr[aux % 3];
  acc = (acc + (weight_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
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
  int checksum_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_68_1 > 23)
  {
    acc_1 = ((acc_1 + (checksum_68_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_68_2 > 23)
  {
    acc_2 = ((acc_2 + (checksum_68_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_10_1) & 63;
  aux_2 = (aux_2 + checksum_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_90_1 = local_arr_1[aux_1 % 3];
  int offset_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_68_1 == checksum_68_2);
  assert(checksum_10_1 == checksum_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_90_1 == offset_90_2);
}

int fn_R001570_7013_10(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_68 > 23)
  {
    acc = ((acc + (checksum_68 * 2)) + 5) & 127;
    aux ^= checksum_68 & 15;
  }
  else
  {
    acc = ((acc - checksum_68) + 11) & 127;
    aux += 3;
  }
  int checksum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_90 = local_arr[aux % 3];
  acc = (acc + (offset_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int damping_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_21_1) & 63;
  aux_2 = (aux_2 + damping_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_69_1)
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

  switch (phase_69_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_21_1 == damping_21_2);
  assert(phase_69_1 == phase_69_2);
}

int fn_R001570_7013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int damping_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_21) & 63;
  acc ^= aux;
  int phase_69 = (aux + st.buffer[1]) & 3;
  switch (phase_69)
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

void fn_R001570_7013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st_1 = {0};
  struct SensorNode_R001570_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_36_1 = local_arr_1[aux_1 % 3];
  int quantum_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_36_2 * 2)) & 127;
  int sample_99_1 = 0;
  int sample_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_99_1 = ((sample_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_99_2 = ((sample_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_99_1) & 127;
    acc_2 = (acc_2 + sample_99_2) & 127;
  }

  int delta_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_33_1)
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

  switch (delta_33_2)
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

  assert(quantum_36_1 == quantum_36_2);
  assert(sample_99_1 == sample_99_2);
  assert(delta_33_1 == delta_33_2);
}

int fn_R001570_7013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int quantum_36 = local_arr[aux % 3];
  acc = (acc + (quantum_36 * 2)) & 127;
  int sample_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_99 = ((sample_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_99) & 127;
  }

  int delta_33 = (aux + st.buffer[1]) & 3;
  switch (delta_33)
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

void fn_R001570_7013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st_1 = {0};
  struct SensorNode_R001570_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_34_1) & 63;
  aux_2 = (aux_2 + bound_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_73_1 > 32)
  {
    acc_1 = ((acc_1 + (scale_73_1 * 2)) + 5) & 127;
    aux_1 ^= scale_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_73_2 > 32)
  {
    acc_2 = ((acc_2 + (scale_73_2 * 2)) + 5) & 127;
    aux_2 ^= scale_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_34_1 == bound_34_2);
  assert(scale_73_1 == scale_73_2);
}

int fn_R001570_7013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_34) & 63;
  acc ^= aux;
  int scale_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_73 > 32)
  {
    acc = ((acc + (scale_73 * 2)) + 5) & 127;
    aux ^= scale_73 & 15;
  }
  else
  {
    acc = ((acc - scale_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001570_7013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st_1 = {0};
  struct Vector3D_R001570_7013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_33_1) & 63;
  aux_2 = (aux_2 + pivot_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_93_1 = local_arr_1[aux_1 % 3];
  int sample_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_33_1 == pivot_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_93_1 == sample_93_2);
}

int fn_R001570_7013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_33) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_93 = local_arr[aux % 3];
  acc = (acc + (sample_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int vector_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_81_1 > 18)
  {
    acc_1 = ((acc_1 + (vector_81_1 * 2)) + 5) & 127;
    aux_1 ^= vector_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_81_2 > 18)
  {
    acc_2 = ((acc_2 + (vector_81_2 * 2)) + 5) & 127;
    aux_2 ^= vector_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_81_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_52_1 = local_arr_1[aux_1 % 3];
  int weight_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_81_1 == vector_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_52_1 == weight_52_2);
}

int fn_R001570_7013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int vector_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_81 > 18)
  {
    acc = ((acc + (vector_81 * 2)) + 5) & 127;
    aux ^= vector_81 & 15;
  }
  else
  {
    acc = ((acc - vector_81) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_52 = local_arr[aux % 3];
  acc = (acc + (weight_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int vector_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_60_1)
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

  switch (vector_60_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_79_1 = local_arr_1[aux_1 % 3];
  int tracker_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_79_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_50_1 > 19)
  {
    acc_1 = ((acc_1 + (window_50_1 * 2)) + 5) & 127;
    aux_1 ^= window_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_50_2 > 19)
  {
    acc_2 = ((acc_2 + (window_50_2 * 2)) + 5) & 127;
    aux_2 ^= window_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_60_1 == vector_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_79_1 == tracker_79_2);
  assert(window_50_1 == window_50_2);
}

int fn_R001570_7013_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int vector_60 = (aux + st.buffer[1]) & 3;
  switch (vector_60)
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

  int local_arr[3] = {4, 9, 15};
  int tracker_79 = local_arr[aux % 3];
  acc = (acc + (tracker_79 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_50 > 19)
  {
    acc = ((acc + (window_50 * 2)) + 5) & 127;
    aux ^= window_50 & 15;
  }
  else
  {
    acc = ((acc - window_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001570_7013_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int metric_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_58_1) & 63;
  aux_2 = (aux_2 + metric_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_45_1)
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

  switch (delta_45_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_58_1 == metric_58_2);
  assert(delta_45_1 == delta_45_2);
}

int fn_R001570_7013_17(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int metric_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_58) & 63;
  acc ^= aux;
  int delta_45 = (aux + st.buffer[1]) & 3;
  switch (delta_45)
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

void fn_R001570_7013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_40_1 = 0;
  int index_reg_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_40_1 = ((index_reg_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_40_2 = ((index_reg_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_40_1) & 127;
    acc_2 = (acc_2 + index_reg_40_2) & 127;
  }

  int coefficient_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_52_1)
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

  switch (coefficient_52_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_40_1 == index_reg_40_2);
  assert(coefficient_52_1 == coefficient_52_2);
}

int fn_R001570_7013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_40 = ((index_reg_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_40) & 127;
  }

  int coefficient_52 = (aux + st.buffer[1]) & 3;
  switch (coefficient_52)
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

void fn_R001570_7013_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st_1 = {0};
  struct Vector3D_R001570_7013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int residue_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_48_1) & 63;
  aux_2 = (aux_2 + residue_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_27_1 = local_arr_1[aux_1 % 3];
  int index_reg_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_27_2 * 2)) & 127;
  int metric_90_1 = 0;
  int metric_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_90_1 = ((metric_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_90_2 = ((metric_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_90_1) & 127;
    acc_2 = (acc_2 + metric_90_2) & 127;
  }

  int tally_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_99_1 > 16)
  {
    acc_1 = ((acc_1 + (tally_99_1 * 2)) + 5) & 127;
    aux_1 ^= tally_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_99_2 > 16)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_48_1 == residue_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_27_1 == index_reg_27_2);
  assert(metric_90_1 == metric_90_2);
  assert(tally_99_1 == tally_99_2);
}

int fn_R001570_7013_19(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001570_7013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int residue_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_27 = local_arr[aux % 3];
  acc = (acc + (index_reg_27 * 2)) & 127;
  int metric_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_90 = ((metric_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_90) & 127;
  }

  int tally_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_99 > 16)
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

void fn_R001570_7013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st_1 = {0};
  struct SensorNode_R001570_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_39_1 > 46)
  {
    acc_1 = ((acc_1 + (window_39_1 * 2)) + 5) & 127;
    aux_1 ^= window_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_39_2 > 46)
  {
    acc_2 = ((acc_2 + (window_39_2 * 2)) + 5) & 127;
    aux_2 ^= window_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_89_1 = 0;
  int tracker_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_89_1 = ((tracker_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_89_2 = ((tracker_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_89_1) & 127;
    acc_2 = (acc_2 + tracker_89_2) & 127;
  }

  int mask_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_86_1)
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

  switch (mask_86_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_39_1 == window_39_2);
  assert(tracker_89_1 == tracker_89_2);
  assert(mask_86_1 == mask_86_2);
}

int fn_R001570_7013_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001570_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_39 > 46)
  {
    acc = ((acc + (window_39 * 2)) + 5) & 127;
    aux ^= window_39 & 15;
  }
  else
  {
    acc = ((acc - window_39) + 11) & 127;
    aux += 3;
  }
  int tracker_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_89 = ((tracker_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_89) & 127;
  }

  int mask_86 = (aux + st.buffer[1]) & 3;
  switch (mask_86)
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

void fn_R001570_7013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st_1 = {0};
  struct AudioFrame_R001570_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_48_1) & 63;
  aux_2 = (aux_2 + factor_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_78_1 = 0;
  int factor_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_78_1 = ((factor_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_78_2 = ((factor_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_78_1) & 127;
    acc_2 = (acc_2 + factor_78_2) & 127;
  }

  int tracker_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_76_1)
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

  switch (tracker_76_2)
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
  int checksum_80_1 = local_arr_1[aux_1 % 3];
  int checksum_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_48_1 == factor_48_2);
  assert(factor_78_1 == factor_78_2);
  assert(tracker_76_1 == tracker_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_80_1 == checksum_80_2);
}

int fn_R001570_7013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001570_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_48) & 63;
  acc ^= aux;
  int factor_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_78 = ((factor_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_78) & 127;
  }

  int tracker_76 = (aux + st.buffer[1]) & 3;
  switch (tracker_76)
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
  int checksum_80 = local_arr[aux % 3];
  acc = (acc + (checksum_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001570_7013_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st_1 = {0};
  struct Transaction_R001570_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int anchor_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_77_1)
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

  switch (anchor_77_2)
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
  int delta_53_1 = local_arr_1[aux_1 % 3];
  int delta_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_58_1 = 0;
  int mask_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_58_1 = ((mask_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_58_2 = ((mask_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_58_1) & 127;
    acc_2 = (acc_2 + mask_58_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_77_1 == anchor_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_53_1 == delta_53_2);
  assert(mask_58_1 == mask_58_2);
}

int fn_R001570_7013_22(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001570_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int anchor_77 = (aux + st.buffer[1]) & 3;
  switch (anchor_77)
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
  int delta_53 = local_arr[aux % 3];
  acc = (acc + (delta_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_58 = ((mask_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_58) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001570_0_1;
  int sec_r001570_0_2;
  int sec_r001570_1_1;
  int sec_r001570_1_2;
  int sec_r001570_2_1;
  int sec_r001570_2_2;
  int sec_r001570_3_1;
  int sec_r001570_3_2;
  int sec_r001570_4_1;
  int sec_r001570_4_2;
  int sec_r001570_5_1;
  int sec_r001570_5_2;
  int sec_r001570_6_1;
  int sec_r001570_6_2;
  int sec_r001570_7_1;
  int sec_r001570_7_2;
  int sec_r001570_8_1;
  int sec_r001570_8_2;
  int sec_r001570_9_1;
  int sec_r001570_9_2;
  int sec_r001570_10_1;
  int sec_r001570_10_2;
  int sec_r001570_11_1;
  int sec_r001570_11_2;
  int sec_r001570_12_1;
  int sec_r001570_12_2;
  int sec_r001570_13_1;
  int sec_r001570_13_2;
  int sec_r001570_14_1;
  int sec_r001570_14_2;
  int sec_r001570_15_1;
  int sec_r001570_15_2;
  int sec_r001570_16_1;
  int sec_r001570_16_2;
  int sec_r001570_17_1;
  int sec_r001570_17_2;
  int pub_r001570_0_1;
  int pub_r001570_0_2;
  int pub_r001570_1_1;
  int pub_r001570_1_2;
  int pub_r001570_2_1;
  int pub_r001570_2_2;
  int pub_r001570_3_1;
  int pub_r001570_3_2;
  int pub_r001570_4_1;
  int pub_r001570_4_2;
  int pub_r001570_5_1;
  int pub_r001570_5_2;
  int pub_r001570_6_1;
  int pub_r001570_6_2;
  int pub_r001570_7_1;
  int pub_r001570_7_2;
  int pub_r001570_8_1;
  int pub_r001570_8_2;
  int pub_r001570_9_1;
  int pub_r001570_9_2;
  int pub_r001570_10_1;
  int pub_r001570_10_2;
  int pub_r001570_11_1;
  int pub_r001570_11_2;
  int pub_r001570_12_1;
  int pub_r001570_12_2;
  int pub_r001570_13_1;
  int pub_r001570_13_2;
  int pub_r001570_14_1;
  int pub_r001570_14_2;
  int pub_r001570_15_1;
  int pub_r001570_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001570_0_1 >= (-100)) && (pub_r001570_0_1 <= 100));
  __CPROVER_assume((pub_r001570_0_2 >= (-100)) && (pub_r001570_0_2 <= 100));
  __CPROVER_assume((pub_r001570_1_1 >= (-100)) && (pub_r001570_1_1 <= 100));
  __CPROVER_assume((pub_r001570_1_2 >= (-100)) && (pub_r001570_1_2 <= 100));
  __CPROVER_assume((pub_r001570_2_1 >= (-100)) && (pub_r001570_2_1 <= 100));
  __CPROVER_assume((pub_r001570_2_2 >= (-100)) && (pub_r001570_2_2 <= 100));
  __CPROVER_assume((pub_r001570_3_1 >= (-100)) && (pub_r001570_3_1 <= 100));
  __CPROVER_assume((pub_r001570_3_2 >= (-100)) && (pub_r001570_3_2 <= 100));
  __CPROVER_assume((pub_r001570_4_1 >= (-100)) && (pub_r001570_4_1 <= 100));
  __CPROVER_assume((pub_r001570_4_2 >= (-100)) && (pub_r001570_4_2 <= 100));
  __CPROVER_assume((pub_r001570_5_1 >= (-100)) && (pub_r001570_5_1 <= 100));
  __CPROVER_assume((pub_r001570_5_2 >= (-100)) && (pub_r001570_5_2 <= 100));
  __CPROVER_assume((pub_r001570_6_1 >= (-100)) && (pub_r001570_6_1 <= 100));
  __CPROVER_assume((pub_r001570_6_2 >= (-100)) && (pub_r001570_6_2 <= 100));
  __CPROVER_assume((pub_r001570_7_1 >= (-100)) && (pub_r001570_7_1 <= 100));
  __CPROVER_assume((pub_r001570_7_2 >= (-100)) && (pub_r001570_7_2 <= 100));
  __CPROVER_assume((pub_r001570_8_1 >= (-100)) && (pub_r001570_8_1 <= 100));
  __CPROVER_assume((pub_r001570_8_2 >= (-100)) && (pub_r001570_8_2 <= 100));
  __CPROVER_assume((pub_r001570_9_1 >= (-100)) && (pub_r001570_9_1 <= 100));
  __CPROVER_assume((pub_r001570_9_2 >= (-100)) && (pub_r001570_9_2 <= 100));
  __CPROVER_assume((pub_r001570_10_1 >= (-100)) && (pub_r001570_10_1 <= 100));
  __CPROVER_assume((pub_r001570_10_2 >= (-100)) && (pub_r001570_10_2 <= 100));
  __CPROVER_assume((pub_r001570_11_1 >= (-100)) && (pub_r001570_11_1 <= 100));
  __CPROVER_assume((pub_r001570_11_2 >= (-100)) && (pub_r001570_11_2 <= 100));
  __CPROVER_assume((pub_r001570_12_1 >= (-100)) && (pub_r001570_12_1 <= 100));
  __CPROVER_assume((pub_r001570_12_2 >= (-100)) && (pub_r001570_12_2 <= 100));
  __CPROVER_assume((pub_r001570_13_1 >= (-100)) && (pub_r001570_13_1 <= 100));
  __CPROVER_assume((pub_r001570_13_2 >= (-100)) && (pub_r001570_13_2 <= 100));
  __CPROVER_assume((pub_r001570_14_1 >= (-100)) && (pub_r001570_14_1 <= 100));
  __CPROVER_assume((pub_r001570_14_2 >= (-100)) && (pub_r001570_14_2 <= 100));
  __CPROVER_assume((pub_r001570_15_1 >= (-100)) && (pub_r001570_15_1 <= 100));
  __CPROVER_assume((pub_r001570_15_2 >= (-100)) && (pub_r001570_15_2 <= 100));
  __CPROVER_assume((sec_r001570_0_1 >= 0) && (sec_r001570_0_1 <= 255));
  __CPROVER_assume((sec_r001570_0_2 >= 0) && (sec_r001570_0_2 <= 255));
  __CPROVER_assume((sec_r001570_1_1 >= 0) && (sec_r001570_1_1 <= 255));
  __CPROVER_assume((sec_r001570_1_2 >= 0) && (sec_r001570_1_2 <= 255));
  __CPROVER_assume((sec_r001570_2_1 >= 0) && (sec_r001570_2_1 <= 255));
  __CPROVER_assume((sec_r001570_2_2 >= 0) && (sec_r001570_2_2 <= 255));
  __CPROVER_assume((sec_r001570_3_1 >= 0) && (sec_r001570_3_1 <= 255));
  __CPROVER_assume((sec_r001570_3_2 >= 0) && (sec_r001570_3_2 <= 255));
  __CPROVER_assume((sec_r001570_4_1 >= 0) && (sec_r001570_4_1 <= 255));
  __CPROVER_assume((sec_r001570_4_2 >= 0) && (sec_r001570_4_2 <= 255));
  __CPROVER_assume((sec_r001570_5_1 >= 0) && (sec_r001570_5_1 <= 255));
  __CPROVER_assume((sec_r001570_5_2 >= 0) && (sec_r001570_5_2 <= 255));
  __CPROVER_assume((sec_r001570_6_1 >= 0) && (sec_r001570_6_1 <= 255));
  __CPROVER_assume((sec_r001570_6_2 >= 0) && (sec_r001570_6_2 <= 255));
  __CPROVER_assume((sec_r001570_7_1 >= 0) && (sec_r001570_7_1 <= 255));
  __CPROVER_assume((sec_r001570_7_2 >= 0) && (sec_r001570_7_2 <= 255));
  __CPROVER_assume((sec_r001570_8_1 >= 0) && (sec_r001570_8_1 <= 255));
  __CPROVER_assume((sec_r001570_8_2 >= 0) && (sec_r001570_8_2 <= 255));
  __CPROVER_assume((sec_r001570_9_1 >= 0) && (sec_r001570_9_1 <= 255));
  __CPROVER_assume((sec_r001570_9_2 >= 0) && (sec_r001570_9_2 <= 255));
  __CPROVER_assume((sec_r001570_10_1 >= 0) && (sec_r001570_10_1 <= 255));
  __CPROVER_assume((sec_r001570_10_2 >= 0) && (sec_r001570_10_2 <= 255));
  __CPROVER_assume((sec_r001570_11_1 >= 0) && (sec_r001570_11_1 <= 255));
  __CPROVER_assume((sec_r001570_11_2 >= 0) && (sec_r001570_11_2 <= 255));
  __CPROVER_assume((sec_r001570_12_1 >= 0) && (sec_r001570_12_1 <= 255));
  __CPROVER_assume((sec_r001570_12_2 >= 0) && (sec_r001570_12_2 <= 255));
  __CPROVER_assume((sec_r001570_13_1 >= 0) && (sec_r001570_13_1 <= 255));
  __CPROVER_assume((sec_r001570_13_2 >= 0) && (sec_r001570_13_2 <= 255));
  __CPROVER_assume((sec_r001570_14_1 >= 0) && (sec_r001570_14_1 <= 255));
  __CPROVER_assume((sec_r001570_14_2 >= 0) && (sec_r001570_14_2 <= 255));
  __CPROVER_assume((sec_r001570_15_1 >= 0) && (sec_r001570_15_1 <= 255));
  __CPROVER_assume((sec_r001570_15_2 >= 0) && (sec_r001570_15_2 <= 255));
  __CPROVER_assume((sec_r001570_16_1 >= 0) && (sec_r001570_16_1 <= 255));
  __CPROVER_assume((sec_r001570_16_2 >= 0) && (sec_r001570_16_2 <= 255));
  __CPROVER_assume((sec_r001570_17_1 >= 0) && (sec_r001570_17_1 <= 255));
  __CPROVER_assume((sec_r001570_17_2 >= 0) && (sec_r001570_17_2 <= 255));
  struct Transaction_R001570_7013_0 st_var_0_1 = {0};
  struct Transaction_R001570_7013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001570_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001570_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001570_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001570_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001570_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001570_0_2 + 7) & 15;
  struct SensorNode_R001570_7013_1 st_var_1_1 = {0};
  struct SensorNode_R001570_7013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001570_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001570_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001570_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001570_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001570_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001570_0_2 + 9) & 15;
  struct AudioFrame_R001570_7013_2 st_var_2_1 = {0};
  struct AudioFrame_R001570_7013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001570_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001570_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001570_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001570_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001570_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001570_0_2 + 11) & 15;
  struct Vector3D_R001570_7013_3 st_var_3_1 = {0};
  struct Vector3D_R001570_7013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001570_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001570_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001570_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001570_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001570_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001570_0_2 + 13) & 15;
  union PacketPayload_R001570_7013_0 u_var_1;
  union PacketPayload_R001570_7013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001570_7013_0(sec_r001570_0_1, sec_r001570_1_1);
  int helper_flow_0_2 = fn_R001570_7013_0(sec_r001570_0_2, sec_r001570_1_2);
  fn_R001570_7013_0_2(sec_r001570_0_1, sec_r001570_1_1, sec_r001570_0_2, sec_r001570_1_2);
  int helper_flow_1_1 = fn_R001570_7013_1(sec_r001570_1_1, sec_r001570_2_1);
  int helper_flow_1_2 = fn_R001570_7013_1(sec_r001570_1_2, sec_r001570_2_2);
  fn_R001570_7013_1_2(sec_r001570_1_1, sec_r001570_2_1, sec_r001570_1_2, sec_r001570_2_2);
  int helper_flow_2_1 = fn_R001570_7013_2(sec_r001570_2_1, pub_r001570_3_1, pub_r001570_4_1, pub_r001570_5_1);
  int helper_flow_2_2 = fn_R001570_7013_2(sec_r001570_2_2, pub_r001570_3_2, pub_r001570_4_2, pub_r001570_5_2);
  fn_R001570_7013_2_2(sec_r001570_2_1, pub_r001570_3_1, pub_r001570_4_1, pub_r001570_5_1, sec_r001570_2_2, pub_r001570_3_2, pub_r001570_4_2, pub_r001570_5_2);
  int helper_flow_3_1 = fn_R001570_7013_3(sec_r001570_3_1, sec_r001570_4_1, pub_r001570_5_1);
  int helper_flow_3_2 = fn_R001570_7013_3(sec_r001570_3_2, sec_r001570_4_2, pub_r001570_5_2);
  fn_R001570_7013_3_2(sec_r001570_3_1, sec_r001570_4_1, pub_r001570_5_1, sec_r001570_3_2, sec_r001570_4_2, pub_r001570_5_2);
  int helper_flow_4_1 = fn_R001570_7013_4(sec_r001570_4_1, pub_r001570_5_1, pub_r001570_6_1, pub_r001570_7_1);
  int helper_flow_4_2 = fn_R001570_7013_4(sec_r001570_4_2, pub_r001570_5_2, pub_r001570_6_2, pub_r001570_7_2);
  fn_R001570_7013_4_2(sec_r001570_4_1, pub_r001570_5_1, pub_r001570_6_1, pub_r001570_7_1, sec_r001570_4_2, pub_r001570_5_2, pub_r001570_6_2, pub_r001570_7_2);
  int helper_flow_5_1 = fn_R001570_7013_5(sec_r001570_5_1, pub_r001570_6_1, pub_r001570_7_1, pub_r001570_8_1);
  int helper_flow_5_2 = fn_R001570_7013_5(sec_r001570_5_2, pub_r001570_6_2, pub_r001570_7_2, pub_r001570_8_2);
  fn_R001570_7013_5_2(sec_r001570_5_1, pub_r001570_6_1, pub_r001570_7_1, pub_r001570_8_1, sec_r001570_5_2, pub_r001570_6_2, pub_r001570_7_2, pub_r001570_8_2);
  int helper_flow_6_1 = fn_R001570_7013_6(sec_r001570_6_1, sec_r001570_7_1, pub_r001570_8_1, pub_r001570_9_1);
  int helper_flow_6_2 = fn_R001570_7013_6(sec_r001570_6_2, sec_r001570_7_2, pub_r001570_8_2, pub_r001570_9_2);
  fn_R001570_7013_6_2(sec_r001570_6_1, sec_r001570_7_1, pub_r001570_8_1, pub_r001570_9_1, sec_r001570_6_2, sec_r001570_7_2, pub_r001570_8_2, pub_r001570_9_2);
  int helper_flow_7_1 = fn_R001570_7013_7(sec_r001570_7_1, pub_r001570_8_1, pub_r001570_9_1, pub_r001570_10_1, pub_r001570_11_1);
  int helper_flow_7_2 = fn_R001570_7013_7(sec_r001570_7_2, pub_r001570_8_2, pub_r001570_9_2, pub_r001570_10_2, pub_r001570_11_2);
  fn_R001570_7013_7_2(sec_r001570_7_1, pub_r001570_8_1, pub_r001570_9_1, pub_r001570_10_1, pub_r001570_11_1, sec_r001570_7_2, pub_r001570_8_2, pub_r001570_9_2, pub_r001570_10_2, pub_r001570_11_2);
  int helper_flow_8_1 = fn_R001570_7013_8(sec_r001570_8_1, sec_r001570_9_1, pub_r001570_10_1, pub_r001570_11_1, pub_r001570_12_1);
  int helper_flow_8_2 = fn_R001570_7013_8(sec_r001570_8_2, sec_r001570_9_2, pub_r001570_10_2, pub_r001570_11_2, pub_r001570_12_2);
  fn_R001570_7013_8_2(sec_r001570_8_1, sec_r001570_9_1, pub_r001570_10_1, pub_r001570_11_1, pub_r001570_12_1, sec_r001570_8_2, sec_r001570_9_2, pub_r001570_10_2, pub_r001570_11_2, pub_r001570_12_2);
  int helper_flow_9_1 = fn_R001570_7013_9(sec_r001570_9_1, pub_r001570_10_1);
  int helper_flow_9_2 = fn_R001570_7013_9(sec_r001570_9_2, pub_r001570_10_2);
  fn_R001570_7013_9_2(sec_r001570_9_1, pub_r001570_10_1, sec_r001570_9_2, pub_r001570_10_2);
  int stage_v_0_1 = (((sec_r001570_8_1 ^ 0x2A) * 2) + pub_r001570_2_1) & 127;
  int stage_v_0_2 = (((sec_r001570_8_2 ^ 0x2A) * 2) + pub_r001570_2_2) & 127;
  if (stage_v_0_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_1_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_1_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_2_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_2_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001570_4_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_3_2 = (((sec_r001570_4_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_3_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001570_8_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_4_2 = (((sec_r001570_8_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_4_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((pub_r001570_1_1 * 2) + 36) & 63;
  int stage_v_5_2 = ((pub_r001570_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_6_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_6_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((pub_r001570_10_1 * 2) + 15) & 63;
  int stage_v_7_2 = ((pub_r001570_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_8_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_8_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001570_7_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_9_2 = (((sec_r001570_7_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
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
  int stage_v_10_1 = ((pub_r001570_12_1 * 2) + 38) & 63;
  int stage_v_10_2 = ((pub_r001570_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001570_15_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_11_2 = (((sec_r001570_15_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_11_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001570_14_1 * 2) + 48) & 63;
  int stage_v_12_2 = ((pub_r001570_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_13_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_13_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_14_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_14_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001570_1_1 * 2) + 44) & 63;
  int stage_v_15_2 = ((pub_r001570_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001570_10_1 * 2) + 29) & 63;
  int stage_v_16_2 = ((pub_r001570_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_17_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_17_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001570_7_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_18_2 = (((sec_r001570_7_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_18_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001570_2_1) & 127;
  int stage_v_19_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001570_2_2) & 127;
  if (stage_v_19_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_20_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_20_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001570_13_1 * 2) + 10) & 63;
  int stage_v_21_2 = ((pub_r001570_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_22_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_22_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_23_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_23_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((pub_r001570_9_1 * 2) + 50) & 63;
  int stage_v_24_2 = ((pub_r001570_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((sec_r001570_0_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_25_2 = (((sec_r001570_0_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_25_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001570_3_1 ^ 0x2A) * 2) + pub_r001570_13_1) & 127;
  int stage_v_26_2 = (((sec_r001570_3_2 ^ 0x2A) * 2) + pub_r001570_13_2) & 127;
  if (stage_v_26_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((sec_r001570_11_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_27_2 = (((sec_r001570_11_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_27_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_28_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_28_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_29_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_29_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_30_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_30_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_31_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_31_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_32_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_32_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_33_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_33_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((pub_r001570_8_1 * 2) + 19) & 63;
  int stage_v_34_2 = ((pub_r001570_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001570_6_1 * 2) + 17) & 63;
  int stage_v_35_2 = ((pub_r001570_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_36_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_36_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_37_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_37_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_38_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_38_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_39_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_39_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_40_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_40_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((pub_r001570_4_1 * 2) + 48) & 63;
  int stage_v_41_2 = ((pub_r001570_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_42_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_42_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_43_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_43_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_44_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_44_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_45_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_45_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((pub_r001570_10_1 * 2) + 16) & 63;
  int stage_v_46_2 = ((pub_r001570_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_47_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_47_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_48_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_48_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((sec_r001570_1_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_49_2 = (((sec_r001570_1_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_49_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_50_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_50_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((pub_r001570_6_1 * 2) + 49) & 63;
  int stage_v_51_2 = ((pub_r001570_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_52_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_52_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((sec_r001570_2_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_53_2 = (((sec_r001570_2_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_53_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_54_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_54_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((sec_r001570_14_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_55_2 = (((sec_r001570_14_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_55_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_56_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_56_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((pub_r001570_6_1 * 2) + 28) & 63;
  int stage_v_57_2 = ((pub_r001570_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((sec_r001570_14_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_58_2 = (((sec_r001570_14_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_58_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((pub_r001570_10_1 * 2) + 29) & 63;
  int stage_v_59_2 = ((pub_r001570_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001570_13_1) & 127;
  int stage_v_60_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001570_13_2) & 127;
  if (stage_v_60_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((sec_r001570_4_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_61_2 = (((sec_r001570_4_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_61_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_62_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_62_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((pub_r001570_10_1 * 2) + 22) & 63;
  int stage_v_63_2 = ((pub_r001570_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((sec_r001570_8_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_64_2 = (((sec_r001570_8_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_64_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((pub_r001570_10_1 * 2) + 25) & 63;
  int stage_v_65_2 = ((pub_r001570_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_66_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_66_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((pub_r001570_11_1 * 2) + 20) & 63;
  int stage_v_67_2 = ((pub_r001570_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001570_13_1 * 2) + 46) & 63;
  int stage_v_68_2 = ((pub_r001570_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((sec_r001570_14_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_69_2 = (((sec_r001570_14_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_69_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_70_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_70_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_71_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_71_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_72_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_72_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((sec_r001570_6_1 ^ 0x2A) * 2) + pub_r001570_13_1) & 127;
  int stage_v_73_2 = (((sec_r001570_6_2 ^ 0x2A) * 2) + pub_r001570_13_2) & 127;
  if (stage_v_73_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_74_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_74_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_75_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_75_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_76_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_76_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001570_5_1 * 2) + 18) & 63;
  int stage_v_77_2 = ((pub_r001570_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_78_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
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
  int stage_v_79_1 = ((pub_r001570_13_1 * 2) + 37) & 63;
  int stage_v_79_2 = ((pub_r001570_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_80_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_80_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_81_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_81_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_82_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_82_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_83_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_83_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((pub_r001570_5_1 * 2) + 32) & 63;
  int stage_v_84_2 = ((pub_r001570_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_85_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_85_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001570_1_1 * 2) + 17) & 63;
  int stage_v_86_2 = ((pub_r001570_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_87_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_87_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_88_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_88_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_89_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_89_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_90_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_90_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_91_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_91_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_92_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_92_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((sec_r001570_1_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_93_2 = (((sec_r001570_1_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_93_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_94_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_94_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001570_1_1 * 2) + 16) & 63;
  int stage_v_95_2 = ((pub_r001570_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_96_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_96_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_97_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_97_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((pub_r001570_10_1 * 2) + 46) & 63;
  int stage_v_98_2 = ((pub_r001570_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_99_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_99_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_100_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_100_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_101_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_101_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((sec_r001570_1_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_102_2 = (((sec_r001570_1_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_102_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_103_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_103_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001570_1_1 * 2) + 44) & 63;
  int stage_v_104_2 = ((pub_r001570_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((sec_r001570_16_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_105_2 = (((sec_r001570_16_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_105_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001570_13_1) & 127;
  int stage_v_106_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001570_13_2) & 127;
  if (stage_v_106_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001570_10_1 * 2) + 18) & 63;
  int stage_v_107_2 = ((pub_r001570_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001570_2_1) & 127;
  int stage_v_108_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001570_2_2) & 127;
  if (stage_v_108_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_109_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_109_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_110_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_110_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((pub_r001570_3_1 * 2) + 37) & 63;
  int stage_v_111_2 = ((pub_r001570_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_112_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_112_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_113_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
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
  int stage_v_114_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_114_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_114_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001570_12_1 * 2) + 35) & 63;
  int stage_v_115_2 = ((pub_r001570_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_116_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_116_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((sec_r001570_4_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_117_2 = (((sec_r001570_4_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_117_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((sec_r001570_12_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_118_2 = (((sec_r001570_12_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_118_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_119_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_119_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_120_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_120_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_121_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_121_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001570_2_1 * 2) + 25) & 63;
  int stage_v_122_2 = ((pub_r001570_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001570_4_1 * 2) + 5) & 63;
  int stage_v_123_2 = ((pub_r001570_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001570_2_1) & 127;
  int stage_v_124_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001570_2_2) & 127;
  if (stage_v_124_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_125_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_125_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_126_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_126_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_127_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_127_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_128_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_128_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((sec_r001570_16_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_129_2 = (((sec_r001570_16_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_129_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_130_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_130_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_131_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_131_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_132_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_132_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_133_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_133_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_134_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_134_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((sec_r001570_4_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_135_2 = (((sec_r001570_4_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_135_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_136_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
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
  int stage_v_137_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_137_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_137_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001570_12_1) & 127;
  int stage_v_138_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001570_12_2) & 127;
  if (stage_v_138_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_139_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_139_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001570_9_1) & 127;
  int stage_v_140_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001570_9_2) & 127;
  if (stage_v_140_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001570_9_1 * 2) + 28) & 63;
  int stage_v_141_2 = ((pub_r001570_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001570_13_1 * 2) + 40) & 63;
  int stage_v_142_2 = ((pub_r001570_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((sec_r001570_16_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_143_2 = (((sec_r001570_16_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_143_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_144_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_144_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001570_7_1 * 2) + 34) & 63;
  int stage_v_145_2 = ((pub_r001570_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_146_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_146_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_147_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_147_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_148_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_148_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_149_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_149_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_150_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_150_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001570_2_1 * 2) + 36) & 63;
  int stage_v_151_2 = ((pub_r001570_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001570_2_1 * 2) + 16) & 63;
  int stage_v_152_2 = ((pub_r001570_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001570_1_1 * 2) + 11) & 63;
  int stage_v_153_2 = ((pub_r001570_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_154_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_154_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((pub_r001570_4_1 * 2) + 6) & 63;
  int stage_v_155_2 = ((pub_r001570_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_156_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_156_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((sec_r001570_0_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_157_2 = (((sec_r001570_0_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_157_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001570_13_1) & 127;
  int stage_v_158_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001570_13_2) & 127;
  if (stage_v_158_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_159_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_159_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_160_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_160_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((pub_r001570_10_1 * 2) + 15) & 63;
  int stage_v_161_2 = ((pub_r001570_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_162_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_162_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001570_15_1 * 2) + 46) & 63;
  int stage_v_163_2 = ((pub_r001570_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_164_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_164_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((pub_r001570_11_1 * 2) + 33) & 63;
  int stage_v_165_2 = ((pub_r001570_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_166_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_166_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_167_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_167_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_168_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_168_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_169_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
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
  int stage_v_170_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_170_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_170_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((sec_r001570_11_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_171_2 = (((sec_r001570_11_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_171_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001570_7_1) & 127;
  int stage_v_172_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001570_7_2) & 127;
  if (stage_v_172_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((sec_r001570_2_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_173_2 = (((sec_r001570_2_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_173_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001570_14_1 * 2) + 43) & 63;
  int stage_v_174_2 = ((pub_r001570_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_175_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_175_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_176_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_176_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001570_2_1 * 2) + 45) & 63;
  int stage_v_177_2 = ((pub_r001570_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001570_13_1) & 127;
  int stage_v_178_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001570_13_2) & 127;
  if (stage_v_178_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001570_10_1 * 2) + 19) & 63;
  int stage_v_179_2 = ((pub_r001570_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_180_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_180_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001570_0_1) & 127;
  int stage_v_181_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001570_0_2) & 127;
  if (stage_v_181_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((sec_r001570_8_1 ^ 0x2A) * 2) + pub_r001570_8_1) & 127;
  int stage_v_182_2 = (((sec_r001570_8_2 ^ 0x2A) * 2) + pub_r001570_8_2) & 127;
  if (stage_v_182_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001570_2_1) & 127;
  int stage_v_183_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001570_2_2) & 127;
  if (stage_v_183_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((pub_r001570_12_1 * 2) + 40) & 63;
  int stage_v_184_2 = ((pub_r001570_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001570_8_1 * 2) + 48) & 63;
  int stage_v_185_2 = ((pub_r001570_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001570_6_1 * 2) + 9) & 63;
  int stage_v_186_2 = ((pub_r001570_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_187_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_187_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001570_2_1) & 127;
  int stage_v_188_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001570_2_2) & 127;
  if (stage_v_188_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_189_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_189_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_190_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_190_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001570_7_1 * 2) + 28) & 63;
  int stage_v_191_2 = ((pub_r001570_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001570_5_1) & 127;
  int stage_v_192_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001570_5_2) & 127;
  if (stage_v_192_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_193_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_193_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_193_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_194_2 = (((stage_v_193_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_194_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001570_1_1 * 2) + 35) & 63;
  int stage_v_195_2 = ((pub_r001570_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001570_14_1) & 127;
  int stage_v_196_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001570_14_2) & 127;
  if (stage_v_196_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001570_11_1 * 2) + 29) & 63;
  int stage_v_197_2 = ((pub_r001570_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_198_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_198_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_199_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_199_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((pub_r001570_6_1 * 2) + 6) & 63;
  int stage_v_200_2 = ((pub_r001570_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001570_11_1 * 2) + 8) & 63;
  int stage_v_201_2 = ((pub_r001570_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_202_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_202_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_183_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_203_2 = (((stage_v_183_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_203_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_204_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_204_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_205_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_205_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_206_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_206_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_207_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_207_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_208_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_208_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_203_1 ^ 0x2A) * 2) + pub_r001570_6_1) & 127;
  int stage_v_209_2 = (((stage_v_203_2 ^ 0x2A) * 2) + pub_r001570_6_2) & 127;
  if (stage_v_209_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_210_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_210_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_196_1 ^ 0x2A) * 2) + pub_r001570_11_1) & 127;
  int stage_v_211_2 = (((stage_v_196_2 ^ 0x2A) * 2) + pub_r001570_11_2) & 127;
  if (stage_v_211_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_193_1 ^ 0x2A) * 2) + pub_r001570_15_1) & 127;
  int stage_v_212_2 = (((stage_v_193_2 ^ 0x2A) * 2) + pub_r001570_15_2) & 127;
  if (stage_v_212_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_213_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_213_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((pub_r001570_9_1 * 2) + 37) & 63;
  int stage_v_214_2 = ((pub_r001570_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_143_1 ^ 0x2A) * 2) + pub_r001570_3_1) & 127;
  int stage_v_215_2 = (((stage_v_143_2 ^ 0x2A) * 2) + pub_r001570_3_2) & 127;
  if (stage_v_215_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((pub_r001570_2_1 * 2) + 9) & 63;
  int stage_v_216_2 = ((pub_r001570_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001570_4_1) & 127;
  int stage_v_217_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001570_4_2) & 127;
  if (stage_v_217_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_204_1 ^ 0x2A) * 2) + pub_r001570_10_1) & 127;
  int stage_v_218_2 = (((stage_v_204_2 ^ 0x2A) * 2) + pub_r001570_10_2) & 127;
  if (stage_v_218_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001570_1_1) & 127;
  int stage_v_219_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001570_1_2) & 127;
  if (stage_v_219_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001570_11_1 != sec_r001570_11_2);
  __CPROVER_assume(sec_r001570_15_1 != sec_r001570_15_2);
  __CPROVER_assume(sec_r001570_12_1 != sec_r001570_12_2);
  __CPROVER_assume(pub_r001570_15_1 == pub_r001570_15_2);
  __CPROVER_assume(pub_r001570_14_1 == pub_r001570_14_2);
  __CPROVER_assume(sec_r001570_8_1 != sec_r001570_8_2);
  __CPROVER_assume(pub_r001570_10_1 == pub_r001570_10_2);
  __CPROVER_assume(pub_r001570_1_1 == pub_r001570_1_2);
  __CPROVER_assume(sec_r001570_1_1 != sec_r001570_1_2);
  __CPROVER_assume(pub_r001570_4_1 == pub_r001570_4_2);
  __CPROVER_assume(sec_r001570_2_1 != sec_r001570_2_2);
  __CPROVER_assume(pub_r001570_2_1 == pub_r001570_2_2);
  __CPROVER_assume(sec_r001570_16_1 != sec_r001570_16_2);
  __CPROVER_assume(pub_r001570_9_1 == pub_r001570_9_2);
  __CPROVER_assume(pub_r001570_13_1 == pub_r001570_13_2);
  __CPROVER_assume(pub_r001570_6_1 == pub_r001570_6_2);
  __CPROVER_assume(pub_r001570_3_1 == pub_r001570_3_2);
  __CPROVER_assume(sec_r001570_14_1 != sec_r001570_14_2);
  __CPROVER_assume(sec_r001570_9_1 != sec_r001570_9_2);
  __CPROVER_assume(sec_r001570_5_1 != sec_r001570_5_2);
  __CPROVER_assume(sec_r001570_0_1 != sec_r001570_0_2);
  __CPROVER_assume(pub_r001570_12_1 == pub_r001570_12_2);
  __CPROVER_assume(sec_r001570_13_1 != sec_r001570_13_2);
  __CPROVER_assume(sec_r001570_10_1 != sec_r001570_10_2);
  __CPROVER_assume(pub_r001570_11_1 == pub_r001570_11_2);
  __CPROVER_assume(sec_r001570_7_1 != sec_r001570_7_2);
  __CPROVER_assume(pub_r001570_7_1 == pub_r001570_7_2);
  __CPROVER_assume(sec_r001570_4_1 != sec_r001570_4_2);
  __CPROVER_assume(sec_r001570_3_1 != sec_r001570_3_2);
  __CPROVER_assume(pub_r001570_8_1 == pub_r001570_8_2);
  __CPROVER_assume(sec_r001570_17_1 != sec_r001570_17_2);
  __CPROVER_assume(pub_r001570_0_1 == pub_r001570_0_2);
  __CPROVER_assume(sec_r001570_6_1 != sec_r001570_6_2);
  __CPROVER_assume(pub_r001570_5_1 == pub_r001570_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.coord_z == st_var_3_2.coord_z);
  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
  assert(st_var_3_1.coord_y == st_var_3_2.coord_y);
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
}


