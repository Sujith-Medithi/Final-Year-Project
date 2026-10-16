typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct 
{
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
uint8_t hash_1[32];
uint8_t hash_2[32];
uint8_t hash[32];
uint8_t input_arr_1[16];
uint8_t input_arr_2[16];
uint8_t input_arr[16];
static const uint32_t k_1[64];
static const uint32_t k_2[64];
static const uint32_t k[64];
struct buffer_state
{
  const uint8_t *p;
  unsigned long len;
  unsigned long total_len;
  int single_one_delivered;
  int total_len_delivered;
};
uint8_t nd_hash();
inline static void right_rot_2(uint32_t value_1, unsigned int count_1, uint32_t value_2, unsigned int count_2)
{
}

inline static uint32_t right_rot(uint32_t value, unsigned int count)
{
  return (value >> count) | (value << (32 - count));
}

static void init_buf_state_2(struct buffer_state *state_1, const void *input_1, unsigned long len_1, struct buffer_state *state_2, const void *input_2, unsigned long len_2)
{
  state_1->p = input_1;
  state_2->p = input_2;
  state_1->len = len_1;
  state_2->len = len_2;
  state_1->total_len = len_1;
  state_2->total_len = len_2;
  state_1->single_one_delivered = 0;
  state_2->single_one_delivered = 0;
  state_1->total_len_delivered = 0;
  state_2->total_len_delivered = 0;
}

static void init_buf_state(struct buffer_state *state, const void *input, unsigned long len)
{
  state->p = input;
  state->len = len;
  state->total_len = len;
  state->single_one_delivered = 0;
  state->total_len_delivered = 0;
}

static void calc_chunk_2(uint8_t chunk_1[64], struct buffer_state *state_1, uint8_t chunk_2[64], struct buffer_state *state_2)
{
  unsigned long space_in_chunk_1;
  unsigned long space_in_chunk_2;
  if (state_1->total_len_delivered)
  {
    return 0;
  }
  if (state_2->total_len_delivered)
  {
    return 0;
  }
  if (state_1->len >= 64)
  {
    memcpy(chunk_1, state_1->p, 64);
    state_1->p += 64;
    state_1->len -= 64;
    return 1;
  }
  if (state_2->len >= 64)
  {
    memcpy(chunk_2, state_2->p, 64);
    state_2->p += 64;
    state_2->len -= 64;
    return 1;
  }
  memcpy_2(chunk_1, state_1->p, 64, chunk_2, state_2->p, 64);
  memcpy(chunk_1, state_1->p, state_1->len);
  memcpy(chunk_2, state_2->p, state_2->len);
  memcpy_2(chunk_1, state_1->p, state_1->len, chunk_2, state_2->p, state_2->len);
  chunk_1 += state_1->len;
  chunk_2 += state_2->len;
  space_in_chunk_1 = 64 - state_1->len;
  space_in_chunk_2 = 64 - state_2->len;
  state_1->p += state_1->len;
  state_2->p += state_2->len;
  state_1->len = 0;
  state_2->len = 0;
  if (!state_1->single_one_delivered)
  {
    *(chunk_1++) = 0x80;
    space_in_chunk_1 -= 1;
    state_1->single_one_delivered = 1;
  }
  if (!state_2->single_one_delivered)
  {
    *(chunk_2++) = 0x80;
    space_in_chunk_2 -= 1;
    state_2->single_one_delivered = 1;
  }
  const unsigned long left_1 = space_in_chunk_1 - 8;
  const unsigned long left_2 = space_in_chunk_2 - 8;
  unsigned long len_1 = state_1->total_len;
  unsigned long len_2 = state_2->total_len;
  int i_1;
  int i_2;
  if (space_in_chunk_1 >= 8)
  {
    memset(chunk_1, 0x00, left_1);
    chunk_1 += left_1;
    chunk_1[7] = (uint8_t) (len_1 << 3);
    len_1 >>= 5;
    for (i_1 = 6; i_1 >= 0; i_1--)
    {
      chunk_1[i_1] = (uint8_t) len_1;
      len_1 >>= 8;
    }

    state_1->total_len_delivered = 1;
  }
  else
  {
    memset(chunk_1, 0x00, space_in_chunk_1);
  }
  if (space_in_chunk_2 >= 8)
  {
    memset(chunk_2, 0x00, left_2);
    chunk_2 += left_2;
    chunk_2[7] = (uint8_t) (len_2 << 3);
    len_2 >>= 5;
    for (i_2 = 6; i_2 >= 0; i_2--)
    {
      chunk_2[i_2] = (uint8_t) len_2;
      len_2 >>= 8;
    }

    state_2->total_len_delivered = 1;
  }
  else
  {
    memset(chunk_2, 0x00, space_in_chunk_2);
  }
  memset_2(chunk_1, 0x00, left_1, chunk_2, 0x00, left_2);
  assert(space_in_chunk_1 == space_in_chunk_2);
  assert(left_1 == left_2);
  assert(len_1 == len_2);
  assert(i_1 == i_2);
}

static int calc_chunk(uint8_t chunk[64], struct buffer_state *state)
{
  unsigned long space_in_chunk;
  if (state->total_len_delivered)
  {
    return 0;
  }
  if (state->len >= 64)
  {
    memcpy(chunk, state->p, 64);
    state->p += 64;
    state->len -= 64;
    return 1;
  }
  memcpy(chunk, state->p, state->len);
  chunk += state->len;
  space_in_chunk = 64 - state->len;
  state->p += state->len;
  state->len = 0;
  if (!state->single_one_delivered)
  {
    *(chunk++) = 0x80;
    space_in_chunk -= 1;
    state->single_one_delivered = 1;
  }
  const unsigned long left = space_in_chunk - 8;
  unsigned long len = state->total_len;
  int i;
  if (space_in_chunk >= 8)
  {
    memset(chunk, 0x00, left);
    chunk += left;
    chunk[7] = (uint8_t) (len << 3);
    len >>= 5;
    for (i = 6; i >= 0; i--)
    {
      chunk[i] = (uint8_t) len;
      len >>= 8;
    }

    state->total_len_delivered = 1;
  }
  else
  {
    memset(chunk, 0x00, space_in_chunk);
  }
  return 1;
}

void calc_sha_256_2(uint8_t hash_1[32], const void *input_1, unsigned long len_1, uint8_t hash_2[32], const void *input_2, unsigned long len_2)
{
  uint32_t h_1[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
  uint32_t h_2[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
  unsigned i_1;
  unsigned i_2;
  unsigned j_1;
  unsigned j_2;
  uint8_t chunk_1[64];
  uint8_t chunk_2[64];
  struct buffer_state state_1;
  struct buffer_state state_2;
  init_buf_state(&state_1, input_1, len_1);
  init_buf_state(&state_2, input_2, len_2);
  init_buf_state_2(&state_1, input_1, len_1, &state_2, input_2, len_2);
  while (calc_chunk(chunk_1, &state_1) && calc_chunk(chunk_2, &state_2))
  {
    uint32_t ah_1[8];
    uint32_t ah_2[8];
    const uint8_t *p_1 = chunk_1;
    const uint8_t *p_2 = chunk_2;
    for (i_1 = 0, i_2 = 0; (i_1 < 8) && (i_2 < 8); i_1++, i_2++)
    {
      ah_1[i_1] = h_1[i_1];
      ah_2[i_2] = h_2[i_2];
    }

    for (i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++)
    {
      uint32_t w_1[16];
      uint32_t w_2[16];
      for (j_1 = 0, j_2 = 0; (j_1 < 16) && (j_2 < 16); j_1++, j_2++)
      {
        if (i_1 == 0)
        {
          w_1[j_1] = (((((uint32_t) p_1[0]) << 24) | (((uint32_t) p_1[1]) << 16)) | (((uint32_t) p_1[2]) << 8)) | ((uint32_t) p_1[3]);
          p_1 += 4;
        }
        else
        {
          const uint32_t s0_1 = (right_rot(w_1[(j_1 + 1) & 0xf], 7) ^ right_rot(w_1[(j_1 + 1) & 0xf], 18)) ^ (w_1[(j_1 + 1) & 0xf] >> 3);
          const uint32_t s1_1 = (right_rot(w_1[(j_1 + 14) & 0xf], 17) ^ right_rot(w_1[(j_1 + 14) & 0xf], 19)) ^ (w_1[(j_1 + 14) & 0xf] >> 10);
          w_1[j_1] = ((w_1[j_1] + s0_1) + w_1[(j_1 + 9) & 0xf]) + s1_1;
        }
        if (i_2 == 0)
        {
          w_2[j_2] = (((((uint32_t) p_2[0]) << 24) | (((uint32_t) p_2[1]) << 16)) | (((uint32_t) p_2[2]) << 8)) | ((uint32_t) p_2[3]);
          p_2 += 4;
        }
        else
        {
          const uint32_t s0_2 = (right_rot(w_2[(j_2 + 1) & 0xf], 7) ^ right_rot(w_2[(j_2 + 1) & 0xf], 18)) ^ (w_2[(j_2 + 1) & 0xf] >> 3);
          const uint32_t s1_2 = (right_rot(w_2[(j_2 + 14) & 0xf], 17) ^ right_rot(w_2[(j_2 + 14) & 0xf], 19)) ^ (w_2[(j_2 + 14) & 0xf] >> 10);
          w_2[j_2] = ((w_2[j_2] + s0_2) + w_2[(j_2 + 9) & 0xf]) + s1_2;
        }
        right_rot_2(w_1[(j_1 + 1) & 0xf], 7, w_2[(j_2 + 1) & 0xf], 7);
        const uint32_t s1_1 = (right_rot(ah_1[4], 6) ^ right_rot(ah_1[4], 11)) ^ right_rot(ah_1[4], 25);
        const uint32_t s1_2 = (right_rot(ah_2[4], 6) ^ right_rot(ah_2[4], 11)) ^ right_rot(ah_2[4], 25);
        right_rot_2(ah_1[4], 6, ah_2[4], 6);
        const uint32_t ch_1 = (ah_1[4] & ah_1[5]) ^ ((~ah_1[4]) & ah_1[6]);
        const uint32_t ch_2 = (ah_2[4] & ah_2[5]) ^ ((~ah_2[4]) & ah_2[6]);
        const uint32_t temp1_1 = (((ah_1[7] + s1_1) + ch_1) + k_1[(i_1 << 4) | j_1]) + w_1[j_1];
        const uint32_t temp1_2 = (((ah_2[7] + s1_2) + ch_2) + k_2[(i_2 << 4) | j_2]) + w_2[j_2];
        const uint32_t s0_1 = (right_rot(ah_1[0], 2) ^ right_rot(ah_1[0], 13)) ^ right_rot(ah_1[0], 22);
        const uint32_t s0_2 = (right_rot(ah_2[0], 2) ^ right_rot(ah_2[0], 13)) ^ right_rot(ah_2[0], 22);
        right_rot_2(ah_1[0], 2, ah_2[0], 2);
        const uint32_t maj_1 = ((ah_1[0] & ah_1[1]) ^ (ah_1[0] & ah_1[2])) ^ (ah_1[1] & ah_1[2]);
        const uint32_t maj_2 = ((ah_2[0] & ah_2[1]) ^ (ah_2[0] & ah_2[2])) ^ (ah_2[1] & ah_2[2]);
        const uint32_t temp2_1 = s0_1 + maj_1;
        const uint32_t temp2_2 = s0_2 + maj_2;
        ah_1[7] = ah_1[6];
        ah_2[7] = ah_2[6];
        ah_1[6] = ah_1[5];
        ah_2[6] = ah_2[5];
        ah_1[5] = ah_1[4];
        ah_2[5] = ah_2[4];
        ah_1[4] = ah_1[3] + temp1_1;
        ah_2[4] = ah_2[3] + temp1_2;
        ah_1[3] = ah_1[2];
        ah_2[3] = ah_2[2];
        ah_1[2] = ah_1[1];
        ah_2[2] = ah_2[1];
        ah_1[1] = ah_1[0];
        ah_2[1] = ah_2[0];
        ah_1[0] = temp1_1 + temp2_1;
        ah_2[0] = temp1_2 + temp2_2;
      }

    }

    for (i_1 = 0, i_2 = 0; (i_1 < 8) && (i_2 < 8); i_1++, i_2++)
    {
      h_1[i_1] += ah_1[i_1];
      h_2[i_2] += ah_2[i_2];
    }

  }

  for (i_1 = 0, j_1 = 0, i_2 = 0, j_2 = 0; (i_1 < 8) && (i_2 < 8); i_1++, i_2++)
  {
    hash_1[j_1++] = (uint8_t) (h_1[i_1] >> 24);
    hash_2[j_2++] = (uint8_t) (h_2[i_2] >> 24);
    hash_1[j_1++] = (uint8_t) (h_1[i_1] >> 16);
    hash_2[j_2++] = (uint8_t) (h_2[i_2] >> 16);
    hash_1[j_1++] = (uint8_t) (h_1[i_1] >> 8);
    hash_2[j_2++] = (uint8_t) (h_2[i_2] >> 8);
    hash_1[j_1++] = (uint8_t) h_1[i_1];
    hash_2[j_2++] = (uint8_t) h_2[i_2];
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(hash_1[i_0] != hash_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(k_1[i_0] == k_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 8; i_0++)
  {
    assert(h_1[i_0] == h_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(j_1 == j_2);
  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(chunk_1[i_0] == chunk_2[i_0]);
  }

  assert((*state_1.p) == (*state_2.p));
  assert(state_1.len == state_2.len);
  assert(state_1.total_len == state_2.total_len);
  assert(state_1.single_one_delivered == state_2.single_one_delivered);
  assert(state_1.total_len_delivered == state_2.total_len_delivered);
}

void calc_sha_256(uint8_t hash[32], const void *input, unsigned long len)
{
  uint32_t h[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
  unsigned i;
  unsigned j;
  uint8_t chunk[64];
  struct buffer_state state;
  init_buf_state(&state, input, len);
  while (calc_chunk(chunk, &state))
  {
    uint32_t ah[8];
    const uint8_t *p = chunk;
    for (i = 0; i < 8; i++)
    {
      ah[i] = h[i];
    }

    for (i = 0; i < 4; i++)
    {
      uint32_t w[16];
      for (j = 0; j < 16; j++)
      {
        if (i == 0)
        {
          w[j] = (((((uint32_t) p[0]) << 24) | (((uint32_t) p[1]) << 16)) | (((uint32_t) p[2]) << 8)) | ((uint32_t) p[3]);
          p += 4;
        }
        else
        {
          const uint32_t s0 = (right_rot(w[(j + 1) & 0xf], 7) ^ right_rot(w[(j + 1) & 0xf], 18)) ^ (w[(j + 1) & 0xf] >> 3);
          const uint32_t s1 = (right_rot(w[(j + 14) & 0xf], 17) ^ right_rot(w[(j + 14) & 0xf], 19)) ^ (w[(j + 14) & 0xf] >> 10);
          w[j] = ((w[j] + s0) + w[(j + 9) & 0xf]) + s1;
        }
        const uint32_t s1 = (right_rot(ah[4], 6) ^ right_rot(ah[4], 11)) ^ right_rot(ah[4], 25);
        const uint32_t ch = (ah[4] & ah[5]) ^ ((~ah[4]) & ah[6]);
        const uint32_t temp1 = (((ah[7] + s1) + ch) + k[(i << 4) | j]) + w[j];
        const uint32_t s0 = (right_rot(ah[0], 2) ^ right_rot(ah[0], 13)) ^ right_rot(ah[0], 22);
        const uint32_t maj = ((ah[0] & ah[1]) ^ (ah[0] & ah[2])) ^ (ah[1] & ah[2]);
        const uint32_t temp2 = s0 + maj;
        ah[7] = ah[6];
        ah[6] = ah[5];
        ah[5] = ah[4];
        ah[4] = ah[3] + temp1;
        ah[3] = ah[2];
        ah[2] = ah[1];
        ah[1] = ah[0];
        ah[0] = temp1 + temp2;
      }

    }

    for (i = 0; i < 8; i++)
    {
      h[i] += ah[i];
    }

  }

  for (i = 0, j = 0; i < 8; i++)
  {
    hash[j++] = (uint8_t) (h[i] >> 24);
    hash[j++] = (uint8_t) (h[i] >> 16);
    hash[j++] = (uint8_t) (h[i] >> 8);
    hash[j++] = (uint8_t) h[i];
  }

}

void main()
{
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    hash_1[i_0] = nd_hash();
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    hash_2[i_0] = nd_hash();
  }

  calc_sha_256(hash_1, input_arr_1, 16);
  calc_sha_256(hash_2, input_arr_2, 16);
  calc_sha_256_2(hash_1, input_arr_1, 16, hash_2, input_arr_2, 16);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(hash_1[i_0] != hash_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(input_arr_1[i_0] == input_arr_2[i_0]);
  }

}


