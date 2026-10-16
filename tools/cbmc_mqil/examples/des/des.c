#include <stdint.h>

#define LB32_MASK 0x00000001
#define LB64_MASK 0x0000000000000001
#define L64_MASK 0x00000000ffffffff
#define H64_MASK 0xffffffff00000000

uint64_t sub_key[16] = {0};
uint64_t calculationofkeys(uint32_t C, uint32_t D, uint32_t L, uint32_t R,
                           char mode);
uint64_t initial_permuatation(uint64_t input, uint32_t L, uint32_t R,
                              uint32_t C, uint32_t D, char mode);
uint64_t schedule_calculation(uint64_t key, uint32_t C, uint32_t D, uint32_t L,
                              uint32_t R, char mode);
uint64_t shiftingcidi(uint32_t C, uint32_t D, uint32_t L, uint32_t R,
                      char mode);
uint64_t calculationofkeys(uint32_t C, uint32_t D, uint32_t L, uint32_t R,
                           char mode);
uint64_t inverse_intial_permuatation(uint32_t L, uint32_t R);
uint64_t initial_permuatation(uint64_t input, uint32_t L, uint32_t R,
                              uint32_t C, uint32_t D, char mode) {
  static char IP[64];
  int i;
  uint64_t init_perm_res = 0;
  uint32_t L1;
  uint32_t R1;
  for (i = 0; i < 64; i++) {

    init_perm_res <<= 1;
    init_perm_res |= (input >> (64 - IP[i])) & LB64_MASK;
  }
  L1 = (uint32_t)(init_perm_res >> 32) & L64_MASK;
  R1 = (uint32_t)init_perm_res & L64_MASK;
  L = L1;
  R = R1;
  return schedule_calculation(input, C, D, L, R, mode);
}

uint64_t schedule_calculation(uint64_t key, uint32_t C, uint32_t D, uint32_t L,
                              uint32_t R, char mode) {
  static char PC1[56];

  int i;
  uint64_t permuted_choice_1 = 0;
  uint64_t C1;
  uint64_t D1;
  for (i = 0; i < 56; i++) {

    permuted_choice_1 <<= 1;
    permuted_choice_1 |= (key >> (64 - PC1[i])) & LB64_MASK;
  }

  C1 = (uint32_t)((permuted_choice_1 >> 28) & 0x000000000fffffff);
  D1 = (uint32_t)(permuted_choice_1 & 0x000000000fffffff);
  C = C1;
  D = D1;
  return shiftingcidi(C, D, L, R, mode);
}

uint64_t shiftingcidi(uint32_t C, uint32_t D, uint32_t L, uint32_t R,
                      char mode) {
  static char iteration_shift[16];
  static char PC2[48];
  uint64_t permuted_choice_2 = 0;
  uint32_t C1 = C;
  uint32_t D1 = D;
  int i, j;

  for (i = 0; i < 16; i++) {

    for (j = 0; j < iteration_shift[i]; j++) {

      C1 = 0x0fffffff & (C1 << 1) | 0x00000001 & (C1 >> 27);

      D1 = 0x0fffffff & (D1 << 1) | 0x00000001 & (D1 >> 27);
    }
    permuted_choice_2 = 0;
    permuted_choice_2 = (((uint64_t)C1) << 28) | (uint64_t)D1;
    sub_key[i] = 0;

    for (j = 0; j < 48; j++) {

      sub_key[i] <<= 1;
      sub_key[i] |= (permuted_choice_2 >> (56 - PC2[j])) & LB64_MASK;
    }
  }

  C = C1;
  D = D1;

  return calculationofkeys(C, D, L, R, mode);
}
uint64_t calculationofkeys(uint32_t C, uint32_t D, uint32_t L, uint32_t R,
                           char mode) {

  static char E[48];
  static char S[8][64];
  static char P[32];

  char row, column;
  uint32_t temp;
  uint32_t f_function_res = 0;
  int i, j;
  uint32_t s_output = 0;
  uint64_t s_input = 0;
  uint32_t C1 = C;
  uint32_t D1 = D;
  uint32_t L1 = L;
  uint32_t R1 = R;

  for (i = 0; i < 16; i++) {

    /* f(R,k) function */
    s_input = 0;

    for (j = 0; j < 48; j++) {

      s_input <<= 1;
      s_input |= (uint64_t)((R1 >> (32 - E[j])) & LB32_MASK);
    }
    if (mode == 'd') {
      s_input = s_input ^ sub_key[15 - i];
    } else {
      s_input = s_input ^ sub_key[i];
    }

    for (j = 0; j < 8; j++) {

      row = (char)((s_input & (0x0000840000000000 >> 6 * j)) >> 42 - 6 * j);
      row = (row >> 4) | row & 0x01;

      column = (char)((s_input & (0x0000780000000000 >> 6 * j)) >> 43 - 6 * j);

      s_output <<= 4;
      s_output |= (uint32_t)(S[j][16 * row + column] & 0x0f);
    }
    f_function_res = 0;

    for (j = 0; j < 32; j++) {

      f_function_res <<= 1;
      f_function_res |= (s_output >> (32 - P[j])) & LB32_MASK;
    }

    temp = R1;
    R1 = L1 ^ f_function_res;
    L1 = temp;
    C = C1;
    D = D1;
    L = L1;
    R = R1;
  }

  return inverse_intial_permuatation(L, R);
}

uint64_t inverse_intial_permuatation(uint32_t L, uint32_t R) {
  static char PI[64];

  uint64_t pre_output = 0;
  int i;
  uint32_t L1 = L;
  uint32_t R1 = R;
  pre_output = (((uint64_t)R1) << 32) | (uint64_t)L1;
  uint64_t inv_init_perm_res = 0;
  for (i = 0; i < 64; i++) {

    inv_init_perm_res <<= 1;
    inv_init_perm_res |= (pre_output >> (64 - PI[i])) & LB64_MASK;
  }
  return inv_init_perm_res;
}

void main() {
  int i;
  uint64_t input;
  uint64_t key;
  uint64_t result = input;
  uint32_t C = 0;
  uint32_t D = 0;
  uint32_t L = 0;
  uint32_t R = 0;
  char mode = 'e';
  for (i = 0; i < 16; i++) {
    C = 0;
    L = 0;
    R = 0;
    D = 0;
    result = initial_permuatation(result, L, R, C, D, mode);
  }
}
