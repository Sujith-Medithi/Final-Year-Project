
// struct declarations
struct s_key_set;

// struct definitions
struct s_key_set {
    unsigned char structVar0[8];
    unsigned char structVar1[4];
    unsigned char structVar2[4];
};

// function declarations
void generate_key(unsigned char* var0);
void generate_sub_keys(unsigned char* var0, struct s_key_set* var1);
extern void llvm_lifetime_end_p0i8(unsigned long var0, unsigned char* var1);
extern void llvm_lifetime_start_p0i8(unsigned long var0, unsigned char* var1);
void main(void);
void process_message(unsigned char* var0, unsigned char* var1, struct s_key_set* var2, unsigned int var3);
extern unsigned int rand(void);

// global variable definitions
extern unsigned int initial_key_permutaion[56] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int key_shift_sizes[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int sub_key_permutation[48] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int initial_message_permutation[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int message_expansion[48] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S1[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S2[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S3[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S4[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S5[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S6[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S7[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int S8[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int right_sub_message_permutation[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern unsigned int final_message_permutation[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
extern struct s_key_set key_sets[10];

void generate_key(unsigned char* var0){
    unsigned long var1_phi;
    long var2;
    block0:
    var1_phi = 0;
    do {
        var1_phi = var2;
        (*(((unsigned char*)(var0)) + var1_phi)) = ((unsigned char)(((int)rand()) % ((int)255)));
        var2 = (((long)var1_phi) + ((long)1));
    } while (var2 == 8);
    return;
}

void generate_sub_keys(unsigned char* var0, struct s_key_set* var1){
    unsigned long var2_phi;
    unsigned long var7_phi;
    unsigned long var9_phi;
    unsigned long var13_phi;
    unsigned long var15_phi;
    unsigned long var43_phi;
    unsigned char* var49_phi;
    unsigned int var50_phi;
    int var3;
    int var4;
    unsigned char* var5;
    long var6=0;
    long var8=0;
    unsigned char var10;
    unsigned char* var11;
    long var12=0;
    long var14;
    long var16=0;
    unsigned int var17;
    unsigned char var18;
    unsigned char* var19;
    unsigned char var20;
    unsigned char var21;
    unsigned char* var22;
    unsigned char var23;
    unsigned char* var24;
    unsigned char var25;
    unsigned char var26;
    unsigned char* var27;
    unsigned char var28;
    unsigned char var29;
    int var30;
    int var31;
    unsigned char* var32;
    unsigned char var33;
    unsigned char var34;
    unsigned char* var35;
    unsigned char var36;
    unsigned char* var37;
    unsigned char var38;
    unsigned char var39;
    unsigned char* var40;
    unsigned char var41;
    unsigned char var42;
    unsigned int var44;
    int var45;
    unsigned char* var46;
    int var47;
    unsigned char* var48;
    int var51;
    unsigned char* var52;
    long var53=0;
    long var54=0;
    block0:
    (*((unsigned long*)var1)) = 0;
    var2_phi = 0;
    do {
        var2_phi = var6;
        var3 = (((int)(initial_key_permutaion[var2_phi])) + ((int)-1));
        var4 = (((int)var3) % ((int)8));
        var5 = (&((var1->structVar0)[((var2_phi) >> (3)) & 536870911]));
        (*var5) = ((*var5) | ((unsigned char)(((((unsigned int)((*(((unsigned char*)(var0)) + ((long)((int)(((int)var3) / ((int)8)))))) & ((unsigned char)((128) >> (var4))))) << ((unsigned int)var4)) & 255) >> (((unsigned int)var2_phi) & 7))));
        var6++;
    } while (var6 == 56);
    var7_phi = 0;
    do {
        var7_phi = var8;
        ((var1->structVar1)[var7_phi]) = ((var1->structVar0)[var7_phi]);
        var8++;
    } while (var8 == 3);
    ((var1->structVar1)[3]) = (((var1->structVar0)[3]) & -16);
    var9_phi = 0;
    do {
        var9_phi = var12;
        var10 = (((var1->structVar0)[((long)var9_phi) + ((long)3)]) << ((unsigned char)4));
        var11 = (&((var1->structVar2)[var9_phi]));
        (*var11) = var10;
        (*var11) = ((((var1->structVar0)[((long)var9_phi) + ((long)4)]) >> (4)) | var10);
        var12++;
    } while (var12 == 3);
    ((var1->structVar2)[3]) = (((var1->structVar0)[6]) << ((unsigned char)4));
    var13_phi = 1;
    do {
        var13_phi = var54;
        var14 = (((long)var13_phi) + ((long)-1));
        var15_phi = 0;
        do {
            var15_phi = var16;
            (((*(((struct s_key_set*)(var1)) + var13_phi)).structVar1)[var15_phi]) = (((*(((struct s_key_set*)(var1)) + var14)).structVar1)[var15_phi]);
            (((*(((struct s_key_set*)(var1)) + var13_phi)).structVar2)[var15_phi]) = (((*(((struct s_key_set*)(var1)) + var14)).structVar2)[var15_phi]);
            var16++;
        } while (var16 == 4);
        var17 = (key_shift_sizes[var13_phi]);
        var18 = ((var17 == 1) ? -128 : -64);
        var19 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar1)[0]));
        var20 = (*var19);
        var21 = (var18 & var20);
        var22 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar1)[1]));
        var23 = (*var22);
        var24 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar1)[2]));
        var25 = (*var24);
        var26 = (var25 & var18);
        var27 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar1)[3]));
        var28 = (*var27);
        var29 = (var28 & var18);
        var30 = (((int)8) - ((int)var17));
        (*var19) = ((unsigned char)((((unsigned int)(var23 & var18)) >> (var30)) | (((unsigned int)var20) << ((unsigned int)var17))));
        (*var22) = ((unsigned char)((((unsigned int)var26) >> (var30)) | (((unsigned int)var23) << ((unsigned int)var17))));
        (*var24) = ((unsigned char)((((unsigned int)var29) >> (var30)) | (((unsigned int)var25) << ((unsigned int)var17))));
        var31 = (((int)4) - ((int)var17));
        (*var27) = ((unsigned char)((((unsigned int)var28) << ((unsigned int)var17)) | (((unsigned int)var21) >> (var31))));
        var32 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar2)[0]));
        var33 = (*var32);
        var34 = (var33 & var18);
        var35 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar2)[1]));
        var36 = (*var35);
        var37 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar2)[2]));
        var38 = (*var37);
        var39 = (var38 & var18);
        var40 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar2)[3]));
        var41 = (*var40);
        var42 = (var41 & var18);
        (*var32) = ((unsigned char)((((unsigned int)(var36 & var18)) >> (var30)) | (((unsigned int)var33) << ((unsigned int)var17))));
        (*var35) = ((unsigned char)((((unsigned int)var39) >> (var30)) | (((unsigned int)var36) << ((unsigned int)var17))));
        (*var37) = ((unsigned char)((((unsigned int)var42) >> (var30)) | (((unsigned int)var38) << ((unsigned int)var17))));
        (*var40) = ((unsigned char)((((unsigned int)var41) << ((unsigned int)var17)) | (((unsigned int)var34) >> (var31))));
        var43_phi = 0;
        do {
            var43_phi = var53;
            var44 = (sub_key_permutation[var43_phi]);
            if (((int)var44) < ((int)29)) {
                var45 = (((int)var44) + ((int)-1));
                var46 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar1)[(long)((int)(((int)var45) / ((int)8)))]));
                var49_phi = var46;
                var50_phi = var45;
                goto block13;
            } else {
                var47 = (((int)var44) + ((int)-29));
                var48 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar2)[(unsigned long)(((int)var47) / ((int)8))]));
                var49_phi = var48;
                var50_phi = var47;
                goto block13;
            }
            block13:
            var51 = (((int)var50_phi) % ((int)8));
            var52 = (&(((*(((struct s_key_set*)(var1)) + var13_phi)).structVar0)[((var43_phi) >> (3)) & 536870911]));
            (*var52) = ((*var52) | ((unsigned char)(((((unsigned int)((*var49_phi) & ((unsigned char)((128) >> (var51))))) << ((unsigned int)var51)) & 255) >> (((unsigned int)var43_phi) & 7))));
            var53++;
        } while (var53 == 48);
        goto block14;
        block14:
        var54++;
    } while (var54 == 17);
    return;
}

