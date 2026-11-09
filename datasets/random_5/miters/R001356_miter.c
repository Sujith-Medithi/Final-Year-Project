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
struct Vector3D_R001356_5613_0
{
  int coord_x;
  short coord_y;
  int norm_sq;
  short pitch;
  int coord_z;
  int heading;
  int buffer[3];
};
struct SensorNode_R001356_5613_1
{
  short threshold;
  int gain;
  unsigned char calib;
  unsigned char offset;
  short reading;
  int status;
  int buffer[3];
};
union ColorPixel_R001356_5613_0
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
void fn_R001356_5613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int factor_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_27_1)
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

  switch (factor_27_2)
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

  int residue_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_97_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_97_1 * 2)) + 5) & 127;
    aux_1 ^= residue_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_97_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_97_2 * 2)) + 5) & 127;
    aux_2 ^= residue_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_27_1 == factor_27_2);
  assert(residue_97_1 == residue_97_2);
}

int fn_R001356_5613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int factor_27 = (aux + st.buffer[1]) & 3;
  switch (factor_27)
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

  int residue_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_97 > 40)
  {
    acc = ((acc + (residue_97 * 2)) + 5) & 127;
    aux ^= residue_97 & 15;
  }
  else
  {
    acc = ((acc - residue_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_72_1 > 19)
  {
    acc_1 = ((acc_1 + (delta_72_1 * 2)) + 5) & 127;
    aux_1 ^= delta_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_72_2 > 19)
  {
    acc_2 = ((acc_2 + (delta_72_2 * 2)) + 5) & 127;
    aux_2 ^= delta_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_98_1 = local_arr_1[aux_1 % 3];
  int tracker_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_72_1 == delta_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_98_1 == tracker_98_2);
}

int fn_R001356_5613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_72 > 19)
  {
    acc = ((acc + (delta_72 * 2)) + 5) & 127;
    aux ^= delta_72 & 15;
  }
  else
  {
    acc = ((acc - delta_72) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tracker_98 = local_arr[aux % 3];
  acc = (acc + (tracker_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int threshold_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_70_1)
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

  switch (threshold_70_2)
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

  int threshold_83_1 = 0;
  int threshold_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_83_1 = ((threshold_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_83_2 = ((threshold_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_83_1) & 127;
    acc_2 = (acc_2 + threshold_83_2) & 127;
  }

  int pivot_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_76_1 > 20)
  {
    acc_1 = ((acc_1 + (pivot_76_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_76_2 > 20)
  {
    acc_2 = ((acc_2 + (pivot_76_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_70_1 == threshold_70_2);
  assert(threshold_83_1 == threshold_83_2);
  assert(pivot_76_1 == pivot_76_2);
}

int fn_R001356_5613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int threshold_70 = (aux + st.buffer[1]) & 3;
  switch (threshold_70)
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

  int threshold_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_83 = ((threshold_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_83) & 127;
  }

  int pivot_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_76 > 20)
  {
    acc = ((acc + (pivot_76 * 2)) + 5) & 127;
    aux ^= pivot_76 & 15;
  }
  else
  {
    acc = ((acc - pivot_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int anchor_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_30_1)
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

  switch (anchor_30_2)
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

  int factor_11_1 = 0;
  int factor_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_11_1 = ((factor_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_11_2 = ((factor_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_11_1) & 127;
    acc_2 = (acc_2 + factor_11_2) & 127;
  }

  int weight_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_33_1 > 36)
  {
    acc_1 = ((acc_1 + (weight_33_1 * 2)) + 5) & 127;
    aux_1 ^= weight_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_33_2 > 36)
  {
    acc_2 = ((acc_2 + (weight_33_2 * 2)) + 5) & 127;
    aux_2 ^= weight_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_30_1 == anchor_30_2);
  assert(factor_11_1 == factor_11_2);
  assert(weight_33_1 == weight_33_2);
}

int fn_R001356_5613_3(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int anchor_30 = (aux + st.buffer[1]) & 3;
  switch (anchor_30)
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

  int factor_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_11 = ((factor_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_11) & 127;
  }

  int weight_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_33 > 36)
  {
    acc = ((acc + (weight_33 * 2)) + 5) & 127;
    aux ^= weight_33 & 15;
  }
  else
  {
    acc = ((acc - weight_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int delta_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_94_1)
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

  switch (delta_94_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_42_1 = local_arr_1[aux_1 % 3];
  int quotient_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_42_2 * 2)) & 127;
  int sample_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_68_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_68_1 * 2)) + 5) & 127;
    aux_1 ^= sample_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_68_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_68_2 * 2)) + 5) & 127;
    aux_2 ^= sample_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_94_1 == delta_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_42_1 == quotient_42_2);
  assert(sample_68_1 == sample_68_2);
}

int fn_R001356_5613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int delta_94 = (aux + st.buffer[1]) & 3;
  switch (delta_94)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_42 = local_arr[aux % 3];
  acc = (acc + (quotient_42 * 2)) & 127;
  int sample_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_68 > 23)
  {
    acc = ((acc + (sample_68 * 2)) + 5) & 127;
    aux ^= sample_68 & 15;
  }
  else
  {
    acc = ((acc - sample_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_64_1 > 41)
  {
    acc_1 = ((acc_1 + (bound_64_1 * 2)) + 5) & 127;
    aux_1 ^= bound_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_64_2 > 41)
  {
    acc_2 = ((acc_2 + (bound_64_2 * 2)) + 5) & 127;
    aux_2 ^= bound_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_26_1 = local_arr_1[aux_1 % 3];
  int accumulator_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_26_2 * 2)) & 127;
  int scale_86_1 = 0;
  int scale_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_86_1 = ((scale_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_86_2 = ((scale_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_86_1) & 127;
    acc_2 = (acc_2 + scale_86_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_64_1 == bound_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  assert(scale_86_1 == scale_86_2);
}

int fn_R001356_5613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_64 > 41)
  {
    acc = ((acc + (bound_64 * 2)) + 5) & 127;
    aux ^= bound_64 & 15;
  }
  else
  {
    acc = ((acc - bound_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_26 = local_arr[aux % 3];
  acc = (acc + (accumulator_26 * 2)) & 127;
  int scale_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_86 = ((scale_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_86) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int cursor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_87_1) & 63;
  aux_2 = (aux_2 + cursor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_98_1 = local_arr_1[aux_1 % 3];
  int segment_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_98_2 * 2)) & 127;
  int window_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_55_1)
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

  switch (window_55_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_87_1 == cursor_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_98_1 == segment_98_2);
  assert(window_55_1 == window_55_2);
}

int fn_R001356_5613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int cursor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_98 = local_arr[aux % 3];
  acc = (acc + (segment_98 * 2)) & 127;
  int window_55 = (aux + st.buffer[1]) & 3;
  switch (window_55)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_33_1)
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

  switch (residue_33_2)
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

  int anchor_33_1 = 0;
  int anchor_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_33_1 = ((anchor_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_33_2 = ((anchor_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_33_1) & 127;
    acc_2 = (acc_2 + anchor_33_2) & 127;
  }

  int cursor_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_11_1 > 32)
  {
    acc_1 = ((acc_1 + (cursor_11_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_11_2 > 32)
  {
    acc_2 = ((acc_2 + (cursor_11_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_33_1 == residue_33_2);
  assert(anchor_33_1 == anchor_33_2);
  assert(cursor_11_1 == cursor_11_2);
}

int fn_R001356_5613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_33 = (aux + st.buffer[1]) & 3;
  switch (residue_33)
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

  int anchor_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_33 = ((anchor_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_33) & 127;
  }

  int cursor_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_11 > 32)
  {
    acc = ((acc + (cursor_11 * 2)) + 5) & 127;
    aux ^= cursor_11 & 15;
  }
  else
  {
    acc = ((acc - cursor_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_11_1)
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

  switch (phase_11_2)
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

  int accumulator_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_46_1 > 28)
  {
    acc_1 = ((acc_1 + (accumulator_46_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_46_2 > 28)
  {
    acc_2 = ((acc_2 + (accumulator_46_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_11_1 == phase_11_2);
  assert(accumulator_46_1 == accumulator_46_2);
}

int fn_R001356_5613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_11 = (aux + st.buffer[1]) & 3;
  switch (phase_11)
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

  int accumulator_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_46 > 28)
  {
    acc = ((acc + (accumulator_46 * 2)) + 5) & 127;
    aux ^= accumulator_46 & 15;
  }
  else
  {
    acc = ((acc - accumulator_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_50_1 > 48)
  {
    acc_1 = ((acc_1 + (tracker_50_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_50_2 > 48)
  {
    acc_2 = ((acc_2 + (tracker_50_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_90_1 = local_arr_1[aux_1 % 3];
  int metric_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_90_2 * 2)) & 127;
  int pivot_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_10_1)
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

  switch (pivot_10_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_50_1 == tracker_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_90_1 == metric_90_2);
  assert(pivot_10_1 == pivot_10_2);
}

int fn_R001356_5613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_50 > 48)
  {
    acc = ((acc + (tracker_50 * 2)) + 5) & 127;
    aux ^= tracker_50 & 15;
  }
  else
  {
    acc = ((acc - tracker_50) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_90 = local_arr[aux % 3];
  acc = (acc + (metric_90 * 2)) & 127;
  int pivot_10 = (aux + st.buffer[1]) & 3;
  switch (pivot_10)
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

void fn_R001356_5613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_33_1 = local_arr_1[aux_1 % 3];
  int quotient_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_33_2 * 2)) & 127;
  int window_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_62_1) & 63;
  aux_2 = (aux_2 + window_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_33_1 == quotient_33_2);
  assert(window_62_1 == window_62_2);
}

int fn_R001356_5613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int quotient_33 = local_arr[aux % 3];
  acc = (acc + (quotient_33 * 2)) & 127;
  int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_62) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_78_1 > 34)
  {
    acc_1 = ((acc_1 + (parity_78_1 * 2)) + 5) & 127;
    aux_1 ^= parity_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_78_2 > 34)
  {
    acc_2 = ((acc_2 + (parity_78_2 * 2)) + 5) & 127;
    aux_2 ^= parity_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_13_1 = local_arr_1[aux_1 % 3];
  int cursor_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_13_1 == cursor_13_2);
}

int fn_R001356_5613_11(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_78 > 34)
  {
    acc = ((acc + (parity_78 * 2)) + 5) & 127;
    aux ^= parity_78 & 15;
  }
  else
  {
    acc = ((acc - parity_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_13 = local_arr[aux % 3];
  acc = (acc + (cursor_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int scale_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_90_1)
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

  switch (scale_90_2)
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

  int anchor_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_29_1 > 15)
  {
    acc_1 = ((acc_1 + (anchor_29_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_29_2 > 15)
  {
    acc_2 = ((acc_2 + (anchor_29_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_29_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_58_1) & 63;
  aux_2 = (aux_2 + margin_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_90_1 == scale_90_2);
  assert(anchor_29_1 == anchor_29_2);
  assert(margin_58_1 == margin_58_2);
}

int fn_R001356_5613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int scale_90 = (aux + st.buffer[1]) & 3;
  switch (scale_90)
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

  int anchor_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_29 > 15)
  {
    acc = ((acc + (anchor_29 * 2)) + 5) & 127;
    aux ^= anchor_29 & 15;
  }
  else
  {
    acc = ((acc - anchor_29) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001356_5613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tracker_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_61_1)
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

  switch (tracker_61_2)
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

  int offset_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_84_1 > 28)
  {
    acc_1 = ((acc_1 + (offset_84_1 * 2)) + 5) & 127;
    aux_1 ^= offset_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_84_2 > 28)
  {
    acc_2 = ((acc_2 + (offset_84_2 * 2)) + 5) & 127;
    aux_2 ^= offset_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_51_1 = 0;
  int residue_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_51_1 = ((residue_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_51_2 = ((residue_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_51_1) & 127;
    acc_2 = (acc_2 + residue_51_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_61_1 == tracker_61_2);
  assert(offset_84_1 == offset_84_2);
  assert(residue_51_1 == residue_51_2);
}

int fn_R001356_5613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tracker_61 = (aux + st.buffer[1]) & 3;
  switch (tracker_61)
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

  int offset_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_84 > 28)
  {
    acc = ((acc + (offset_84 * 2)) + 5) & 127;
    aux ^= offset_84 & 15;
  }
  else
  {
    acc = ((acc - offset_84) + 11) & 127;
    aux += 3;
  }
  int residue_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_51 = ((residue_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_51) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001356_5613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tally_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_99_1 > 32)
  {
    acc_1 = ((acc_1 + (tally_99_1 * 2)) + 5) & 127;
    aux_1 ^= tally_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_99_2 > 32)
  {
    acc_2 = ((acc_2 + (tally_99_2 * 2)) + 5) & 127;
    aux_2 ^= tally_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_57_1 = local_arr_1[aux_1 % 3];
  int metric_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_57_2 * 2)) & 127;
  int margin_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_72_1) & 63;
  aux_2 = (aux_2 + margin_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_99_1 == tally_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_57_1 == metric_57_2);
  assert(margin_72_1 == margin_72_2);
}

int fn_R001356_5613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tally_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_99 > 32)
  {
    acc = ((acc + (tally_99 * 2)) + 5) & 127;
    aux ^= tally_99 & 15;
  }
  else
  {
    acc = ((acc - tally_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_57 = local_arr[aux % 3];
  acc = (acc + (metric_57 * 2)) & 127;
  int margin_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001356_5613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_80_1 = local_arr_1[aux_1 % 3];
  int accumulator_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_80_2 * 2)) & 127;
  int delta_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_69_1 > 49)
  {
    acc_1 = ((acc_1 + (delta_69_1 * 2)) + 5) & 127;
    aux_1 ^= delta_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_69_2 > 49)
  {
    acc_2 = ((acc_2 + (delta_69_2 * 2)) + 5) & 127;
    aux_2 ^= delta_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_43_1) & 63;
  aux_2 = (aux_2 + pivot_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_80_1 == accumulator_80_2);
  assert(delta_69_1 == delta_69_2);
  assert(pivot_43_1 == pivot_43_2);
}

int fn_R001356_5613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int accumulator_80 = local_arr[aux % 3];
  acc = (acc + (accumulator_80 * 2)) & 127;
  int delta_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_69 > 49)
  {
    acc = ((acc + (delta_69 * 2)) + 5) & 127;
    aux ^= delta_69 & 15;
  }
  else
  {
    acc = ((acc - delta_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001356_5613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_38_1 > 15)
  {
    acc_1 = ((acc_1 + (margin_38_1 * 2)) + 5) & 127;
    aux_1 ^= margin_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_38_2 > 15)
  {
    acc_2 = ((acc_2 + (margin_38_2 * 2)) + 5) & 127;
    aux_2 ^= margin_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_38_1 == margin_38_2);
}

int fn_R001356_5613_16(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_38 > 15)
  {
    acc = ((acc + (margin_38 * 2)) + 5) & 127;
    aux ^= margin_38 & 15;
  }
  else
  {
    acc = ((acc - margin_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001356_5613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int margin_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_91_1) & 63;
  aux_2 = (aux_2 + margin_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_14_1)
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

  switch (anchor_14_2)
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
  int scale_19_1 = local_arr_1[aux_1 % 3];
  int scale_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(anchor_14_1 == anchor_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_19_1 == scale_19_2);
}

int fn_R001356_5613_17(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_91) & 63;
  acc ^= aux;
  int anchor_14 = (aux + st.buffer[1]) & 3;
  switch (anchor_14)
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
  int scale_19 = local_arr[aux % 3];
  acc = (acc + (scale_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
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
  int factor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_70_1) & 63;
  aux_2 = (aux_2 + factor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_90_1 = local_arr_1[aux_1 % 3];
  int quotient_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_90_2 * 2)) & 127;
  int index_reg_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_67_1)
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

  switch (index_reg_67_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_70_1 == factor_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_90_1 == quotient_90_2);
  assert(index_reg_67_1 == index_reg_67_2);
}

int fn_R001356_5613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_70) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_90 = local_arr[aux % 3];
  acc = (acc + (quotient_90 * 2)) & 127;
  int index_reg_67 = (aux + st.buffer[1]) & 3;
  switch (index_reg_67)
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

void fn_R001356_5613_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st_1 = {0};
  struct Vector3D_R001356_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int window_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_26_1 > 45)
  {
    acc_1 = ((acc_1 + (window_26_1 * 2)) + 5) & 127;
    aux_1 ^= window_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_26_2 > 45)
  {
    acc_2 = ((acc_2 + (window_26_2 * 2)) + 5) & 127;
    aux_2 ^= window_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_22_1 = local_arr_1[aux_1 % 3];
  int sample_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_26_1 == window_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_22_1 == sample_22_2);
}

int fn_R001356_5613_19(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001356_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int window_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_26 > 45)
  {
    acc = ((acc + (window_26 * 2)) + 5) & 127;
    aux ^= window_26 & 15;
  }
  else
  {
    acc = ((acc - window_26) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_22 = local_arr[aux % 3];
  acc = (acc + (sample_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001356_5613_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st_1 = {0};
  struct SensorNode_R001356_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_60_1)
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

  switch (metric_60_2)
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
  int offset_45_1 = local_arr_1[aux_1 % 3];
  int offset_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_60_1 == metric_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_45_1 == offset_45_2);
}

int fn_R001356_5613_20(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001356_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_60 = (aux + st.buffer[1]) & 3;
  switch (metric_60)
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
  int offset_45 = local_arr[aux % 3];
  acc = (acc + (offset_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001356_0_1;
  int sec_r001356_0_2;
  int sec_r001356_1_1;
  int sec_r001356_1_2;
  int sec_r001356_2_1;
  int sec_r001356_2_2;
  int sec_r001356_3_1;
  int sec_r001356_3_2;
  int sec_r001356_4_1;
  int sec_r001356_4_2;
  int sec_r001356_5_1;
  int sec_r001356_5_2;
  int sec_r001356_6_1;
  int sec_r001356_6_2;
  int sec_r001356_7_1;
  int sec_r001356_7_2;
  int sec_r001356_8_1;
  int sec_r001356_8_2;
  int sec_r001356_9_1;
  int sec_r001356_9_2;
  int sec_r001356_10_1;
  int sec_r001356_10_2;
  int sec_r001356_11_1;
  int sec_r001356_11_2;
  int sec_r001356_12_1;
  int sec_r001356_12_2;
  int sec_r001356_13_1;
  int sec_r001356_13_2;
  int sec_r001356_14_1;
  int sec_r001356_14_2;
  int sec_r001356_15_1;
  int sec_r001356_15_2;
  int sec_r001356_16_1;
  int sec_r001356_16_2;
  int sec_r001356_17_1;
  int sec_r001356_17_2;
  int sec_r001356_18_1;
  int sec_r001356_18_2;
  int sec_r001356_19_1;
  int sec_r001356_19_2;
  int sec_r001356_20_1;
  int sec_r001356_20_2;
  int pub_r001356_0_1;
  int pub_r001356_0_2;
  int pub_r001356_1_1;
  int pub_r001356_1_2;
  int pub_r001356_2_1;
  int pub_r001356_2_2;
  int pub_r001356_3_1;
  int pub_r001356_3_2;
  int pub_r001356_4_1;
  int pub_r001356_4_2;
  int pub_r001356_5_1;
  int pub_r001356_5_2;
  int pub_r001356_6_1;
  int pub_r001356_6_2;
  int pub_r001356_7_1;
  int pub_r001356_7_2;
  int pub_r001356_8_1;
  int pub_r001356_8_2;
  int pub_r001356_9_1;
  int pub_r001356_9_2;
  int pub_r001356_10_1;
  int pub_r001356_10_2;
  int pub_r001356_11_1;
  int pub_r001356_11_2;
  int pub_r001356_12_1;
  int pub_r001356_12_2;
  int pub_r001356_13_1;
  int pub_r001356_13_2;
  int pub_r001356_14_1;
  int pub_r001356_14_2;
  int pub_r001356_15_1;
  int pub_r001356_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001356_0_1 >= (-100)) && (pub_r001356_0_1 <= 100));
  __CPROVER_assume((pub_r001356_0_2 >= (-100)) && (pub_r001356_0_2 <= 100));
  __CPROVER_assume((pub_r001356_1_1 >= (-100)) && (pub_r001356_1_1 <= 100));
  __CPROVER_assume((pub_r001356_1_2 >= (-100)) && (pub_r001356_1_2 <= 100));
  __CPROVER_assume((pub_r001356_2_1 >= (-100)) && (pub_r001356_2_1 <= 100));
  __CPROVER_assume((pub_r001356_2_2 >= (-100)) && (pub_r001356_2_2 <= 100));
  __CPROVER_assume((pub_r001356_3_1 >= (-100)) && (pub_r001356_3_1 <= 100));
  __CPROVER_assume((pub_r001356_3_2 >= (-100)) && (pub_r001356_3_2 <= 100));
  __CPROVER_assume((pub_r001356_4_1 >= (-100)) && (pub_r001356_4_1 <= 100));
  __CPROVER_assume((pub_r001356_4_2 >= (-100)) && (pub_r001356_4_2 <= 100));
  __CPROVER_assume((pub_r001356_5_1 >= (-100)) && (pub_r001356_5_1 <= 100));
  __CPROVER_assume((pub_r001356_5_2 >= (-100)) && (pub_r001356_5_2 <= 100));
  __CPROVER_assume((pub_r001356_6_1 >= (-100)) && (pub_r001356_6_1 <= 100));
  __CPROVER_assume((pub_r001356_6_2 >= (-100)) && (pub_r001356_6_2 <= 100));
  __CPROVER_assume((pub_r001356_7_1 >= (-100)) && (pub_r001356_7_1 <= 100));
  __CPROVER_assume((pub_r001356_7_2 >= (-100)) && (pub_r001356_7_2 <= 100));
  __CPROVER_assume((pub_r001356_8_1 >= (-100)) && (pub_r001356_8_1 <= 100));
  __CPROVER_assume((pub_r001356_8_2 >= (-100)) && (pub_r001356_8_2 <= 100));
  __CPROVER_assume((pub_r001356_9_1 >= (-100)) && (pub_r001356_9_1 <= 100));
  __CPROVER_assume((pub_r001356_9_2 >= (-100)) && (pub_r001356_9_2 <= 100));
  __CPROVER_assume((pub_r001356_10_1 >= (-100)) && (pub_r001356_10_1 <= 100));
  __CPROVER_assume((pub_r001356_10_2 >= (-100)) && (pub_r001356_10_2 <= 100));
  __CPROVER_assume((pub_r001356_11_1 >= (-100)) && (pub_r001356_11_1 <= 100));
  __CPROVER_assume((pub_r001356_11_2 >= (-100)) && (pub_r001356_11_2 <= 100));
  __CPROVER_assume((pub_r001356_12_1 >= (-100)) && (pub_r001356_12_1 <= 100));
  __CPROVER_assume((pub_r001356_12_2 >= (-100)) && (pub_r001356_12_2 <= 100));
  __CPROVER_assume((pub_r001356_13_1 >= (-100)) && (pub_r001356_13_1 <= 100));
  __CPROVER_assume((pub_r001356_13_2 >= (-100)) && (pub_r001356_13_2 <= 100));
  __CPROVER_assume((pub_r001356_14_1 >= (-100)) && (pub_r001356_14_1 <= 100));
  __CPROVER_assume((pub_r001356_14_2 >= (-100)) && (pub_r001356_14_2 <= 100));
  __CPROVER_assume((pub_r001356_15_1 >= (-100)) && (pub_r001356_15_1 <= 100));
  __CPROVER_assume((pub_r001356_15_2 >= (-100)) && (pub_r001356_15_2 <= 100));
  __CPROVER_assume((sec_r001356_0_1 >= 0) && (sec_r001356_0_1 <= 255));
  __CPROVER_assume((sec_r001356_0_2 >= 0) && (sec_r001356_0_2 <= 255));
  __CPROVER_assume((sec_r001356_1_1 >= 0) && (sec_r001356_1_1 <= 255));
  __CPROVER_assume((sec_r001356_1_2 >= 0) && (sec_r001356_1_2 <= 255));
  __CPROVER_assume((sec_r001356_2_1 >= 0) && (sec_r001356_2_1 <= 255));
  __CPROVER_assume((sec_r001356_2_2 >= 0) && (sec_r001356_2_2 <= 255));
  __CPROVER_assume((sec_r001356_3_1 >= 0) && (sec_r001356_3_1 <= 255));
  __CPROVER_assume((sec_r001356_3_2 >= 0) && (sec_r001356_3_2 <= 255));
  __CPROVER_assume((sec_r001356_4_1 >= 0) && (sec_r001356_4_1 <= 255));
  __CPROVER_assume((sec_r001356_4_2 >= 0) && (sec_r001356_4_2 <= 255));
  __CPROVER_assume((sec_r001356_5_1 >= 0) && (sec_r001356_5_1 <= 255));
  __CPROVER_assume((sec_r001356_5_2 >= 0) && (sec_r001356_5_2 <= 255));
  __CPROVER_assume((sec_r001356_6_1 >= 0) && (sec_r001356_6_1 <= 255));
  __CPROVER_assume((sec_r001356_6_2 >= 0) && (sec_r001356_6_2 <= 255));
  __CPROVER_assume((sec_r001356_7_1 >= 0) && (sec_r001356_7_1 <= 255));
  __CPROVER_assume((sec_r001356_7_2 >= 0) && (sec_r001356_7_2 <= 255));
  __CPROVER_assume((sec_r001356_8_1 >= 0) && (sec_r001356_8_1 <= 255));
  __CPROVER_assume((sec_r001356_8_2 >= 0) && (sec_r001356_8_2 <= 255));
  __CPROVER_assume((sec_r001356_9_1 >= 0) && (sec_r001356_9_1 <= 255));
  __CPROVER_assume((sec_r001356_9_2 >= 0) && (sec_r001356_9_2 <= 255));
  __CPROVER_assume((sec_r001356_10_1 >= 0) && (sec_r001356_10_1 <= 255));
  __CPROVER_assume((sec_r001356_10_2 >= 0) && (sec_r001356_10_2 <= 255));
  __CPROVER_assume((sec_r001356_11_1 >= 0) && (sec_r001356_11_1 <= 255));
  __CPROVER_assume((sec_r001356_11_2 >= 0) && (sec_r001356_11_2 <= 255));
  __CPROVER_assume((sec_r001356_12_1 >= 0) && (sec_r001356_12_1 <= 255));
  __CPROVER_assume((sec_r001356_12_2 >= 0) && (sec_r001356_12_2 <= 255));
  __CPROVER_assume((sec_r001356_13_1 >= 0) && (sec_r001356_13_1 <= 255));
  __CPROVER_assume((sec_r001356_13_2 >= 0) && (sec_r001356_13_2 <= 255));
  __CPROVER_assume((sec_r001356_14_1 >= 0) && (sec_r001356_14_1 <= 255));
  __CPROVER_assume((sec_r001356_14_2 >= 0) && (sec_r001356_14_2 <= 255));
  __CPROVER_assume((sec_r001356_15_1 >= 0) && (sec_r001356_15_1 <= 255));
  __CPROVER_assume((sec_r001356_15_2 >= 0) && (sec_r001356_15_2 <= 255));
  __CPROVER_assume((sec_r001356_16_1 >= 0) && (sec_r001356_16_1 <= 255));
  __CPROVER_assume((sec_r001356_16_2 >= 0) && (sec_r001356_16_2 <= 255));
  __CPROVER_assume((sec_r001356_17_1 >= 0) && (sec_r001356_17_1 <= 255));
  __CPROVER_assume((sec_r001356_17_2 >= 0) && (sec_r001356_17_2 <= 255));
  __CPROVER_assume((sec_r001356_18_1 >= 0) && (sec_r001356_18_1 <= 255));
  __CPROVER_assume((sec_r001356_18_2 >= 0) && (sec_r001356_18_2 <= 255));
  __CPROVER_assume((sec_r001356_19_1 >= 0) && (sec_r001356_19_1 <= 255));
  __CPROVER_assume((sec_r001356_19_2 >= 0) && (sec_r001356_19_2 <= 255));
  __CPROVER_assume((sec_r001356_20_1 >= 0) && (sec_r001356_20_1 <= 255));
  __CPROVER_assume((sec_r001356_20_2 >= 0) && (sec_r001356_20_2 <= 255));
  struct Vector3D_R001356_5613_0 st_var_0_1 = {0};
  struct Vector3D_R001356_5613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001356_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001356_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001356_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001356_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001356_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001356_0_2 + 7) & 15;
  struct SensorNode_R001356_5613_1 st_var_1_1 = {0};
  struct SensorNode_R001356_5613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001356_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001356_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001356_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001356_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001356_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001356_0_2 + 9) & 15;
  union ColorPixel_R001356_5613_0 u_var_1;
  union ColorPixel_R001356_5613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001356_5613_0(sec_r001356_0_1, pub_r001356_1_1, pub_r001356_2_1, pub_r001356_3_1, pub_r001356_4_1);
  int helper_flow_0_2 = fn_R001356_5613_0(sec_r001356_0_2, pub_r001356_1_2, pub_r001356_2_2, pub_r001356_3_2, pub_r001356_4_2);
  fn_R001356_5613_0_2(sec_r001356_0_1, pub_r001356_1_1, pub_r001356_2_1, pub_r001356_3_1, pub_r001356_4_1, sec_r001356_0_2, pub_r001356_1_2, pub_r001356_2_2, pub_r001356_3_2, pub_r001356_4_2);
  int helper_flow_1_1 = fn_R001356_5613_1(sec_r001356_1_1, pub_r001356_2_1, pub_r001356_3_1, pub_r001356_4_1);
  int helper_flow_1_2 = fn_R001356_5613_1(sec_r001356_1_2, pub_r001356_2_2, pub_r001356_3_2, pub_r001356_4_2);
  fn_R001356_5613_1_2(sec_r001356_1_1, pub_r001356_2_1, pub_r001356_3_1, pub_r001356_4_1, sec_r001356_1_2, pub_r001356_2_2, pub_r001356_3_2, pub_r001356_4_2);
  int helper_flow_2_1 = fn_R001356_5613_2(sec_r001356_2_1, sec_r001356_3_1, pub_r001356_4_1, pub_r001356_5_1, pub_r001356_6_1);
  int helper_flow_2_2 = fn_R001356_5613_2(sec_r001356_2_2, sec_r001356_3_2, pub_r001356_4_2, pub_r001356_5_2, pub_r001356_6_2);
  fn_R001356_5613_2_2(sec_r001356_2_1, sec_r001356_3_1, pub_r001356_4_1, pub_r001356_5_1, pub_r001356_6_1, sec_r001356_2_2, sec_r001356_3_2, pub_r001356_4_2, pub_r001356_5_2, pub_r001356_6_2);
  int helper_flow_3_1 = fn_R001356_5613_3(sec_r001356_3_1, sec_r001356_4_1);
  int helper_flow_3_2 = fn_R001356_5613_3(sec_r001356_3_2, sec_r001356_4_2);
  fn_R001356_5613_3_2(sec_r001356_3_1, sec_r001356_4_1, sec_r001356_3_2, sec_r001356_4_2);
  int helper_flow_4_1 = fn_R001356_5613_4(sec_r001356_4_1, pub_r001356_5_1, pub_r001356_6_1);
  int helper_flow_4_2 = fn_R001356_5613_4(sec_r001356_4_2, pub_r001356_5_2, pub_r001356_6_2);
  fn_R001356_5613_4_2(sec_r001356_4_1, pub_r001356_5_1, pub_r001356_6_1, sec_r001356_4_2, pub_r001356_5_2, pub_r001356_6_2);
  int helper_flow_5_1 = fn_R001356_5613_5(sec_r001356_5_1, pub_r001356_6_1, pub_r001356_7_1, pub_r001356_8_1);
  int helper_flow_5_2 = fn_R001356_5613_5(sec_r001356_5_2, pub_r001356_6_2, pub_r001356_7_2, pub_r001356_8_2);
  fn_R001356_5613_5_2(sec_r001356_5_1, pub_r001356_6_1, pub_r001356_7_1, pub_r001356_8_1, sec_r001356_5_2, pub_r001356_6_2, pub_r001356_7_2, pub_r001356_8_2);
  int helper_flow_6_1 = fn_R001356_5613_6(sec_r001356_6_1, sec_r001356_7_1, pub_r001356_8_1);
  int helper_flow_6_2 = fn_R001356_5613_6(sec_r001356_6_2, sec_r001356_7_2, pub_r001356_8_2);
  fn_R001356_5613_6_2(sec_r001356_6_1, sec_r001356_7_1, pub_r001356_8_1, sec_r001356_6_2, sec_r001356_7_2, pub_r001356_8_2);
  int helper_flow_7_1 = fn_R001356_5613_7(sec_r001356_7_1, sec_r001356_8_1, pub_r001356_9_1);
  int helper_flow_7_2 = fn_R001356_5613_7(sec_r001356_7_2, sec_r001356_8_2, pub_r001356_9_2);
  fn_R001356_5613_7_2(sec_r001356_7_1, sec_r001356_8_1, pub_r001356_9_1, sec_r001356_7_2, sec_r001356_8_2, pub_r001356_9_2);
  int helper_flow_8_1 = fn_R001356_5613_8(sec_r001356_8_1, pub_r001356_9_1, pub_r001356_10_1, pub_r001356_11_1, pub_r001356_12_1);
  int helper_flow_8_2 = fn_R001356_5613_8(sec_r001356_8_2, pub_r001356_9_2, pub_r001356_10_2, pub_r001356_11_2, pub_r001356_12_2);
  fn_R001356_5613_8_2(sec_r001356_8_1, pub_r001356_9_1, pub_r001356_10_1, pub_r001356_11_1, pub_r001356_12_1, sec_r001356_8_2, pub_r001356_9_2, pub_r001356_10_2, pub_r001356_11_2, pub_r001356_12_2);
  int helper_flow_9_1 = fn_R001356_5613_9(sec_r001356_9_1, pub_r001356_10_1, pub_r001356_11_1);
  int helper_flow_9_2 = fn_R001356_5613_9(sec_r001356_9_2, pub_r001356_10_2, pub_r001356_11_2);
  fn_R001356_5613_9_2(sec_r001356_9_1, pub_r001356_10_1, pub_r001356_11_1, sec_r001356_9_2, pub_r001356_10_2, pub_r001356_11_2);
  int helper_flow_10_1 = fn_R001356_5613_10(sec_r001356_10_1, sec_r001356_11_1, pub_r001356_12_1, pub_r001356_13_1, pub_r001356_14_1);
  int helper_flow_10_2 = fn_R001356_5613_10(sec_r001356_10_2, sec_r001356_11_2, pub_r001356_12_2, pub_r001356_13_2, pub_r001356_14_2);
  fn_R001356_5613_10_2(sec_r001356_10_1, sec_r001356_11_1, pub_r001356_12_1, pub_r001356_13_1, pub_r001356_14_1, sec_r001356_10_2, sec_r001356_11_2, pub_r001356_12_2, pub_r001356_13_2, pub_r001356_14_2);
  int stage_v_0_1 = ((helper_flow_10_1 + (pub_r001356_13_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_10_2 + (pub_r001356_13_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001356_13_1 * 2) + 44) & 63;
  int stage_v_1_2 = ((pub_r001356_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001356_10_1 + (pub_r001356_3_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001356_10_2 + (pub_r001356_3_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001356_7_1 + (pub_r001356_12_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001356_7_2 + (pub_r001356_12_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((helper_flow_3_1 + (pub_r001356_10_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_3_2 + (pub_r001356_10_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001356_4_1 + (pub_r001356_2_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001356_4_2 + (pub_r001356_2_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001356_19_1 + (pub_r001356_5_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001356_19_2 + (pub_r001356_5_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001356_8_1 * 2) + 37) & 63;
  int stage_v_7_2 = ((pub_r001356_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((stage_v_5_1 + (pub_r001356_6_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((stage_v_5_2 + (pub_r001356_6_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001356_2_1 * 2) + 50) & 63;
  int stage_v_9_2 = ((pub_r001356_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001356_18_1 + (pub_r001356_3_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001356_18_2 + (pub_r001356_3_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((stage_v_2_1 + (pub_r001356_3_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((stage_v_2_2 + (pub_r001356_3_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001356_4_1 + (pub_r001356_12_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001356_4_2 + (pub_r001356_12_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001356_5_1 + (pub_r001356_2_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001356_5_2 + (pub_r001356_2_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_10_1 + (pub_r001356_9_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_10_2 + (pub_r001356_9_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_10_1 + (pub_r001356_15_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_10_2 + (pub_r001356_15_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_10_1 + (pub_r001356_2_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_10_2 + (pub_r001356_2_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001356_16_1 + (pub_r001356_5_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001356_16_2 + (pub_r001356_5_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001356_10_1 + (pub_r001356_12_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001356_10_2 + (pub_r001356_12_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001356_6_1 + (pub_r001356_9_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001356_6_2 + (pub_r001356_9_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001356_12_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001356_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((stage_v_17_1 + (pub_r001356_7_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_17_2 + (pub_r001356_7_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001356_6_1 * 2) + 49) & 63;
  int stage_v_22_2 = ((pub_r001356_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((sec_r001356_5_1 + (pub_r001356_8_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001356_5_2 + (pub_r001356_8_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((pub_r001356_10_1 * 2) + 33) & 63;
  int stage_v_24_2 = ((pub_r001356_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((stage_v_6_1 + (pub_r001356_7_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_6_2 + (pub_r001356_7_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((helper_flow_4_1 + (pub_r001356_3_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_4_2 + (pub_r001356_3_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((pub_r001356_0_1 * 2) + 27) & 63;
  int stage_v_27_2 = ((pub_r001356_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((stage_v_11_1 + (pub_r001356_1_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_11_2 + (pub_r001356_1_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001356_18_1 + (pub_r001356_6_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001356_18_2 + (pub_r001356_6_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001356_6_1 * 2) + 29) & 63;
  int stage_v_30_2 = ((pub_r001356_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_25_1 + (pub_r001356_9_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_25_2 + (pub_r001356_9_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_17_1 + (pub_r001356_14_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_17_2 + (pub_r001356_14_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((helper_flow_10_1 + (pub_r001356_3_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((helper_flow_10_2 + (pub_r001356_3_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((sec_r001356_11_1 + (pub_r001356_1_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001356_11_2 + (pub_r001356_1_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((stage_v_23_1 + (pub_r001356_15_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_23_2 + (pub_r001356_15_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_19_1 + (pub_r001356_3_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_19_2 + (pub_r001356_3_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001356_6_1 * 2) + 17) & 63;
  int stage_v_37_2 = ((pub_r001356_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_29_1 + (pub_r001356_1_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_29_2 + (pub_r001356_1_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001356_2_1 * 2) + 27) & 63;
  int stage_v_39_2 = ((pub_r001356_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_17_1 + (pub_r001356_12_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_17_2 + (pub_r001356_12_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_21_1 + (pub_r001356_6_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_21_2 + (pub_r001356_6_2 * 2)) + 128) & 127;
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
  int stage_v_42_1 = ((helper_flow_4_1 + (pub_r001356_10_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_4_2 + (pub_r001356_10_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_41_1 + (pub_r001356_14_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_41_2 + (pub_r001356_14_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_40_1 + (pub_r001356_1_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_40_2 + (pub_r001356_1_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001356_15_1 + (pub_r001356_3_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001356_15_2 + (pub_r001356_3_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((helper_flow_5_1 + (pub_r001356_8_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((helper_flow_5_2 + (pub_r001356_8_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001356_15_1 + (pub_r001356_3_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001356_15_2 + (pub_r001356_3_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((sec_r001356_20_1 + (pub_r001356_8_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001356_20_2 + (pub_r001356_8_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((pub_r001356_1_1 * 2) + 45) & 63;
  int stage_v_49_2 = ((pub_r001356_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001356_5_1 * 2) + 31) & 63;
  int stage_v_50_2 = ((pub_r001356_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((stage_v_42_1 + (pub_r001356_4_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_42_2 + (pub_r001356_4_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((helper_flow_9_1 + (pub_r001356_7_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((helper_flow_9_2 + (pub_r001356_7_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((stage_v_46_1 + (pub_r001356_8_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_46_2 + (pub_r001356_8_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((helper_flow_9_1 + (pub_r001356_8_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((helper_flow_9_2 + (pub_r001356_8_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((helper_flow_1_1 + (pub_r001356_14_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_1_2 + (pub_r001356_14_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_10_1 + (pub_r001356_0_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_10_2 + (pub_r001356_0_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_55_1 + (pub_r001356_5_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_55_2 + (pub_r001356_5_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001356_11_1 * 2) + 23) & 63;
  int stage_v_58_2 = ((pub_r001356_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001356_11_1 * 2) + 42) & 63;
  int stage_v_59_2 = ((pub_r001356_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((helper_flow_2_1 + (pub_r001356_7_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((helper_flow_2_2 + (pub_r001356_7_2 * 2)) + 185) & 127;
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
  int stage_v_61_1 = ((stage_v_21_1 + (pub_r001356_15_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_21_2 + (pub_r001356_15_2 * 2)) + 188) & 127;
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
  int stage_v_62_1 = ((pub_r001356_13_1 * 2) + 9) & 63;
  int stage_v_62_2 = ((pub_r001356_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001356_15_1 + (pub_r001356_1_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((sec_r001356_15_2 + (pub_r001356_1_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001356_18_1 + (pub_r001356_0_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001356_18_2 + (pub_r001356_0_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_33_1 + (pub_r001356_7_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_33_2 + (pub_r001356_7_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_12_1 + (pub_r001356_14_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_12_2 + (pub_r001356_14_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((sec_r001356_1_1 + (pub_r001356_3_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((sec_r001356_1_2 + (pub_r001356_3_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001356_5_1 * 2) + 39) & 63;
  int stage_v_68_2 = ((pub_r001356_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001356_13_1 * 2) + 11) & 63;
  int stage_v_69_2 = ((pub_r001356_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_14_1 + (pub_r001356_6_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_14_2 + (pub_r001356_6_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((pub_r001356_3_1 * 2) + 47) & 63;
  int stage_v_71_2 = ((pub_r001356_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001356_6_1 * 2) + 7) & 63;
  int stage_v_72_2 = ((pub_r001356_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_18_1 + (pub_r001356_15_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_18_2 + (pub_r001356_15_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001356_12_1 * 2) + 10) & 63;
  int stage_v_74_2 = ((pub_r001356_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_4_1 + (pub_r001356_6_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_4_2 + (pub_r001356_6_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_25_1 + (pub_r001356_13_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_25_2 + (pub_r001356_13_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((sec_r001356_18_1 + (pub_r001356_6_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((sec_r001356_18_2 + (pub_r001356_6_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001356_10_1 * 2) + 34) & 63;
  int stage_v_78_2 = ((pub_r001356_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_5_1 + (pub_r001356_14_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_5_2 + (pub_r001356_14_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001356_15_1 + (pub_r001356_4_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001356_15_2 + (pub_r001356_4_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001356_6_1 * 2) + 5) & 63;
  int stage_v_81_2 = ((pub_r001356_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_41_1 + (pub_r001356_5_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_41_2 + (pub_r001356_5_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_56_1 + (pub_r001356_12_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_56_2 + (pub_r001356_12_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_10_1 + (pub_r001356_14_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_10_2 + (pub_r001356_14_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_47_1 + (pub_r001356_12_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_47_2 + (pub_r001356_12_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_44_1 + (pub_r001356_1_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_44_2 + (pub_r001356_1_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_48_1 + (pub_r001356_7_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_48_2 + (pub_r001356_7_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001356_8_1 * 2) + 12) & 63;
  int stage_v_88_2 = ((pub_r001356_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001356_1_1 * 2) + 39) & 63;
  int stage_v_89_2 = ((pub_r001356_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_17_1 + (pub_r001356_9_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_17_2 + (pub_r001356_9_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_2_1 + (pub_r001356_7_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_2_2 + (pub_r001356_7_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((sec_r001356_10_1 + (pub_r001356_8_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001356_10_2 + (pub_r001356_8_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_10_1 + (pub_r001356_8_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_10_2 + (pub_r001356_8_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((pub_r001356_1_1 * 2) + 49) & 63;
  int stage_v_94_2 = ((pub_r001356_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((stage_v_8_1 + (pub_r001356_5_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_8_2 + (pub_r001356_5_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_85_1 + (pub_r001356_8_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_85_2 + (pub_r001356_8_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_28_1 + (pub_r001356_8_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_28_2 + (pub_r001356_8_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_29_1 + (pub_r001356_11_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_29_2 + (pub_r001356_11_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((sec_r001356_8_1 + (pub_r001356_3_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((sec_r001356_8_2 + (pub_r001356_3_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_18_1 + (pub_r001356_8_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_18_2 + (pub_r001356_8_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_14_1 + (pub_r001356_11_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_14_2 + (pub_r001356_11_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((sec_r001356_16_1 + (pub_r001356_9_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((sec_r001356_16_2 + (pub_r001356_9_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001356_6_1 + (pub_r001356_12_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001356_6_2 + (pub_r001356_12_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001356_4_1 * 2) + 14) & 63;
  int stage_v_104_2 = ((pub_r001356_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((sec_r001356_16_1 + (pub_r001356_7_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((sec_r001356_16_2 + (pub_r001356_7_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((sec_r001356_1_1 + (pub_r001356_2_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((sec_r001356_1_2 + (pub_r001356_2_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001356_7_1 * 2) + 31) & 63;
  int stage_v_107_2 = ((pub_r001356_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001356_9_1 * 2) + 14) & 63;
  int stage_v_108_2 = ((pub_r001356_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_63_1 + (pub_r001356_15_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_63_2 + (pub_r001356_15_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_73_1 + (pub_r001356_7_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_73_2 + (pub_r001356_7_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((pub_r001356_6_1 * 2) + 18) & 63;
  int stage_v_111_2 = ((pub_r001356_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((stage_v_70_1 + (pub_r001356_0_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_70_2 + (pub_r001356_0_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((sec_r001356_3_1 + (pub_r001356_7_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001356_3_2 + (pub_r001356_7_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001356_3_1 * 2) + 34) & 63;
  int stage_v_114_2 = ((pub_r001356_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001356_12_1 * 2) + 35) & 63;
  int stage_v_115_2 = ((pub_r001356_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((sec_r001356_13_1 + (pub_r001356_15_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001356_13_2 + (pub_r001356_15_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001356_7_1 * 2) + 36) & 63;
  int stage_v_117_2 = ((pub_r001356_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001356_11_1 * 2) + 10) & 63;
  int stage_v_118_2 = ((pub_r001356_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001356_10_1 * 2) + 31) & 63;
  int stage_v_119_2 = ((pub_r001356_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_106_1 + (pub_r001356_2_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_106_2 + (pub_r001356_2_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((helper_flow_8_1 + (pub_r001356_7_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((helper_flow_8_2 + (pub_r001356_7_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_97_1 + (pub_r001356_7_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_97_2 + (pub_r001356_7_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_35_1 + (pub_r001356_5_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_35_2 + (pub_r001356_5_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_102_1 + (pub_r001356_0_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_102_2 + (pub_r001356_0_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_124_1 + (pub_r001356_7_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_124_2 + (pub_r001356_7_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_77_1 + (pub_r001356_1_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_77_2 + (pub_r001356_1_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_106_1 + (pub_r001356_9_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_106_2 + (pub_r001356_9_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_103_1 + (pub_r001356_9_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_103_2 + (pub_r001356_9_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_15_1 + (pub_r001356_7_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_15_2 + (pub_r001356_7_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((helper_flow_5_1 + (pub_r001356_11_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((helper_flow_5_2 + (pub_r001356_11_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001356_10_1 * 2) + 29) & 63;
  int stage_v_131_2 = ((pub_r001356_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_121_1 + (pub_r001356_11_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_121_2 + (pub_r001356_11_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_54_1 + (pub_r001356_5_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_54_2 + (pub_r001356_5_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_46_1 + (pub_r001356_0_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_46_2 + (pub_r001356_0_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_122_1 + (pub_r001356_7_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_122_2 + (pub_r001356_7_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((pub_r001356_1_1 * 2) + 34) & 63;
  int stage_v_136_2 = ((pub_r001356_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((sec_r001356_9_1 + (pub_r001356_6_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((sec_r001356_9_2 + (pub_r001356_6_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001356_11_1 * 2) + 19) & 63;
  int stage_v_138_2 = ((pub_r001356_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_100_1 + (pub_r001356_4_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_100_2 + (pub_r001356_4_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_96_1 + (pub_r001356_10_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_96_2 + (pub_r001356_10_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((helper_flow_6_1 + (pub_r001356_1_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((helper_flow_6_2 + (pub_r001356_1_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_106_1 + (pub_r001356_15_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_106_2 + (pub_r001356_15_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001356_4_1 * 2) + 34) & 63;
  int stage_v_143_2 = ((pub_r001356_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001356_0_1 * 2) + 18) & 63;
  int stage_v_144_2 = ((pub_r001356_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001356_0_1 * 2) + 11) & 63;
  int stage_v_145_2 = ((pub_r001356_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001356_8_1 * 2) + 38) & 63;
  int stage_v_146_2 = ((pub_r001356_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_46_1 + (pub_r001356_10_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_46_2 + (pub_r001356_10_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((helper_flow_9_1 + (pub_r001356_10_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((helper_flow_9_2 + (pub_r001356_10_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_13_1 + (pub_r001356_14_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_13_2 + (pub_r001356_14_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((pub_r001356_7_1 * 2) + 18) & 63;
  int stage_v_150_2 = ((pub_r001356_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_77_1 + (pub_r001356_11_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_77_2 + (pub_r001356_11_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_73_1 + (pub_r001356_15_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_73_2 + (pub_r001356_15_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_106_1 + (pub_r001356_2_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_106_2 + (pub_r001356_2_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_93_1 + (pub_r001356_7_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_93_2 + (pub_r001356_7_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001356_5_1 * 2) + 33) & 63;
  int stage_v_155_2 = ((pub_r001356_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001356_15_1 * 2) + 28) & 63;
  int stage_v_156_2 = ((pub_r001356_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_91_1 + (pub_r001356_8_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_91_2 + (pub_r001356_8_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001356_6_1 * 2) + 31) & 63;
  int stage_v_158_2 = ((pub_r001356_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001356_12_1 * 2) + 40) & 63;
  int stage_v_159_2 = ((pub_r001356_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001356_15_1 * 2) + 21) & 63;
  int stage_v_160_2 = ((pub_r001356_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_83_1 + (pub_r001356_1_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_83_2 + (pub_r001356_1_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_100_1 + (pub_r001356_11_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_100_2 + (pub_r001356_11_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_56_1 + (pub_r001356_13_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_56_2 + (pub_r001356_13_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_29_1 + (pub_r001356_11_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_29_2 + (pub_r001356_11_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_132_1 + (pub_r001356_5_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_132_2 + (pub_r001356_5_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((helper_flow_8_1 + (pub_r001356_11_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((helper_flow_8_2 + (pub_r001356_11_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001356_12_1 * 2) + 28) & 63;
  int stage_v_167_2 = ((pub_r001356_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_29_1 + (pub_r001356_8_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_29_2 + (pub_r001356_8_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_65_1 + (pub_r001356_8_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_65_2 + (pub_r001356_8_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_124_1 + (pub_r001356_9_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_124_2 + (pub_r001356_9_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001356_3_1 * 2) + 13) & 63;
  int stage_v_171_2 = ((pub_r001356_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_90_1 + (pub_r001356_11_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_90_2 + (pub_r001356_11_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001356_5_1 * 2) + 35) & 63;
  int stage_v_173_2 = ((pub_r001356_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_149_1 + (pub_r001356_11_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_149_2 + (pub_r001356_11_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001356_14_1 * 2) + 39) & 63;
  int stage_v_175_2 = ((pub_r001356_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001356_12_1 * 2) + 22) & 63;
  int stage_v_176_2 = ((pub_r001356_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_66_1 + (pub_r001356_11_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_66_2 + (pub_r001356_11_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_124_1 + (pub_r001356_14_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_124_2 + (pub_r001356_14_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001356_14_1 * 2) + 18) & 63;
  int stage_v_179_2 = ((pub_r001356_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001356_13_1 * 2) + 5) & 63;
  int stage_v_180_2 = ((pub_r001356_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((sec_r001356_11_1 + (pub_r001356_6_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((sec_r001356_11_2 + (pub_r001356_6_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001356_1_1 * 2) + 8) & 63;
  int stage_v_182_2 = ((pub_r001356_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_133_1 + (pub_r001356_3_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_133_2 + (pub_r001356_3_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((helper_flow_7_1 + (pub_r001356_7_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((helper_flow_7_2 + (pub_r001356_7_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_142_1 + (pub_r001356_7_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_142_2 + (pub_r001356_7_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_2_1 + (pub_r001356_3_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_2_2 + (pub_r001356_3_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_54_1 + (pub_r001356_9_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_54_2 + (pub_r001356_9_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001356_10_1 * 2) + 40) & 63;
  int stage_v_188_2 = ((pub_r001356_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_90_1 + (pub_r001356_7_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_90_2 + (pub_r001356_7_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_55_1 + (pub_r001356_14_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_55_2 + (pub_r001356_14_2 * 2)) + 575) & 127;
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
  int stage_v_191_1 = ((pub_r001356_5_1 * 2) + 22) & 63;
  int stage_v_191_2 = ((pub_r001356_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001356_13_1 * 2) + 37) & 63;
  int stage_v_192_2 = ((pub_r001356_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001356_1_1 * 2) + 25) & 63;
  int stage_v_193_2 = ((pub_r001356_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_60_1 + (pub_r001356_9_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_60_2 + (pub_r001356_9_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001356_14_1 * 2) + 49) & 63;
  int stage_v_195_2 = ((pub_r001356_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001356_13_1 * 2) + 49) & 63;
  int stage_v_196_2 = ((pub_r001356_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001356_8_1 * 2) + 24) & 63;
  int stage_v_197_2 = ((pub_r001356_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_187_1 + (pub_r001356_7_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_187_2 + (pub_r001356_7_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001356_0_1 != sec_r001356_0_2);
  __CPROVER_assume(pub_r001356_11_1 == pub_r001356_11_2);
  __CPROVER_assume(sec_r001356_11_1 != sec_r001356_11_2);
  __CPROVER_assume(pub_r001356_2_1 == pub_r001356_2_2);
  __CPROVER_assume(sec_r001356_10_1 != sec_r001356_10_2);
  __CPROVER_assume(sec_r001356_18_1 != sec_r001356_18_2);
  __CPROVER_assume(pub_r001356_4_1 == pub_r001356_4_2);
  __CPROVER_assume(sec_r001356_17_1 != sec_r001356_17_2);
  __CPROVER_assume(pub_r001356_3_1 == pub_r001356_3_2);
  __CPROVER_assume(sec_r001356_15_1 != sec_r001356_15_2);
  __CPROVER_assume(sec_r001356_20_1 != sec_r001356_20_2);
  __CPROVER_assume(pub_r001356_13_1 == pub_r001356_13_2);
  __CPROVER_assume(sec_r001356_5_1 != sec_r001356_5_2);
  __CPROVER_assume(pub_r001356_6_1 == pub_r001356_6_2);
  __CPROVER_assume(pub_r001356_8_1 == pub_r001356_8_2);
  __CPROVER_assume(sec_r001356_7_1 != sec_r001356_7_2);
  __CPROVER_assume(pub_r001356_1_1 == pub_r001356_1_2);
  __CPROVER_assume(pub_r001356_5_1 == pub_r001356_5_2);
  __CPROVER_assume(pub_r001356_0_1 == pub_r001356_0_2);
  __CPROVER_assume(sec_r001356_12_1 != sec_r001356_12_2);
  __CPROVER_assume(sec_r001356_13_1 != sec_r001356_13_2);
  __CPROVER_assume(sec_r001356_6_1 != sec_r001356_6_2);
  __CPROVER_assume(sec_r001356_19_1 != sec_r001356_19_2);
  __CPROVER_assume(sec_r001356_9_1 != sec_r001356_9_2);
  __CPROVER_assume(pub_r001356_14_1 == pub_r001356_14_2);
  __CPROVER_assume(sec_r001356_2_1 != sec_r001356_2_2);
  __CPROVER_assume(pub_r001356_15_1 == pub_r001356_15_2);
  __CPROVER_assume(pub_r001356_9_1 == pub_r001356_9_2);
  __CPROVER_assume(pub_r001356_10_1 == pub_r001356_10_2);
  __CPROVER_assume(pub_r001356_12_1 == pub_r001356_12_2);
  __CPROVER_assume(sec_r001356_4_1 != sec_r001356_4_2);
  __CPROVER_assume(sec_r001356_3_1 != sec_r001356_3_2);
  __CPROVER_assume(sec_r001356_16_1 != sec_r001356_16_2);
  __CPROVER_assume(pub_r001356_7_1 == pub_r001356_7_2);
  __CPROVER_assume(sec_r001356_1_1 != sec_r001356_1_2);
  __CPROVER_assume(sec_r001356_8_1 != sec_r001356_8_2);
  __CPROVER_assume(sec_r001356_14_1 != sec_r001356_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.reading == st_var_1_2.reading);
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
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
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
}


