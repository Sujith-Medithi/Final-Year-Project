unsigned int AddRoundKey(unsigned int *var0, unsigned int var1, unsigned int var2);
void ByteSub_ShiftRow(unsigned int *var0, unsigned int var1);
unsigned int KeySchedule(unsigned int var0, unsigned int *var1);
unsigned int MixColumn_AddRoundKey(unsigned int *var0, unsigned int var1, unsigned int var2);
unsigned int SubByte(unsigned int var0);
unsigned int encrypt(unsigned int *var0, unsigned int *var1, unsigned int var2);
extern void llvm_lifetime_end_p0i8(unsigned long var0, unsigned char *var1);
extern void llvm_lifetime_start_p0i8(unsigned long var0, unsigned char *var1);
int main(void);
unsigned int __const_encrypt_out_enc_statemt_1[16] = {57, 37, 132, 29, 2, 220, 9, 251, 220, 17, 133, 151, 25, 106, 11, 50};
unsigned int __const_encrypt_out_enc_statemt_2[16] = {57, 37, 132, 29, 2, 220, 9, 251, 220, 17, 133, 151, 25, 106, 11, 50};
unsigned int __const_encrypt_out_enc_statemt[16] = {57, 37, 132, 29, 2, 220, 9, 251, 220, 17, 133, 151, 25, 106, 11, 50};
unsigned int round_val_1 = 0;
unsigned int round_val_2 = 0;
unsigned int round_val = 0;
unsigned int nb_1 = 0;
unsigned int nb_2 = 0;
unsigned int nb = 0;
unsigned int main_result_1 = 0;
unsigned int main_result_2 = 0;
unsigned int main_result = 0;
unsigned int Sbox_1[16][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
unsigned int Sbox_2[16][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
unsigned int Sbox[16][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
unsigned int word_1[4][120] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
unsigned int word_2[4][120] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
unsigned int word[4][120] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
unsigned int Rcon0_1[30] = {1, 2, 4, 8, 16, 32, 64, 128, 27, 54, 108, 216, 171, 77, 154, 47, 94, 188, 99, 198, 151, 53, 106, 212, 179, 125, 250, 239, 197, 145};
unsigned int Rcon0_2[30] = {1, 2, 4, 8, 16, 32, 64, 128, 27, 54, 108, 216, 171, 77, 154, 47, 94, 188, 99, 198, 151, 53, 106, 212, 179, 125, 250, 239, 197, 145};
unsigned int Rcon0[30] = {1, 2, 4, 8, 16, 32, 64, 128, 27, 54, 108, 216, 171, 77, 154, 47, 94, 188, 99, 198, 151, 53, 106, 212, 179, 125, 250, 239, 197, 145};
unsigned int statemt_1[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int statemt_2[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int statemt[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int key_1[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int key_2[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int key[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int type_1 = 0;
unsigned int type_2 = 0;
unsigned int type = 0;
unsigned int nd_key();
void AddRoundKey_2(unsigned int *var0_1, unsigned int var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int var1_2, unsigned int var2_2)
{
  unsigned int var3_phi_1;
  unsigned int var3_phi_2;
  unsigned long var5_phi_1;
  unsigned long var5_phi_2;
  long var4_1;
  long var4_2;
  long var6_1;
  long var6_2;
  long var7_1;
  long var7_2;
  unsigned int *var8_1;
  unsigned int *var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int *var10_1;
  unsigned int *var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  long var12_1;
  long var12_2;
  block0_1:
  switch (var1_1)
  {
    case 128192:
      goto block1_1;

    case 128256:
      goto block2_1;

    case 192192:
      goto block1_1;

    case 192256:
      goto block2_1;

    case 256192:
      goto block1_1;

    case 256256:
      goto block2_1;

    default:
      goto block3_1;

  }


  block0_2:
  switch (var1_2)
  {
    case 128192:
      goto block1_2;

    case 128256:
      goto block2_2;

    case 192192:
      goto block1_2;

    case 192256:
      goto block2_2;

    case 256192:
      goto block1_2;

    case 256256:
      goto block2_2;

    default:
      goto block3_2;

  }


  block3_1:
  var4_1 = (long) ((int) (((int) var3_phi_1) * ((int) var2_1)));

  block3_2:
  var4_2 = (long) ((int) (((int) var3_phi_2) * ((int) var2_2)));

  var5_phi_1 = 0;
  var5_phi_2 = 0;
  goto block4_1;
  goto block4_2;
  block2_1:
  var3_phi_1 = 8;

  block2_2:
  var3_phi_2 = 8;

  goto block3_1;
  goto block3_2;
  block1_1:
  var3_phi_1 = 6;

  block1_2:
  var3_phi_2 = 6;

  goto block3_1;
  goto block3_2;
  block4_1:
  var6_1 = ((long) var5_phi_1) + ((long) var4_1);

  block4_2:
  var6_2 = ((long) var5_phi_2) + ((long) var4_2);

  var7_1 = ((long) var5_phi_1) << ((long) ((unsigned long) ((long) 2)));
  var7_2 = ((long) var5_phi_2) << ((long) ((unsigned long) ((long) 2)));
  var8_1 = &(*(((unsigned int *) var0_1) + var7_1));
  var8_2 = &(*(((unsigned int *) var0_2) + var7_2));
  *var8_1 = (*var8_1) ^ word_1[0][var6_1];
  *var8_2 = (*var8_2) ^ word_2[0][var6_2];
  var9_1 = &(*(((unsigned int *) var0_1) + (var7_1 | 1)));
  var9_2 = &(*(((unsigned int *) var0_2) + (var7_2 | 1)));
  *var9_1 = (*var9_1) ^ word_1[1][var6_1];
  *var9_2 = (*var9_2) ^ word_2[1][var6_2];
  var10_1 = &(*(((unsigned int *) var0_1) + (var7_1 | 2)));
  var10_2 = &(*(((unsigned int *) var0_2) + (var7_2 | 2)));
  *var10_1 = (*var10_1) ^ word_1[2][var6_1];
  *var10_2 = (*var10_2) ^ word_2[2][var6_2];
  var11_1 = &(*(((unsigned int *) var0_1) + (var7_1 | 3)));
  var11_2 = &(*(((unsigned int *) var0_2) + (var7_2 | 3)));
  *var11_1 = (*var11_1) ^ word_1[3][var6_1];
  *var11_2 = (*var11_2) ^ word_2[3][var6_2];
  var12_1 = ((long) var5_phi_1) + ((long) 1);
  var12_2 = ((long) var5_phi_2) + ((long) 1);
  if (var12_1 == 8)
  {
    return 0;
  }
  else
  {
    var5_phi_1 = var12_1;
    goto block4_1;
  }
  if (var12_2 == 8)
  {
    return 0;
  }
  else
  {
    var5_phi_2 = var12_2;
    goto block4_2;
  }
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(var3_phi_1 == var3_phi_2);
  assert(var5_phi_1 == var5_phi_2);
  assert(var4_1 == var4_2);
  assert(var6_1 == var6_2);
  assert(var7_1 == var7_2);
  assert((*var8_1) == (*var8_2));
  assert((*var9_1) == (*var9_2));
  assert((*var10_1) == (*var10_2));
  assert((*var11_1) == (*var11_2));
  assert(var12_1 == var12_2);
}

unsigned int AddRoundKey(unsigned int *var0, unsigned int var1, unsigned int var2)
{
  unsigned int var3_phi;
  unsigned long var5_phi;
  long var4;
  long var6;
  long var7;
  unsigned int *var8;
  unsigned int *var9;
  unsigned int *var10;
  unsigned int *var11;
  long var12;
  block0:
  switch (var1)
  {
    case 128192:
      goto block1;

    case 128256:
      goto block2;

    case 192192:
      goto block1;

    case 192256:
      goto block2;

    case 256192:
      goto block1;

    case 256256:
      goto block2;

    default:
      goto block3;

  }


  block3:
  var4 = (long) ((int) (((int) var3_phi) * ((int) var2)));

  var5_phi = 0;
  goto block4;
  block2:
  var3_phi = 8;

  goto block3;
  block1:
  var3_phi = 6;

  goto block3;
  block4:
  var6 = ((long) var5_phi) + ((long) var4);

  var7 = ((long) var5_phi) << ((long) ((unsigned long) ((long) 2)));
  var8 = &(*(((unsigned int *) var0) + var7));
  *var8 = (*var8) ^ word[0][var6];
  var9 = &(*(((unsigned int *) var0) + (var7 | 1)));
  *var9 = (*var9) ^ word[1][var6];
  var10 = &(*(((unsigned int *) var0) + (var7 | 2)));
  *var10 = (*var10) ^ word[2][var6];
  var11 = &(*(((unsigned int *) var0) + (var7 | 3)));
  *var11 = (*var11) ^ word[3][var6];
  var12 = ((long) var5_phi) + ((long) 1);
  if (var12 == 8)
  {
    return 0;
  }
  else
  {
    var5_phi = var12;
    goto block4;
  }
}

void ByteSub_ShiftRow_2(unsigned int *var0_1, unsigned int var1_1, unsigned int *var0_2, unsigned int var1_2)
{
  unsigned int *var156_phi_1;
  unsigned int *var156_phi_2;
  unsigned int *var2_1;
  unsigned int *var2_2;
  unsigned int var3_1;
  unsigned int var3_2;
  unsigned int var4_1;
  unsigned int var4_2;
  unsigned int *var5_1;
  unsigned int *var5_2;
  unsigned int var6_1;
  unsigned int var6_2;
  unsigned int *var7_1;
  unsigned int *var7_2;
  unsigned int var8_1;
  unsigned int var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int var10_1;
  unsigned int var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned int var12_1;
  unsigned int var12_2;
  unsigned int var13_1;
  unsigned int var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  unsigned int var15_1;
  unsigned int var15_2;
  unsigned int *var16_1;
  unsigned int *var16_2;
  unsigned int var17_1;
  unsigned int var17_2;
  unsigned int var18_1;
  unsigned int var18_2;
  unsigned int *var19_1;
  unsigned int *var19_2;
  unsigned int var20_1;
  unsigned int var20_2;
  unsigned int *var21_1;
  unsigned int *var21_2;
  unsigned int var22_1;
  unsigned int var22_2;
  unsigned int var23_1;
  unsigned int var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int *var26_1;
  unsigned int *var26_2;
  unsigned int var27_1;
  unsigned int var27_2;
  unsigned int *var28_1;
  unsigned int *var28_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int *var31_1;
  unsigned int *var31_2;
  unsigned int var32_1;
  unsigned int var32_2;
  unsigned int *var33_1;
  unsigned int *var33_2;
  unsigned int var34_1;
  unsigned int var34_2;
  unsigned int *var35_1;
  unsigned int *var35_2;
  unsigned int *var36_1;
  unsigned int *var36_2;
  unsigned int var37_1;
  unsigned int var37_2;
  unsigned int var38_1;
  unsigned int var38_2;
  unsigned int *var39_1;
  unsigned int *var39_2;
  unsigned int var40_1;
  unsigned int var40_2;
  unsigned int *var41_1;
  unsigned int *var41_2;
  unsigned int var42_1;
  unsigned int var42_2;
  unsigned int *var43_1;
  unsigned int *var43_2;
  unsigned int var44_1;
  unsigned int var44_2;
  unsigned int *var45_1;
  unsigned int *var45_2;
  unsigned int var46_1;
  unsigned int var46_2;
  unsigned int *var47_1;
  unsigned int *var47_2;
  unsigned int var48_1;
  unsigned int var48_2;
  unsigned int *var49_1;
  unsigned int *var49_2;
  unsigned int var50_1;
  unsigned int var50_2;
  unsigned int var51_1;
  unsigned int var51_2;
  unsigned int *var52_1;
  unsigned int *var52_2;
  unsigned int var53_1;
  unsigned int var53_2;
  unsigned int *var54_1;
  unsigned int *var54_2;
  unsigned int var55_1;
  unsigned int var55_2;
  unsigned int *var56_1;
  unsigned int *var56_2;
  unsigned int var57_1;
  unsigned int var57_2;
  unsigned int var58_1;
  unsigned int var58_2;
  unsigned int *var59_1;
  unsigned int *var59_2;
  unsigned int var60_1;
  unsigned int var60_2;
  unsigned int *var61_1;
  unsigned int *var61_2;
  unsigned int var62_1;
  unsigned int var62_2;
  unsigned int *var63_1;
  unsigned int *var63_2;
  unsigned int var64_1;
  unsigned int var64_2;
  unsigned int var65_1;
  unsigned int var65_2;
  unsigned int *var66_1;
  unsigned int *var66_2;
  unsigned int var67_1;
  unsigned int var67_2;
  unsigned int *var68_1;
  unsigned int *var68_2;
  unsigned int var69_1;
  unsigned int var69_2;
  unsigned int var70_1;
  unsigned int var70_2;
  unsigned int *var71_1;
  unsigned int *var71_2;
  unsigned int var72_1;
  unsigned int var72_2;
  unsigned int *var73_1;
  unsigned int *var73_2;
  unsigned int var74_1;
  unsigned int var74_2;
  unsigned int var75_1;
  unsigned int var75_2;
  unsigned int *var76_1;
  unsigned int *var76_2;
  unsigned int var77_1;
  unsigned int var77_2;
  unsigned int var78_1;
  unsigned int var78_2;
  unsigned int *var79_1;
  unsigned int *var79_2;
  unsigned int var80_1;
  unsigned int var80_2;
  unsigned int *var81_1;
  unsigned int *var81_2;
  unsigned int var82_1;
  unsigned int var82_2;
  unsigned int *var83_1;
  unsigned int *var83_2;
  unsigned int var84_1;
  unsigned int var84_2;
  unsigned int *var85_1;
  unsigned int *var85_2;
  unsigned int var86_1;
  unsigned int var86_2;
  unsigned int *var87_1;
  unsigned int *var87_2;
  unsigned int *var88_1;
  unsigned int *var88_2;
  unsigned int var89_1;
  unsigned int var89_2;
  unsigned int var90_1;
  unsigned int var90_2;
  unsigned int *var91_1;
  unsigned int *var91_2;
  unsigned int var92_1;
  unsigned int var92_2;
  unsigned int *var93_1;
  unsigned int *var93_2;
  unsigned int var94_1;
  unsigned int var94_2;
  unsigned int *var95_1;
  unsigned int *var95_2;
  unsigned int var96_1;
  unsigned int var96_2;
  unsigned int *var97_1;
  unsigned int *var97_2;
  unsigned int var98_1;
  unsigned int var98_2;
  unsigned int *var99_1;
  unsigned int *var99_2;
  unsigned int var100_1;
  unsigned int var100_2;
  unsigned int *var101_1;
  unsigned int *var101_2;
  unsigned int var102_1;
  unsigned int var102_2;
  unsigned int *var103_1;
  unsigned int *var103_2;
  unsigned int var104_1;
  unsigned int var104_2;
  unsigned int *var105_1;
  unsigned int *var105_2;
  unsigned int var106_1;
  unsigned int var106_2;
  unsigned int var107_1;
  unsigned int var107_2;
  unsigned int *var108_1;
  unsigned int *var108_2;
  unsigned int var109_1;
  unsigned int var109_2;
  unsigned int *var110_1;
  unsigned int *var110_2;
  unsigned int var111_1;
  unsigned int var111_2;
  unsigned int *var112_1;
  unsigned int *var112_2;
  unsigned int var113_1;
  unsigned int var113_2;
  unsigned int *var114_1;
  unsigned int *var114_2;
  unsigned int var115_1;
  unsigned int var115_2;
  unsigned int *var116_1;
  unsigned int *var116_2;
  unsigned int var117_1;
  unsigned int var117_2;
  unsigned int *var118_1;
  unsigned int *var118_2;
  unsigned int var119_1;
  unsigned int var119_2;
  unsigned int *var120_1;
  unsigned int *var120_2;
  unsigned int var121_1;
  unsigned int var121_2;
  unsigned int *var122_1;
  unsigned int *var122_2;
  unsigned int var123_1;
  unsigned int var123_2;
  unsigned int var124_1;
  unsigned int var124_2;
  unsigned int *var125_1;
  unsigned int *var125_2;
  unsigned int var126_1;
  unsigned int var126_2;
  unsigned int *var127_1;
  unsigned int *var127_2;
  unsigned int var128_1;
  unsigned int var128_2;
  unsigned int var129_1;
  unsigned int var129_2;
  unsigned int *var130_1;
  unsigned int *var130_2;
  unsigned int var131_1;
  unsigned int var131_2;
  unsigned int *var132_1;
  unsigned int *var132_2;
  unsigned int var133_1;
  unsigned int var133_2;
  unsigned int var134_1;
  unsigned int var134_2;
  unsigned int *var135_1;
  unsigned int *var135_2;
  unsigned int var136_1;
  unsigned int var136_2;
  unsigned int *var137_1;
  unsigned int *var137_2;
  unsigned int var138_1;
  unsigned int var138_2;
  unsigned int var139_1;
  unsigned int var139_2;
  unsigned int *var140_1;
  unsigned int *var140_2;
  unsigned int var141_1;
  unsigned int var141_2;
  unsigned int var142_1;
  unsigned int var142_2;
  unsigned int *var143_1;
  unsigned int *var143_2;
  unsigned int var144_1;
  unsigned int var144_2;
  unsigned int *var145_1;
  unsigned int *var145_2;
  unsigned int var146_1;
  unsigned int var146_2;
  unsigned int *var147_1;
  unsigned int *var147_2;
  unsigned int var148_1;
  unsigned int var148_2;
  unsigned int *var149_1;
  unsigned int *var149_2;
  unsigned int var150_1;
  unsigned int var150_2;
  unsigned int *var151_1;
  unsigned int *var151_2;
  unsigned int var152_1;
  unsigned int var152_2;
  unsigned int *var153_1;
  unsigned int *var153_2;
  unsigned int var154_1;
  unsigned int var154_2;
  unsigned int *var155_1;
  unsigned int *var155_2;
  unsigned int var157_1;
  unsigned int var157_2;
  block0_1:
  switch (var1_1)
  {
    case 4:
      var2_1 = &(*(((unsigned int *) var0_1) + 1));
      var3_1 = *var2_1;
      var4_1 = Sbox_1[(long) ((int) (var3_1 >> ((unsigned int) 4)))][(unsigned long) (var3_1 & 15)];
      var5_1 = &(*(((unsigned int *) var0_1) + 5));
      var6_1 = *var5_1;
      *var2_1 = Sbox_1[(long) ((int) (var6_1 >> ((unsigned int) 4)))][(unsigned long) (var6_1 & 15)];
      var7_1 = &(*(((unsigned int *) var0_1) + 9));
      var8_1 = *var7_1;
      *var5_1 = Sbox_1[(long) ((int) (var8_1 >> ((unsigned int) 4)))][(unsigned long) (var8_1 & 15)];
      var9_1 = &(*(((unsigned int *) var0_1) + 13));
      var10_1 = *var9_1;
      *var7_1 = Sbox_1[(long) ((int) (var10_1 >> ((unsigned int) 4)))][(unsigned long) (var10_1 & 15)];
      *var9_1 = var4_1;
      var11_1 = &(*(((unsigned int *) var0_1) + 2));
      var12_1 = *var11_1;
      var13_1 = Sbox_1[(long) ((int) (var12_1 >> ((unsigned int) 4)))][(unsigned long) (var12_1 & 15)];
      var14_1 = &(*(((unsigned int *) var0_1) + 10));
      var15_1 = *var14_1;
      *var11_1 = Sbox_1[(long) ((int) (var15_1 >> ((unsigned int) 4)))][(unsigned long) (var15_1 & 15)];
      *var14_1 = var13_1;
      var16_1 = &(*(((unsigned int *) var0_1) + 6));
      var17_1 = *var16_1;
      var18_1 = Sbox_1[(long) ((int) (var17_1 >> ((unsigned int) 4)))][(unsigned long) (var17_1 & 15)];
      var19_1 = &(*(((unsigned int *) var0_1) + 14));
      var20_1 = *var19_1;
      *var16_1 = Sbox_1[(long) ((int) (var20_1 >> ((unsigned int) 4)))][(unsigned long) (var20_1 & 15)];
      *var19_1 = var18_1;
      var21_1 = &(*(((unsigned int *) var0_1) + 3));
      var22_1 = *var21_1;
      var23_1 = Sbox_1[(long) ((int) (var22_1 >> ((unsigned int) 4)))][(unsigned long) (var22_1 & 15)];
      var24_1 = &(*(((unsigned int *) var0_1) + 15));
      var25_1 = *var24_1;
      *var21_1 = Sbox_1[(long) ((int) (var25_1 >> ((unsigned int) 4)))][(unsigned long) (var25_1 & 15)];
      var26_1 = &(*(((unsigned int *) var0_1) + 11));
      var27_1 = *var26_1;
      *var24_1 = Sbox_1[(long) ((int) (var27_1 >> ((unsigned int) 4)))][(unsigned long) (var27_1 & 15)];
      var28_1 = &(*(((unsigned int *) var0_1) + 7));
      var29_1 = *var28_1;
      *var26_1 = Sbox_1[(long) ((int) (var29_1 >> ((unsigned int) 4)))][(unsigned long) (var29_1 & 15)];
      *var28_1 = var23_1;
      var30_1 = *var0_1;
      *var0_1 = Sbox_1[(long) ((int) (var30_1 >> ((unsigned int) 4)))][(unsigned long) (var30_1 & 15)];
      var31_1 = &(*(((unsigned int *) var0_1) + 4));
      var32_1 = *var31_1;
      *var31_1 = Sbox_1[(long) ((int) (var32_1 >> ((unsigned int) 4)))][(unsigned long) (var32_1 & 15)];
      var33_1 = &(*(((unsigned int *) var0_1) + 8));
      var34_1 = *var33_1;
      *var33_1 = Sbox_1[(long) ((int) (var34_1 >> ((unsigned int) 4)))][(unsigned long) (var34_1 & 15)];
      var35_1 = &(*(((unsigned int *) var0_1) + 12));
      var156_phi_1 = var35_1;
      goto block4_1;

    case 6:
      var36_1 = &(*(((unsigned int *) var0_1) + 1));
      var37_1 = *var36_1;
      var38_1 = Sbox_1[(long) ((int) (var37_1 >> ((unsigned int) 4)))][(unsigned long) (var37_1 & 15)];
      var39_1 = &(*(((unsigned int *) var0_1) + 5));
      var40_1 = *var39_1;
      *var36_1 = Sbox_1[(long) ((int) (var40_1 >> ((unsigned int) 4)))][(unsigned long) (var40_1 & 15)];
      var41_1 = &(*(((unsigned int *) var0_1) + 9));
      var42_1 = *var41_1;
      *var39_1 = Sbox_1[(long) ((int) (var42_1 >> ((unsigned int) 4)))][(unsigned long) (var42_1 & 15)];
      var43_1 = &(*(((unsigned int *) var0_1) + 13));
      var44_1 = *var43_1;
      *var41_1 = Sbox_1[(long) ((int) (var44_1 >> ((unsigned int) 4)))][(unsigned long) (var44_1 & 15)];
      var45_1 = &(*(((unsigned int *) var0_1) + 17));
      var46_1 = *var45_1;
      *var43_1 = Sbox_1[(long) ((int) (var46_1 >> ((unsigned int) 4)))][(unsigned long) (var46_1 & 15)];
      var47_1 = &(*(((unsigned int *) var0_1) + 21));
      var48_1 = *var47_1;
      *var45_1 = Sbox_1[(long) ((int) (var48_1 >> ((unsigned int) 4)))][(unsigned long) (var48_1 & 15)];
      *var47_1 = var38_1;
      var49_1 = &(*(((unsigned int *) var0_1) + 2));
      var50_1 = *var49_1;
      var51_1 = Sbox_1[(long) ((int) (var50_1 >> ((unsigned int) 4)))][(unsigned long) (var50_1 & 15)];
      var52_1 = &(*(((unsigned int *) var0_1) + 10));
      var53_1 = *var52_1;
      *var49_1 = Sbox_1[(long) ((int) (var53_1 >> ((unsigned int) 4)))][(unsigned long) (var53_1 & 15)];
      var54_1 = &(*(((unsigned int *) var0_1) + 18));
      var55_1 = *var54_1;
      *var52_1 = Sbox_1[(long) ((int) (var55_1 >> ((unsigned int) 4)))][(unsigned long) (var55_1 & 15)];
      *var54_1 = var51_1;
      var56_1 = &(*(((unsigned int *) var0_1) + 6));
      var57_1 = *var56_1;
      var58_1 = Sbox_1[(long) ((int) (var57_1 >> ((unsigned int) 4)))][(unsigned long) (var57_1 & 15)];
      var59_1 = &(*(((unsigned int *) var0_1) + 14));
      var60_1 = *var59_1;
      *var56_1 = Sbox_1[(long) ((int) (var60_1 >> ((unsigned int) 4)))][(unsigned long) (var60_1 & 15)];
      var61_1 = &(*(((unsigned int *) var0_1) + 22));
      var62_1 = *var61_1;
      *var59_1 = Sbox_1[(long) ((int) (var62_1 >> ((unsigned int) 4)))][(unsigned long) (var62_1 & 15)];
      *var61_1 = var58_1;
      var63_1 = &(*(((unsigned int *) var0_1) + 3));
      var64_1 = *var63_1;
      var65_1 = Sbox_1[(long) ((int) (var64_1 >> ((unsigned int) 4)))][(unsigned long) (var64_1 & 15)];
      var66_1 = &(*(((unsigned int *) var0_1) + 15));
      var67_1 = *var66_1;
      *var63_1 = Sbox_1[(long) ((int) (var67_1 >> ((unsigned int) 4)))][(unsigned long) (var67_1 & 15)];
      *var66_1 = var65_1;
      var68_1 = &(*(((unsigned int *) var0_1) + 7));
      var69_1 = *var68_1;
      var70_1 = Sbox_1[(long) ((int) (var69_1 >> ((unsigned int) 4)))][(unsigned long) (var69_1 & 15)];
      var71_1 = &(*(((unsigned int *) var0_1) + 19));
      var72_1 = *var71_1;
      *var68_1 = Sbox_1[(long) ((int) (var72_1 >> ((unsigned int) 4)))][(unsigned long) (var72_1 & 15)];
      *var71_1 = var70_1;
      var73_1 = &(*(((unsigned int *) var0_1) + 11));
      var74_1 = *var73_1;
      var75_1 = Sbox_1[(long) ((int) (var74_1 >> ((unsigned int) 4)))][(unsigned long) (var74_1 & 15)];
      var76_1 = &(*(((unsigned int *) var0_1) + 23));
      var77_1 = *var76_1;
      *var73_1 = Sbox_1[(long) ((int) (var77_1 >> ((unsigned int) 4)))][(unsigned long) (var77_1 & 15)];
      *var76_1 = var75_1;
      var78_1 = *var0_1;
      *var0_1 = Sbox_1[(long) ((int) (var78_1 >> ((unsigned int) 4)))][(unsigned long) (var78_1 & 15)];
      var79_1 = &(*(((unsigned int *) var0_1) + 4));
      var80_1 = *var79_1;
      *var79_1 = Sbox_1[(long) ((int) (var80_1 >> ((unsigned int) 4)))][(unsigned long) (var80_1 & 15)];
      var81_1 = &(*(((unsigned int *) var0_1) + 8));
      var82_1 = *var81_1;
      *var81_1 = Sbox_1[(long) ((int) (var82_1 >> ((unsigned int) 4)))][(unsigned long) (var82_1 & 15)];
      var83_1 = &(*(((unsigned int *) var0_1) + 12));
      var84_1 = *var83_1;
      *var83_1 = Sbox_1[(long) ((int) (var84_1 >> ((unsigned int) 4)))][(unsigned long) (var84_1 & 15)];
      var85_1 = &(*(((unsigned int *) var0_1) + 16));
      var86_1 = *var85_1;
      *var85_1 = Sbox_1[(long) ((int) (var86_1 >> ((unsigned int) 4)))][(unsigned long) (var86_1 & 15)];
      var87_1 = &(*(((unsigned int *) var0_1) + 20));
      var156_phi_1 = var87_1;
      goto block4_1;

    case 8:
      var88_1 = &(*(((unsigned int *) var0_1) + 1));
      var89_1 = *var88_1;
      var90_1 = Sbox_1[(long) ((int) (var89_1 >> ((unsigned int) 4)))][(unsigned long) (var89_1 & 15)];
      var91_1 = &(*(((unsigned int *) var0_1) + 5));
      var92_1 = *var91_1;
      *var88_1 = Sbox_1[(long) ((int) (var92_1 >> ((unsigned int) 4)))][(unsigned long) (var92_1 & 15)];
      var93_1 = &(*(((unsigned int *) var0_1) + 9));
      var94_1 = *var93_1;
      *var91_1 = Sbox_1[(long) ((int) (var94_1 >> ((unsigned int) 4)))][(unsigned long) (var94_1 & 15)];
      var95_1 = &(*(((unsigned int *) var0_1) + 13));
      var96_1 = *var95_1;
      *var93_1 = Sbox_1[(long) ((int) (var96_1 >> ((unsigned int) 4)))][(unsigned long) (var96_1 & 15)];
      var97_1 = &(*(((unsigned int *) var0_1) + 17));
      var98_1 = *var97_1;
      *var95_1 = Sbox_1[(long) ((int) (var98_1 >> ((unsigned int) 4)))][(unsigned long) (var98_1 & 15)];
      var99_1 = &(*(((unsigned int *) var0_1) + 21));
      var100_1 = *var99_1;
      *var97_1 = Sbox_1[(long) ((int) (var100_1 >> ((unsigned int) 4)))][(unsigned long) (var100_1 & 15)];
      var101_1 = &(*(((unsigned int *) var0_1) + 25));
      var102_1 = *var101_1;
      *var99_1 = Sbox_1[(long) ((int) (var102_1 >> ((unsigned int) 4)))][(unsigned long) (var102_1 & 15)];
      var103_1 = &(*(((unsigned int *) var0_1) + 29));
      var104_1 = *var103_1;
      *var101_1 = Sbox_1[(long) ((int) (var104_1 >> ((unsigned int) 4)))][(unsigned long) (var104_1 & 15)];
      *var103_1 = var90_1;
      var105_1 = &(*(((unsigned int *) var0_1) + 2));
      var106_1 = *var105_1;
      var107_1 = Sbox_1[(long) ((int) (var106_1 >> ((unsigned int) 4)))][(unsigned long) (var106_1 & 15)];
      var108_1 = &(*(((unsigned int *) var0_1) + 14));
      var109_1 = *var108_1;
      *var105_1 = Sbox_1[(long) ((int) (var109_1 >> ((unsigned int) 4)))][(unsigned long) (var109_1 & 15)];
      var110_1 = &(*(((unsigned int *) var0_1) + 26));
      var111_1 = *var110_1;
      *var108_1 = Sbox_1[(long) ((int) (var111_1 >> ((unsigned int) 4)))][(unsigned long) (var111_1 & 15)];
      var112_1 = &(*(((unsigned int *) var0_1) + 6));
      var113_1 = *var112_1;
      *var110_1 = Sbox_1[(long) ((int) (var113_1 >> ((unsigned int) 4)))][(unsigned long) (var113_1 & 15)];
      var114_1 = &(*(((unsigned int *) var0_1) + 18));
      var115_1 = *var114_1;
      *var112_1 = Sbox_1[(long) ((int) (var115_1 >> ((unsigned int) 4)))][(unsigned long) (var115_1 & 15)];
      var116_1 = &(*(((unsigned int *) var0_1) + 30));
      var117_1 = *var116_1;
      *var114_1 = Sbox_1[(long) ((int) (var117_1 >> ((unsigned int) 4)))][(unsigned long) (var117_1 & 15)];
      var118_1 = &(*(((unsigned int *) var0_1) + 10));
      var119_1 = *var118_1;
      *var116_1 = Sbox_1[(long) ((int) (var119_1 >> ((unsigned int) 4)))][(unsigned long) (var119_1 & 15)];
      var120_1 = &(*(((unsigned int *) var0_1) + 22));
      var121_1 = *var120_1;
      *var118_1 = Sbox_1[(long) ((int) (var121_1 >> ((unsigned int) 4)))][(unsigned long) (var121_1 & 15)];
      *var120_1 = var107_1;
      var122_1 = &(*(((unsigned int *) var0_1) + 3));
      var123_1 = *var122_1;
      var124_1 = Sbox_1[(long) ((int) (var123_1 >> ((unsigned int) 4)))][(unsigned long) (var123_1 & 15)];
      var125_1 = &(*(((unsigned int *) var0_1) + 19));
      var126_1 = *var125_1;
      *var122_1 = Sbox_1[(long) ((int) (var126_1 >> ((unsigned int) 4)))][(unsigned long) (var126_1 & 15)];
      *var125_1 = var124_1;
      var127_1 = &(*(((unsigned int *) var0_1) + 7));
      var128_1 = *var127_1;
      var129_1 = Sbox_1[(long) ((int) (var128_1 >> ((unsigned int) 4)))][(unsigned long) (var128_1 & 15)];
      var130_1 = &(*(((unsigned int *) var0_1) + 23));
      var131_1 = *var130_1;
      *var127_1 = Sbox_1[(long) ((int) (var131_1 >> ((unsigned int) 4)))][(unsigned long) (var131_1 & 15)];
      *var130_1 = var129_1;
      var132_1 = &(*(((unsigned int *) var0_1) + 11));
      var133_1 = *var132_1;
      var134_1 = Sbox_1[(long) ((int) (var133_1 >> ((unsigned int) 4)))][(unsigned long) (var133_1 & 15)];
      var135_1 = &(*(((unsigned int *) var0_1) + 27));
      var136_1 = *var135_1;
      *var132_1 = Sbox_1[(long) ((int) (var136_1 >> ((unsigned int) 4)))][(unsigned long) (var136_1 & 15)];
      *var135_1 = var134_1;
      var137_1 = &(*(((unsigned int *) var0_1) + 15));
      var138_1 = *var137_1;
      var139_1 = Sbox_1[(long) ((int) (var138_1 >> ((unsigned int) 4)))][(unsigned long) (var138_1 & 15)];
      var140_1 = &(*(((unsigned int *) var0_1) + 31));
      var141_1 = *var140_1;
      *var137_1 = Sbox_1[(long) ((int) (var141_1 >> ((unsigned int) 4)))][(unsigned long) (var141_1 & 15)];
      *var140_1 = var139_1;
      var142_1 = *var0_1;
      *var0_1 = Sbox_1[(long) ((int) (var142_1 >> ((unsigned int) 4)))][(unsigned long) (var142_1 & 15)];
      var143_1 = &(*(((unsigned int *) var0_1) + 4));
      var144_1 = *var143_1;
      *var143_1 = Sbox_1[(long) ((int) (var144_1 >> ((unsigned int) 4)))][(unsigned long) (var144_1 & 15)];
      var145_1 = &(*(((unsigned int *) var0_1) + 8));
      var146_1 = *var145_1;
      *var145_1 = Sbox_1[(long) ((int) (var146_1 >> ((unsigned int) 4)))][(unsigned long) (var146_1 & 15)];
      var147_1 = &(*(((unsigned int *) var0_1) + 12));
      var148_1 = *var147_1;
      *var147_1 = Sbox_1[(long) ((int) (var148_1 >> ((unsigned int) 4)))][(unsigned long) (var148_1 & 15)];
      var149_1 = &(*(((unsigned int *) var0_1) + 16));
      var150_1 = *var149_1;
      *var149_1 = Sbox_1[(long) ((int) (var150_1 >> ((unsigned int) 4)))][(unsigned long) (var150_1 & 15)];
      var151_1 = &(*(((unsigned int *) var0_1) + 20));
      var152_1 = *var151_1;
      *var151_1 = Sbox_1[(long) ((int) (var152_1 >> ((unsigned int) 4)))][(unsigned long) (var152_1 & 15)];
      var153_1 = &(*(((unsigned int *) var0_1) + 24));
      var154_1 = *var153_1;
      *var153_1 = Sbox_1[(long) ((int) (var154_1 >> ((unsigned int) 4)))][(unsigned long) (var154_1 & 15)];
      var155_1 = &(*(((unsigned int *) var0_1) + 28));
      var156_phi_1 = var155_1;
      goto block4_1;

    default:
      return;

  }


  block0_2:
  switch (var1_2)
  {
    case 4:
      var2_2 = &(*(((unsigned int *) var0_2) + 1));
      var3_2 = *var2_2;
      var4_2 = Sbox_2[(long) ((int) (var3_2 >> ((unsigned int) 4)))][(unsigned long) (var3_2 & 15)];
      var5_2 = &(*(((unsigned int *) var0_2) + 5));
      var6_2 = *var5_2;
      *var2_2 = Sbox_2[(long) ((int) (var6_2 >> ((unsigned int) 4)))][(unsigned long) (var6_2 & 15)];
      var7_2 = &(*(((unsigned int *) var0_2) + 9));
      var8_2 = *var7_2;
      *var5_2 = Sbox_2[(long) ((int) (var8_2 >> ((unsigned int) 4)))][(unsigned long) (var8_2 & 15)];
      var9_2 = &(*(((unsigned int *) var0_2) + 13));
      var10_2 = *var9_2;
      *var7_2 = Sbox_2[(long) ((int) (var10_2 >> ((unsigned int) 4)))][(unsigned long) (var10_2 & 15)];
      *var9_2 = var4_2;
      var11_2 = &(*(((unsigned int *) var0_2) + 2));
      var12_2 = *var11_2;
      var13_2 = Sbox_2[(long) ((int) (var12_2 >> ((unsigned int) 4)))][(unsigned long) (var12_2 & 15)];
      var14_2 = &(*(((unsigned int *) var0_2) + 10));
      var15_2 = *var14_2;
      *var11_2 = Sbox_2[(long) ((int) (var15_2 >> ((unsigned int) 4)))][(unsigned long) (var15_2 & 15)];
      *var14_2 = var13_2;
      var16_2 = &(*(((unsigned int *) var0_2) + 6));
      var17_2 = *var16_2;
      var18_2 = Sbox_2[(long) ((int) (var17_2 >> ((unsigned int) 4)))][(unsigned long) (var17_2 & 15)];
      var19_2 = &(*(((unsigned int *) var0_2) + 14));
      var20_2 = *var19_2;
      *var16_2 = Sbox_2[(long) ((int) (var20_2 >> ((unsigned int) 4)))][(unsigned long) (var20_2 & 15)];
      *var19_2 = var18_2;
      var21_2 = &(*(((unsigned int *) var0_2) + 3));
      var22_2 = *var21_2;
      var23_2 = Sbox_2[(long) ((int) (var22_2 >> ((unsigned int) 4)))][(unsigned long) (var22_2 & 15)];
      var24_2 = &(*(((unsigned int *) var0_2) + 15));
      var25_2 = *var24_2;
      *var21_2 = Sbox_2[(long) ((int) (var25_2 >> ((unsigned int) 4)))][(unsigned long) (var25_2 & 15)];
      var26_2 = &(*(((unsigned int *) var0_2) + 11));
      var27_2 = *var26_2;
      *var24_2 = Sbox_2[(long) ((int) (var27_2 >> ((unsigned int) 4)))][(unsigned long) (var27_2 & 15)];
      var28_2 = &(*(((unsigned int *) var0_2) + 7));
      var29_2 = *var28_2;
      *var26_2 = Sbox_2[(long) ((int) (var29_2 >> ((unsigned int) 4)))][(unsigned long) (var29_2 & 15)];
      *var28_2 = var23_2;
      var30_2 = *var0_2;
      *var0_2 = Sbox_2[(long) ((int) (var30_2 >> ((unsigned int) 4)))][(unsigned long) (var30_2 & 15)];
      var31_2 = &(*(((unsigned int *) var0_2) + 4));
      var32_2 = *var31_2;
      *var31_2 = Sbox_2[(long) ((int) (var32_2 >> ((unsigned int) 4)))][(unsigned long) (var32_2 & 15)];
      var33_2 = &(*(((unsigned int *) var0_2) + 8));
      var34_2 = *var33_2;
      *var33_2 = Sbox_2[(long) ((int) (var34_2 >> ((unsigned int) 4)))][(unsigned long) (var34_2 & 15)];
      var35_2 = &(*(((unsigned int *) var0_2) + 12));
      var156_phi_2 = var35_2;
      goto block4_2;

    case 6:
      var36_2 = &(*(((unsigned int *) var0_2) + 1));
      var37_2 = *var36_2;
      var38_2 = Sbox_2[(long) ((int) (var37_2 >> ((unsigned int) 4)))][(unsigned long) (var37_2 & 15)];
      var39_2 = &(*(((unsigned int *) var0_2) + 5));
      var40_2 = *var39_2;
      *var36_2 = Sbox_2[(long) ((int) (var40_2 >> ((unsigned int) 4)))][(unsigned long) (var40_2 & 15)];
      var41_2 = &(*(((unsigned int *) var0_2) + 9));
      var42_2 = *var41_2;
      *var39_2 = Sbox_2[(long) ((int) (var42_2 >> ((unsigned int) 4)))][(unsigned long) (var42_2 & 15)];
      var43_2 = &(*(((unsigned int *) var0_2) + 13));
      var44_2 = *var43_2;
      *var41_2 = Sbox_2[(long) ((int) (var44_2 >> ((unsigned int) 4)))][(unsigned long) (var44_2 & 15)];
      var45_2 = &(*(((unsigned int *) var0_2) + 17));
      var46_2 = *var45_2;
      *var43_2 = Sbox_2[(long) ((int) (var46_2 >> ((unsigned int) 4)))][(unsigned long) (var46_2 & 15)];
      var47_2 = &(*(((unsigned int *) var0_2) + 21));
      var48_2 = *var47_2;
      *var45_2 = Sbox_2[(long) ((int) (var48_2 >> ((unsigned int) 4)))][(unsigned long) (var48_2 & 15)];
      *var47_2 = var38_2;
      var49_2 = &(*(((unsigned int *) var0_2) + 2));
      var50_2 = *var49_2;
      var51_2 = Sbox_2[(long) ((int) (var50_2 >> ((unsigned int) 4)))][(unsigned long) (var50_2 & 15)];
      var52_2 = &(*(((unsigned int *) var0_2) + 10));
      var53_2 = *var52_2;
      *var49_2 = Sbox_2[(long) ((int) (var53_2 >> ((unsigned int) 4)))][(unsigned long) (var53_2 & 15)];
      var54_2 = &(*(((unsigned int *) var0_2) + 18));
      var55_2 = *var54_2;
      *var52_2 = Sbox_2[(long) ((int) (var55_2 >> ((unsigned int) 4)))][(unsigned long) (var55_2 & 15)];
      *var54_2 = var51_2;
      var56_2 = &(*(((unsigned int *) var0_2) + 6));
      var57_2 = *var56_2;
      var58_2 = Sbox_2[(long) ((int) (var57_2 >> ((unsigned int) 4)))][(unsigned long) (var57_2 & 15)];
      var59_2 = &(*(((unsigned int *) var0_2) + 14));
      var60_2 = *var59_2;
      *var56_2 = Sbox_2[(long) ((int) (var60_2 >> ((unsigned int) 4)))][(unsigned long) (var60_2 & 15)];
      var61_2 = &(*(((unsigned int *) var0_2) + 22));
      var62_2 = *var61_2;
      *var59_2 = Sbox_2[(long) ((int) (var62_2 >> ((unsigned int) 4)))][(unsigned long) (var62_2 & 15)];
      *var61_2 = var58_2;
      var63_2 = &(*(((unsigned int *) var0_2) + 3));
      var64_2 = *var63_2;
      var65_2 = Sbox_2[(long) ((int) (var64_2 >> ((unsigned int) 4)))][(unsigned long) (var64_2 & 15)];
      var66_2 = &(*(((unsigned int *) var0_2) + 15));
      var67_2 = *var66_2;
      *var63_2 = Sbox_2[(long) ((int) (var67_2 >> ((unsigned int) 4)))][(unsigned long) (var67_2 & 15)];
      *var66_2 = var65_2;
      var68_2 = &(*(((unsigned int *) var0_2) + 7));
      var69_2 = *var68_2;
      var70_2 = Sbox_2[(long) ((int) (var69_2 >> ((unsigned int) 4)))][(unsigned long) (var69_2 & 15)];
      var71_2 = &(*(((unsigned int *) var0_2) + 19));
      var72_2 = *var71_2;
      *var68_2 = Sbox_2[(long) ((int) (var72_2 >> ((unsigned int) 4)))][(unsigned long) (var72_2 & 15)];
      *var71_2 = var70_2;
      var73_2 = &(*(((unsigned int *) var0_2) + 11));
      var74_2 = *var73_2;
      var75_2 = Sbox_2[(long) ((int) (var74_2 >> ((unsigned int) 4)))][(unsigned long) (var74_2 & 15)];
      var76_2 = &(*(((unsigned int *) var0_2) + 23));
      var77_2 = *var76_2;
      *var73_2 = Sbox_2[(long) ((int) (var77_2 >> ((unsigned int) 4)))][(unsigned long) (var77_2 & 15)];
      *var76_2 = var75_2;
      var78_2 = *var0_2;
      *var0_2 = Sbox_2[(long) ((int) (var78_2 >> ((unsigned int) 4)))][(unsigned long) (var78_2 & 15)];
      var79_2 = &(*(((unsigned int *) var0_2) + 4));
      var80_2 = *var79_2;
      *var79_2 = Sbox_2[(long) ((int) (var80_2 >> ((unsigned int) 4)))][(unsigned long) (var80_2 & 15)];
      var81_2 = &(*(((unsigned int *) var0_2) + 8));
      var82_2 = *var81_2;
      *var81_2 = Sbox_2[(long) ((int) (var82_2 >> ((unsigned int) 4)))][(unsigned long) (var82_2 & 15)];
      var83_2 = &(*(((unsigned int *) var0_2) + 12));
      var84_2 = *var83_2;
      *var83_2 = Sbox_2[(long) ((int) (var84_2 >> ((unsigned int) 4)))][(unsigned long) (var84_2 & 15)];
      var85_2 = &(*(((unsigned int *) var0_2) + 16));
      var86_2 = *var85_2;
      *var85_2 = Sbox_2[(long) ((int) (var86_2 >> ((unsigned int) 4)))][(unsigned long) (var86_2 & 15)];
      var87_2 = &(*(((unsigned int *) var0_2) + 20));
      var156_phi_2 = var87_2;
      goto block4_2;

    case 8:
      var88_2 = &(*(((unsigned int *) var0_2) + 1));
      var89_2 = *var88_2;
      var90_2 = Sbox_2[(long) ((int) (var89_2 >> ((unsigned int) 4)))][(unsigned long) (var89_2 & 15)];
      var91_2 = &(*(((unsigned int *) var0_2) + 5));
      var92_2 = *var91_2;
      *var88_2 = Sbox_2[(long) ((int) (var92_2 >> ((unsigned int) 4)))][(unsigned long) (var92_2 & 15)];
      var93_2 = &(*(((unsigned int *) var0_2) + 9));
      var94_2 = *var93_2;
      *var91_2 = Sbox_2[(long) ((int) (var94_2 >> ((unsigned int) 4)))][(unsigned long) (var94_2 & 15)];
      var95_2 = &(*(((unsigned int *) var0_2) + 13));
      var96_2 = *var95_2;
      *var93_2 = Sbox_2[(long) ((int) (var96_2 >> ((unsigned int) 4)))][(unsigned long) (var96_2 & 15)];
      var97_2 = &(*(((unsigned int *) var0_2) + 17));
      var98_2 = *var97_2;
      *var95_2 = Sbox_2[(long) ((int) (var98_2 >> ((unsigned int) 4)))][(unsigned long) (var98_2 & 15)];
      var99_2 = &(*(((unsigned int *) var0_2) + 21));
      var100_2 = *var99_2;
      *var97_2 = Sbox_2[(long) ((int) (var100_2 >> ((unsigned int) 4)))][(unsigned long) (var100_2 & 15)];
      var101_2 = &(*(((unsigned int *) var0_2) + 25));
      var102_2 = *var101_2;
      *var99_2 = Sbox_2[(long) ((int) (var102_2 >> ((unsigned int) 4)))][(unsigned long) (var102_2 & 15)];
      var103_2 = &(*(((unsigned int *) var0_2) + 29));
      var104_2 = *var103_2;
      *var101_2 = Sbox_2[(long) ((int) (var104_2 >> ((unsigned int) 4)))][(unsigned long) (var104_2 & 15)];
      *var103_2 = var90_2;
      var105_2 = &(*(((unsigned int *) var0_2) + 2));
      var106_2 = *var105_2;
      var107_2 = Sbox_2[(long) ((int) (var106_2 >> ((unsigned int) 4)))][(unsigned long) (var106_2 & 15)];
      var108_2 = &(*(((unsigned int *) var0_2) + 14));
      var109_2 = *var108_2;
      *var105_2 = Sbox_2[(long) ((int) (var109_2 >> ((unsigned int) 4)))][(unsigned long) (var109_2 & 15)];
      var110_2 = &(*(((unsigned int *) var0_2) + 26));
      var111_2 = *var110_2;
      *var108_2 = Sbox_2[(long) ((int) (var111_2 >> ((unsigned int) 4)))][(unsigned long) (var111_2 & 15)];
      var112_2 = &(*(((unsigned int *) var0_2) + 6));
      var113_2 = *var112_2;
      *var110_2 = Sbox_2[(long) ((int) (var113_2 >> ((unsigned int) 4)))][(unsigned long) (var113_2 & 15)];
      var114_2 = &(*(((unsigned int *) var0_2) + 18));
      var115_2 = *var114_2;
      *var112_2 = Sbox_2[(long) ((int) (var115_2 >> ((unsigned int) 4)))][(unsigned long) (var115_2 & 15)];
      var116_2 = &(*(((unsigned int *) var0_2) + 30));
      var117_2 = *var116_2;
      *var114_2 = Sbox_2[(long) ((int) (var117_2 >> ((unsigned int) 4)))][(unsigned long) (var117_2 & 15)];
      var118_2 = &(*(((unsigned int *) var0_2) + 10));
      var119_2 = *var118_2;
      *var116_2 = Sbox_2[(long) ((int) (var119_2 >> ((unsigned int) 4)))][(unsigned long) (var119_2 & 15)];
      var120_2 = &(*(((unsigned int *) var0_2) + 22));
      var121_2 = *var120_2;
      *var118_2 = Sbox_2[(long) ((int) (var121_2 >> ((unsigned int) 4)))][(unsigned long) (var121_2 & 15)];
      *var120_2 = var107_2;
      var122_2 = &(*(((unsigned int *) var0_2) + 3));
      var123_2 = *var122_2;
      var124_2 = Sbox_2[(long) ((int) (var123_2 >> ((unsigned int) 4)))][(unsigned long) (var123_2 & 15)];
      var125_2 = &(*(((unsigned int *) var0_2) + 19));
      var126_2 = *var125_2;
      *var122_2 = Sbox_2[(long) ((int) (var126_2 >> ((unsigned int) 4)))][(unsigned long) (var126_2 & 15)];
      *var125_2 = var124_2;
      var127_2 = &(*(((unsigned int *) var0_2) + 7));
      var128_2 = *var127_2;
      var129_2 = Sbox_2[(long) ((int) (var128_2 >> ((unsigned int) 4)))][(unsigned long) (var128_2 & 15)];
      var130_2 = &(*(((unsigned int *) var0_2) + 23));
      var131_2 = *var130_2;
      *var127_2 = Sbox_2[(long) ((int) (var131_2 >> ((unsigned int) 4)))][(unsigned long) (var131_2 & 15)];
      *var130_2 = var129_2;
      var132_2 = &(*(((unsigned int *) var0_2) + 11));
      var133_2 = *var132_2;
      var134_2 = Sbox_2[(long) ((int) (var133_2 >> ((unsigned int) 4)))][(unsigned long) (var133_2 & 15)];
      var135_2 = &(*(((unsigned int *) var0_2) + 27));
      var136_2 = *var135_2;
      *var132_2 = Sbox_2[(long) ((int) (var136_2 >> ((unsigned int) 4)))][(unsigned long) (var136_2 & 15)];
      *var135_2 = var134_2;
      var137_2 = &(*(((unsigned int *) var0_2) + 15));
      var138_2 = *var137_2;
      var139_2 = Sbox_2[(long) ((int) (var138_2 >> ((unsigned int) 4)))][(unsigned long) (var138_2 & 15)];
      var140_2 = &(*(((unsigned int *) var0_2) + 31));
      var141_2 = *var140_2;
      *var137_2 = Sbox_2[(long) ((int) (var141_2 >> ((unsigned int) 4)))][(unsigned long) (var141_2 & 15)];
      *var140_2 = var139_2;
      var142_2 = *var0_2;
      *var0_2 = Sbox_2[(long) ((int) (var142_2 >> ((unsigned int) 4)))][(unsigned long) (var142_2 & 15)];
      var143_2 = &(*(((unsigned int *) var0_2) + 4));
      var144_2 = *var143_2;
      *var143_2 = Sbox_2[(long) ((int) (var144_2 >> ((unsigned int) 4)))][(unsigned long) (var144_2 & 15)];
      var145_2 = &(*(((unsigned int *) var0_2) + 8));
      var146_2 = *var145_2;
      *var145_2 = Sbox_2[(long) ((int) (var146_2 >> ((unsigned int) 4)))][(unsigned long) (var146_2 & 15)];
      var147_2 = &(*(((unsigned int *) var0_2) + 12));
      var148_2 = *var147_2;
      *var147_2 = Sbox_2[(long) ((int) (var148_2 >> ((unsigned int) 4)))][(unsigned long) (var148_2 & 15)];
      var149_2 = &(*(((unsigned int *) var0_2) + 16));
      var150_2 = *var149_2;
      *var149_2 = Sbox_2[(long) ((int) (var150_2 >> ((unsigned int) 4)))][(unsigned long) (var150_2 & 15)];
      var151_2 = &(*(((unsigned int *) var0_2) + 20));
      var152_2 = *var151_2;
      *var151_2 = Sbox_2[(long) ((int) (var152_2 >> ((unsigned int) 4)))][(unsigned long) (var152_2 & 15)];
      var153_2 = &(*(((unsigned int *) var0_2) + 24));
      var154_2 = *var153_2;
      *var153_2 = Sbox_2[(long) ((int) (var154_2 >> ((unsigned int) 4)))][(unsigned long) (var154_2 & 15)];
      var155_2 = &(*(((unsigned int *) var0_2) + 28));
      var156_phi_2 = var155_2;
      goto block4_2;

    default:
      return;

  }


  block4_1:
  var157_1 = *var156_phi_1;

  block4_2:
  var157_2 = *var156_phi_2;

  *var156_phi_1 = Sbox_1[(long) ((int) (var157_1 >> ((unsigned int) 4)))][(unsigned long) (var157_1 & 15)];
  *var156_phi_2 = Sbox_2[(long) ((int) (var157_2 >> ((unsigned int) 4)))][(unsigned long) (var157_2 & 15)];
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

  assert((*var156_phi_1) == (*var156_phi_2));
  assert((*var2_1) == (*var2_2));
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert((*var5_1) == (*var5_2));
  assert(var6_1 == var6_2);
  assert((*var7_1) == (*var7_2));
  assert(var8_1 == var8_2);
  assert((*var9_1) == (*var9_2));
  assert(var10_1 == var10_2);
  assert((*var11_1) == (*var11_2));
  assert(var12_1 == var12_2);
  assert(var13_1 == var13_2);
  assert((*var14_1) == (*var14_2));
  assert(var15_1 == var15_2);
  assert((*var16_1) == (*var16_2));
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert((*var19_1) == (*var19_2));
  assert(var20_1 == var20_2);
  assert((*var21_1) == (*var21_2));
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
  assert((*var24_1) == (*var24_2));
  assert(var25_1 == var25_2);
  assert((*var26_1) == (*var26_2));
  assert(var27_1 == var27_2);
  assert((*var28_1) == (*var28_2));
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert((*var31_1) == (*var31_2));
  assert(var32_1 == var32_2);
  assert((*var33_1) == (*var33_2));
  assert(var34_1 == var34_2);
  assert((*var35_1) == (*var35_2));
  assert((*var36_1) == (*var36_2));
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
  assert((*var39_1) == (*var39_2));
  assert(var40_1 == var40_2);
  assert((*var41_1) == (*var41_2));
  assert(var42_1 == var42_2);
  assert((*var43_1) == (*var43_2));
  assert(var44_1 == var44_2);
  assert((*var45_1) == (*var45_2));
  assert(var46_1 == var46_2);
  assert((*var47_1) == (*var47_2));
  assert(var48_1 == var48_2);
  assert((*var49_1) == (*var49_2));
  assert(var50_1 == var50_2);
  assert(var51_1 == var51_2);
  assert((*var52_1) == (*var52_2));
  assert(var53_1 == var53_2);
  assert((*var54_1) == (*var54_2));
  assert(var55_1 == var55_2);
  assert((*var56_1) == (*var56_2));
  assert(var57_1 == var57_2);
  assert(var58_1 == var58_2);
  assert((*var59_1) == (*var59_2));
  assert(var60_1 == var60_2);
  assert((*var61_1) == (*var61_2));
  assert(var62_1 == var62_2);
  assert((*var63_1) == (*var63_2));
  assert(var64_1 == var64_2);
  assert(var65_1 == var65_2);
  assert((*var66_1) == (*var66_2));
  assert(var67_1 == var67_2);
  assert((*var68_1) == (*var68_2));
  assert(var69_1 == var69_2);
  assert(var70_1 == var70_2);
  assert((*var71_1) == (*var71_2));
  assert(var72_1 == var72_2);
  assert((*var73_1) == (*var73_2));
  assert(var74_1 == var74_2);
  assert(var75_1 == var75_2);
  assert((*var76_1) == (*var76_2));
  assert(var77_1 == var77_2);
  assert(var78_1 == var78_2);
  assert((*var79_1) == (*var79_2));
  assert(var80_1 == var80_2);
  assert((*var81_1) == (*var81_2));
  assert(var82_1 == var82_2);
  assert((*var83_1) == (*var83_2));
  assert(var84_1 == var84_2);
  assert((*var85_1) == (*var85_2));
  assert(var86_1 == var86_2);
  assert((*var87_1) == (*var87_2));
  assert((*var88_1) == (*var88_2));
  assert(var89_1 == var89_2);
  assert(var90_1 == var90_2);
  assert((*var91_1) == (*var91_2));
  assert(var92_1 == var92_2);
  assert((*var93_1) == (*var93_2));
  assert(var94_1 == var94_2);
  assert((*var95_1) == (*var95_2));
  assert(var96_1 == var96_2);
  assert((*var97_1) == (*var97_2));
  assert(var98_1 == var98_2);
  assert((*var99_1) == (*var99_2));
  assert(var100_1 == var100_2);
  assert((*var101_1) == (*var101_2));
  assert(var102_1 == var102_2);
  assert((*var103_1) == (*var103_2));
  assert(var104_1 == var104_2);
  assert((*var105_1) == (*var105_2));
  assert(var106_1 == var106_2);
  assert(var107_1 == var107_2);
  assert((*var108_1) == (*var108_2));
  assert(var109_1 == var109_2);
  assert((*var110_1) == (*var110_2));
  assert(var111_1 == var111_2);
  assert((*var112_1) == (*var112_2));
  assert(var113_1 == var113_2);
  assert((*var114_1) == (*var114_2));
  assert(var115_1 == var115_2);
  assert((*var116_1) == (*var116_2));
  assert(var117_1 == var117_2);
  assert((*var118_1) == (*var118_2));
  assert(var119_1 == var119_2);
  assert((*var120_1) == (*var120_2));
  assert(var121_1 == var121_2);
  assert((*var122_1) == (*var122_2));
  assert(var123_1 == var123_2);
  assert(var124_1 == var124_2);
  assert((*var125_1) == (*var125_2));
  assert(var126_1 == var126_2);
  assert((*var127_1) == (*var127_2));
  assert(var128_1 == var128_2);
  assert(var129_1 == var129_2);
  assert((*var130_1) == (*var130_2));
  assert(var131_1 == var131_2);
  assert((*var132_1) == (*var132_2));
  assert(var133_1 == var133_2);
  assert(var134_1 == var134_2);
  assert((*var135_1) == (*var135_2));
  assert(var136_1 == var136_2);
  assert((*var137_1) == (*var137_2));
  assert(var138_1 == var138_2);
  assert(var139_1 == var139_2);
  assert((*var140_1) == (*var140_2));
  assert(var141_1 == var141_2);
  assert(var142_1 == var142_2);
  assert((*var143_1) == (*var143_2));
  assert(var144_1 == var144_2);
  assert((*var145_1) == (*var145_2));
  assert(var146_1 == var146_2);
  assert((*var147_1) == (*var147_2));
  assert(var148_1 == var148_2);
  assert((*var149_1) == (*var149_2));
  assert(var150_1 == var150_2);
  assert((*var151_1) == (*var151_2));
  assert(var152_1 == var152_2);
  assert((*var153_1) == (*var153_2));
  assert(var154_1 == var154_2);
  assert((*var155_1) == (*var155_2));
  assert(var157_1 == var157_2);
}

void ByteSub_ShiftRow(unsigned int *var0, unsigned int var1)
{
  unsigned int *var156_phi;
  unsigned int *var2;
  unsigned int var3;
  unsigned int var4;
  unsigned int *var5;
  unsigned int var6;
  unsigned int *var7;
  unsigned int var8;
  unsigned int *var9;
  unsigned int var10;
  unsigned int *var11;
  unsigned int var12;
  unsigned int var13;
  unsigned int *var14;
  unsigned int var15;
  unsigned int *var16;
  unsigned int var17;
  unsigned int var18;
  unsigned int *var19;
  unsigned int var20;
  unsigned int *var21;
  unsigned int var22;
  unsigned int var23;
  unsigned int *var24;
  unsigned int var25;
  unsigned int *var26;
  unsigned int var27;
  unsigned int *var28;
  unsigned int var29;
  unsigned int var30;
  unsigned int *var31;
  unsigned int var32;
  unsigned int *var33;
  unsigned int var34;
  unsigned int *var35;
  unsigned int *var36;
  unsigned int var37;
  unsigned int var38;
  unsigned int *var39;
  unsigned int var40;
  unsigned int *var41;
  unsigned int var42;
  unsigned int *var43;
  unsigned int var44;
  unsigned int *var45;
  unsigned int var46;
  unsigned int *var47;
  unsigned int var48;
  unsigned int *var49;
  unsigned int var50;
  unsigned int var51;
  unsigned int *var52;
  unsigned int var53;
  unsigned int *var54;
  unsigned int var55;
  unsigned int *var56;
  unsigned int var57;
  unsigned int var58;
  unsigned int *var59;
  unsigned int var60;
  unsigned int *var61;
  unsigned int var62;
  unsigned int *var63;
  unsigned int var64;
  unsigned int var65;
  unsigned int *var66;
  unsigned int var67;
  unsigned int *var68;
  unsigned int var69;
  unsigned int var70;
  unsigned int *var71;
  unsigned int var72;
  unsigned int *var73;
  unsigned int var74;
  unsigned int var75;
  unsigned int *var76;
  unsigned int var77;
  unsigned int var78;
  unsigned int *var79;
  unsigned int var80;
  unsigned int *var81;
  unsigned int var82;
  unsigned int *var83;
  unsigned int var84;
  unsigned int *var85;
  unsigned int var86;
  unsigned int *var87;
  unsigned int *var88;
  unsigned int var89;
  unsigned int var90;
  unsigned int *var91;
  unsigned int var92;
  unsigned int *var93;
  unsigned int var94;
  unsigned int *var95;
  unsigned int var96;
  unsigned int *var97;
  unsigned int var98;
  unsigned int *var99;
  unsigned int var100;
  unsigned int *var101;
  unsigned int var102;
  unsigned int *var103;
  unsigned int var104;
  unsigned int *var105;
  unsigned int var106;
  unsigned int var107;
  unsigned int *var108;
  unsigned int var109;
  unsigned int *var110;
  unsigned int var111;
  unsigned int *var112;
  unsigned int var113;
  unsigned int *var114;
  unsigned int var115;
  unsigned int *var116;
  unsigned int var117;
  unsigned int *var118;
  unsigned int var119;
  unsigned int *var120;
  unsigned int var121;
  unsigned int *var122;
  unsigned int var123;
  unsigned int var124;
  unsigned int *var125;
  unsigned int var126;
  unsigned int *var127;
  unsigned int var128;
  unsigned int var129;
  unsigned int *var130;
  unsigned int var131;
  unsigned int *var132;
  unsigned int var133;
  unsigned int var134;
  unsigned int *var135;
  unsigned int var136;
  unsigned int *var137;
  unsigned int var138;
  unsigned int var139;
  unsigned int *var140;
  unsigned int var141;
  unsigned int var142;
  unsigned int *var143;
  unsigned int var144;
  unsigned int *var145;
  unsigned int var146;
  unsigned int *var147;
  unsigned int var148;
  unsigned int *var149;
  unsigned int var150;
  unsigned int *var151;
  unsigned int var152;
  unsigned int *var153;
  unsigned int var154;
  unsigned int *var155;
  unsigned int var157;
  block0:
  switch (var1)
  {
    case 4:
      var2 = &(*(((unsigned int *) var0) + 1));
      var3 = *var2;
      var4 = Sbox[(long) ((int) (var3 >> ((unsigned int) 4)))][(unsigned long) (var3 & 15)];
      var5 = &(*(((unsigned int *) var0) + 5));
      var6 = *var5;
      *var2 = Sbox[(long) ((int) (var6 >> ((unsigned int) 4)))][(unsigned long) (var6 & 15)];
      var7 = &(*(((unsigned int *) var0) + 9));
      var8 = *var7;
      *var5 = Sbox[(long) ((int) (var8 >> ((unsigned int) 4)))][(unsigned long) (var8 & 15)];
      var9 = &(*(((unsigned int *) var0) + 13));
      var10 = *var9;
      *var7 = Sbox[(long) ((int) (var10 >> ((unsigned int) 4)))][(unsigned long) (var10 & 15)];
      *var9 = var4;
      var11 = &(*(((unsigned int *) var0) + 2));
      var12 = *var11;
      var13 = Sbox[(long) ((int) (var12 >> ((unsigned int) 4)))][(unsigned long) (var12 & 15)];
      var14 = &(*(((unsigned int *) var0) + 10));
      var15 = *var14;
      *var11 = Sbox[(long) ((int) (var15 >> ((unsigned int) 4)))][(unsigned long) (var15 & 15)];
      *var14 = var13;
      var16 = &(*(((unsigned int *) var0) + 6));
      var17 = *var16;
      var18 = Sbox[(long) ((int) (var17 >> ((unsigned int) 4)))][(unsigned long) (var17 & 15)];
      var19 = &(*(((unsigned int *) var0) + 14));
      var20 = *var19;
      *var16 = Sbox[(long) ((int) (var20 >> ((unsigned int) 4)))][(unsigned long) (var20 & 15)];
      *var19 = var18;
      var21 = &(*(((unsigned int *) var0) + 3));
      var22 = *var21;
      var23 = Sbox[(long) ((int) (var22 >> ((unsigned int) 4)))][(unsigned long) (var22 & 15)];
      var24 = &(*(((unsigned int *) var0) + 15));
      var25 = *var24;
      *var21 = Sbox[(long) ((int) (var25 >> ((unsigned int) 4)))][(unsigned long) (var25 & 15)];
      var26 = &(*(((unsigned int *) var0) + 11));
      var27 = *var26;
      *var24 = Sbox[(long) ((int) (var27 >> ((unsigned int) 4)))][(unsigned long) (var27 & 15)];
      var28 = &(*(((unsigned int *) var0) + 7));
      var29 = *var28;
      *var26 = Sbox[(long) ((int) (var29 >> ((unsigned int) 4)))][(unsigned long) (var29 & 15)];
      *var28 = var23;
      var30 = *var0;
      *var0 = Sbox[(long) ((int) (var30 >> ((unsigned int) 4)))][(unsigned long) (var30 & 15)];
      var31 = &(*(((unsigned int *) var0) + 4));
      var32 = *var31;
      *var31 = Sbox[(long) ((int) (var32 >> ((unsigned int) 4)))][(unsigned long) (var32 & 15)];
      var33 = &(*(((unsigned int *) var0) + 8));
      var34 = *var33;
      *var33 = Sbox[(long) ((int) (var34 >> ((unsigned int) 4)))][(unsigned long) (var34 & 15)];
      var35 = &(*(((unsigned int *) var0) + 12));
      var156_phi = var35;
      goto block4;

    case 6:
      var36 = &(*(((unsigned int *) var0) + 1));
      var37 = *var36;
      var38 = Sbox[(long) ((int) (var37 >> ((unsigned int) 4)))][(unsigned long) (var37 & 15)];
      var39 = &(*(((unsigned int *) var0) + 5));
      var40 = *var39;
      *var36 = Sbox[(long) ((int) (var40 >> ((unsigned int) 4)))][(unsigned long) (var40 & 15)];
      var41 = &(*(((unsigned int *) var0) + 9));
      var42 = *var41;
      *var39 = Sbox[(long) ((int) (var42 >> ((unsigned int) 4)))][(unsigned long) (var42 & 15)];
      var43 = &(*(((unsigned int *) var0) + 13));
      var44 = *var43;
      *var41 = Sbox[(long) ((int) (var44 >> ((unsigned int) 4)))][(unsigned long) (var44 & 15)];
      var45 = &(*(((unsigned int *) var0) + 17));
      var46 = *var45;
      *var43 = Sbox[(long) ((int) (var46 >> ((unsigned int) 4)))][(unsigned long) (var46 & 15)];
      var47 = &(*(((unsigned int *) var0) + 21));
      var48 = *var47;
      *var45 = Sbox[(long) ((int) (var48 >> ((unsigned int) 4)))][(unsigned long) (var48 & 15)];
      *var47 = var38;
      var49 = &(*(((unsigned int *) var0) + 2));
      var50 = *var49;
      var51 = Sbox[(long) ((int) (var50 >> ((unsigned int) 4)))][(unsigned long) (var50 & 15)];
      var52 = &(*(((unsigned int *) var0) + 10));
      var53 = *var52;
      *var49 = Sbox[(long) ((int) (var53 >> ((unsigned int) 4)))][(unsigned long) (var53 & 15)];
      var54 = &(*(((unsigned int *) var0) + 18));
      var55 = *var54;
      *var52 = Sbox[(long) ((int) (var55 >> ((unsigned int) 4)))][(unsigned long) (var55 & 15)];
      *var54 = var51;
      var56 = &(*(((unsigned int *) var0) + 6));
      var57 = *var56;
      var58 = Sbox[(long) ((int) (var57 >> ((unsigned int) 4)))][(unsigned long) (var57 & 15)];
      var59 = &(*(((unsigned int *) var0) + 14));
      var60 = *var59;
      *var56 = Sbox[(long) ((int) (var60 >> ((unsigned int) 4)))][(unsigned long) (var60 & 15)];
      var61 = &(*(((unsigned int *) var0) + 22));
      var62 = *var61;
      *var59 = Sbox[(long) ((int) (var62 >> ((unsigned int) 4)))][(unsigned long) (var62 & 15)];
      *var61 = var58;
      var63 = &(*(((unsigned int *) var0) + 3));
      var64 = *var63;
      var65 = Sbox[(long) ((int) (var64 >> ((unsigned int) 4)))][(unsigned long) (var64 & 15)];
      var66 = &(*(((unsigned int *) var0) + 15));
      var67 = *var66;
      *var63 = Sbox[(long) ((int) (var67 >> ((unsigned int) 4)))][(unsigned long) (var67 & 15)];
      *var66 = var65;
      var68 = &(*(((unsigned int *) var0) + 7));
      var69 = *var68;
      var70 = Sbox[(long) ((int) (var69 >> ((unsigned int) 4)))][(unsigned long) (var69 & 15)];
      var71 = &(*(((unsigned int *) var0) + 19));
      var72 = *var71;
      *var68 = Sbox[(long) ((int) (var72 >> ((unsigned int) 4)))][(unsigned long) (var72 & 15)];
      *var71 = var70;
      var73 = &(*(((unsigned int *) var0) + 11));
      var74 = *var73;
      var75 = Sbox[(long) ((int) (var74 >> ((unsigned int) 4)))][(unsigned long) (var74 & 15)];
      var76 = &(*(((unsigned int *) var0) + 23));
      var77 = *var76;
      *var73 = Sbox[(long) ((int) (var77 >> ((unsigned int) 4)))][(unsigned long) (var77 & 15)];
      *var76 = var75;
      var78 = *var0;
      *var0 = Sbox[(long) ((int) (var78 >> ((unsigned int) 4)))][(unsigned long) (var78 & 15)];
      var79 = &(*(((unsigned int *) var0) + 4));
      var80 = *var79;
      *var79 = Sbox[(long) ((int) (var80 >> ((unsigned int) 4)))][(unsigned long) (var80 & 15)];
      var81 = &(*(((unsigned int *) var0) + 8));
      var82 = *var81;
      *var81 = Sbox[(long) ((int) (var82 >> ((unsigned int) 4)))][(unsigned long) (var82 & 15)];
      var83 = &(*(((unsigned int *) var0) + 12));
      var84 = *var83;
      *var83 = Sbox[(long) ((int) (var84 >> ((unsigned int) 4)))][(unsigned long) (var84 & 15)];
      var85 = &(*(((unsigned int *) var0) + 16));
      var86 = *var85;
      *var85 = Sbox[(long) ((int) (var86 >> ((unsigned int) 4)))][(unsigned long) (var86 & 15)];
      var87 = &(*(((unsigned int *) var0) + 20));
      var156_phi = var87;
      goto block4;

    case 8:
      var88 = &(*(((unsigned int *) var0) + 1));
      var89 = *var88;
      var90 = Sbox[(long) ((int) (var89 >> ((unsigned int) 4)))][(unsigned long) (var89 & 15)];
      var91 = &(*(((unsigned int *) var0) + 5));
      var92 = *var91;
      *var88 = Sbox[(long) ((int) (var92 >> ((unsigned int) 4)))][(unsigned long) (var92 & 15)];
      var93 = &(*(((unsigned int *) var0) + 9));
      var94 = *var93;
      *var91 = Sbox[(long) ((int) (var94 >> ((unsigned int) 4)))][(unsigned long) (var94 & 15)];
      var95 = &(*(((unsigned int *) var0) + 13));
      var96 = *var95;
      *var93 = Sbox[(long) ((int) (var96 >> ((unsigned int) 4)))][(unsigned long) (var96 & 15)];
      var97 = &(*(((unsigned int *) var0) + 17));
      var98 = *var97;
      *var95 = Sbox[(long) ((int) (var98 >> ((unsigned int) 4)))][(unsigned long) (var98 & 15)];
      var99 = &(*(((unsigned int *) var0) + 21));
      var100 = *var99;
      *var97 = Sbox[(long) ((int) (var100 >> ((unsigned int) 4)))][(unsigned long) (var100 & 15)];
      var101 = &(*(((unsigned int *) var0) + 25));
      var102 = *var101;
      *var99 = Sbox[(long) ((int) (var102 >> ((unsigned int) 4)))][(unsigned long) (var102 & 15)];
      var103 = &(*(((unsigned int *) var0) + 29));
      var104 = *var103;
      *var101 = Sbox[(long) ((int) (var104 >> ((unsigned int) 4)))][(unsigned long) (var104 & 15)];
      *var103 = var90;
      var105 = &(*(((unsigned int *) var0) + 2));
      var106 = *var105;
      var107 = Sbox[(long) ((int) (var106 >> ((unsigned int) 4)))][(unsigned long) (var106 & 15)];
      var108 = &(*(((unsigned int *) var0) + 14));
      var109 = *var108;
      *var105 = Sbox[(long) ((int) (var109 >> ((unsigned int) 4)))][(unsigned long) (var109 & 15)];
      var110 = &(*(((unsigned int *) var0) + 26));
      var111 = *var110;
      *var108 = Sbox[(long) ((int) (var111 >> ((unsigned int) 4)))][(unsigned long) (var111 & 15)];
      var112 = &(*(((unsigned int *) var0) + 6));
      var113 = *var112;
      *var110 = Sbox[(long) ((int) (var113 >> ((unsigned int) 4)))][(unsigned long) (var113 & 15)];
      var114 = &(*(((unsigned int *) var0) + 18));
      var115 = *var114;
      *var112 = Sbox[(long) ((int) (var115 >> ((unsigned int) 4)))][(unsigned long) (var115 & 15)];
      var116 = &(*(((unsigned int *) var0) + 30));
      var117 = *var116;
      *var114 = Sbox[(long) ((int) (var117 >> ((unsigned int) 4)))][(unsigned long) (var117 & 15)];
      var118 = &(*(((unsigned int *) var0) + 10));
      var119 = *var118;
      *var116 = Sbox[(long) ((int) (var119 >> ((unsigned int) 4)))][(unsigned long) (var119 & 15)];
      var120 = &(*(((unsigned int *) var0) + 22));
      var121 = *var120;
      *var118 = Sbox[(long) ((int) (var121 >> ((unsigned int) 4)))][(unsigned long) (var121 & 15)];
      *var120 = var107;
      var122 = &(*(((unsigned int *) var0) + 3));
      var123 = *var122;
      var124 = Sbox[(long) ((int) (var123 >> ((unsigned int) 4)))][(unsigned long) (var123 & 15)];
      var125 = &(*(((unsigned int *) var0) + 19));
      var126 = *var125;
      *var122 = Sbox[(long) ((int) (var126 >> ((unsigned int) 4)))][(unsigned long) (var126 & 15)];
      *var125 = var124;
      var127 = &(*(((unsigned int *) var0) + 7));
      var128 = *var127;
      var129 = Sbox[(long) ((int) (var128 >> ((unsigned int) 4)))][(unsigned long) (var128 & 15)];
      var130 = &(*(((unsigned int *) var0) + 23));
      var131 = *var130;
      *var127 = Sbox[(long) ((int) (var131 >> ((unsigned int) 4)))][(unsigned long) (var131 & 15)];
      *var130 = var129;
      var132 = &(*(((unsigned int *) var0) + 11));
      var133 = *var132;
      var134 = Sbox[(long) ((int) (var133 >> ((unsigned int) 4)))][(unsigned long) (var133 & 15)];
      var135 = &(*(((unsigned int *) var0) + 27));
      var136 = *var135;
      *var132 = Sbox[(long) ((int) (var136 >> ((unsigned int) 4)))][(unsigned long) (var136 & 15)];
      *var135 = var134;
      var137 = &(*(((unsigned int *) var0) + 15));
      var138 = *var137;
      var139 = Sbox[(long) ((int) (var138 >> ((unsigned int) 4)))][(unsigned long) (var138 & 15)];
      var140 = &(*(((unsigned int *) var0) + 31));
      var141 = *var140;
      *var137 = Sbox[(long) ((int) (var141 >> ((unsigned int) 4)))][(unsigned long) (var141 & 15)];
      *var140 = var139;
      var142 = *var0;
      *var0 = Sbox[(long) ((int) (var142 >> ((unsigned int) 4)))][(unsigned long) (var142 & 15)];
      var143 = &(*(((unsigned int *) var0) + 4));
      var144 = *var143;
      *var143 = Sbox[(long) ((int) (var144 >> ((unsigned int) 4)))][(unsigned long) (var144 & 15)];
      var145 = &(*(((unsigned int *) var0) + 8));
      var146 = *var145;
      *var145 = Sbox[(long) ((int) (var146 >> ((unsigned int) 4)))][(unsigned long) (var146 & 15)];
      var147 = &(*(((unsigned int *) var0) + 12));
      var148 = *var147;
      *var147 = Sbox[(long) ((int) (var148 >> ((unsigned int) 4)))][(unsigned long) (var148 & 15)];
      var149 = &(*(((unsigned int *) var0) + 16));
      var150 = *var149;
      *var149 = Sbox[(long) ((int) (var150 >> ((unsigned int) 4)))][(unsigned long) (var150 & 15)];
      var151 = &(*(((unsigned int *) var0) + 20));
      var152 = *var151;
      *var151 = Sbox[(long) ((int) (var152 >> ((unsigned int) 4)))][(unsigned long) (var152 & 15)];
      var153 = &(*(((unsigned int *) var0) + 24));
      var154 = *var153;
      *var153 = Sbox[(long) ((int) (var154 >> ((unsigned int) 4)))][(unsigned long) (var154 & 15)];
      var155 = &(*(((unsigned int *) var0) + 28));
      var156_phi = var155;
      goto block4;

    default:
      return;

  }


  block4:
  var157 = *var156_phi;

  *var156_phi = Sbox[(long) ((int) (var157 >> ((unsigned int) 4)))][(unsigned long) (var157 & 15)];
  return;
}

void KeySchedule_2(unsigned int var0_1, unsigned int *var1_1, unsigned int var0_2, unsigned int *var1_2)
{
  unsigned int var2_1[4];
  unsigned int var2_2[4];
  unsigned char *var3_1;
  unsigned char *var3_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned int var5_phi_1;
  unsigned int var5_phi_2;
  unsigned long var6_phi_1;
  unsigned long var6_phi_2;
  unsigned long var17_phi_1;
  unsigned long var17_phi_2;
  unsigned long var20_phi_1;
  unsigned long var20_phi_2;
  unsigned int *var29_phi_1;
  unsigned int *var29_phi_2;
  unsigned int *var30_phi_1;
  unsigned int *var30_phi_2;
  unsigned long var31_phi_1;
  unsigned long var31_phi_2;
  unsigned long var36_phi_1;
  unsigned long var36_phi_2;
  unsigned int var39_phi_1;
  unsigned int var39_phi_2;
  long var7_1;
  long var7_2;
  unsigned int *var8_1;
  unsigned int *var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int *var10_1;
  unsigned int *var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned int *var12_1;
  unsigned int *var12_2;
  unsigned int *var13_1;
  unsigned int *var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  unsigned int *var15_1;
  unsigned int *var15_2;
  unsigned long var16_1;
  unsigned long var16_2;
  long var18_1;
  long var18_2;
  long var19_1;
  long var19_2;
  unsigned int var21_1;
  unsigned int var21_2;
  long var22_1;
  long var22_2;
  unsigned int var23_1;
  unsigned int var23_2;
  unsigned int var24_1;
  unsigned int var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int var26_1;
  unsigned int var26_2;
  unsigned int *var27_1;
  unsigned int *var27_2;
  unsigned int *var28_1;
  unsigned int *var28_2;
  unsigned int *var32_1;
  unsigned int *var32_2;
  unsigned int var33_1;
  unsigned int var33_2;
  long var34_1;
  long var34_2;
  long var35_1;
  long var35_2;
  long var37_1;
  long var37_2;
  long var38_1;
  long var38_2;
  block0_1:
  var3_1 = (unsigned char *) (&var2_1);

  block0_2:
  var3_2 = (unsigned char *) (&var2_2);

  switch (var0_1)
  {
    case 128128:
      goto block7_1;

    case 128192:
      goto block7_1;

    case 128256:
      goto block7_1;

    case 192128:
      var4_phi_1 = 0;
      var5_phi_1 = 6;
      goto block7_1;

    case 192192:
      var4_phi_1 = 0;
      var5_phi_1 = 6;
      goto block7_1;

    case 192256:
      var4_phi_1 = 0;
      var5_phi_1 = 6;
      goto block7_1;

    case 256128:
      var4_phi_1 = 1;
      var5_phi_1 = 8;
      goto block7_1;

    case 256192:
      var4_phi_1 = 1;
      var5_phi_1 = 8;
      goto block7_1;

    case 256256:
      var4_phi_1 = 1;
      var5_phi_1 = 8;
      goto block7_1;

    default:
      return var39_phi_1;

  }

  switch (var0_2)
  {
    case 128128:
      goto block7_2;

    case 128192:
      goto block7_2;

    case 128256:
      goto block7_2;

    case 192128:
      var4_phi_2 = 0;
      var5_phi_2 = 6;
      goto block7_2;

    case 192192:
      var4_phi_2 = 0;
      var5_phi_2 = 6;
      goto block7_2;

    case 192256:
      var4_phi_2 = 0;
      var5_phi_2 = 6;
      goto block7_2;

    case 256128:
      var4_phi_2 = 1;
      var5_phi_2 = 8;
      goto block7_2;

    case 256192:
      var4_phi_2 = 1;
      var5_phi_2 = 8;
      goto block7_2;

    case 256256:
      var4_phi_2 = 1;
      var5_phi_2 = 8;
      goto block7_2;

    default:
      return var39_phi_2;

  }

  block15_1:
  *var30_phi_1 = *var29_phi_1;

  block15_2:
  *var30_phi_2 = *var29_phi_2;

  if ((var4_phi_1) ? (var21_1 == 4) : (0))
  {
    var31_phi_1 = 0;
    goto block16_1;
  }
  else
  {
    goto block17_1;
  }
  if ((var4_phi_2) ? (var21_2 == 4) : (0))
  {
    var31_phi_2 = 0;
    goto block16_2;
  }
  else
  {
    goto block17_2;
  }
  block7_1:
  var6_phi_1 = 0;

  block7_2:
  var6_phi_2 = 0;

  goto block8_1;
  goto block8_2;
  block8_1:
  var7_1 = ((long) var6_phi_1) << ((long) ((unsigned long) ((long) 2)));

  block8_2:
  var7_2 = ((long) var6_phi_2) << ((long) ((unsigned long) ((long) 2)));

  var17_phi_1 = 0;
  var17_phi_2 = 0;
  goto block10_1;
  goto block10_2;
  block10_1:
  word_1[var17_phi_1][var6_phi_1] = *(((unsigned int *) var1_1) + (((long) var17_phi_1) + ((long) var7_1)));

  block10_2:
  word_2[var17_phi_2][var6_phi_2] = *(((unsigned int *) var1_2) + (((long) var17_phi_2) + ((long) var7_2)));

  var18_1 = ((long) var17_phi_1) + ((long) 1);
  var18_2 = ((long) var17_phi_2) + ((long) 1);
  if (var18_1 == 4)
  {
    var19_1 = ((long) var6_phi_1) + ((long) 1);
    if (var19_1 == 8)
    {
      var8_1 = &var2_1[0];
      var9_1 = &var2_1[1];
      var10_1 = &var2_1[2];
      var11_1 = &var2_1[3];
      var12_1 = &var2_1[0];
      var13_1 = &var2_1[1];
      var14_1 = &var2_1[2];
      var15_1 = &var2_1[3];
      var16_1 = (unsigned long) var5_phi_1;
      var20_phi_1 = 8;
      goto block12_1;
    }
    else
    {
      var6_phi_1 = var19_1;
      goto block8_1;
    }
  }
  else
  {
    var17_phi_1 = var18_1;
    goto block10_1;
  }
  if (var18_2 == 4)
  {
    var19_2 = ((long) var6_phi_2) + ((long) 1);
    if (var19_2 == 8)
    {
      var8_2 = &var2_2[0];
      var9_2 = &var2_2[1];
      var10_2 = &var2_2[2];
      var11_2 = &var2_2[3];
      var12_2 = &var2_2[0];
      var13_2 = &var2_2[1];
      var14_2 = &var2_2[2];
      var15_2 = &var2_2[3];
      var16_2 = (unsigned long) var5_phi_2;
      var20_phi_2 = 8;
      goto block12_2;
    }
    else
    {
      var6_phi_2 = var19_2;
      goto block8_2;
    }
  }
  else
  {
    var17_phi_2 = var18_2;
    goto block10_2;
  }
  block12_1:
  var21_1 = ((unsigned int) var20_phi_1) % var5_phi_1;

  block12_2:
  var21_2 = ((unsigned int) var20_phi_2) % var5_phi_2;

  var22_1 = ((long) var20_phi_1) + ((long) (-1));
  var22_2 = ((long) var20_phi_2) + ((long) (-1));
  if (var21_1 == 0)
  {
    var23_1 = word_1[1][var22_1];
    *var12_1 = Rcon0_1[(long) ((int) (((int) (((unsigned int) var20_phi_1) / var5_phi_1)) + ((int) (-1))))] ^ Sbox_1[(long) ((int) (((int) var23_1) / ((int) 16)))][(long) ((int) (((int) var23_1) % ((int) 16)))];
    var24_1 = word_1[2][var22_1];
    *var13_1 = Sbox_1[(long) ((int) (((int) var24_1) / ((int) 16)))][(long) ((int) (((int) var24_1) % ((int) 16)))];
    var25_1 = word_1[3][var22_1];
    *var14_1 = Sbox_1[(long) ((int) (((int) var25_1) / ((int) 16)))][(long) ((int) (((int) var25_1) % ((int) 16)))];
    var26_1 = word_1[0][var22_1];
    var27_1 = &Sbox_1[(long) ((int) (((int) var26_1) / ((int) 16)))][(long) ((int) (((int) var26_1) % ((int) 16)))];
    var29_phi_1 = var27_1;
    var30_phi_1 = var15_1;
    goto block15_1;
  }
  else
  {
    *var8_1 = word_1[0][var22_1];
    *var9_1 = word_1[1][var22_1];
    *var10_1 = word_1[2][var22_1];
    var28_1 = &word_1[3][var22_1];
    var29_phi_1 = var28_1;
    var30_phi_1 = var11_1;
    goto block15_1;
  }
  if (var21_2 == 0)
  {
    var23_2 = word_2[1][var22_2];
    *var12_2 = Rcon0_2[(long) ((int) (((int) (((unsigned int) var20_phi_2) / var5_phi_2)) + ((int) (-1))))] ^ Sbox_2[(long) ((int) (((int) var23_2) / ((int) 16)))][(long) ((int) (((int) var23_2) % ((int) 16)))];
    var24_2 = word_2[2][var22_2];
    *var13_2 = Sbox_2[(long) ((int) (((int) var24_2) / ((int) 16)))][(long) ((int) (((int) var24_2) % ((int) 16)))];
    var25_2 = word_2[3][var22_2];
    *var14_2 = Sbox_2[(long) ((int) (((int) var25_2) / ((int) 16)))][(long) ((int) (((int) var25_2) % ((int) 16)))];
    var26_2 = word_2[0][var22_2];
    var27_2 = &Sbox_2[(long) ((int) (((int) var26_2) / ((int) 16)))][(long) ((int) (((int) var26_2) % ((int) 16)))];
    var29_phi_2 = var27_2;
    var30_phi_2 = var15_2;
    goto block15_2;
  }
  else
  {
    *var8_2 = word_2[0][var22_2];
    *var9_2 = word_2[1][var22_2];
    *var10_2 = word_2[2][var22_2];
    var28_2 = &word_2[3][var22_2];
    var29_phi_2 = var28_2;
    var30_phi_2 = var11_2;
    goto block15_2;
  }
  block16_1:
  var32_1 = &var2_1[var31_phi_1];

  block16_2:
  var32_2 = &var2_2[var31_phi_2];

  var33_1 = *var32_1;
  var33_2 = *var32_2;
  *var32_1 = Sbox_1[(long) ((int) (((int) var33_1) / ((int) 16)))][(long) ((int) (((int) var33_1) % ((int) 16)))];
  *var32_2 = Sbox_2[(long) ((int) (((int) var33_2) / ((int) 16)))][(long) ((int) (((int) var33_2) % ((int) 16)))];
  var34_1 = ((long) var31_phi_1) + ((long) 1);
  var34_2 = ((long) var31_phi_2) + ((long) 1);
  if (var34_1 == 4)
  {
    goto block17_1;
  }
  else
  {
    var31_phi_1 = var34_1;
    goto block16_1;
  }
  if (var34_2 == 4)
  {
    goto block17_2;
  }
  else
  {
    var31_phi_2 = var34_2;
    goto block16_2;
  }
  block17_1:
  var35_1 = ((long) var20_phi_1) - ((long) var16_1);

  block17_2:
  var35_2 = ((long) var20_phi_2) - ((long) var16_2);

  var36_phi_1 = 0;
  var36_phi_2 = 0;
  goto block18_1;
  goto block18_2;
  block18_1:
  word_1[var36_phi_1][var20_phi_1] = var2_1[var36_phi_1] ^ word_1[var36_phi_1][var35_1];

  block18_2:
  word_2[var36_phi_2][var20_phi_2] = var2_2[var36_phi_2] ^ word_2[var36_phi_2][var35_2];

  var37_1 = ((long) var36_phi_1) + ((long) 1);
  var37_2 = ((long) var36_phi_2) + ((long) 1);
  if (var37_1 == 4)
  {
    var38_1 = ((long) var20_phi_1) + ((long) 1);
    if (var38_1 == 40)
    {
      var39_phi_1 = 0;
      return var39_phi_1;
    }
    else
    {
      var20_phi_1 = var38_1;
      goto block12_1;
    }
  }
  else
  {
    var36_phi_1 = var37_1;
    goto block18_1;
  }
  if (var37_2 == 4)
  {
    var38_2 = ((long) var20_phi_2) + ((long) 1);
    if (var38_2 == 40)
    {
      var39_phi_2 = 0;
      return var39_phi_2;
    }
    else
    {
      var20_phi_2 = var38_2;
      goto block12_2;
    }
  }
  else
  {
    var36_phi_2 = var37_2;
    goto block18_2;
  }
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 30; i_0++)
  {
    assert(Rcon0_1[i_0] == Rcon0_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(var2_1[i_0] == var2_2[i_0]);
  }

  assert((*var3_1) == (*var3_2));
  assert(var4_phi_1 == var4_phi_2);
  assert(var5_phi_1 == var5_phi_2);
  assert(var6_phi_1 == var6_phi_2);
  assert(var17_phi_1 == var17_phi_2);
  assert(var20_phi_1 == var20_phi_2);
  assert((*var29_phi_1) == (*var29_phi_2));
  assert((*var30_phi_1) == (*var30_phi_2));
  assert(var31_phi_1 == var31_phi_2);
  assert(var36_phi_1 == var36_phi_2);
  assert(var39_phi_1 == var39_phi_2);
  assert(var7_1 == var7_2);
  assert((*var8_1) == (*var8_2));
  assert((*var9_1) == (*var9_2));
  assert((*var10_1) == (*var10_2));
  assert((*var11_1) == (*var11_2));
  assert((*var12_1) == (*var12_2));
  assert((*var13_1) == (*var13_2));
  assert((*var14_1) == (*var14_2));
  assert((*var15_1) == (*var15_2));
  assert(var16_1 == var16_2);
  assert(var18_1 == var18_2);
  assert(var19_1 == var19_2);
  assert(var21_1 == var21_2);
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
  assert(var24_1 == var24_2);
  assert(var25_1 == var25_2);
  assert(var26_1 == var26_2);
  assert((*var27_1) == (*var27_2));
  assert((*var28_1) == (*var28_2));
  assert((*var32_1) == (*var32_2));
  assert(var33_1 == var33_2);
  assert(var34_1 == var34_2);
  assert(var35_1 == var35_2);
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
}

unsigned int KeySchedule(unsigned int var0, unsigned int *var1)
{
  unsigned int var2[4];
  unsigned char *var3;
  unsigned int var4_phi;
  unsigned int var5_phi;
  unsigned long var6_phi;
  unsigned long var17_phi;
  unsigned long var20_phi;
  unsigned int *var29_phi;
  unsigned int *var30_phi;
  unsigned long var31_phi;
  unsigned long var36_phi;
  unsigned int var39_phi;
  long var7;
  unsigned int *var8;
  unsigned int *var9;
  unsigned int *var10;
  unsigned int *var11;
  unsigned int *var12;
  unsigned int *var13;
  unsigned int *var14;
  unsigned int *var15;
  unsigned long var16;
  long var18;
  long var19;
  unsigned int var21;
  long var22;
  unsigned int var23;
  unsigned int var24;
  unsigned int var25;
  unsigned int var26;
  unsigned int *var27;
  unsigned int *var28;
  unsigned int *var32;
  unsigned int var33;
  long var34;
  long var35;
  long var37;
  long var38;
  block0:
  var3 = (unsigned char *) (&var2);

  switch (var0)
  {
    case 128128:
      goto block7;

    case 128192:
      goto block7;

    case 128256:
      goto block7;

    case 192128:
      var4_phi = 0;
      var5_phi = 6;
      goto block7;

    case 192192:
      var4_phi = 0;
      var5_phi = 6;
      goto block7;

    case 192256:
      var4_phi = 0;
      var5_phi = 6;
      goto block7;

    case 256128:
      var4_phi = 1;
      var5_phi = 8;
      goto block7;

    case 256192:
      var4_phi = 1;
      var5_phi = 8;
      goto block7;

    case 256256:
      var4_phi = 1;
      var5_phi = 8;
      goto block7;

    default:
      return var39_phi;

  }

  block15:
  *var30_phi = *var29_phi;

  if ((var4_phi) ? (var21 == 4) : (0))
  {
    var31_phi = 0;
    goto block16;
  }
  else
  {
    goto block17;
  }
  block7:
  var6_phi = 0;

  goto block8;
  block8:
  var7 = ((long) var6_phi) << ((long) ((unsigned long) ((long) 2)));

  var17_phi = 0;
  goto block10;
  block10:
  word[var17_phi][var6_phi] = *(((unsigned int *) var1) + (((long) var17_phi) + ((long) var7)));

  var18 = ((long) var17_phi) + ((long) 1);
  if (var18 == 4)
  {
    var19 = ((long) var6_phi) + ((long) 1);
    if (var19 == 8)
    {
      var8 = &var2[0];
      var9 = &var2[1];
      var10 = &var2[2];
      var11 = &var2[3];
      var12 = &var2[0];
      var13 = &var2[1];
      var14 = &var2[2];
      var15 = &var2[3];
      var16 = (unsigned long) var5_phi;
      var20_phi = 8;
      goto block12;
    }
    else
    {
      var6_phi = var19;
      goto block8;
    }
  }
  else
  {
    var17_phi = var18;
    goto block10;
  }
  block12:
  var21 = ((unsigned int) var20_phi) % var5_phi;

  var22 = ((long) var20_phi) + ((long) (-1));
  if (var21 == 0)
  {
    var23 = word[1][var22];
    *var12 = Rcon0[(long) ((int) (((int) (((unsigned int) var20_phi) / var5_phi)) + ((int) (-1))))] ^ Sbox[(long) ((int) (((int) var23) / ((int) 16)))][(long) ((int) (((int) var23) % ((int) 16)))];
    var24 = word[2][var22];
    *var13 = Sbox[(long) ((int) (((int) var24) / ((int) 16)))][(long) ((int) (((int) var24) % ((int) 16)))];
    var25 = word[3][var22];
    *var14 = Sbox[(long) ((int) (((int) var25) / ((int) 16)))][(long) ((int) (((int) var25) % ((int) 16)))];
    var26 = word[0][var22];
    var27 = &Sbox[(long) ((int) (((int) var26) / ((int) 16)))][(long) ((int) (((int) var26) % ((int) 16)))];
    var29_phi = var27;
    var30_phi = var15;
    goto block15;
  }
  else
  {
    *var8 = word[0][var22];
    *var9 = word[1][var22];
    *var10 = word[2][var22];
    var28 = &word[3][var22];
    var29_phi = var28;
    var30_phi = var11;
    goto block15;
  }
  block16:
  var32 = &var2[var31_phi];

  var33 = *var32;
  *var32 = Sbox[(long) ((int) (((int) var33) / ((int) 16)))][(long) ((int) (((int) var33) % ((int) 16)))];
  var34 = ((long) var31_phi) + ((long) 1);
  if (var34 == 4)
  {
    goto block17;
  }
  else
  {
    var31_phi = var34;
    goto block16;
  }
  block17:
  var35 = ((long) var20_phi) - ((long) var16);

  var36_phi = 0;
  goto block18;
  block18:
  word[var36_phi][var20_phi] = var2[var36_phi] ^ word[var36_phi][var35];

  var37 = ((long) var36_phi) + ((long) 1);
  if (var37 == 4)
  {
    var38 = ((long) var20_phi) + ((long) 1);
    if (var38 == 40)
    {
      var39_phi = 0;
      return var39_phi;
    }
    else
    {
      var20_phi = var38;
      goto block12;
    }
  }
  else
  {
    var36_phi = var37;
    goto block18;
  }
}

void MixColumn_AddRoundKey_2(unsigned int *var0_1, unsigned int var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int var1_2, unsigned int var2_2)
{
  unsigned int var3_1[32];
  unsigned int var3_2[32];
  unsigned char *var4_1;
  unsigned char *var4_2;
  long var5_1;
  long var5_2;
  unsigned long var6_phi_1;
  unsigned long var6_phi_2;
  unsigned long var37_phi_1;
  unsigned long var37_phi_2;
  long var7_1;
  long var7_2;
  unsigned int var8_1;
  unsigned int var8_2;
  unsigned int var9_1;
  unsigned int var9_2;
  unsigned int *var10_1;
  unsigned int *var10_2;
  unsigned int var11_1;
  unsigned int var11_2;
  long var12_1;
  long var12_2;
  unsigned int var13_1;
  unsigned int var13_2;
  unsigned int var14_1;
  unsigned int var14_2;
  unsigned int var15_1;
  unsigned int var15_2;
  unsigned int var16_1;
  unsigned int var16_2;
  long var17_1;
  long var17_2;
  unsigned int var18_1;
  unsigned int var18_2;
  long var19_1;
  long var19_2;
  unsigned int var20_1;
  unsigned int var20_2;
  long var21_1;
  long var21_2;
  unsigned int *var22_1;
  unsigned int *var22_2;
  unsigned int var23_1;
  unsigned int var23_2;
  unsigned int var24_1;
  unsigned int var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int var26_1;
  unsigned int var26_2;
  unsigned int *var27_1;
  unsigned int *var27_2;
  unsigned int var28_1;
  unsigned int var28_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int var31_1;
  unsigned int var31_2;
  unsigned int *var32_1;
  unsigned int *var32_2;
  unsigned int var33_1;
  unsigned int var33_2;
  unsigned int var34_1;
  unsigned int var34_2;
  unsigned int var35_1;
  unsigned int var35_2;
  long var36_1;
  long var36_2;
  long var38_1;
  long var38_2;
  long var39_1;
  long var39_2;
  long var40_1;
  long var40_2;
  long var41_1;
  long var41_2;
  long var42_1;
  long var42_2;
  block0_1:
  var4_1 = (unsigned char *) (&var3_1);

  block0_2:
  var4_2 = (unsigned char *) (&var3_2);

  var5_1 = (long) ((int) (((int) var2_1) * ((int) var1_1)));
  var5_2 = (long) ((int) (((int) var2_2) * ((int) var1_2)));
  var6_phi_1 = 0;
  var6_phi_2 = 0;
  goto block1_1;
  goto block1_2;
  block1_1:
  var7_1 = ((long) var6_phi_1) << ((long) ((unsigned long) ((long) 2)));

  block1_2:
  var7_2 = ((long) var6_phi_2) << ((long) ((unsigned long) ((long) 2)));

  var8_1 = *(((unsigned int *) var0_1) + var7_1);
  var8_2 = *(((unsigned int *) var0_2) + var7_2);
  var9_1 = var8_1 << ((unsigned int) 1);
  var9_2 = var8_2 << ((unsigned int) 1);
  var10_1 = &var3_1[var7_1];
  var10_2 = &var3_2[var7_2];
  var11_1 = ((var8_1 & 2147483520) == 128) ? (var9_1 ^ 283) : (var9_1);
  var11_2 = ((var8_2 & 2147483520) == 128) ? (var9_2 ^ 283) : (var9_2);
  *var10_1 = var11_1;
  *var10_2 = var11_2;
  var12_1 = var7_1 | 1;
  var12_2 = var7_2 | 1;
  var13_1 = *(((unsigned int *) var0_1) + var12_1);
  var13_2 = *(((unsigned int *) var0_2) + var12_2);
  var14_1 = var13_1 << ((unsigned int) 1);
  var14_2 = var13_2 << ((unsigned int) 1);
  var15_1 = var14_1 ^ var13_1;
  var15_2 = var14_2 ^ var13_2;
  var16_1 = ((var15_1 & (-256)) == 256) ? ((var15_1 ^ var11_1) ^ 283) : (var15_1 ^ var11_1);
  var16_2 = ((var15_2 & (-256)) == 256) ? ((var15_2 ^ var11_2) ^ 283) : (var15_2 ^ var11_2);
  *var10_1 = var16_1;
  *var10_2 = var16_2;
  var17_1 = var7_1 | 2;
  var17_2 = var7_2 | 2;
  var18_1 = *(((unsigned int *) var0_1) + var17_1);
  var18_2 = *(((unsigned int *) var0_2) + var17_2);
  var19_1 = var7_1 | 3;
  var19_2 = var7_2 | 3;
  var20_1 = *(((unsigned int *) var0_1) + var19_1);
  var20_2 = *(((unsigned int *) var0_2) + var19_2);
  var21_1 = ((long) var6_phi_1) + ((long) var5_1);
  var21_2 = ((long) var6_phi_2) + ((long) var5_2);
  *var10_1 = ((var20_1 ^ var18_1) ^ word_1[0][var21_1]) ^ var16_1;
  *var10_2 = ((var20_2 ^ var18_2) ^ word_2[0][var21_2]) ^ var16_2;
  var22_1 = &var3_1[var12_1];
  var22_2 = &var3_2[var12_2];
  var23_1 = ((var13_1 & 2147483520) == 128) ? (var14_1 ^ 283) : (var14_1);
  var23_2 = ((var13_2 & 2147483520) == 128) ? (var14_2 ^ 283) : (var14_2);
  *var22_1 = var23_1;
  *var22_2 = var23_2;
  var24_1 = var18_1 << ((unsigned int) 1);
  var24_2 = var18_2 << ((unsigned int) 1);
  var25_1 = var24_1 ^ var18_1;
  var25_2 = var24_2 ^ var18_2;
  var26_1 = ((var25_1 & (-256)) == 256) ? ((var25_1 ^ var23_1) ^ 283) : (var25_1 ^ var23_1);
  var26_2 = ((var25_2 & (-256)) == 256) ? ((var25_2 ^ var23_2) ^ 283) : (var25_2 ^ var23_2);
  *var22_1 = var26_1;
  *var22_2 = var26_2;
  *var22_1 = ((var20_1 ^ var8_1) ^ var26_1) ^ word_1[1][var21_1];
  *var22_2 = ((var20_2 ^ var8_2) ^ var26_2) ^ word_2[1][var21_2];
  var27_1 = &var3_1[var17_1];
  var27_2 = &var3_2[var17_2];
  var28_1 = ((var18_1 & 2147483520) == 128) ? (var24_1 ^ 283) : (var24_1);
  var28_2 = ((var18_2 & 2147483520) == 128) ? (var24_2 ^ 283) : (var24_2);
  *var27_1 = var28_1;
  *var27_2 = var28_2;
  var29_1 = var20_1 << ((unsigned int) 1);
  var29_2 = var20_2 << ((unsigned int) 1);
  var30_1 = var29_1 ^ var20_1;
  var30_2 = var29_2 ^ var20_2;
  var31_1 = ((var30_1 & (-256)) == 256) ? ((var30_1 ^ var28_1) ^ 283) : (var28_1 ^ var30_1);
  var31_2 = ((var30_2 & (-256)) == 256) ? ((var30_2 ^ var28_2) ^ 283) : (var28_2 ^ var30_2);
  *var27_1 = var31_1;
  *var27_2 = var31_2;
  *var27_1 = ((var13_1 ^ var8_1) ^ var31_1) ^ word_1[2][var21_1];
  *var27_2 = ((var13_2 ^ var8_2) ^ var31_2) ^ word_2[2][var21_2];
  var32_1 = &var3_1[var19_1];
  var32_2 = &var3_2[var19_2];
  var33_1 = ((var20_1 & 2147483520) == 128) ? (var29_1 ^ 283) : (var29_1);
  var33_2 = ((var20_2 & 2147483520) == 128) ? (var29_2 ^ 283) : (var29_2);
  *var32_1 = var33_1;
  *var32_2 = var33_2;
  var34_1 = var9_1 ^ var8_1;
  var34_2 = var9_2 ^ var8_2;
  var35_1 = ((var34_1 & (-256)) == 256) ? ((var33_1 ^ var34_1) ^ 283) : (var33_1 ^ var34_1);
  var35_2 = ((var34_2 & (-256)) == 256) ? ((var33_2 ^ var34_2) ^ 283) : (var33_2 ^ var34_2);
  *var32_1 = var35_1;
  *var32_2 = var35_2;
  *var32_1 = ((var18_1 ^ var13_1) ^ var35_1) ^ word_1[3][var21_1];
  *var32_2 = ((var18_2 ^ var13_2) ^ var35_2) ^ word_2[3][var21_2];
  var36_1 = ((long) var6_phi_1) + ((long) 1);
  var36_2 = ((long) var6_phi_2) + ((long) 1);
  if (var36_1 == 8)
  {
    var37_phi_1 = 0;
    goto block2_1;
  }
  else
  {
    var6_phi_1 = var36_1;
    goto block1_1;
  }
  if (var36_2 == 8)
  {
    var37_phi_2 = 0;
    goto block2_2;
  }
  else
  {
    var6_phi_2 = var36_2;
    goto block1_2;
  }
  block2_1:
  var38_1 = ((long) var37_phi_1) << ((long) ((unsigned long) ((long) 2)));

  block2_2:
  var38_2 = ((long) var37_phi_2) << ((long) ((unsigned long) ((long) 2)));

  *(((unsigned int *) var0_1) + var38_1) = var3_1[var38_1];
  *(((unsigned int *) var0_2) + var38_2) = var3_2[var38_2];
  var39_1 = var38_1 | 1;
  var39_2 = var38_2 | 1;
  *(((unsigned int *) var0_1) + var39_1) = var3_1[var39_1];
  *(((unsigned int *) var0_2) + var39_2) = var3_2[var39_2];
  var40_1 = var38_1 | 2;
  var40_2 = var38_2 | 2;
  *(((unsigned int *) var0_1) + var40_1) = var3_1[var40_1];
  *(((unsigned int *) var0_2) + var40_2) = var3_2[var40_2];
  var41_1 = var38_1 | 3;
  var41_2 = var38_2 | 3;
  *(((unsigned int *) var0_1) + var41_1) = var3_1[var41_1];
  *(((unsigned int *) var0_2) + var41_2) = var3_2[var41_2];
  var42_1 = ((long) var37_phi_1) + ((long) 1);
  var42_2 = ((long) var37_phi_2) + ((long) 1);
  if (var42_1 == 8)
  {
    return 0;
  }
  else
  {
    var37_phi_1 = var42_1;
    goto block2_1;
  }
  if (var42_2 == 8)
  {
    return 0;
  }
  else
  {
    var37_phi_2 = var42_2;
    goto block2_2;
  }
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(var3_1[i_0] == var3_2[i_0]);
  }

  assert((*var4_1) == (*var4_2));
  assert(var5_1 == var5_2);
  assert(var6_phi_1 == var6_phi_2);
  assert(var37_phi_1 == var37_phi_2);
  assert(var7_1 == var7_2);
  assert(var8_1 == var8_2);
  assert(var9_1 == var9_2);
  assert((*var10_1) == (*var10_2));
  assert(var11_1 == var11_2);
  assert(var12_1 == var12_2);
  assert(var13_1 == var13_2);
  assert(var14_1 == var14_2);
  assert(var15_1 == var15_2);
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert(var19_1 == var19_2);
  assert(var20_1 == var20_2);
  assert(var21_1 == var21_2);
  assert((*var22_1) == (*var22_2));
  assert(var23_1 == var23_2);
  assert(var24_1 == var24_2);
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
  assert(var35_1 == var35_2);
  assert(var36_1 == var36_2);
  assert(var38_1 == var38_2);
  assert(var39_1 == var39_2);
  assert(var40_1 == var40_2);
  assert(var41_1 == var41_2);
  assert(var42_1 == var42_2);
}

unsigned int MixColumn_AddRoundKey(unsigned int *var0, unsigned int var1, unsigned int var2)
{
  unsigned int var3[32];
  unsigned char *var4;
  long var5;
  unsigned long var6_phi;
  unsigned long var37_phi;
  long var7;
  unsigned int var8;
  unsigned int var9;
  unsigned int *var10;
  unsigned int var11;
  long var12;
  unsigned int var13;
  unsigned int var14;
  unsigned int var15;
  unsigned int var16;
  long var17;
  unsigned int var18;
  long var19;
  unsigned int var20;
  long var21;
  unsigned int *var22;
  unsigned int var23;
  unsigned int var24;
  unsigned int var25;
  unsigned int var26;
  unsigned int *var27;
  unsigned int var28;
  unsigned int var29;
  unsigned int var30;
  unsigned int var31;
  unsigned int *var32;
  unsigned int var33;
  unsigned int var34;
  unsigned int var35;
  long var36;
  long var38;
  long var39;
  long var40;
  long var41;
  long var42;
  block0:
  var4 = (unsigned char *) (&var3);

  var5 = (long) ((int) (((int) var2) * ((int) var1)));
  var6_phi = 0;
  goto block1;
  block1:
  var7 = ((long) var6_phi) << ((long) ((unsigned long) ((long) 2)));

  var8 = *(((unsigned int *) var0) + var7);
  var9 = var8 << ((unsigned int) 1);
  var10 = &var3[var7];
  var11 = ((var8 & 2147483520) == 128) ? (var9 ^ 283) : (var9);
  *var10 = var11;
  var12 = var7 | 1;
  var13 = *(((unsigned int *) var0) + var12);
  var14 = var13 << ((unsigned int) 1);
  var15 = var14 ^ var13;
  var16 = ((var15 & (-256)) == 256) ? ((var15 ^ var11) ^ 283) : (var15 ^ var11);
  *var10 = var16;
  var17 = var7 | 2;
  var18 = *(((unsigned int *) var0) + var17);
  var19 = var7 | 3;
  var20 = *(((unsigned int *) var0) + var19);
  var21 = ((long) var6_phi) + ((long) var5);
  *var10 = ((var20 ^ var18) ^ word[0][var21]) ^ var16;
  var22 = &var3[var12];
  var23 = ((var13 & 2147483520) == 128) ? (var14 ^ 283) : (var14);
  *var22 = var23;
  var24 = var18 << ((unsigned int) 1);
  var25 = var24 ^ var18;
  var26 = ((var25 & (-256)) == 256) ? ((var25 ^ var23) ^ 283) : (var25 ^ var23);
  *var22 = var26;
  *var22 = ((var20 ^ var8) ^ var26) ^ word[1][var21];
  var27 = &var3[var17];
  var28 = ((var18 & 2147483520) == 128) ? (var24 ^ 283) : (var24);
  *var27 = var28;
  var29 = var20 << ((unsigned int) 1);
  var30 = var29 ^ var20;
  var31 = ((var30 & (-256)) == 256) ? ((var30 ^ var28) ^ 283) : (var28 ^ var30);
  *var27 = var31;
  *var27 = ((var13 ^ var8) ^ var31) ^ word[2][var21];
  var32 = &var3[var19];
  var33 = ((var20 & 2147483520) == 128) ? (var29 ^ 283) : (var29);
  *var32 = var33;
  var34 = var9 ^ var8;
  var35 = ((var34 & (-256)) == 256) ? ((var33 ^ var34) ^ 283) : (var33 ^ var34);
  *var32 = var35;
  *var32 = ((var18 ^ var13) ^ var35) ^ word[3][var21];
  var36 = ((long) var6_phi) + ((long) 1);
  if (var36 == 8)
  {
    var37_phi = 0;
    goto block2;
  }
  else
  {
    var6_phi = var36;
    goto block1;
  }
  block2:
  var38 = ((long) var37_phi) << ((long) ((unsigned long) ((long) 2)));

  *(((unsigned int *) var0) + var38) = var3[var38];
  var39 = var38 | 1;
  *(((unsigned int *) var0) + var39) = var3[var39];
  var40 = var38 | 2;
  *(((unsigned int *) var0) + var40) = var3[var40];
  var41 = var38 | 3;
  *(((unsigned int *) var0) + var41) = var3[var41];
  var42 = ((long) var37_phi) + ((long) 1);
  if (var42 == 8)
  {
    return 0;
  }
  else
  {
    var37_phi = var42;
    goto block2;
  }
}

void SubByte_2(unsigned int var0_1, unsigned int var0_2)
{
  block0_1:
  return Sbox_1[(long) ((int) (((int) var0_1) / ((int) 16)))][(long) ((int) (((int) var0_1) % ((int) 16)))];

  block0_2:
  return Sbox_2[(long) ((int) (((int) var0_2) / ((int) 16)))][(long) ((int) (((int) var0_2) % ((int) 16)))];

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

}

unsigned int SubByte(unsigned int var0)
{
  block0:
  return Sbox[(long) ((int) (((int) var0) / ((int) 16)))][(long) ((int) (((int) var0) % ((int) 16)))];

}

void encrypt_2(unsigned int *var0_1, unsigned int *var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int *var1_2, unsigned int var2_2)
{
  unsigned int var3_phi_1;
  unsigned int var3_phi_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned long var5_phi_1;
  unsigned long var5_phi_2;
  unsigned int var12_phi_1;
  unsigned int var12_phi_2;
  unsigned long var14_phi_1;
  unsigned long var14_phi_2;
  unsigned long var15_phi_1;
  unsigned long var15_phi_2;
  unsigned long var23_phi_1;
  unsigned long var23_phi_2;
  long var6_1;
  long var6_2;
  unsigned int *var7_1;
  unsigned int *var7_2;
  unsigned int *var8_1;
  unsigned int *var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int *var10_1;
  unsigned int *var10_2;
  long var11_1;
  long var11_2;
  int var13_1;
  int var13_2;
  long var16_1;
  long var16_2;
  long var17_1;
  long var17_2;
  unsigned int *var18_1;
  unsigned int *var18_2;
  unsigned int *var19_1;
  unsigned int *var19_2;
  unsigned int *var20_1;
  unsigned int *var20_2;
  unsigned int *var21_1;
  unsigned int *var21_2;
  long var22_1;
  long var22_2;
  long var24_1;
  long var24_2;
  block0_1:
  KeySchedule(var2_1, var1_1);

  block0_2:
  KeySchedule(var2_2, var1_2);

  KeySchedule_2(var2_1, var1_1, var2_2, var1_2);
  switch (var2_1)
  {
    case 128128:
      goto block6_1;

    case 128192:
      goto block3_1;

    case 128256:
      goto block5_1;

    case 192128:
      var3_phi_1 = 2;
      var4_phi_1 = 4;
      goto block6_1;

    case 192192:
      goto block3_1;

    case 192256:
      goto block5_1;

    case 256128:
      var3_phi_1 = 4;
      var4_phi_1 = 4;
      goto block6_1;

    case 256192:
      var3_phi_1 = 4;
      var4_phi_1 = 6;
      goto block6_1;

    case 256256:
      goto block5_1;

    default:
      goto block7_1;

  }

  switch (var2_2)
  {
    case 128128:
      goto block6_2;

    case 128192:
      goto block3_2;

    case 128256:
      goto block5_2;

    case 192128:
      var3_phi_2 = 2;
      var4_phi_2 = 4;
      goto block6_2;

    case 192192:
      goto block3_2;

    case 192256:
      goto block5_2;

    case 256128:
      var3_phi_2 = 4;
      var4_phi_2 = 4;
      goto block6_2;

    case 256192:
      var3_phi_2 = 4;
      var4_phi_2 = 6;
      goto block6_2;

    case 256256:
      goto block5_2;

    default:
      goto block7_2;

  }

  block5_1:
  var3_phi_1 = 4;

  block5_2:
  var3_phi_2 = 4;

  var4_phi_1 = 8;
  var4_phi_2 = 8;
  goto block6_1;
  goto block6_2;
  block7_1:
  var5_phi_1 = 0;

  block7_2:
  var5_phi_2 = 0;

  goto block8_1;
  goto block8_2;
  block6_1:
  round_val_1 = var3_phi_1;

  block6_2:
  round_val_2 = var3_phi_2;

  nb_1 = var4_phi_1;
  nb_2 = var4_phi_2;
  goto block7_1;
  goto block7_2;
  block3_1:
  var3_phi_1 = 2;

  block3_2:
  var3_phi_2 = 2;

  var4_phi_1 = 6;
  var4_phi_2 = 6;
  goto block6_1;
  goto block6_2;
  block8_1:
  var6_1 = ((long) var5_phi_1) << ((long) ((unsigned long) ((long) 2)));

  block8_2:
  var6_2 = ((long) var5_phi_2) << ((long) ((unsigned long) ((long) 2)));

  var7_1 = &(*(((unsigned int *) var0_1) + var6_1));
  var7_2 = &(*(((unsigned int *) var0_2) + var6_2));
  *var7_1 = (*var7_1) ^ word_1[0][var5_phi_1];
  *var7_2 = (*var7_2) ^ word_2[0][var5_phi_2];
  var8_1 = &(*(((unsigned int *) var0_1) + (var6_1 | 1)));
  var8_2 = &(*(((unsigned int *) var0_2) + (var6_2 | 1)));
  *var8_1 = (*var8_1) ^ word_1[1][var5_phi_1];
  *var8_2 = (*var8_2) ^ word_2[1][var5_phi_2];
  var9_1 = &(*(((unsigned int *) var0_1) + (var6_1 | 2)));
  var9_2 = &(*(((unsigned int *) var0_2) + (var6_2 | 2)));
  *var9_1 = (*var9_1) ^ word_1[2][var5_phi_1];
  *var9_2 = (*var9_2) ^ word_2[2][var5_phi_2];
  var10_1 = &(*(((unsigned int *) var0_1) + (var6_1 | 3)));
  var10_2 = &(*(((unsigned int *) var0_2) + (var6_2 | 3)));
  *var10_1 = (*var10_1) ^ word_1[3][var5_phi_1];
  *var10_2 = (*var10_2) ^ word_2[3][var5_phi_2];
  var11_1 = ((long) var5_phi_1) + ((long) 1);
  var11_2 = ((long) var5_phi_2) + ((long) 1);
  if (var11_1 == 8)
  {
    var12_phi_1 = 1;
    goto block9_1;
  }
  else
  {
    var5_phi_1 = var11_1;
    goto block8_1;
  }
  if (var11_2 == 8)
  {
    var12_phi_2 = 1;
    goto block9_2;
  }
  else
  {
    var5_phi_2 = var11_2;
    goto block8_2;
  }
  block9_1:
  ByteSub_ShiftRow(var0_1, nb_1);

  block9_2:
  ByteSub_ShiftRow(var0_2, nb_2);

  ByteSub_ShiftRow_2(var0_1, nb_1, var0_2, nb_2);
  MixColumn_AddRoundKey(var0_1, nb_1, var12_phi_1);
  MixColumn_AddRoundKey(var0_2, nb_2, var12_phi_2);
  MixColumn_AddRoundKey_2(var0_1, nb_1, var12_phi_1, var0_2, nb_2, var12_phi_2);
  var13_1 = ((int) var12_phi_1) + ((int) 1);
  var13_2 = ((int) var12_phi_2) + ((int) 1);
  if (var13_1 == 14)
  {
    ByteSub_ShiftRow(var0_1, nb_1);
    switch (var2_1)
    {
      case 128192:
        goto block11_1;

      case 128256:
        goto block12_1;

      case 192192:
        goto block11_1;

      case 192256:
        goto block12_1;

      case 256192:
        goto block11_1;

      case 256256:
        goto block12_1;

      default:
        goto block13_1;

    }

  }
  else
  {
    var12_phi_1 = var13_1;
    goto block9_1;
  }
  if (var13_2 == 14)
  {
    ByteSub_ShiftRow(var0_2, nb_2);
    switch (var2_2)
    {
      case 128192:
        goto block11_2;

      case 128256:
        goto block12_2;

      case 192192:
        goto block11_2;

      case 192256:
        goto block12_2;

      case 256192:
        goto block11_2;

      case 256256:
        goto block12_2;

      default:
        goto block13_2;

    }

  }
  else
  {
    var12_phi_2 = var13_2;
    goto block9_2;
  }
  ByteSub_ShiftRow_2(var0_1, nb_1, var0_2, nb_2);
  block13_1:
  var15_phi_1 = 0;

  block13_2:
  var15_phi_2 = 0;

  goto block14_1;
  goto block14_2;
  block12_1:
  var14_phi_1 = 112;

  block12_2:
  var14_phi_2 = 112;

  goto block13_1;
  goto block13_2;
  block11_1:
  var14_phi_1 = 84;

  block11_2:
  var14_phi_2 = 84;

  goto block13_1;
  goto block13_2;
  block14_1:
  var16_1 = ((long) var15_phi_1) + ((long) var14_phi_1);

  block14_2:
  var16_2 = ((long) var15_phi_2) + ((long) var14_phi_2);

  var17_1 = ((long) var15_phi_1) << ((long) ((unsigned long) ((long) 2)));
  var17_2 = ((long) var15_phi_2) << ((long) ((unsigned long) ((long) 2)));
  var18_1 = &(*(((unsigned int *) var0_1) + var17_1));
  var18_2 = &(*(((unsigned int *) var0_2) + var17_2));
  *var18_1 = (*var18_1) ^ word_1[0][var16_1];
  *var18_2 = (*var18_2) ^ word_2[0][var16_2];
  var19_1 = &(*(((unsigned int *) var0_1) + (var17_1 | 1)));
  var19_2 = &(*(((unsigned int *) var0_2) + (var17_2 | 1)));
  *var19_1 = (*var19_1) ^ word_1[1][var16_1];
  *var19_2 = (*var19_2) ^ word_2[1][var16_2];
  var20_1 = &(*(((unsigned int *) var0_1) + (var17_1 | 2)));
  var20_2 = &(*(((unsigned int *) var0_2) + (var17_2 | 2)));
  *var20_1 = (*var20_1) ^ word_1[2][var16_1];
  *var20_2 = (*var20_2) ^ word_2[2][var16_2];
  var21_1 = &(*(((unsigned int *) var0_1) + (var17_1 | 3)));
  var21_2 = &(*(((unsigned int *) var0_2) + (var17_2 | 3)));
  *var21_1 = (*var21_1) ^ word_1[3][var16_1];
  *var21_2 = (*var21_2) ^ word_2[3][var16_2];
  var22_1 = ((long) var15_phi_1) + ((long) 1);
  var22_2 = ((long) var15_phi_2) + ((long) 1);
  if (var22_1 == 8)
  {
    var23_phi_1 = 0;
    goto block15_1;
  }
  else
  {
    var15_phi_1 = var22_1;
    goto block14_1;
  }
  if (var22_2 == 8)
  {
    var23_phi_2 = 0;
    goto block15_2;
  }
  else
  {
    var15_phi_2 = var22_2;
    goto block14_2;
  }
  block15_1:
  main_result_1 = ((int) main_result_1) + ((int) ((unsigned int) ((*(((unsigned int *) var0_1) + var23_phi_1)) != __const_encrypt_out_enc_statemt_1[var23_phi_1])));

  block15_2:
  main_result_2 = ((int) main_result_2) + ((int) ((unsigned int) ((*(((unsigned int *) var0_2) + var23_phi_2)) != __const_encrypt_out_enc_statemt_2[var23_phi_2])));

  var24_1 = ((long) var23_phi_1) + ((long) 1);
  var24_2 = ((long) var23_phi_2) + ((long) 1);
  if (var24_1 == 16)
  {
    return 0;
  }
  else
  {
    var23_phi_1 = var24_1;
    goto block15_1;
  }
  if (var24_2 == 16)
  {
    return 0;
  }
  else
  {
    var23_phi_2 = var24_2;
    goto block15_2;
  }
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(__const_encrypt_out_enc_statemt_1[i_0] == __const_encrypt_out_enc_statemt_2[i_0]);
  }

  assert(round_val_1 == round_val_2);
  assert(nb_1 == nb_2);
  assert(main_result_1 == main_result_2);
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(var3_phi_1 == var3_phi_2);
  assert(var4_phi_1 == var4_phi_2);
  assert(var5_phi_1 == var5_phi_2);
  assert(var12_phi_1 == var12_phi_2);
  assert(var14_phi_1 == var14_phi_2);
  assert(var15_phi_1 == var15_phi_2);
  assert(var23_phi_1 == var23_phi_2);
  assert(var6_1 == var6_2);
  assert((*var7_1) == (*var7_2));
  assert((*var8_1) == (*var8_2));
  assert((*var9_1) == (*var9_2));
  assert((*var10_1) == (*var10_2));
  assert(var11_1 == var11_2);
  assert(var13_1 == var13_2);
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert((*var18_1) == (*var18_2));
  assert((*var19_1) == (*var19_2));
  assert((*var20_1) == (*var20_2));
  assert((*var21_1) == (*var21_2));
  assert(var22_1 == var22_2);
  assert(var24_1 == var24_2);
}

unsigned int encrypt(unsigned int *var0, unsigned int *var1, unsigned int var2)
{
  unsigned int var3_phi;
  unsigned int var4_phi;
  unsigned long var5_phi;
  unsigned int var12_phi;
  unsigned long var14_phi;
  unsigned long var15_phi;
  unsigned long var23_phi;
  long var6;
  unsigned int *var7;
  unsigned int *var8;
  unsigned int *var9;
  unsigned int *var10;
  long var11;
  int var13;
  long var16;
  long var17;
  unsigned int *var18;
  unsigned int *var19;
  unsigned int *var20;
  unsigned int *var21;
  long var22;
  long var24;
  block0:
  KeySchedule(var2, var1);

  switch (var2)
  {
    case 128128:
      goto block6;

    case 128192:
      goto block3;

    case 128256:
      goto block5;

    case 192128:
      var3_phi = 2;
      var4_phi = 4;
      goto block6;

    case 192192:
      goto block3;

    case 192256:
      goto block5;

    case 256128:
      var3_phi = 4;
      var4_phi = 4;
      goto block6;

    case 256192:
      var3_phi = 4;
      var4_phi = 6;
      goto block6;

    case 256256:
      goto block5;

    default:
      goto block7;

  }

  block5:
  var3_phi = 4;

  var4_phi = 8;
  goto block6;
  block7:
  var5_phi = 0;

  goto block8;
  block6:
  round_val = var3_phi;

  nb = var4_phi;
  goto block7;
  block3:
  var3_phi = 2;

  var4_phi = 6;
  goto block6;
  block8:
  var6 = ((long) var5_phi) << ((long) ((unsigned long) ((long) 2)));

  var7 = &(*(((unsigned int *) var0) + var6));
  *var7 = (*var7) ^ word[0][var5_phi];
  var8 = &(*(((unsigned int *) var0) + (var6 | 1)));
  *var8 = (*var8) ^ word[1][var5_phi];
  var9 = &(*(((unsigned int *) var0) + (var6 | 2)));
  *var9 = (*var9) ^ word[2][var5_phi];
  var10 = &(*(((unsigned int *) var0) + (var6 | 3)));
  *var10 = (*var10) ^ word[3][var5_phi];
  var11 = ((long) var5_phi) + ((long) 1);
  if (var11 == 8)
  {
    var12_phi = 1;
    goto block9;
  }
  else
  {
    var5_phi = var11;
    goto block8;
  }
  block9:
  ByteSub_ShiftRow(var0, nb);

  MixColumn_AddRoundKey(var0, nb, var12_phi);
  var13 = ((int) var12_phi) + ((int) 1);
  if (var13 == 14)
  {
    ByteSub_ShiftRow(var0, nb);
    switch (var2)
    {
      case 128192:
        goto block11;

      case 128256:
        goto block12;

      case 192192:
        goto block11;

      case 192256:
        goto block12;

      case 256192:
        goto block11;

      case 256256:
        goto block12;

      default:
        goto block13;

    }

  }
  else
  {
    var12_phi = var13;
    goto block9;
  }
  block13:
  var15_phi = 0;

  goto block14;
  block12:
  var14_phi = 112;

  goto block13;
  block11:
  var14_phi = 84;

  goto block13;
  block14:
  var16 = ((long) var15_phi) + ((long) var14_phi);

  var17 = ((long) var15_phi) << ((long) ((unsigned long) ((long) 2)));
  var18 = &(*(((unsigned int *) var0) + var17));
  *var18 = (*var18) ^ word[0][var16];
  var19 = &(*(((unsigned int *) var0) + (var17 | 1)));
  *var19 = (*var19) ^ word[1][var16];
  var20 = &(*(((unsigned int *) var0) + (var17 | 2)));
  *var20 = (*var20) ^ word[2][var16];
  var21 = &(*(((unsigned int *) var0) + (var17 | 3)));
  *var21 = (*var21) ^ word[3][var16];
  var22 = ((long) var15_phi) + ((long) 1);
  if (var22 == 8)
  {
    var23_phi = 0;
    goto block15;
  }
  else
  {
    var15_phi = var22;
    goto block14;
  }
  block15:
  main_result = ((int) main_result) + ((int) ((unsigned int) ((*(((unsigned int *) var0) + var23_phi)) != __const_encrypt_out_enc_statemt[var23_phi])));

  var24 = ((long) var23_phi) + ((long) 1);
  if (var24 == 16)
  {
    return 0;
  }
  else
  {
    var23_phi = var24;
    goto block15;
  }
}

void main(void)
{
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    key_1[i_0] = nd_key();
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    key_2[i_0] = nd_key();
  }

  block0_1:
  main_result_1 = 0;

  block0_2:
  main_result_2 = 0;

  encrypt(&statemt_1[0], &key_1[0], 128128);
  encrypt(&statemt_2[0], &key_2[0], 128128);
  encrypt_2(&statemt_1[0], &key_1[0], 128128, &statemt_2[0], &key_2[0], 128128);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(statemt_1[i_0] == statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(key_1[i_0] != key_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
}


