struct s_key_set;
struct s_key_set
{
  unsigned char structVar0[8];
  unsigned char structVar1[4];
  unsigned char structVar2[4];
};
void generate_key(unsigned char *var0);
void generate_sub_keys(unsigned char *var0, struct s_key_set *var1);
extern void llvm_lifetime_end_p0i8(unsigned long var0, unsigned char *var1);
extern void llvm_lifetime_start_p0i8(unsigned long var0, unsigned char *var1);
void main(void);
void process_message(unsigned char *var0, unsigned char *var1, struct s_key_set *var2, unsigned int var3);
extern unsigned int rand(void);
extern unsigned int initial_key_permutaion_1[56] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int initial_key_permutaion_2[56] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int initial_key_permutaion[56] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int key_shift_sizes_1[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int key_shift_sizes_2[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int key_shift_sizes[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int sub_key_permutation_1[48] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int sub_key_permutation_2[48] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int sub_key_permutation[48] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int initial_message_permutation_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int initial_message_permutation_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int initial_message_permutation[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int message_expansion_1[48] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int message_expansion_2[48] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int message_expansion[48] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S1_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S1_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S2_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S2_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S3_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S3_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S3[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S4_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S4_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S4[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S5_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S5_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S5[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S6_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S6_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S6[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S7_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S7_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S7[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S8_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S8_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int S8[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int right_sub_message_permutation_1[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int right_sub_message_permutation_2[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int right_sub_message_permutation[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int final_message_permutation_1[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int final_message_permutation_2[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern unsigned int final_message_permutation[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
extern struct s_key_set key_sets_1[10];
extern struct s_key_set key_sets_2[10];
extern struct s_key_set key_sets[10];
struct s_key_set nd_key_sets();
void generate_key_2(unsigned char *var0_1, unsigned char *var0_2)
{
  unsigned long var1_phi_1;
  unsigned long var1_phi_2;
  long var2_1;
  long var2_2;
  block0_1:
  var1_phi_1 = 0;

  block0_2:
  var1_phi_2 = 0;

  do
  {
    var1_phi_1 = var2_1;
    var1_phi_2 = var2_2;
    *(((unsigned char *) var0_1) + var1_phi_1) = (unsigned char) (((int) rand()) % ((int) 255));
    *(((unsigned char *) var0_2) + var1_phi_2) = (unsigned char) (((int) rand()) % ((int) 255));
    rand_2();
    var2_1 = ((long) var1_phi_1) + ((long) 1);
    var2_2 = ((long) var1_phi_2) + ((long) 1);
  }
  while ((var2_1 == 8) && (var2_2 == 8));
  assert(var1_phi_1 == var1_phi_2);
  assert(var2_1 == var2_2);
}

void generate_key(unsigned char *var0)
{
  unsigned long var1_phi;
  long var2;
  block0:
  var1_phi = 0;

  do
  {
    var1_phi = var2;
    *(((unsigned char *) var0) + var1_phi) = (unsigned char) (((int) rand()) % ((int) 255));
    var2 = ((long) var1_phi) + ((long) 1);
  }
  while (var2 == 8);
  return;
}

void generate_sub_keys_2(unsigned char *var0_1, struct s_key_set *var1_1, unsigned char *var0_2, struct s_key_set *var1_2)
{
  unsigned long var2_phi_1;
  unsigned long var2_phi_2;
  unsigned long var7_phi_1;
  unsigned long var7_phi_2;
  unsigned long var9_phi_1;
  unsigned long var9_phi_2;
  unsigned long var13_phi_1;
  unsigned long var13_phi_2;
  unsigned long var15_phi_1;
  unsigned long var15_phi_2;
  unsigned long var43_phi_1;
  unsigned long var43_phi_2;
  unsigned char *var49_phi_1;
  unsigned char *var49_phi_2;
  unsigned int var50_phi_1;
  unsigned int var50_phi_2;
  int var3_1;
  int var3_2;
  int var4_1;
  int var4_2;
  unsigned char *var5_1;
  unsigned char *var5_2;
  long var6_1=0;
  long var6_2=0;
  long var8_1=0;
  long var8_2=0;
  unsigned char var10_1;
  unsigned char var10_2;
  unsigned char *var11_1;
  unsigned char *var11_2;
  long var12_1=0;
  long var12_2=0;
  long var14_1;
  long var14_2;
  long var16_1=0;
  long var16_2=0;
  unsigned int var17_1;
  unsigned int var17_2;
  unsigned char var18_1;
  unsigned char var18_2;
  unsigned char *var19_1;
  unsigned char *var19_2;
  unsigned char var20_1;
  unsigned char var20_2;
  unsigned char var21_1;
  unsigned char var21_2;
  unsigned char *var22_1;
  unsigned char *var22_2;
  unsigned char var23_1;
  unsigned char var23_2;
  unsigned char *var24_1;
  unsigned char *var24_2;
  unsigned char var25_1;
  unsigned char var25_2;
  unsigned char var26_1;
  unsigned char var26_2;
  unsigned char *var27_1;
  unsigned char *var27_2;
  unsigned char var28_1;
  unsigned char var28_2;
  unsigned char var29_1;
  unsigned char var29_2;
  int var30_1;
  int var30_2;
  int var31_1;
  int var31_2;
  unsigned char *var32_1;
  unsigned char *var32_2;
  unsigned char var33_1;
  unsigned char var33_2;
  unsigned char var34_1;
  unsigned char var34_2;
  unsigned char *var35_1;
  unsigned char *var35_2;
  unsigned char var36_1;
  unsigned char var36_2;
  unsigned char *var37_1;
  unsigned char *var37_2;
  unsigned char var38_1;
  unsigned char var38_2;
  unsigned char var39_1;
  unsigned char var39_2;
  unsigned char *var40_1;
  unsigned char *var40_2;
  unsigned char var41_1;
  unsigned char var41_2;
  unsigned char var42_1;
  unsigned char var42_2;
  unsigned int var44_1;
  unsigned int var44_2;
  int var45_1;
  int var45_2;
  unsigned char *var46_1;
  unsigned char *var46_2;
  int var47_1;
  int var47_2;
  unsigned char *var48_1;
  unsigned char *var48_2;
  int var51_1;
  int var51_2;
  unsigned char *var52_1;
  unsigned char *var52_2;
  long var53_1=0;
  long var53_2=0;
  long var54_1=0;
  long var54_2=0;
  block0_1:
  *((unsigned long *) var1_1) = 0;

  block0_2:
  *((unsigned long *) var1_2) = 0;

  var2_phi_1 = 0;
  var2_phi_2 = 0;
  do
  {
    var2_phi_1 = var6_1;
    var2_phi_2 = var6_2;
    var3_1 = ((int) initial_key_permutaion_1[var2_phi_1]) + ((int) (-1));
    var3_2 = ((int) initial_key_permutaion_2[var2_phi_2]) + ((int) (-1));
    var4_1 = ((int) var3_1) % ((int) 8);
    var4_2 = ((int) var3_2) % ((int) 8);
    var5_1 = &var1_1->structVar0[(var2_phi_1 >> 3) & 536870911];
    var5_2 = &var1_2->structVar0[(var2_phi_2 >> 3) & 536870911];
    *var5_1 = (*var5_1) | ((unsigned char) (((((unsigned int) ((*(((unsigned char *) var0_1) + ((long) ((int) (((int) var3_1) / ((int) 8)))))) & ((unsigned char) (128 >> var4_1)))) << ((unsigned int) var4_1)) & 255) >> (((unsigned int) var2_phi_1) & 7)));
    *var5_2 = (*var5_2) | ((unsigned char) (((((unsigned int) ((*(((unsigned char *) var0_2) + ((long) ((int) (((int) var3_2) / ((int) 8)))))) & ((unsigned char) (128 >> var4_2)))) << ((unsigned int) var4_2)) & 255) >> (((unsigned int) var2_phi_2) & 7)));
    var6_1++;
    var6_2++;
  }
  while ((var6_1 == 56) && (var6_2 == 56));
  var7_phi_1 = 0;
  var7_phi_2 = 0;
  do
  {
    var7_phi_1 = var8_1;
    var7_phi_2 = var8_2;
    var1_1->structVar1[var7_phi_1] = var1_1->structVar0[var7_phi_1];
    var1_2->structVar1[var7_phi_2] = var1_2->structVar0[var7_phi_2];
    var8_1++;
    var8_2++;
  }
  while ((var8_1 == 3) && (var8_2 == 3));
  var1_1->structVar1[3] = var1_1->structVar0[3] & (-16);
  var1_2->structVar1[3] = var1_2->structVar0[3] & (-16);
  var9_phi_1 = 0;
  var9_phi_2 = 0;
  do
  {
    var9_phi_1 = var12_1;
    var9_phi_2 = var12_2;
    var10_1 = var1_1->structVar0[((long) var9_phi_1) + ((long) 3)] << ((unsigned char) 4);
    var10_2 = var1_2->structVar0[((long) var9_phi_2) + ((long) 3)] << ((unsigned char) 4);
    var11_1 = &var1_1->structVar2[var9_phi_1];
    var11_2 = &var1_2->structVar2[var9_phi_2];
    *var11_1 = var10_1;
    *var11_2 = var10_2;
    *var11_1 = (var1_1->structVar0[((long) var9_phi_1) + ((long) 4)] >> 4) | var10_1;
    *var11_2 = (var1_2->structVar0[((long) var9_phi_2) + ((long) 4)] >> 4) | var10_2;
    var12_1++;
    var12_2++;
  }
  while ((var12_1 == 3) && (var12_2 == 3));
  var1_1->structVar2[3] = var1_1->structVar0[6] << ((unsigned char) 4);
  var1_2->structVar2[3] = var1_2->structVar0[6] << ((unsigned char) 4);
  var13_phi_1 = 1;
  var13_phi_2 = 1;
  do
  {
    var13_phi_1 = var54_1;
    var13_phi_2 = var54_2;
    var14_1 = ((long) var13_phi_1) + ((long) (-1));
    var14_2 = ((long) var13_phi_2) + ((long) (-1));
    var15_phi_1 = 0;
    var15_phi_2 = 0;
    do
    {
      var15_phi_1 = var16_1;
      var15_phi_2 = var16_2;
      (*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar1[var15_phi_1] = (*(((struct s_key_set *) var1_1) + var14_1)).structVar1[var15_phi_1];
      (*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar1[var15_phi_2] = (*(((struct s_key_set *) var1_2) + var14_2)).structVar1[var15_phi_2];
      (*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar2[var15_phi_1] = (*(((struct s_key_set *) var1_1) + var14_1)).structVar2[var15_phi_1];
      (*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar2[var15_phi_2] = (*(((struct s_key_set *) var1_2) + var14_2)).structVar2[var15_phi_2];
      var16_1++;
      var16_2++;
    }
    while ((var16_1 == 4) && (var16_2 == 4));
    var17_1 = key_shift_sizes_1[var13_phi_1];
    var17_2 = key_shift_sizes_2[var13_phi_2];
    var18_1 = (var17_1 == 1) ? (-128) : (-64);
    var18_2 = (var17_2 == 1) ? (-128) : (-64);
    var19_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar1[0];
    var19_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar1[0];
    var20_1 = *var19_1;
    var20_2 = *var19_2;
    var21_1 = var18_1 & var20_1;
    var21_2 = var18_2 & var20_2;
    var22_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar1[1];
    var22_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar1[1];
    var23_1 = *var22_1;
    var23_2 = *var22_2;
    var24_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar1[2];
    var24_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar1[2];
    var25_1 = *var24_1;
    var25_2 = *var24_2;
    var26_1 = var25_1 & var18_1;
    var26_2 = var25_2 & var18_2;
    var27_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar1[3];
    var27_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar1[3];
    var28_1 = *var27_1;
    var28_2 = *var27_2;
    var29_1 = var28_1 & var18_1;
    var29_2 = var28_2 & var18_2;
    var30_1 = ((int) 8) - ((int) var17_1);
    var30_2 = ((int) 8) - ((int) var17_2);
    *var19_1 = (unsigned char) ((((unsigned int) (var23_1 & var18_1)) >> var30_1) | (((unsigned int) var20_1) << ((unsigned int) var17_1)));
    *var19_2 = (unsigned char) ((((unsigned int) (var23_2 & var18_2)) >> var30_2) | (((unsigned int) var20_2) << ((unsigned int) var17_2)));
    *var22_1 = (unsigned char) ((((unsigned int) var26_1) >> var30_1) | (((unsigned int) var23_1) << ((unsigned int) var17_1)));
    *var22_2 = (unsigned char) ((((unsigned int) var26_2) >> var30_2) | (((unsigned int) var23_2) << ((unsigned int) var17_2)));
    *var24_1 = (unsigned char) ((((unsigned int) var29_1) >> var30_1) | (((unsigned int) var25_1) << ((unsigned int) var17_1)));
    *var24_2 = (unsigned char) ((((unsigned int) var29_2) >> var30_2) | (((unsigned int) var25_2) << ((unsigned int) var17_2)));
    var31_1 = ((int) 4) - ((int) var17_1);
    var31_2 = ((int) 4) - ((int) var17_2);
    *var27_1 = (unsigned char) ((((unsigned int) var28_1) << ((unsigned int) var17_1)) | (((unsigned int) var21_1) >> var31_1));
    *var27_2 = (unsigned char) ((((unsigned int) var28_2) << ((unsigned int) var17_2)) | (((unsigned int) var21_2) >> var31_2));
    var32_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar2[0];
    var32_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar2[0];
    var33_1 = *var32_1;
    var33_2 = *var32_2;
    var34_1 = var33_1 & var18_1;
    var34_2 = var33_2 & var18_2;
    var35_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar2[1];
    var35_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar2[1];
    var36_1 = *var35_1;
    var36_2 = *var35_2;
    var37_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar2[2];
    var37_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar2[2];
    var38_1 = *var37_1;
    var38_2 = *var37_2;
    var39_1 = var38_1 & var18_1;
    var39_2 = var38_2 & var18_2;
    var40_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar2[3];
    var40_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar2[3];
    var41_1 = *var40_1;
    var41_2 = *var40_2;
    var42_1 = var41_1 & var18_1;
    var42_2 = var41_2 & var18_2;
    *var32_1 = (unsigned char) ((((unsigned int) (var36_1 & var18_1)) >> var30_1) | (((unsigned int) var33_1) << ((unsigned int) var17_1)));
    *var32_2 = (unsigned char) ((((unsigned int) (var36_2 & var18_2)) >> var30_2) | (((unsigned int) var33_2) << ((unsigned int) var17_2)));
    *var35_1 = (unsigned char) ((((unsigned int) var39_1) >> var30_1) | (((unsigned int) var36_1) << ((unsigned int) var17_1)));
    *var35_2 = (unsigned char) ((((unsigned int) var39_2) >> var30_2) | (((unsigned int) var36_2) << ((unsigned int) var17_2)));
    *var37_1 = (unsigned char) ((((unsigned int) var42_1) >> var30_1) | (((unsigned int) var38_1) << ((unsigned int) var17_1)));
    *var37_2 = (unsigned char) ((((unsigned int) var42_2) >> var30_2) | (((unsigned int) var38_2) << ((unsigned int) var17_2)));
    *var40_1 = (unsigned char) ((((unsigned int) var41_1) << ((unsigned int) var17_1)) | (((unsigned int) var34_1) >> var31_1));
    *var40_2 = (unsigned char) ((((unsigned int) var41_2) << ((unsigned int) var17_2)) | (((unsigned int) var34_2) >> var31_2));
    var43_phi_1 = 0;
    var43_phi_2 = 0;
    do
    {
      var43_phi_1 = var53_1;
      var43_phi_2 = var53_2;
      var44_1 = sub_key_permutation_1[var43_phi_1];
      var44_2 = sub_key_permutation_2[var43_phi_2];
      if (((int) var44_1) < ((int) 29))
      {
        var45_1 = ((int) var44_1) + ((int) (-1));
        var46_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar1[(long) ((int) (((int) var45_1) / ((int) 8)))];
        var49_phi_1 = var46_1;
        var50_phi_1 = var45_1;
        goto block13_1;
      }
      else
      {
        var47_1 = ((int) var44_1) + ((int) (-29));
        var48_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar2[(unsigned long) (((int) var47_1) / ((int) 8))];
        var49_phi_1 = var48_1;
        var50_phi_1 = var47_1;
        goto block13_1;
      }
      if (((int) var44_2) < ((int) 29))
      {
        var45_2 = ((int) var44_2) + ((int) (-1));
        var46_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar1[(long) ((int) (((int) var45_2) / ((int) 8)))];
        var49_phi_2 = var46_2;
        var50_phi_2 = var45_2;
        goto block13_2;
      }
      else
      {
        var47_2 = ((int) var44_2) + ((int) (-29));
        var48_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar2[(unsigned long) (((int) var47_2) / ((int) 8))];
        var49_phi_2 = var48_2;
        var50_phi_2 = var47_2;
        goto block13_2;
      }
      block13_1:
      var51_1 = ((int) var50_phi_1) % ((int) 8);

      block13_2:
      var51_2 = ((int) var50_phi_2) % ((int) 8);

      var52_1 = &(*(((struct s_key_set *) var1_1) + var13_phi_1)).structVar0[(var43_phi_1 >> 3) & 536870911];
      var52_2 = &(*(((struct s_key_set *) var1_2) + var13_phi_2)).structVar0[(var43_phi_2 >> 3) & 536870911];
      *var52_1 = (*var52_1) | ((unsigned char) (((((unsigned int) ((*var49_phi_1) & ((unsigned char) (128 >> var51_1)))) << ((unsigned int) var51_1)) & 255) >> (((unsigned int) var43_phi_1) & 7)));
      *var52_2 = (*var52_2) | ((unsigned char) (((((unsigned int) ((*var49_phi_2) & ((unsigned char) (128 >> var51_2)))) << ((unsigned int) var51_2)) & 255) >> (((unsigned int) var43_phi_2) & 7)));
      var53_1++;
      var53_2++;
    }
    while ((var53_1 == 48) && (var53_2 == 48));
    goto block14_1;
    goto block14_2;
    block14_1:
    var54_1++;

    block14_2:
    var54_2++;

  }
  while ((var54_1 == 17) && (var54_2 == 17));
  for (int i_0 = 0; i_0 < 56; i_0++)
  {
    assert(initial_key_permutaion_1[i_0] == initial_key_permutaion_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 17; i_0++)
  {
    assert(key_shift_sizes_1[i_0] == key_shift_sizes_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 48; i_0++)
  {
    assert(sub_key_permutation_1[i_0] == sub_key_permutation_2[i_0]);
  }

  assert(var2_phi_1 == var2_phi_2);
  assert(var7_phi_1 == var7_phi_2);
  assert(var9_phi_1 == var9_phi_2);
  assert(var13_phi_1 == var13_phi_2);
  assert(var15_phi_1 == var15_phi_2);
  assert(var43_phi_1 == var43_phi_2);
  assert((*var49_phi_1) == (*var49_phi_2));
  assert(var50_phi_1 == var50_phi_2);
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert((*var5_1) == (*var5_2));
  assert(var6_1 == var6_2);
  assert(var8_1 == var8_2);
  assert(var10_1 == var10_2);
  assert((*var11_1) == (*var11_2));
  assert(var12_1 == var12_2);
  assert(var14_1 == var14_2);
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert((*var19_1) == (*var19_2));
  assert(var20_1 == var20_2);
  assert(var21_1 == var21_2);
  assert((*var22_1) == (*var22_2));
  assert(var23_1 == var23_2);
  assert((*var24_1) == (*var24_2));
  assert(var25_1 == var25_2);
  assert(var26_1 == var26_2);
  assert((*var27_1) == (*var27_2));
  assert(var28_1 == var28_2);
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert(var31_1 == var31_2);
  assert((*var32_1) == (*var32_2));
  assert(var33_1 == var33_2);
  assert(var34_1 == var34_2);
  assert((*var35_1) == (*var35_2));
  assert(var36_1 == var36_2);
  assert((*var37_1) == (*var37_2));
  assert(var38_1 == var38_2);
  assert(var39_1 == var39_2);
  assert((*var40_1) == (*var40_2));
  assert(var41_1 == var41_2);
  assert(var42_1 == var42_2);
  assert(var44_1 == var44_2);
  assert(var45_1 == var45_2);
  assert((*var46_1) == (*var46_2));
  assert(var47_1 == var47_2);
  assert((*var48_1) == (*var48_2));
  assert(var51_1 == var51_2);
  assert((*var52_1) == (*var52_2));
  assert(var53_1 == var53_2);
  assert(var54_1 == var54_2);
}

void generate_sub_keys(unsigned char *var0, struct s_key_set *var1)
{
  unsigned long var2_phi;
  unsigned long var7_phi;
  unsigned long var9_phi;
  unsigned long var13_phi;
  unsigned long var15_phi;
  unsigned long var43_phi;
  unsigned char *var49_phi;
  unsigned int var50_phi;
  int var3;
  int var4;
  unsigned char *var5;
  long var6=0;
  long var8=0;
  unsigned char var10;
  unsigned char *var11;
  long var12=0;
  long var14;
  long var16=0;
  unsigned int var17;
  unsigned char var18;
  unsigned char *var19;
  unsigned char var20;
  unsigned char var21;
  unsigned char *var22;
  unsigned char var23;
  unsigned char *var24;
  unsigned char var25;
  unsigned char var26;
  unsigned char *var27;
  unsigned char var28;
  unsigned char var29;
  int var30;
  int var31;
  unsigned char *var32;
  unsigned char var33;
  unsigned char var34;
  unsigned char *var35;
  unsigned char var36;
  unsigned char *var37;
  unsigned char var38;
  unsigned char var39;
  unsigned char *var40;
  unsigned char var41;
  unsigned char var42;
  unsigned int var44;
  int var45;
  unsigned char *var46;
  int var47;
  unsigned char *var48;
  int var51;
  unsigned char *var52;
  long var53=0;
  long var54=0;
  block0:
  *((unsigned long *) var1) = 0;

  var2_phi = 0;
  do
  {
    var2_phi = var6;
    var3 = ((int) initial_key_permutaion[var2_phi]) + ((int) (-1));
    var4 = ((int) var3) % ((int) 8);
    var5 = &var1->structVar0[(var2_phi >> 3) & 536870911];
    *var5 = (*var5) | ((unsigned char) (((((unsigned int) ((*(((unsigned char *) var0) + ((long) ((int) (((int) var3) / ((int) 8)))))) & ((unsigned char) (128 >> var4)))) << ((unsigned int) var4)) & 255) >> (((unsigned int) var2_phi) & 7)));
    var6++;
  }
  while (var6 == 56);
  var7_phi = 0;
  do
  {
    var7_phi = var8;
    var1->structVar1[var7_phi] = var1->structVar0[var7_phi];
    var8++;
  }
  while (var8 == 3);
  var1->structVar1[3] = var1->structVar0[3] & (-16);
  var9_phi = 0;
  do
  {
    var9_phi = var12;
    var10 = var1->structVar0[((long) var9_phi) + ((long) 3)] << ((unsigned char) 4);
    var11 = &var1->structVar2[var9_phi];
    *var11 = var10;
    *var11 = (var1->structVar0[((long) var9_phi) + ((long) 4)] >> 4) | var10;
    var12++;
  }
  while (var12 == 3);
  var1->structVar2[3] = var1->structVar0[6] << ((unsigned char) 4);
  var13_phi = 1;
  do
  {
    var13_phi = var54;
    var14 = ((long) var13_phi) + ((long) (-1));
    var15_phi = 0;
    do
    {
      var15_phi = var16;
      (*(((struct s_key_set *) var1) + var13_phi)).structVar1[var15_phi] = (*(((struct s_key_set *) var1) + var14)).structVar1[var15_phi];
      (*(((struct s_key_set *) var1) + var13_phi)).structVar2[var15_phi] = (*(((struct s_key_set *) var1) + var14)).structVar2[var15_phi];
      var16++;
    }
    while (var16 == 4);
    var17 = key_shift_sizes[var13_phi];
    var18 = (var17 == 1) ? (-128) : (-64);
    var19 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar1[0];
    var20 = *var19;
    var21 = var18 & var20;
    var22 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar1[1];
    var23 = *var22;
    var24 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar1[2];
    var25 = *var24;
    var26 = var25 & var18;
    var27 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar1[3];
    var28 = *var27;
    var29 = var28 & var18;
    var30 = ((int) 8) - ((int) var17);
    *var19 = (unsigned char) ((((unsigned int) (var23 & var18)) >> var30) | (((unsigned int) var20) << ((unsigned int) var17)));
    *var22 = (unsigned char) ((((unsigned int) var26) >> var30) | (((unsigned int) var23) << ((unsigned int) var17)));
    *var24 = (unsigned char) ((((unsigned int) var29) >> var30) | (((unsigned int) var25) << ((unsigned int) var17)));
    var31 = ((int) 4) - ((int) var17);
    *var27 = (unsigned char) ((((unsigned int) var28) << ((unsigned int) var17)) | (((unsigned int) var21) >> var31));
    var32 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar2[0];
    var33 = *var32;
    var34 = var33 & var18;
    var35 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar2[1];
    var36 = *var35;
    var37 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar2[2];
    var38 = *var37;
    var39 = var38 & var18;
    var40 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar2[3];
    var41 = *var40;
    var42 = var41 & var18;
    *var32 = (unsigned char) ((((unsigned int) (var36 & var18)) >> var30) | (((unsigned int) var33) << ((unsigned int) var17)));
    *var35 = (unsigned char) ((((unsigned int) var39) >> var30) | (((unsigned int) var36) << ((unsigned int) var17)));
    *var37 = (unsigned char) ((((unsigned int) var42) >> var30) | (((unsigned int) var38) << ((unsigned int) var17)));
    *var40 = (unsigned char) ((((unsigned int) var41) << ((unsigned int) var17)) | (((unsigned int) var34) >> var31));
    var43_phi = 0;
    do
    {
      var43_phi = var53;
      var44 = sub_key_permutation[var43_phi];
      if (((int) var44) < ((int) 29))
      {
        var45 = ((int) var44) + ((int) (-1));
        var46 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar1[(long) ((int) (((int) var45) / ((int) 8)))];
        var49_phi = var46;
        var50_phi = var45;
        goto block13;
      }
      else
      {
        var47 = ((int) var44) + ((int) (-29));
        var48 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar2[(unsigned long) (((int) var47) / ((int) 8))];
        var49_phi = var48;
        var50_phi = var47;
        goto block13;
      }
      block13:
      var51 = ((int) var50_phi) % ((int) 8);

      var52 = &(*(((struct s_key_set *) var1) + var13_phi)).structVar0[(var43_phi >> 3) & 536870911];
      *var52 = (*var52) | ((unsigned char) (((((unsigned int) ((*var49_phi) & ((unsigned char) (128 >> var51)))) << ((unsigned int) var51)) & 255) >> (((unsigned int) var43_phi) & 7)));
      var53++;
    }
    while (var53 == 48);
    goto block14;
    block14:
    var54++;

  }
  while (var54 == 17);
  return;
}

void main(void)
{
  for (int i_0 = 0; i_0 < 1000; i_0++)
  {
    key_sets_1[i_0] = nd_key_sets();
  }

  for (int i_0 = 0; i_0 < 1000; i_0++)
  {
    key_sets_2[i_0] = nd_key_sets();
  }

  struct s_key_set key_sets_1[10];
  struct s_key_set key_sets_2[10];
  unsigned char des_key_1[32];
  unsigned char des_key_2[32];
  unsigned char data_block_1[32];
  unsigned char data_block_2[32];
  unsigned char processed_block_1[32];
  unsigned char processed_block_2[32];
  unsigned char *var4_1;
  unsigned char *var4_2;
  unsigned char *var5_1;
  unsigned char *var5_2;
  unsigned char *var6_1;
  unsigned char *var6_2;
  unsigned char *var7_1;
  unsigned char *var7_2;
  struct s_key_set *var8_1;
  struct s_key_set *var8_2;
  unsigned char *var9_1;
  unsigned char *var9_2;
  unsigned char *var10_1;
  unsigned char *var10_2;
  block0_1:
  var4_1 = &key_sets_1[0].structVar0[0];
  var9_1= &key_sets_1[0].structVar1[0];
  var10_1= &key_sets_1[0].structVar2[0];

  block0_2:
  var4_2 = &key_sets_2[0].structVar0[0];
  var9_1= &key_sets_1[0].structVar1[0];
  var10_1= &key_sets_1[0].structVar2[0];
		
  var5_1 = &des_key_1[0];
  var5_2 = &des_key_2[0];
  var6_1 = &data_block_1[0];
  var6_2 = &data_block_2[0];
  var7_1 = &processed_block_1[0];
  var7_2 = &processed_block_2[0];
  var8_1 = &key_sets_1[0];
  var8_2 = &key_sets_2[0];
  generate_sub_keys(var5_1, var8_1);
  generate_sub_keys(var5_2, var8_2);
  generate_sub_keys_2(var5_1, var8_1, var5_2, var8_2);
  process_message(var6_1, var7_1, var8_1, 1);
  process_message(var6_2, var7_2, var8_2, 1);
  process_message_2(var6_1, var7_1, var8_1, 1, var6_2, var7_2, var8_2, 1);
  for (int i_0 = 0; i_0 < 1000; i_0++)
  {
    __CPROVER_assume(key_sets_1[i_0] != key_sets_2[i_0]);
  }
  for (int i_1 = 0; i_1 < 1000; i_1++)
  {
    __CPROVER_assume(key_sets_1[i_1] != key_sets_2[i_1]);
  }
  for (int i_2 = 0; i_2 < 1000; i_2++)
  {
    __CPROVER_assume(key_sets_1[i_2] != key_sets_2[i_2]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    __CPROVER_assume(data_block_1[i_0] == data_block_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    __CPROVER_assume(des_key_1[i_0] != des_key_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(processed_block_1[i_0] == processed_block_2[i_0]);
  }

  assert((*var4_1) == (*var4_2));
  assert((*var5_1) == (*var5_2));
  assert((*var6_1) == (*var6_2));
  assert((*var7_1) == (*var7_2));
  assert((*var8_1) == (*var8_2));
  assert((*var9_1) == (*var9_2));
  assert((*var10_1) == (*var10_2));
  }

void process_message_2(unsigned char *var0_1, unsigned char *var1_1, struct s_key_set *var2_1, unsigned int var3_1, unsigned char *var0_2, unsigned char *var1_2, struct s_key_set *var2_2, unsigned int var3_2)
{
  unsigned long var4_1;
  unsigned long var4_2;
  unsigned int var5_1;
  unsigned int var5_2;
  unsigned int var6_1;
  unsigned int var6_2;
  unsigned int var7_1;
  unsigned int var7_2;
  unsigned char var8_1[6];
  unsigned char var8_2[6];
  unsigned int var9_1;
  unsigned int var9_2;
  unsigned char var10_1[8];
  unsigned char var10_2[8];
  unsigned char *var11_1;
  unsigned char *var11_2;
  unsigned char (*var12_1)[8];
  unsigned char (*var12_2)[8];
  unsigned char (*var13_1)[4];
  unsigned char (*var13_2)[4];
  unsigned char (*var14_1)[4];
  unsigned char (*var14_2)[4];
  unsigned char (*var15_1)[4];
  unsigned char (*var15_2)[4];
  unsigned char *var16_1;
  unsigned char *var16_2;
  unsigned long var17_phi_1;
  unsigned long var17_phi_2;
  unsigned int var37_phi_1;
  unsigned int var37_phi_2;
  unsigned long var39_phi_1;
  unsigned long var39_phi_2;
  unsigned long var45_phi_1;
  unsigned long var45_phi_2;
  unsigned long var58_phi_1;
  unsigned long var58_phi_2;
  unsigned long var63_phi_1;
  unsigned long var63_phi_2;
  unsigned long var68_phi_1;
  unsigned long var68_phi_2;
  int var18_1;
  int var18_2;
  int var19_1;
  int var19_2;
  unsigned char *var20_1;
  unsigned char *var20_2;
  long var21_1=1;
  long var21_2=1;
  unsigned char (*var22_1)[4];
  unsigned char (*var22_2)[4];
  unsigned char *var23_1;
  unsigned char *var23_2;
  unsigned char *var24_1;
  unsigned char *var24_2;
  unsigned char *var25_1;
  unsigned char *var25_2;
  unsigned char *var26_1;
  unsigned char *var26_2;
  unsigned char *var27_1;
  unsigned char *var27_2;
  unsigned int var28_1;
  unsigned int var28_2;
  unsigned char *var29_1;
  unsigned char *var29_2;
  unsigned char *var30_1;
  unsigned char *var30_2;
  unsigned char *var31_1;
  unsigned char *var31_2;
  unsigned char *var32_1;
  unsigned char *var32_2;
  unsigned char *var33_1;
  unsigned char *var33_2;
  unsigned char *var34_1;
  unsigned char *var34_2;
  unsigned char *var35_1;
  unsigned char *var35_2;
  unsigned char *var36_1;
  unsigned char *var36_2;
  unsigned int var38_1;
  unsigned int var38_2;
  int var40_1;
  int var40_2;
  int var41_1;
  int var41_2;
  unsigned char *var42_1;
  unsigned char *var42_2;
  long var43_1=0;
  long var43_2=0;
  long var44_1;
  long var44_2;
  unsigned char *var46_1;
  unsigned char *var46_2;
  long var47_1=0;
  long var47_2=0;
  unsigned char var48_1;
  unsigned char var48_2;
  unsigned char var49_1;
  unsigned char var49_2;
  unsigned char var50_1;
  unsigned char var50_2;
  unsigned char var51_1;
  unsigned char var51_2;
  unsigned char var52_1;
  unsigned char var52_2;
  unsigned char var53_1;
  unsigned char var53_2;
  unsigned char var54_1;
  unsigned char var54_2;
  unsigned char var55_1;
  unsigned char var55_2;
  unsigned char var56_1;
  unsigned char var56_2;
  unsigned char var57_1;
  unsigned char var57_2;
  int var59_1;
  int var59_2;
  int var60_1;
  int var60_2;
  unsigned char *var61_1;
  unsigned char *var61_2;
  long var62_1=0;
  long var62_2=0;
  unsigned char *var64_1;
  unsigned char *var64_2;
  long var65_1=0;
  long var65_2=0;
  int var66_1=0;
  int var66_2=0;
  unsigned char *var67_1;
  unsigned char *var67_2;
  int var69_1;
  int var69_2;
  int var70_1;
  int var70_2;
  unsigned char *var71_1;
  unsigned char *var71_2;
  long var72_1=0;
  long var72_2=0;
  block0_1:
  var11_1 = (unsigned char *) (&var4_1);

  block0_2:
  var11_2 = (unsigned char *) (&var4_2);

  var12_1 = (unsigned char (*)[8]) (&var4_1);
  var12_2 = (unsigned char (*)[8]) (&var4_2);
  var13_1 = (unsigned char (*)[4]) (&var5_1);
  var13_2 = (unsigned char (*)[4]) (&var5_2);
  var14_1 = (unsigned char (*)[4]) (&var7_1);
  var14_2 = (unsigned char (*)[4]) (&var7_2);
  var15_1 = (unsigned char (*)[4]) (&var9_1);
  var15_2 = (unsigned char (*)[4]) (&var9_2);
  var16_1 = (unsigned char *) (&var4_1);
  var16_2 = (unsigned char *) (&var4_2);
  var4_1 = 0;
  var4_2 = 0;
  *((unsigned long *) var1_1) = 0;
  *((unsigned long *) var1_2) = 0;
  var17_phi_1 = 0;
  var17_phi_2 = 0;
  do
  {
    var17_phi_1 = var21_1;
    var17_phi_2 = var21_2;
    var18_1 = ((int) initial_message_permutation_1[var17_phi_1]) + ((int) (-1));
    var18_2 = ((int) initial_message_permutation_2[var17_phi_2]) + ((int) (-1));
    var19_1 = ((int) var18_1) % ((int) 8);
    var19_2 = ((int) var18_2) % ((int) 8);
    var20_1 = &(*var12_1)[(var17_phi_1 >> 3) & 536870911];
    var20_2 = &(*var12_2)[(var17_phi_2 >> 3) & 536870911];
    *var20_1 = (*var20_1) | ((unsigned char) (((((unsigned int) ((*(((unsigned char *) var0_1) + ((long) ((int) (((int) var18_1) / ((int) 8)))))) & ((unsigned char) (128 >> var19_1)))) << ((unsigned int) var19_1)) & 255) >> (((unsigned int) var17_phi_1) & 7)));
    *var20_2 = (*var20_2) | ((unsigned char) (((((unsigned int) ((*(((unsigned char *) var0_2) + ((long) ((int) (((int) var18_2) / ((int) 8)))))) & ((unsigned char) (128 >> var19_2)))) << ((unsigned int) var19_2)) & 255) >> (((unsigned int) var17_phi_2) & 7)));
    var21_1++;
    var21_2++;
  }
  while ((var21_1 == 64) && (var21_2 == 64));
  var22_1 = (unsigned char (*)[4]) (&var6_1);
  var22_2 = (unsigned char (*)[4]) (&var6_2);
  var23_1 = (unsigned char *) (&var5_1);
  var23_2 = (unsigned char *) (&var5_2);
  var24_1 = (unsigned char *) (&var6_1);
  var24_2 = (unsigned char *) (&var6_2);
  var5_1 = *((unsigned int *) (&var4_1));
  var5_2 = *((unsigned int *) (&var4_2));
  var6_1 = *((unsigned int *) (&(*(((unsigned char *) var11_1) + 4))));
  var6_2 = *((unsigned int *) (&(*(((unsigned char *) var11_2) + 4))));
  var25_1 = (unsigned char *) (&var7_1);
  var25_2 = (unsigned char *) (&var7_2);
  var26_1 = &var8_1[0];
  var26_2 = &var8_2[0];
  var27_1 = (unsigned char *) (&var9_1);
  var27_2 = (unsigned char *) (&var9_2);
  var28_1 = var3_1 == 0;
  var28_2 = var3_2 == 0;
  var29_1 = &var8_1[1];
  var29_2 = &var8_2[1];
  var30_1 = &var8_1[2];
  var30_2 = &var8_2[2];
  var31_1 = &(*var15_1)[1];
  var31_2 = &(*var15_2)[1];
  var32_1 = &var8_1[3];
  var32_2 = &var8_2[3];
  var33_1 = &(*var15_1)[2];
  var33_2 = &(*var15_2)[2];
  var34_1 = &var8_1[4];
  var34_2 = &var8_2[4];
  var35_1 = &var8_1[5];
  var35_2 = &var8_2[5];
  var36_1 = &(*var15_1)[3];
  var36_2 = &(*var15_2)[3];
  var37_phi_1 = 1;
  var37_phi_2 = 1;
  do
  {
    var37_phi_1 = var66_1;
    var37_phi_2 = var66_2;
    var38_1 = var6_1;
    var38_2 = var6_2;
    memset(var26_1, 0, 6);
    memset(var26_2, 0, 6);
    memset_2(var26_1, 0, 6, var26_2, 0, 6);
    var39_phi_1 = 0;
    var39_phi_2 = 0;
    do
    {
      var39_phi_1 = var43_1;
      var39_phi_2 = var43_2;
      var40_1 = ((int) message_expansion_1[var39_phi_1]) + ((int) (-1));
      var40_2 = ((int) message_expansion_2[var39_phi_2]) + ((int) (-1));
      var41_1 = ((int) var40_1) % ((int) 8);
      var41_2 = ((int) var40_2) % ((int) 8);
      var42_1 = &var8_1[(var39_phi_1 >> 3) & 536870911];
      var42_2 = &var8_2[(var39_phi_2 >> 3) & 536870911];
      *var42_1 = (*var42_1) | ((unsigned char) (((((unsigned int) ((*var22_1)[(long) ((int) (((int) var40_1) / ((int) 8)))] & ((unsigned char) (128 >> var41_1)))) << ((unsigned int) var41_1)) & 255) >> (((unsigned int) var39_phi_1) & 7)));
      *var42_2 = (*var42_2) | ((unsigned char) (((((unsigned int) ((*var22_2)[(long) ((int) (((int) var40_2) / ((int) 8)))] & ((unsigned char) (128 >> var41_2)))) << ((unsigned int) var41_2)) & 255) >> (((unsigned int) var39_phi_2) & 7)));
      var43_1++;
      var43_2++;
    }
    while ((var43_1 == 48) && (var43_2 == 48));
    var44_1 = (long) ((int) ((var28_1) ? (((int) 17) - ((int) var37_phi_1)) : (var37_phi_1)));
    var44_2 = (long) ((int) ((var28_2) ? (((int) 17) - ((int) var37_phi_2)) : (var37_phi_2)));
    var45_phi_1 = 0;
    var45_phi_2 = 0;
    do
    {
      var45_phi_1 = var47_1;
      var45_phi_2 = var47_2;
      var46_1 = &var8_1[var45_phi_1];
      var46_2 = &var8_2[var45_phi_2];
      *var46_1 = (*var46_1) ^ (*(((struct s_key_set *) var2_1) + var44_1)).structVar0[var45_phi_1];
      *var46_2 = (*var46_2) ^ (*(((struct s_key_set *) var2_2) + var44_2)).structVar0[var45_phi_2];
      var47_1++;
      var47_2++;
    }
    while ((var47_1 == 6) && (var47_2 == 6));
    var9_1 = 0;
    var9_2 = 0;
    var48_1 = *var26_1;
    var48_2 = *var26_2;
    var49_1 = (((unsigned char) S1_1[(unsigned long) ((((char) (((var48_1 >> 2) & 1) | ((var48_1 >> 6) & 2))) << ((char) ((unsigned char) ((char) 4)))) | ((var48_1 >> 3) & 15))]) << ((unsigned char) 4)) | (*var27_1);
    var49_2 = (((unsigned char) S1_2[(unsigned long) ((((char) (((var48_2 >> 2) & 1) | ((var48_2 >> 6) & 2))) << ((char) ((unsigned char) ((char) 4)))) | ((var48_2 >> 3) & 15))]) << ((unsigned char) 4)) | (*var27_2);
    *var27_1 = var49_1;
    *var27_2 = var49_2;
    var50_1 = *var29_1;
    var50_2 = *var29_2;
    *var27_1 = var49_1 | ((unsigned char) S2_1[(unsigned long) (((((var48_1 << ((unsigned char) 3)) & 8) | ((var48_1 << ((unsigned char) 4)) & 32)) | (var50_1 & 16)) | (var50_1 >> 5))]);
    *var27_2 = var49_2 | ((unsigned char) S2_2[(unsigned long) (((((var48_2 << ((unsigned char) 3)) & 8) | ((var48_2 << ((unsigned char) 4)) & 32)) | (var50_2 & 16)) | (var50_2 >> 5))]);
    var51_1 = *var30_1;
    var51_2 = *var30_2;
    var52_1 = (((unsigned char) S3_1[(unsigned long) ((((char) (((var51_1 >> 6) & 1) | ((var50_1 >> 2) & 2))) << ((char) ((unsigned char) ((char) 4)))) | (((var50_1 << ((unsigned char) 1)) & 14) | (var51_1 >> 7)))]) << ((unsigned char) 4)) | (*var31_1);
    var52_2 = (((unsigned char) S3_2[(unsigned long) ((((char) (((var51_2 >> 6) & 1) | ((var50_2 >> 2) & 2))) << ((char) ((unsigned char) ((char) 4)))) | (((var50_2 << ((unsigned char) 1)) & 14) | (var51_2 >> 7)))]) << ((unsigned char) 4)) | (*var31_2);
    *var31_1 = var52_1;
    *var31_2 = var52_2;
    *var31_1 = var52_1 | ((unsigned char) S4_1[(unsigned long) ((((var51_1 << ((unsigned char) 4)) & 16) | (var51_1 & 32)) | ((var51_1 >> 1) & 15))]);
    *var31_2 = var52_2 | ((unsigned char) S4_2[(unsigned long) ((((var51_2 << ((unsigned char) 4)) & 16) | (var51_2 & 32)) | ((var51_2 >> 1) & 15))]);
    var53_1 = *var32_1;
    var53_2 = *var32_2;
    var54_1 = (((unsigned char) S5_1[(unsigned long) ((((char) (((var53_1 >> 2) & 1) | ((var53_1 >> 6) & 2))) << ((char) ((unsigned char) ((char) 4)))) | ((var53_1 >> 3) & 15))]) << ((unsigned char) 4)) | (*var33_1);
    var54_2 = (((unsigned char) S5_2[(unsigned long) ((((char) (((var53_2 >> 2) & 1) | ((var53_2 >> 6) & 2))) << ((char) ((unsigned char) ((char) 4)))) | ((var53_2 >> 3) & 15))]) << ((unsigned char) 4)) | (*var33_2);
    *var33_1 = var54_1;
    *var33_2 = var54_2;
    var55_1 = *var34_1;
    var55_2 = *var34_2;
    *var33_1 = var54_1 | ((unsigned char) S6_1[(unsigned long) (((((var53_1 << ((unsigned char) 3)) & 8) | ((var53_1 << ((unsigned char) 4)) & 32)) | (var55_1 & 16)) | (var55_1 >> 5))]);
    *var33_2 = var54_2 | ((unsigned char) S6_2[(unsigned long) (((((var53_2 << ((unsigned char) 3)) & 8) | ((var53_2 << ((unsigned char) 4)) & 32)) | (var55_2 & 16)) | (var55_2 >> 5))]);
    var56_1 = *var35_1;
    var56_2 = *var35_2;
    var57_1 = (((unsigned char) S7_1[(unsigned long) ((((char) (((var56_1 >> 6) & 1) | ((var55_1 >> 2) & 2))) << ((char) ((unsigned char) ((char) 4)))) | (((var55_1 << ((unsigned char) 1)) & 14) | (var56_1 >> 7)))]) << ((unsigned char) 4)) | (*var36_1);
    var57_2 = (((unsigned char) S7_2[(unsigned long) ((((char) (((var56_2 >> 6) & 1) | ((var55_2 >> 2) & 2))) << ((char) ((unsigned char) ((char) 4)))) | (((var55_2 << ((unsigned char) 1)) & 14) | (var56_2 >> 7)))]) << ((unsigned char) 4)) | (*var36_2);
    *var36_1 = var57_1;
    *var36_2 = var57_2;
    *var36_1 = var57_1 | ((unsigned char) S8_1[(unsigned long) ((((var56_1 << ((unsigned char) 4)) & 16) | (var56_1 & 32)) | ((var56_1 >> 1) & 15))]);
    *var36_2 = var57_2 | ((unsigned char) S8_2[(unsigned long) ((((var56_2 << ((unsigned char) 4)) & 16) | (var56_2 & 32)) | ((var56_2 >> 1) & 15))]);
    var7_1 = 0;
    var7_2 = 0;
    var58_phi_1 = 0;
    var58_phi_2 = 0;
    do
    {
      var58_phi_1 = var62_1;
      var58_phi_2 = var62_2;
      var59_1 = ((int) right_sub_message_permutation_1[var58_phi_1]) + ((int) (-1));
      var59_2 = ((int) right_sub_message_permutation_2[var58_phi_2]) + ((int) (-1));
      var60_1 = ((int) var59_1) % ((int) 8);
      var60_2 = ((int) var59_2) % ((int) 8);
      var61_1 = &(*var14_1)[(var58_phi_1 >> 3) & 536870911];
      var61_2 = &(*var14_2)[(var58_phi_2 >> 3) & 536870911];
      *var61_1 = (*var61_1) | ((unsigned char) (((((unsigned int) ((*var15_1)[(long) ((int) (((int) var59_1) / ((int) 8)))] & ((unsigned char) (128 >> var60_1)))) << ((unsigned int) var60_1)) & 255) >> (((unsigned int) var58_phi_1) & 7)));
      *var61_2 = (*var61_2) | ((unsigned char) (((((unsigned int) ((*var15_2)[(long) ((int) (((int) var59_2) / ((int) 8)))] & ((unsigned char) (128 >> var60_2)))) << ((unsigned int) var60_2)) & 255) >> (((unsigned int) var58_phi_2) & 7)));
      var62_1++;
      var62_2++;
    }
    while ((var62_1 == 32) && (var62_2 == 32));
    var63_phi_1 = 0;
    var63_phi_2 = 0;
    do
    {
      var63_phi_1 = var65_1;
      var63_phi_2 = var65_2;
      var64_1 = &(*var14_1)[var63_phi_1];
      var64_2 = &(*var14_2)[var63_phi_2];
      *var64_1 = (*var64_1) ^ (*var13_1)[var63_phi_1];
      *var64_2 = (*var64_2) ^ (*var13_2)[var63_phi_2];
      var65_1++;
      var65_2++;
    }
    while ((var65_1 == 4) && (var65_2 == 4));
    goto block11_1;
    goto block11_2;
    block11_1:
    var5_1 = var38_1;

    block11_2:
    var5_2 = var38_2;

    var6_1 = var7_1;
    var6_2 = var7_2;
    var66_1++;
    var66_2++;
  }
  while ((var66_1 == 17) && (var66_2 == 17));
  var67_1 = &var10_1[0];
  var67_2 = &var10_2[0];
  *((unsigned int *) (&var10_1)) = var7_1;
  *((unsigned int *) (&var10_2)) = var7_2;
  *((unsigned int *) (&var10_1[4])) = var5_1;
  *((unsigned int *) (&var10_2[4])) = var5_2;
  var68_phi_1 = 0;
  var68_phi_2 = 0;
  do
  {
    var68_phi_1 = var72_1;
    var68_phi_2 = var72_2;
    var69_1 = ((int) final_message_permutation_1[var68_phi_1]) + ((int) (-1));
    var69_2 = ((int) final_message_permutation_2[var68_phi_2]) + ((int) (-1));
    var70_1 = ((int) var69_1) % ((int) 8);
    var70_2 = ((int) var69_2) % ((int) 8);
    var71_1 = &(*(((unsigned char *) var1_1) + ((var68_phi_1 >> 3) & 536870911)));
    var71_2 = &(*(((unsigned char *) var1_2) + ((var68_phi_2 >> 3) & 536870911)));
    *var71_1 = (*var71_1) | ((unsigned char) (((((unsigned int) (var10_1[(long) ((int) (((int) var69_1) / ((int) 8)))] & ((unsigned char) (128 >> var70_1)))) << ((unsigned int) var70_1)) & 255) >> (((unsigned int) var68_phi_1) & 7)));
    *var71_2 = (*var71_2) | ((unsigned char) (((((unsigned int) (var10_2[(long) ((int) (((int) var69_2) / ((int) 8)))] & ((unsigned char) (128 >> var70_2)))) << ((unsigned int) var70_2)) & 255) >> (((unsigned int) var68_phi_2) & 7)));
    var72_1++;
    var72_2++;
  }
  while ((var72_1 == 64) && (var72_2 == 64));
  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(initial_message_permutation_1[i_0] == initial_message_permutation_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 48; i_0++)
  {
    assert(message_expansion_1[i_0] == message_expansion_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S1_1[i_0] == S1_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S2_1[i_0] == S2_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S3_1[i_0] == S3_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S4_1[i_0] == S4_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S5_1[i_0] == S5_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S6_1[i_0] == S6_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S7_1[i_0] == S7_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(S8_1[i_0] == S8_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(right_sub_message_permutation_1[i_0] == right_sub_message_permutation_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(final_message_permutation_1[i_0] == final_message_permutation_2[i_0]);
  }

  assert(var4_1 == var4_2);
  assert(var5_1 == var5_2);
  assert(var6_1 == var6_2);
  assert(var7_1 == var7_2);
  for (int i_0 = 0; i_0 < 6; i_0++)
  {
    assert(var8_1[i_0] == var8_2[i_0]);
  }

  assert(var9_1 == var9_2);
  for (int i_0 = 0; i_0 < 8; i_0++)
  {
    assert(var10_1[i_0] == var10_2[i_0]);
  }

  assert((*var11_1) == (*var11_2));
  assert((*var12_1) == (*var12_2));
  assert((*var13_1) == (*var13_2));
  assert((*var14_1) == (*var14_2));
  assert((*var15_1) == (*var15_2));
  assert((*var16_1) == (*var16_2));
  assert(var17_phi_1 == var17_phi_2);
  assert(var37_phi_1 == var37_phi_2);
  assert(var39_phi_1 == var39_phi_2);
  assert(var45_phi_1 == var45_phi_2);
  assert(var58_phi_1 == var58_phi_2);
  assert(var63_phi_1 == var63_phi_2);
  assert(var68_phi_1 == var68_phi_2);
  assert(var18_1 == var18_2);
  assert(var19_1 == var19_2);
  assert((*var20_1) == (*var20_2));
  assert(var21_1 == var21_2);
  assert((*var22_1) == (*var22_2));
  assert((*var23_1) == (*var23_2));
  assert((*var24_1) == (*var24_2));
  assert((*var25_1) == (*var25_2));
  assert((*var26_1) == (*var26_2));
  assert((*var27_1) == (*var27_2));
  assert(var28_1 == var28_2);
  assert((*var29_1) == (*var29_2));
  assert((*var30_1) == (*var30_2));
  assert((*var31_1) == (*var31_2));
  assert((*var32_1) == (*var32_2));
  assert((*var33_1) == (*var33_2));
  assert((*var34_1) == (*var34_2));
  assert((*var35_1) == (*var35_2));
  assert((*var36_1) == (*var36_2));
  assert(var38_1 == var38_2);
  assert(var40_1 == var40_2);
  assert(var41_1 == var41_2);
  assert((*var42_1) == (*var42_2));
  assert(var43_1 == var43_2);
  assert(var44_1 == var44_2);
  assert((*var46_1) == (*var46_2));
  assert(var47_1 == var47_2);
  assert(var48_1 == var48_2);
  assert(var49_1 == var49_2);
  assert(var50_1 == var50_2);
  assert(var51_1 == var51_2);
  assert(var52_1 == var52_2);
  assert(var53_1 == var53_2);
  assert(var54_1 == var54_2);
  assert(var55_1 == var55_2);
  assert(var56_1 == var56_2);
  assert(var57_1 == var57_2);
  assert(var59_1 == var59_2);
  assert(var60_1 == var60_2);
  assert((*var61_1) == (*var61_2));
  assert(var62_1 == var62_2);
  assert((*var64_1) == (*var64_2));
  assert(var65_1 == var65_2);
  assert(var66_1 == var66_2);
  assert((*var67_1) == (*var67_2));
  assert(var69_1 == var69_2);
  assert(var70_1 == var70_2);
  assert((*var71_1) == (*var71_2));
  assert(var72_1 == var72_2);
}

void process_message(unsigned char *var0, unsigned char *var1, struct s_key_set *var2, unsigned int var3)
{
  unsigned long var4;
  unsigned int var5;
  unsigned int var6;
  unsigned int var7;
  unsigned char var8[6];
  unsigned int var9;
  unsigned char var10[8];
  unsigned char *var11;
  unsigned char (*var12)[8];
  unsigned char (*var13)[4];
  unsigned char (*var14)[4];
  unsigned char (*var15)[4];
  unsigned char *var16;
  unsigned long var17_phi;
  unsigned int var37_phi;
  unsigned long var39_phi;
  unsigned long var45_phi;
  unsigned long var58_phi;
  unsigned long var63_phi;
  unsigned long var68_phi;
  int var18;
  int var19;
  unsigned char *var20;
  long var21=0;
  unsigned char (*var22)[4];
  unsigned char *var23;
  unsigned char *var24;
  unsigned char *var25;
  unsigned char *var26;
  unsigned char *var27;
  unsigned int var28;
  unsigned char *var29;
  unsigned char *var30;
  unsigned char *var31;
  unsigned char *var32;
  unsigned char *var33;
  unsigned char *var34;
  unsigned char *var35;
  unsigned char *var36;
  unsigned int var38;
  int var40;
  int var41;
  unsigned char *var42;
  long var43=0;
  long var44;
  unsigned char *var46;
  long var47=0;
  unsigned char var48;
  unsigned char var49;
  unsigned char var50;
  unsigned char var51;
  unsigned char var52;
  unsigned char var53;
  unsigned char var54;
  unsigned char var55;
  unsigned char var56;
  unsigned char var57;
  int var59;
  int var60;
  unsigned char *var61;
  long var62=0;
  unsigned char *var64;
  long var65=0;
  int var66=0;
  unsigned char *var67;
  int var69;
  int var70;
  unsigned char *var71;
  long var72=0;
  block0:
  var11 = (unsigned char *) (&var4);

  var12 = (unsigned char (*)[8]) (&var4);
  var13 = (unsigned char (*)[4]) (&var5);
  var14 = (unsigned char (*)[4]) (&var7);
  var15 = (unsigned char (*)[4]) (&var9);
  var16 = (unsigned char *) (&var4);
  var4 = 0;
  *((unsigned long *) var1) = 0;
  var17_phi = 0;
  do
  {
    var17_phi = var21;
    var18 = ((int) initial_message_permutation[var17_phi]) + ((int) (-1));
    var19 = ((int) var18) % ((int) 8);
    var20 = &(*var12)[(var17_phi >> 3) & 536870911];
    *var20 = (*var20) | ((unsigned char) (((((unsigned int) ((*(((unsigned char *) var0) + ((long) ((int) (((int) var18) / ((int) 8)))))) & ((unsigned char) (128 >> var19)))) << ((unsigned int) var19)) & 255) >> (((unsigned int) var17_phi) & 7)));
    var21++;
  }
  while (var21 == 64);
  var22 = (unsigned char (*)[4]) (&var6);
  var23 = (unsigned char *) (&var5);
  var24 = (unsigned char *) (&var6);
  var5 = *((unsigned int *) (&var4));
  var6 = *((unsigned int *) (&(*(((unsigned char *) var11) + 4))));
  var25 = (unsigned char *) (&var7);
  var26 = &var8[0];
  var27 = (unsigned char *) (&var9);
  var28 = var3 == 0;
  var29 = &var8[1];
  var30 = &var8[2];
  var31 = &(*var15)[1];
  var32 = &var8[3];
  var33 = &(*var15)[2];
  var34 = &var8[4];
  var35 = &var8[5];
  var36 = &(*var15)[3];
  var37_phi = 1;
  do
  {
    var37_phi = var66;
    var38 = var6;
    memset(var26, 0, 6);
    var39_phi = 0;
    do
    {
      var39_phi = var43;
      var40 = ((int) message_expansion[var39_phi]) + ((int) (-1));
      var41 = ((int) var40) % ((int) 8);
      var42 = &var8[(var39_phi >> 3) & 536870911];
      *var42 = (*var42) | ((unsigned char) (((((unsigned int) ((*var22)[(long) ((int) (((int) var40) / ((int) 8)))] & ((unsigned char) (128 >> var41)))) << ((unsigned int) var41)) & 255) >> (((unsigned int) var39_phi) & 7)));
      var43++;
    }
    while (var43 == 48);
    var44 = (long) ((int) ((var28) ? (((int) 17) - ((int) var37_phi)) : (var37_phi)));
    var45_phi = 0;
    do
    {
      var45_phi = var47;
      var46 = &var8[var45_phi];
      *var46 = (*var46) ^ (*(((struct s_key_set *) var2) + var44)).structVar0[var45_phi];
      var47++;
    }
    while (var47 == 6);
    var9 = 0;
    var48 = *var26;
    var49 = (((unsigned char) S1[(unsigned long) ((((char) (((var48 >> 2) & 1) | ((var48 >> 6) & 2))) << ((char) ((unsigned char) ((char) 4)))) | ((var48 >> 3) & 15))]) << ((unsigned char) 4)) | (*var27);
    *var27 = var49;
    var50 = *var29;
    *var27 = var49 | ((unsigned char) S2[(unsigned long) (((((var48 << ((unsigned char) 3)) & 8) | ((var48 << ((unsigned char) 4)) & 32)) | (var50 & 16)) | (var50 >> 5))]);
    var51 = *var30;
    var52 = (((unsigned char) S3[(unsigned long) ((((char) (((var51 >> 6) & 1) | ((var50 >> 2) & 2))) << ((char) ((unsigned char) ((char) 4)))) | (((var50 << ((unsigned char) 1)) & 14) | (var51 >> 7)))]) << ((unsigned char) 4)) | (*var31);
    *var31 = var52;
    *var31 = var52 | ((unsigned char) S4[(unsigned long) ((((var51 << ((unsigned char) 4)) & 16) | (var51 & 32)) | ((var51 >> 1) & 15))]);
    var53 = *var32;
    var54 = (((unsigned char) S5[(unsigned long) ((((char) (((var53 >> 2) & 1) | ((var53 >> 6) & 2))) << ((char) ((unsigned char) ((char) 4)))) | ((var53 >> 3) & 15))]) << ((unsigned char) 4)) | (*var33);
    *var33 = var54;
    var55 = *var34;
    *var33 = var54 | ((unsigned char) S6[(unsigned long) (((((var53 << ((unsigned char) 3)) & 8) | ((var53 << ((unsigned char) 4)) & 32)) | (var55 & 16)) | (var55 >> 5))]);
    var56 = *var35;
    var57 = (((unsigned char) S7[(unsigned long) ((((char) (((var56 >> 6) & 1) | ((var55 >> 2) & 2))) << ((char) ((unsigned char) ((char) 4)))) | (((var55 << ((unsigned char) 1)) & 14) | (var56 >> 7)))]) << ((unsigned char) 4)) | (*var36);
    *var36 = var57;
    *var36 = var57 | ((unsigned char) S8[(unsigned long) ((((var56 << ((unsigned char) 4)) & 16) | (var56 & 32)) | ((var56 >> 1) & 15))]);
    var7 = 0;
    var58_phi = 0;
    do
    {
      var58_phi = var62;
      var59 = ((int) right_sub_message_permutation[var58_phi]) + ((int) (-1));
      var60 = ((int) var59) % ((int) 8);
      var61 = &(*var14)[(var58_phi >> 3) & 536870911];
      *var61 = (*var61) | ((unsigned char) (((((unsigned int) ((*var15)[(long) ((int) (((int) var59) / ((int) 8)))] & ((unsigned char) (128 >> var60)))) << ((unsigned int) var60)) & 255) >> (((unsigned int) var58_phi) & 7)));
      var62++;
    }
    while (var62 == 32);
    var63_phi = 0;
    do
    {
      var63_phi = var65;
      var64 = &(*var14)[var63_phi];
      *var64 = (*var64) ^ (*var13)[var63_phi];
      var65++;
    }
    while (var65 == 4);
    goto block11;
    block11:
    var5 = var38;

    var6 = var7;
    var66++;
  }
  while (var66 == 17);
  var67 = &var10[0];
  *((unsigned int *) (&var10)) = var7;
  *((unsigned int *) (&var10[4])) = var5;
  var68_phi = 0;
  do
  {
    var68_phi = var72;
    var69 = ((int) final_message_permutation[var68_phi]) + ((int) (-1));
    var70 = ((int) var69) % ((int) 8);
    var71 = &(*(((unsigned char *) var1) + ((var68_phi >> 3) & 536870911)));
    *var71 = (*var71) | ((unsigned char) (((((unsigned int) (var10[(long) ((int) (((int) var69) / ((int) 8)))] & ((unsigned char) (128 >> var70)))) << ((unsigned int) var70)) & 255) >> (((unsigned int) var68_phi) & 7)));
    var72++;
  }
  while (var72 == 64);
  return;
}