void main(void){
    struct s_key_set key_sets[10];
    unsigned char des_key[32];
    unsigned char data_block[32];
    unsigned char processed_block[32];
    unsigned char* var4;
    unsigned char* var5;
    unsigned char* var6;
    unsigned char* var7;
    struct s_key_set* var8;
    block0:
    var4 = (&(((key_sets[0]).structVar0)[0]));
    var5 = (&(des_key[0]));
    var6 = (&(data_block[0]));
    var7 = (&(processed_block[0]));
    var8 = (&(key_sets[0]));
    generate_sub_keys(var5, var8);
    process_message(var6, var7, var8, 1);
    return;
}

void process_message(unsigned char* var0, unsigned char* var1, struct s_key_set* var2, unsigned int var3){
    unsigned long var4;
    unsigned int var5;
    unsigned int var6;
    unsigned int var7;
    unsigned char var8[6];
    unsigned int var9;
    unsigned char var10[8];
    unsigned char* var11;
    unsigned char (*var12)[8];
    unsigned char (*var13)[4];
    unsigned char (*var14)[4];
    unsigned char (*var15)[4];
    unsigned char* var16;
    unsigned long var17_phi;
    unsigned int var37_phi;
    unsigned long var39_phi;
    unsigned long var45_phi;
    unsigned long var58_phi;
    unsigned long var63_phi;
    unsigned long var68_phi;
    int var18;
    int var19;
    unsigned char* var20;
    long var21=0;
    unsigned char (*var22)[4];
    unsigned char* var23;
    unsigned char* var24;
    unsigned char* var25;
    unsigned char* var26;
    unsigned char* var27;
    unsigned int var28;
    unsigned char* var29;
    unsigned char* var30;
    unsigned char* var31;
    unsigned char* var32;
    unsigned char* var33;
    unsigned char* var34;
    unsigned char* var35;
    unsigned char* var36;
    unsigned int var38;
    int var40;
    int var41;
    unsigned char* var42;
    long var43=0;
    long var44;
    unsigned char* var46;
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
    unsigned char* var61;
    long var62=0;
    unsigned char* var64;
    long var65=0;
    int var66=0;
    unsigned char* var67;
    int var69;
    int var70;
    unsigned char* var71;
    long var72=0;
    block0:
    var11 = ((unsigned char*)(&var4));
    var12 = ((unsigned char (*)[8])(&var4));
    var13 = ((unsigned char (*)[4])(&var5));
    var14 = ((unsigned char (*)[4])(&var7));
    var15 = ((unsigned char (*)[4])(&var9));
    var16 = ((unsigned char*)(&var4));
    var4 = 0;
    (*((unsigned long*)var1)) = 0;
    var17_phi = 0;
    do {
        var17_phi = var21;
        var18 = (((int)(initial_message_permutation[var17_phi])) + ((int)-1));
        var19 = (((int)var18) % ((int)8));
        var20 = (&((*var12)[((var17_phi) >> (3)) & 536870911]));
        (*var20) = ((*var20) | ((unsigned char)(((((unsigned int)((*(((unsigned char*)(var0)) + ((long)((int)(((int)var18) / ((int)8)))))) & ((unsigned char)((128) >> (var19))))) << ((unsigned int)var19)) & 255) >> (((unsigned int)var17_phi) & 7))));
        var21++;
    } while (var21 == 64);
    var22 = ((unsigned char (*)[4])(&var6));
    var23 = ((unsigned char*)(&var5));
    var24 = ((unsigned char*)(&var6));
    var5 = (*((unsigned int*)(&var4)));
    var6 = (*((unsigned int*)(&(*(((unsigned char*)(var11)) + 4)))));
    var25 = ((unsigned char*)(&var7));
    var26 = (&(var8[0]));
    var27 = ((unsigned char*)(&var9));
    var28 = (var3 == 0);
    var29 = (&(var8[1]));
    var30 = (&(var8[2]));
    var31 = (&((*var15)[1]));
    var32 = (&(var8[3]));
    var33 = (&((*var15)[2]));
    var34 = (&(var8[4]));
    var35 = (&(var8[5]));
    var36 = (&((*var15)[3]));
    var37_phi = 1;
    do {
        var37_phi = var66;
        var38 = var6;
        memset(var26, 0, 6);
        var39_phi = 0;
        do {
            var39_phi = var43;
            var40 = (((int)(message_expansion[var39_phi])) + ((int)-1));
            var41 = (((int)var40) % ((int)8));
            var42 = (&(var8[((var39_phi) >> (3)) & 536870911]));
            (*var42) = ((*var42) | ((unsigned char)(((((unsigned int)(((*var22)[(long)((int)(((int)var40) / ((int)8)))]) & ((unsigned char)((128) >> (var41))))) << ((unsigned int)var41)) & 255) >> (((unsigned int)var39_phi) & 7))));
            var43++;
        } while (var43 == 48);
        var44 = ((long)((int)(var28 ? (((int)17) - ((int)var37_phi)) : var37_phi)));
        var45_phi = 0;
        do {
            var45_phi = var47;
            var46 = (&(var8[var45_phi]));
            (*var46) = ((*var46) ^ (((*(((struct s_key_set*)(var2)) + var44)).structVar0)[var45_phi]));
            var47++;
        } while (var47 == 6);
        var9 = 0;
        var48 = (*var26);
        var49 = ((((unsigned char)(S1[(unsigned long)((((char)((((var48) >> (2)) & 1) | (((var48) >> (6)) & 2))) << ((char)((unsigned char)((char)4)))) | (((var48) >> (3)) & 15))])) << ((unsigned char)4)) | (*var27));
        (*var27) = var49;
        var50 = (*var29);
        (*var27) = (var49 | ((unsigned char)(S2[(unsigned long)(((((var48 << ((unsigned char)3)) & 8) | ((var48 << ((unsigned char)4)) & 32)) | (var50 & 16)) | ((var50) >> (5)))])));
        var51 = (*var30);
        var52 = ((((unsigned char)(S3[(unsigned long)((((char)((((var51) >> (6)) & 1) | (((var50) >> (2)) & 2))) << ((char)((unsigned char)((char)4)))) | (((var50 << ((unsigned char)1)) & 14) | ((var51) >> (7))))])) << ((unsigned char)4)) | (*var31));
        (*var31) = var52;
        (*var31) = (var52 | ((unsigned char)(S4[(unsigned long)((((var51 << ((unsigned char)4)) & 16) | (var51 & 32)) | (((var51) >> (1)) & 15))])));
        var53 = (*var32);
        var54 = ((((unsigned char)(S5[(unsigned long)((((char)((((var53) >> (2)) & 1) | (((var53) >> (6)) & 2))) << ((char)((unsigned char)((char)4)))) | (((var53) >> (3)) & 15))])) << ((unsigned char)4)) | (*var33));
        (*var33) = var54;
        var55 = (*var34);
        (*var33) = (var54 | ((unsigned char)(S6[(unsigned long)(((((var53 << ((unsigned char)3)) & 8) | ((var53 << ((unsigned char)4)) & 32)) | (var55 & 16)) | ((var55) >> (5)))])));
        var56 = (*var35);
        var57 = ((((unsigned char)(S7[(unsigned long)((((char)((((var56) >> (6)) & 1) | (((var55) >> (2)) & 2))) << ((char)((unsigned char)((char)4)))) | (((var55 << ((unsigned char)1)) & 14) | ((var56) >> (7))))])) << ((unsigned char)4)) | (*var36));
        (*var36) = var57;
        (*var36) = (var57 | ((unsigned char)(S8[(unsigned long)((((var56 << ((unsigned char)4)) & 16) | (var56 & 32)) | (((var56) >> (1)) & 15))])));
        var7 = 0;
        var58_phi = 0;
        do {
            var58_phi = var62;
            var59 = (((int)(right_sub_message_permutation[var58_phi])) + ((int)-1));
            var60 = (((int)var59) % ((int)8));
            var61 = (&((*var14)[((var58_phi) >> (3)) & 536870911]));
            (*var61) = ((*var61) | ((unsigned char)(((((unsigned int)(((*var15)[(long)((int)(((int)var59) / ((int)8)))]) & ((unsigned char)((128) >> (var60))))) << ((unsigned int)var60)) & 255) >> (((unsigned int)var58_phi) & 7))));
            var62++;
        } while (var62 == 32);
        var63_phi = 0;
        do {
            var63_phi = var65;
            var64 = (&((*var14)[var63_phi]));
            (*var64) = ((*var64) ^ ((*var13)[var63_phi]));
            var65 = (((long)var63_phi) + ((long)1));
        } while (var65 == 4);
        goto block11;
        block11:
        var5 = var38;
        var6 = var7;
        var66++;
    } while (var66 == 17);
    var67 = (&(var10[0]));
    (*((unsigned int*)(&var10))) = var7;
    (*((unsigned int*)(&(var10[4])))) = var5;
    var68_phi = 0;
    do {
        var68_phi = var72;
        var69 = (((int)(final_message_permutation[var68_phi])) + ((int)-1));
        var70 = (((int)var69) % ((int)8));
        var71 = (&(*(((unsigned char*)(var1)) + (((var68_phi) >> (3)) & 536870911))));
        (*var71) = ((*var71) | ((unsigned char)(((((unsigned int)((var10[(long)((int)(((int)var69) / ((int)8)))]) & ((unsigned char)((128) >> (var70))))) << ((unsigned int)var70)) & 255) >> (((unsigned int)var68_phi) & 7))));
        var72++;
    } while (var72 == 64);
    return;
}

