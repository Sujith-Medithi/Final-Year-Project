// function declarations
unsigned int AddRoundKey(unsigned int* var0, unsigned int var1, unsigned int var2);
void ByteSub_ShiftRow(unsigned int* var0, unsigned int var1);
unsigned int KeySchedule(unsigned int var0, unsigned int* var1);
unsigned int MixColumn_AddRoundKey(unsigned int* var0, unsigned int var1, unsigned int var2);
unsigned int SubByte(unsigned int var0);
unsigned int encrypt(unsigned int* var0, unsigned int* var1, unsigned int var2);
extern void llvm_lifetime_end_p0i8(unsigned long var0, unsigned char* var1);
extern void llvm_lifetime_start_p0i8(unsigned long var0, unsigned char* var1);
int main(void);

// global variable definitions
unsigned int __const_encrypt_out_enc_statemt[16] = {57,37,132,29,2,220,9,251,220,17,133,151,25,106,11,50,};
unsigned int round_val = 0;
unsigned int nb = 0;
unsigned int main_result = 0;
unsigned int Sbox[16][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},};
unsigned int word[4][120] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},};
unsigned int Rcon0[30] = {1,2,4,8,16,32,64,128,27,54,108,216,171,77,154,47,94,188,99,198,151,53,106,212,179,125,250,239,197,145,};
unsigned int statemt[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
unsigned int key[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
unsigned int type = 0;

unsigned int AddRoundKey(unsigned int* var0, unsigned int var1, unsigned int var2){
    unsigned int var3_phi;
    unsigned long var6_phi;
    long var4;
    unsigned long var5;
    long var7;
    long var8;
    unsigned int* var9;
    unsigned int* var10;
    unsigned int* var11;
    unsigned int* var12;
    long var13;
    block0:
    switch (var1) {
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
    var4 = ((long)((int)(((int)var3_phi) * ((int)var2))));
    var5 = ((unsigned long)var3_phi);
    var6_phi = 0;
    goto block4;
    block2:
    var3_phi = 8;
    goto block3;
    block1:
    var3_phi = 6;
    goto block3;
    block4:
    var7 = (((long)var6_phi) + ((long)var4));
    var8 = (((long)var6_phi) << ((long)((unsigned long)((long)2))));
    var9 = (&(*(((unsigned int*)(var0)) + var8)));
    (*var9) = ((*var9) ^ ((word[0])[var7]));
    var10 = (&(*(((unsigned int*)(var0)) + (var8 | 1))));
    (*var10) = ((*var10) ^ ((word[1])[var7]));
    var11 = (&(*(((unsigned int*)(var0)) + (var8 | 2))));
    (*var11) = ((*var11) ^ ((word[2])[var7]));
    var12 = (&(*(((unsigned int*)(var0)) + (var8 | 3))));
    (*var12) = ((*var12) ^ ((word[3])[var7]));
    var13 = (((long)var6_phi) + ((long)1));
    if (var13 == var5) {
        return 0;
    } else {
        var6_phi = var13;
        goto block4;
    }
}

void ByteSub_ShiftRow(unsigned int* var0, unsigned int var1){
    unsigned int* var156_phi;
    unsigned int* var2;
    unsigned int var3;
    unsigned int var4;
    unsigned int* var5;
    unsigned int var6;
    unsigned int* var7;
    unsigned int var8;
    unsigned int* var9;
    unsigned int var10;
    unsigned int* var11;
    unsigned int var12;
    unsigned int var13;
    unsigned int* var14;
    unsigned int var15;
    unsigned int* var16;
    unsigned int var17;
    unsigned int var18;
    unsigned int* var19;
    unsigned int var20;
    unsigned int* var21;
    unsigned int var22;
    unsigned int var23;
    unsigned int* var24;
    unsigned int var25;
    unsigned int* var26;
    unsigned int var27;
    unsigned int* var28;
    unsigned int var29;
    unsigned int var30;
    unsigned int* var31;
    unsigned int var32;
    unsigned int* var33;
    unsigned int var34;
    unsigned int* var35;
    unsigned int* var36;
    unsigned int var37;
    unsigned int var38;
    unsigned int* var39;
    unsigned int var40;
    unsigned int* var41;
    unsigned int var42;
    unsigned int* var43;
    unsigned int var44;
    unsigned int* var45;
    unsigned int var46;
    unsigned int* var47;
    unsigned int var48;
    unsigned int* var49;
    unsigned int var50;
    unsigned int var51;
    unsigned int* var52;
    unsigned int var53;
    unsigned int* var54;
    unsigned int var55;
    unsigned int* var56;
    unsigned int var57;
    unsigned int var58;
    unsigned int* var59;
    unsigned int var60;
    unsigned int* var61;
    unsigned int var62;
    unsigned int* var63;
    unsigned int var64;
    unsigned int var65;
    unsigned int* var66;
    unsigned int var67;
    unsigned int* var68;
    unsigned int var69;
    unsigned int var70;
    unsigned int* var71;
    unsigned int var72;
    unsigned int* var73;
    unsigned int var74;
    unsigned int var75;
    unsigned int* var76;
    unsigned int var77;
    unsigned int var78;
    unsigned int* var79;
    unsigned int var80;
    unsigned int* var81;
    unsigned int var82;
    unsigned int* var83;
    unsigned int var84;
    unsigned int* var85;
    unsigned int var86;
    unsigned int* var87;
    unsigned int* var88;
    unsigned int var89;
    unsigned int var90;
    unsigned int* var91;
    unsigned int var92;
    unsigned int* var93;
    unsigned int var94;
    unsigned int* var95;
    unsigned int var96;
    unsigned int* var97;
    unsigned int var98;
    unsigned int* var99;
    unsigned int var100;
    unsigned int* var101;
    unsigned int var102;
    unsigned int* var103;
    unsigned int var104;
    unsigned int* var105;
    unsigned int var106;
    unsigned int var107;
    unsigned int* var108;
    unsigned int var109;
    unsigned int* var110;
    unsigned int var111;
    unsigned int* var112;
    unsigned int var113;
    unsigned int* var114;
    unsigned int var115;
    unsigned int* var116;
    unsigned int var117;
    unsigned int* var118;
    unsigned int var119;
    unsigned int* var120;
    unsigned int var121;
    unsigned int* var122;
    unsigned int var123;
    unsigned int var124;
    unsigned int* var125;
    unsigned int var126;
    unsigned int* var127;
    unsigned int var128;
    unsigned int var129;
    unsigned int* var130;
    unsigned int var131;
    unsigned int* var132;
    unsigned int var133;
    unsigned int var134;
    unsigned int* var135;
    unsigned int var136;
    unsigned int* var137;
    unsigned int var138;
    unsigned int var139;
    unsigned int* var140;
    unsigned int var141;
    unsigned int var142;
    unsigned int* var143;
    unsigned int var144;
    unsigned int* var145;
    unsigned int var146;
    unsigned int* var147;
    unsigned int var148;
    unsigned int* var149;
    unsigned int var150;
    unsigned int* var151;
    unsigned int var152;
    unsigned int* var153;
    unsigned int var154;
    unsigned int* var155;
    unsigned int var157;
    block0:
    switch (var1) {
        case 4:
            var2 = (&(*(((unsigned int*)(var0)) + 1)));
            var3 = (*var2);
            var4 = ((Sbox[(long)((int)(var3 >> ((unsigned int)4)))])[(unsigned long)(var3 & 15)]);
            var5 = (&(*(((unsigned int*)(var0)) + 5)));
            var6 = (*var5);
            (*var2) = ((Sbox[(long)((int)(var6 >> ((unsigned int)4)))])[(unsigned long)(var6 & 15)]);
            var7 = (&(*(((unsigned int*)(var0)) + 9)));
            var8 = (*var7);
            (*var5) = ((Sbox[(long)((int)(var8 >> ((unsigned int)4)))])[(unsigned long)(var8 & 15)]);
            var9 = (&(*(((unsigned int*)(var0)) + 13)));
            var10 = (*var9);
            (*var7) = ((Sbox[(long)((int)(var10 >> ((unsigned int)4)))])[(unsigned long)(var10 & 15)]);
            (*var9) = var4;
            var11 = (&(*(((unsigned int*)(var0)) + 2)));
            var12 = (*var11);
            var13 = ((Sbox[(long)((int)(var12 >> ((unsigned int)4)))])[(unsigned long)(var12 & 15)]);
            var14 = (&(*(((unsigned int*)(var0)) + 10)));
            var15 = (*var14);
            (*var11) = ((Sbox[(long)((int)(var15 >> ((unsigned int)4)))])[(unsigned long)(var15 & 15)]);
            (*var14) = var13;
            var16 = (&(*(((unsigned int*)(var0)) + 6)));
            var17 = (*var16);
            var18 = ((Sbox[(long)((int)(var17 >> ((unsigned int)4)))])[(unsigned long)(var17 & 15)]);
            var19 = (&(*(((unsigned int*)(var0)) + 14)));
            var20 = (*var19);
            (*var16) = ((Sbox[(long)((int)(var20 >> ((unsigned int)4)))])[(unsigned long)(var20 & 15)]);
            (*var19) = var18;
            var21 = (&(*(((unsigned int*)(var0)) + 3)));
            var22 = (*var21);
            var23 = ((Sbox[(long)((int)(var22 >> ((unsigned int)4)))])[(unsigned long)(var22 & 15)]);
            var24 = (&(*(((unsigned int*)(var0)) + 15)));
            var25 = (*var24);
            (*var21) = ((Sbox[(long)((int)(var25 >> ((unsigned int)4)))])[(unsigned long)(var25 & 15)]);
            var26 = (&(*(((unsigned int*)(var0)) + 11)));
            var27 = (*var26);
            (*var24) = ((Sbox[(long)((int)(var27 >> ((unsigned int)4)))])[(unsigned long)(var27 & 15)]);
            var28 = (&(*(((unsigned int*)(var0)) + 7)));
            var29 = (*var28);
            (*var26) = ((Sbox[(long)((int)(var29 >> ((unsigned int)4)))])[(unsigned long)(var29 & 15)]);
            (*var28) = var23;
            var30 = (*var0);
            (*var0) = ((Sbox[(long)((int)(var30 >> ((unsigned int)4)))])[(unsigned long)(var30 & 15)]);
            var31 = (&(*(((unsigned int*)(var0)) + 4)));
            var32 = (*var31);
            (*var31) = ((Sbox[(long)((int)(var32 >> ((unsigned int)4)))])[(unsigned long)(var32 & 15)]);
            var33 = (&(*(((unsigned int*)(var0)) + 8)));
            var34 = (*var33);
            (*var33) = ((Sbox[(long)((int)(var34 >> ((unsigned int)4)))])[(unsigned long)(var34 & 15)]);
            var35 = (&(*(((unsigned int*)(var0)) + 12)));
            var156_phi = var35;
            goto block4;
        case 6:
            var36 = (&(*(((unsigned int*)(var0)) + 1)));
            var37 = (*var36);
            var38 = ((Sbox[(long)((int)(var37 >> ((unsigned int)4)))])[(unsigned long)(var37 & 15)]);
            var39 = (&(*(((unsigned int*)(var0)) + 5)));
            var40 = (*var39);
            (*var36) = ((Sbox[(long)((int)(var40 >> ((unsigned int)4)))])[(unsigned long)(var40 & 15)]);
            var41 = (&(*(((unsigned int*)(var0)) + 9)));
            var42 = (*var41);
            (*var39) = ((Sbox[(long)((int)(var42 >> ((unsigned int)4)))])[(unsigned long)(var42 & 15)]);
            var43 = (&(*(((unsigned int*)(var0)) + 13)));
            var44 = (*var43);
            (*var41) = ((Sbox[(long)((int)(var44 >> ((unsigned int)4)))])[(unsigned long)(var44 & 15)]);
            var45 = (&(*(((unsigned int*)(var0)) + 17)));
            var46 = (*var45);
            (*var43) = ((Sbox[(long)((int)(var46 >> ((unsigned int)4)))])[(unsigned long)(var46 & 15)]);
            var47 = (&(*(((unsigned int*)(var0)) + 21)));
            var48 = (*var47);
            (*var45) = ((Sbox[(long)((int)(var48 >> ((unsigned int)4)))])[(unsigned long)(var48 & 15)]);
            (*var47) = var38;
            var49 = (&(*(((unsigned int*)(var0)) + 2)));
            var50 = (*var49);
            var51 = ((Sbox[(long)((int)(var50 >> ((unsigned int)4)))])[(unsigned long)(var50 & 15)]);
            var52 = (&(*(((unsigned int*)(var0)) + 10)));
            var53 = (*var52);
            (*var49) = ((Sbox[(long)((int)(var53 >> ((unsigned int)4)))])[(unsigned long)(var53 & 15)]);
            var54 = (&(*(((unsigned int*)(var0)) + 18)));
            var55 = (*var54);
            (*var52) = ((Sbox[(long)((int)(var55 >> ((unsigned int)4)))])[(unsigned long)(var55 & 15)]);
            (*var54) = var51;
            var56 = (&(*(((unsigned int*)(var0)) + 6)));
            var57 = (*var56);
            var58 = ((Sbox[(long)((int)(var57 >> ((unsigned int)4)))])[(unsigned long)(var57 & 15)]);
            var59 = (&(*(((unsigned int*)(var0)) + 14)));
            var60 = (*var59);
            (*var56) = ((Sbox[(long)((int)(var60 >> ((unsigned int)4)))])[(unsigned long)(var60 & 15)]);
            var61 = (&(*(((unsigned int*)(var0)) + 22)));
            var62 = (*var61);
            (*var59) = ((Sbox[(long)((int)(var62 >> ((unsigned int)4)))])[(unsigned long)(var62 & 15)]);
            (*var61) = var58;
            var63 = (&(*(((unsigned int*)(var0)) + 3)));
            var64 = (*var63);
            var65 = ((Sbox[(long)((int)(var64 >> ((unsigned int)4)))])[(unsigned long)(var64 & 15)]);
            var66 = (&(*(((unsigned int*)(var0)) + 15)));
            var67 = (*var66);
            (*var63) = ((Sbox[(long)((int)(var67 >> ((unsigned int)4)))])[(unsigned long)(var67 & 15)]);
            (*var66) = var65;
            var68 = (&(*(((unsigned int*)(var0)) + 7)));
            var69 = (*var68);
            var70 = ((Sbox[(long)((int)(var69 >> ((unsigned int)4)))])[(unsigned long)(var69 & 15)]);
            var71 = (&(*(((unsigned int*)(var0)) + 19)));
            var72 = (*var71);
            (*var68) = ((Sbox[(long)((int)(var72 >> ((unsigned int)4)))])[(unsigned long)(var72 & 15)]);
            (*var71) = var70;
            var73 = (&(*(((unsigned int*)(var0)) + 11)));
            var74 = (*var73);
            var75 = ((Sbox[(long)((int)(var74 >> ((unsigned int)4)))])[(unsigned long)(var74 & 15)]);
            var76 = (&(*(((unsigned int*)(var0)) + 23)));
            var77 = (*var76);
            (*var73) = ((Sbox[(long)((int)(var77 >> ((unsigned int)4)))])[(unsigned long)(var77 & 15)]);
            (*var76) = var75;
            var78 = (*var0);
            (*var0) = ((Sbox[(long)((int)(var78 >> ((unsigned int)4)))])[(unsigned long)(var78 & 15)]);
            var79 = (&(*(((unsigned int*)(var0)) + 4)));
            var80 = (*var79);
            (*var79) = ((Sbox[(long)((int)(var80 >> ((unsigned int)4)))])[(unsigned long)(var80 & 15)]);
            var81 = (&(*(((unsigned int*)(var0)) + 8)));
            var82 = (*var81);
            (*var81) = ((Sbox[(long)((int)(var82 >> ((unsigned int)4)))])[(unsigned long)(var82 & 15)]);
            var83 = (&(*(((unsigned int*)(var0)) + 12)));
            var84 = (*var83);
            (*var83) = ((Sbox[(long)((int)(var84 >> ((unsigned int)4)))])[(unsigned long)(var84 & 15)]);
            var85 = (&(*(((unsigned int*)(var0)) + 16)));
            var86 = (*var85);
            (*var85) = ((Sbox[(long)((int)(var86 >> ((unsigned int)4)))])[(unsigned long)(var86 & 15)]);
            var87 = (&(*(((unsigned int*)(var0)) + 20)));
            var156_phi = var87;
            goto block4;
        case 8:
            var88 = (&(*(((unsigned int*)(var0)) + 1)));
            var89 = (*var88);
            var90 = ((Sbox[(long)((int)(var89 >> ((unsigned int)4)))])[(unsigned long)(var89 & 15)]);
            var91 = (&(*(((unsigned int*)(var0)) + 5)));
            var92 = (*var91);
            (*var88) = ((Sbox[(long)((int)(var92 >> ((unsigned int)4)))])[(unsigned long)(var92 & 15)]);
            var93 = (&(*(((unsigned int*)(var0)) + 9)));
            var94 = (*var93);
            (*var91) = ((Sbox[(long)((int)(var94 >> ((unsigned int)4)))])[(unsigned long)(var94 & 15)]);
            var95 = (&(*(((unsigned int*)(var0)) + 13)));
            var96 = (*var95);
            (*var93) = ((Sbox[(long)((int)(var96 >> ((unsigned int)4)))])[(unsigned long)(var96 & 15)]);
            var97 = (&(*(((unsigned int*)(var0)) + 17)));
            var98 = (*var97);
            (*var95) = ((Sbox[(long)((int)(var98 >> ((unsigned int)4)))])[(unsigned long)(var98 & 15)]);
            var99 = (&(*(((unsigned int*)(var0)) + 21)));
            var100 = (*var99);
            (*var97) = ((Sbox[(long)((int)(var100 >> ((unsigned int)4)))])[(unsigned long)(var100 & 15)]);
            var101 = (&(*(((unsigned int*)(var0)) + 25)));
            var102 = (*var101);
            (*var99) = ((Sbox[(long)((int)(var102 >> ((unsigned int)4)))])[(unsigned long)(var102 & 15)]);
            var103 = (&(*(((unsigned int*)(var0)) + 29)));
            var104 = (*var103);
            (*var101) = ((Sbox[(long)((int)(var104 >> ((unsigned int)4)))])[(unsigned long)(var104 & 15)]);
            (*var103) = var90;
            var105 = (&(*(((unsigned int*)(var0)) + 2)));
            var106 = (*var105);
            var107 = ((Sbox[(long)((int)(var106 >> ((unsigned int)4)))])[(unsigned long)(var106 & 15)]);
            var108 = (&(*(((unsigned int*)(var0)) + 14)));
            var109 = (*var108);
            (*var105) = ((Sbox[(long)((int)(var109 >> ((unsigned int)4)))])[(unsigned long)(var109 & 15)]);
            var110 = (&(*(((unsigned int*)(var0)) + 26)));
            var111 = (*var110);
            (*var108) = ((Sbox[(long)((int)(var111 >> ((unsigned int)4)))])[(unsigned long)(var111 & 15)]);
            var112 = (&(*(((unsigned int*)(var0)) + 6)));
            var113 = (*var112);
            (*var110) = ((Sbox[(long)((int)(var113 >> ((unsigned int)4)))])[(unsigned long)(var113 & 15)]);
            var114 = (&(*(((unsigned int*)(var0)) + 18)));
            var115 = (*var114);
            (*var112) = ((Sbox[(long)((int)(var115 >> ((unsigned int)4)))])[(unsigned long)(var115 & 15)]);
            var116 = (&(*(((unsigned int*)(var0)) + 30)));
            var117 = (*var116);
            (*var114) = ((Sbox[(long)((int)(var117 >> ((unsigned int)4)))])[(unsigned long)(var117 & 15)]);
            var118 = (&(*(((unsigned int*)(var0)) + 10)));
            var119 = (*var118);
            (*var116) = ((Sbox[(long)((int)(var119 >> ((unsigned int)4)))])[(unsigned long)(var119 & 15)]);
            var120 = (&(*(((unsigned int*)(var0)) + 22)));
            var121 = (*var120);
            (*var118) = ((Sbox[(long)((int)(var121 >> ((unsigned int)4)))])[(unsigned long)(var121 & 15)]);
            (*var120) = var107;
            var122 = (&(*(((unsigned int*)(var0)) + 3)));
            var123 = (*var122);
            var124 = ((Sbox[(long)((int)(var123 >> ((unsigned int)4)))])[(unsigned long)(var123 & 15)]);
            var125 = (&(*(((unsigned int*)(var0)) + 19)));
            var126 = (*var125);
            (*var122) = ((Sbox[(long)((int)(var126 >> ((unsigned int)4)))])[(unsigned long)(var126 & 15)]);
            (*var125) = var124;
            var127 = (&(*(((unsigned int*)(var0)) + 7)));
            var128 = (*var127);
            var129 = ((Sbox[(long)((int)(var128 >> ((unsigned int)4)))])[(unsigned long)(var128 & 15)]);
            var130 = (&(*(((unsigned int*)(var0)) + 23)));
            var131 = (*var130);
            (*var127) = ((Sbox[(long)((int)(var131 >> ((unsigned int)4)))])[(unsigned long)(var131 & 15)]);
            (*var130) = var129;
            var132 = (&(*(((unsigned int*)(var0)) + 11)));
            var133 = (*var132);
            var134 = ((Sbox[(long)((int)(var133 >> ((unsigned int)4)))])[(unsigned long)(var133 & 15)]);
            var135 = (&(*(((unsigned int*)(var0)) + 27)));
            var136 = (*var135);
            (*var132) = ((Sbox[(long)((int)(var136 >> ((unsigned int)4)))])[(unsigned long)(var136 & 15)]);
            (*var135) = var134;
            var137 = (&(*(((unsigned int*)(var0)) + 15)));
            var138 = (*var137);
            var139 = ((Sbox[(long)((int)(var138 >> ((unsigned int)4)))])[(unsigned long)(var138 & 15)]);
            var140 = (&(*(((unsigned int*)(var0)) + 31)));
            var141 = (*var140);
            (*var137) = ((Sbox[(long)((int)(var141 >> ((unsigned int)4)))])[(unsigned long)(var141 & 15)]);
            (*var140) = var139;
            var142 = (*var0);
            (*var0) = ((Sbox[(long)((int)(var142 >> ((unsigned int)4)))])[(unsigned long)(var142 & 15)]);
            var143 = (&(*(((unsigned int*)(var0)) + 4)));
            var144 = (*var143);
            (*var143) = ((Sbox[(long)((int)(var144 >> ((unsigned int)4)))])[(unsigned long)(var144 & 15)]);
            var145 = (&(*(((unsigned int*)(var0)) + 8)));
            var146 = (*var145);
            (*var145) = ((Sbox[(long)((int)(var146 >> ((unsigned int)4)))])[(unsigned long)(var146 & 15)]);
            var147 = (&(*(((unsigned int*)(var0)) + 12)));
            var148 = (*var147);
            (*var147) = ((Sbox[(long)((int)(var148 >> ((unsigned int)4)))])[(unsigned long)(var148 & 15)]);
            var149 = (&(*(((unsigned int*)(var0)) + 16)));
            var150 = (*var149);
            (*var149) = ((Sbox[(long)((int)(var150 >> ((unsigned int)4)))])[(unsigned long)(var150 & 15)]);
            var151 = (&(*(((unsigned int*)(var0)) + 20)));
            var152 = (*var151);
            (*var151) = ((Sbox[(long)((int)(var152 >> ((unsigned int)4)))])[(unsigned long)(var152 & 15)]);
            var153 = (&(*(((unsigned int*)(var0)) + 24)));
            var154 = (*var153);
            (*var153) = ((Sbox[(long)((int)(var154 >> ((unsigned int)4)))])[(unsigned long)(var154 & 15)]);
            var155 = (&(*(((unsigned int*)(var0)) + 28)));
            var156_phi = var155;
            goto block4;
        default:
            return;
}
    block4:
    var157 = (*var156_phi);
    (*var156_phi) = ((Sbox[(long)((int)(var157 >> ((unsigned int)4)))])[(unsigned long)(var157 & 15)]);
    return;
}

unsigned int KeySchedule(unsigned int var0, unsigned int* var1){
    unsigned int var2[4];
    unsigned char* var3;
    unsigned int var4_phi;
    unsigned int var5_phi;
    unsigned long var6_phi;
    unsigned long var7_phi;
    unsigned long var9_phi;
    unsigned long var21_phi;
    unsigned long var24_phi;
    unsigned int* var33_phi;
    unsigned int* var34_phi;
    unsigned long var35_phi;
    unsigned long var40_phi;
    unsigned int var43_phi;
    unsigned long var8;
    long var10;
    long var11;
    unsigned int* var12;
    unsigned int* var13;
    unsigned int* var14;
    unsigned int* var15;
    unsigned int* var16;
    unsigned int* var17;
    unsigned int* var18;
    unsigned int* var19;
    unsigned long var20;
    long var22;
    long var23;
    unsigned int var25;
    long var26;
    unsigned int var27;
    unsigned int var28;
    unsigned int var29;
    unsigned int var30;
    unsigned int* var31;
    unsigned int* var32;
    unsigned int* var36;
    unsigned int var37;
    long var38;
    long var39;
    long var41;
    long var42;
    block0:
    var3 = ((unsigned char*)(&var2));
    switch (var0) {
        case 128128:
            goto block9;
        case 128192:
            var4_phi = 0;
            var5_phi = 4;
            var6_phi = 6;
            var7_phi = 13;
            goto block9;
        case 128256:
            var4_phi = 0;
            var5_phi = 4;
            var6_phi = 8;
            var7_phi = 15;
            goto block9;
        case 192128:
            var4_phi = 0;
            var5_phi = 6;
            var6_phi = 4;
            var7_phi = 13;
            goto block9;
        case 192192:
            var4_phi = 0;
            var5_phi = 6;
            var6_phi = 6;
            var7_phi = 13;
            goto block9;
        case 192256:
            var4_phi = 0;
            var5_phi = 6;
            var6_phi = 8;
            var7_phi = 15;
            goto block9;
        case 256128:
            var4_phi = 1;
            var5_phi = 8;
            var6_phi = 4;
            var7_phi = 15;
            goto block9;
        case 256192:
            var4_phi = 1;
            var5_phi = 8;
            var6_phi = 6;
            var7_phi = 15;
            goto block9;
        case 256256:
            var4_phi = 1;
            var5_phi = 8;
            var6_phi = 8;
            var7_phi = 15;
            goto block9;
        default:
            return var43_phi;
}
    block17:
    (*var34_phi) = (*var33_phi);
    if (var4_phi ? (var25 == 4) : 0) {
        var35_phi = 0;
        goto block18;
    } else {
        goto block19;
    }
    block9:
    var8 = ((unsigned long)var5_phi);
    var9_phi = 0;
    goto block10;
    block10:
    var10 = (((long)var9_phi) << ((long)((unsigned long)((long)2))));
    var21_phi = 0;
    goto block12;
    block12:
    ((word[var21_phi])[var9_phi]) = (*(((unsigned int*)(var1)) + (((long)var21_phi) + ((long)var10))));
    var22 = (((long)var21_phi) + ((long)1));
    if (var22 == 4) {
        var23 = (((long)var9_phi) + ((long)1));
        if (var23 == var8) {
            var11 = (((long)var7_phi) * ((long)var6_phi));
            var12 = (&(var2[0]));
            var13 = (&(var2[1]));
            var14 = (&(var2[2]));
            var15 = (&(var2[3]));
            var16 = (&(var2[0]));
            var17 = (&(var2[1]));
            var18 = (&(var2[2]));
            var19 = (&(var2[3]));
            var20 = ((unsigned long)var5_phi);
            var24_phi = var8;
            goto block14;
        } else {
            var9_phi = var23;
            goto block10;
        }
    } else {
        var21_phi = var22;
        goto block12;
    }
    block14:
    var25 = (((unsigned int)var24_phi) % var5_phi);
    var26 = (((long)var24_phi) + ((long)-1));
    if (var25 == 0) {
        var27 = ((word[1])[var26]);
        (*var16) = ((Rcon0[(long)((int)(((int)(((unsigned int)var24_phi) / var5_phi)) + ((int)-1)))]) ^ ((Sbox[(long)((int)(((int)var27) / ((int)16)))])[(long)((int)(((int)var27) % ((int)16)))]));
        var28 = ((word[2])[var26]);
        (*var17) = ((Sbox[(long)((int)(((int)var28) / ((int)16)))])[(long)((int)(((int)var28) % ((int)16)))]);
        var29 = ((word[3])[var26]);
        (*var18) = ((Sbox[(long)((int)(((int)var29) / ((int)16)))])[(long)((int)(((int)var29) % ((int)16)))]);
        var30 = ((word[0])[var26]);
        var31 = (&((Sbox[(long)((int)(((int)var30) / ((int)16)))])[(long)((int)(((int)var30) % ((int)16)))]));
        var33_phi = var31;
        var34_phi = var19;
        goto block17;
    } else {
        (*var12) = ((word[0])[var26]);
        (*var13) = ((word[1])[var26]);
        (*var14) = ((word[2])[var26]);
        var32 = (&((word[3])[var26]));
        var33_phi = var32;
        var34_phi = var15;
        goto block17;
    }
    block18:
    var36 = (&(var2[var35_phi]));
    var37 = (*var36);
    (*var36) = ((Sbox[(long)((int)(((int)var37) / ((int)16)))])[(long)((int)(((int)var37) % ((int)16)))]);
    var38 = (((long)var35_phi) + ((long)1));
    if (var38 == 4) {
        goto block19;
    } else {
        var35_phi = var38;
        goto block18;
    }
    block19:
    var39 = (((long)var24_phi) - ((long)var20));
    var40_phi = 0;
    goto block20;
    block20:
    ((word[var40_phi])[var24_phi]) = ((var2[var40_phi]) ^ ((word[var40_phi])[var39]));
    var41 = (((long)var40_phi) + ((long)1));
    if (var41 == 4) {
        var42 = (((long)var24_phi) + ((long)1));
        if (var42 == var11) {
            var43_phi = 0;
            return var43_phi;
        } else {
            var24_phi = var42;
            goto block14;
        }
    } else {
        var40_phi = var41;
        goto block20;
    }
}

unsigned int MixColumn_AddRoundKey(unsigned int* var0, unsigned int var1, unsigned int var2){
    unsigned int var3[32];
    unsigned char* var4;
    unsigned long var8_phi;
    unsigned long var39_phi;
    long var5;
    unsigned long var6;
    unsigned long var7;
    long var9;
    unsigned int var10;
    unsigned int var11;
    unsigned int* var12;
    unsigned int var13;
    long var14;
    unsigned int var15;
    unsigned int var16;
    unsigned int var17;
    unsigned int var18;
    long var19;
    unsigned int var20;
    long var21;
    unsigned int var22;
    long var23;
    unsigned int* var24;
    unsigned int var25;
    unsigned int var26;
    unsigned int var27;
    unsigned int var28;
    unsigned int* var29;
    unsigned int var30;
    unsigned int var31;
    unsigned int var32;
    unsigned int var33;
    unsigned int* var34;
    unsigned int var35;
    unsigned int var36;
    unsigned int var37;
    long var38;
    long var40;
    long var41;
    long var42;
    long var43;
    long var44;
    block0:
    var4 = ((unsigned char*)(&var3));
    if (((int)var1) > ((int)0)) {
        var5 = ((long)((int)(((int)var2) * ((int)var1))));
        var6 = ((unsigned long)var1);
        var8_phi = 0;
        goto block4;
    } else {
        goto block2;
    }
    block4:
    var9 = (((long)var8_phi) << ((long)((unsigned long)((long)2))));
    var10 = (*(((unsigned int*)(var0)) + var9));
    var11 = (var10 << ((unsigned int)1));
    var12 = (&(var3[var9]));
    var13 = (((var10 & 2147483520) == 128) ? (var11 ^ 283) : var11);
    (*var12) = var13;
    var14 = (var9 | 1);
    var15 = (*(((unsigned int*)(var0)) + var14));
    var16 = (var15 << ((unsigned int)1));
    var17 = (var16 ^ var15);
    var18 = (((var17 & -256) == 256) ? ((var17 ^ var13) ^ 283) : (var17 ^ var13));
    (*var12) = var18;
    var19 = (var9 | 2);
    var20 = (*(((unsigned int*)(var0)) + var19));
    var21 = (var9 | 3);
    var22 = (*(((unsigned int*)(var0)) + var21));
    var23 = (((long)var8_phi) + ((long)var5));
    (*var12) = (((var22 ^ var20) ^ ((word[0])[var23])) ^ var18);
    var24 = (&(var3[var14]));
    var25 = (((var15 & 2147483520) == 128) ? (var16 ^ 283) : var16);
    (*var24) = var25;
    var26 = (var20 << ((unsigned int)1));
    var27 = (var26 ^ var20);
    var28 = (((var27 & -256) == 256) ? ((var27 ^ var25) ^ 283) : (var27 ^ var25));
    (*var24) = var28;
    (*var24) = (((var22 ^ var10) ^ var28) ^ ((word[1])[var23]));
    var29 = (&(var3[var19]));
    var30 = (((var20 & 2147483520) == 128) ? (var26 ^ 283) : var26);
    (*var29) = var30;
    var31 = (var22 << ((unsigned int)1));
    var32 = (var31 ^ var22);
    var33 = (((var32 & -256) == 256) ? ((var32 ^ var30) ^ 283) : (var30 ^ var32));
    (*var29) = var33;
    (*var29) = (((var15 ^ var10) ^ var33) ^ ((word[2])[var23]));
    var34 = (&(var3[var21]));
    var35 = (((var22 & 2147483520) == 128) ? (var31 ^ 283) : var31);
    (*var34) = var35;
    var36 = (var11 ^ var10);
    var37 = (((var36 & -256) == 256) ? ((var35 ^ var36) ^ 283) : (var35 ^ var36));
    (*var34) = var37;
    (*var34) = (((var20 ^ var15) ^ var37) ^ ((word[3])[var23]));
    var38 = (((long)var8_phi) + ((long)1));
    if (var38 == var6) {
        goto block2;
    } else {
        var8_phi = var38;
        goto block4;
    }
    block2:
    if (((int)var1) > ((int)0)) {
        var7 = ((unsigned long)var1);
        var39_phi = 0;
        goto block5;
    } else {
        return 0;
    }
    block5:
    var40 = (((long)var39_phi) << ((long)((unsigned long)((long)2))));
    (*(((unsigned int*)(var0)) + var40)) = (var3[var40]);
    var41 = (var40 | 1);
    (*(((unsigned int*)(var0)) + var41)) = (var3[var41]);
    var42 = (var40 | 2);
    (*(((unsigned int*)(var0)) + var42)) = (var3[var42]);
    var43 = (var40 | 3);
    (*(((unsigned int*)(var0)) + var43)) = (var3[var43]);
    var44 = (((long)var39_phi) + ((long)1));
    if (var44 == var7) {
        return 0;
    } else {
        var39_phi = var44;
        goto block5;
    }
}

unsigned int SubByte(unsigned int var0){
    block0:
    return (Sbox[(long)((int)(((int)var0) / ((int)16)))])[(long)((int)(((int)var0) % ((int)16)))];
}

unsigned int encrypt(unsigned int* var0, unsigned int* var1, unsigned int var2){
    unsigned int var3_phi;
    unsigned int var4_phi;
    unsigned long var5_phi;
    unsigned long var6_phi;
    unsigned int var13_phi;
    unsigned int var15_phi;
    unsigned int var16_phi;
    unsigned long var19_phi;
    unsigned long var27_phi;
    long var7;
    unsigned int* var8;
    unsigned int* var9;
    unsigned int* var10;
    unsigned int* var11;
    long var12;
    int var14;
    unsigned long var17;
    unsigned long var18;
    long var20;
    long var21;
    unsigned int* var22;
    unsigned int* var23;
    unsigned int* var24;
    unsigned int* var25;
    long var26;
    long var28;
    block0:
    KeySchedule(var2, var1);
    switch (var2) {
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
            goto block9;
}
    block5:
    var3_phi = 4;
    var4_phi = 8;
    goto block6;
    block9:
    var6_phi = 0;
    goto block10;
    block6:
    round_val = var3_phi;
    nb = var4_phi;
    switch (var2) {
        case 128192:
            goto block7;
        case 128256:
            goto block8;
        case 192192:
            goto block7;
        case 192256:
            goto block8;
        case 256192:
            goto block7;
        case 256256:
            goto block8;
        default:
            goto block9;
}
    block3:
    var3_phi = 2;
    var4_phi = 6;
    goto block6;
    block8:
    var5_phi = 8;
    goto block9;
    block7:
    var5_phi = 6;
    goto block9;
    block10:
    var7 = (((long)var6_phi) << ((long)((unsigned long)((long)2))));
    var8 = (&(*(((unsigned int*)(var0)) + var7)));
    (*var8) = ((*var8) ^ ((word[0])[var6_phi]));
    var9 = (&(*(((unsigned int*)(var0)) + (var7 | 1))));
    (*var9) = ((*var9) ^ ((word[1])[var6_phi]));
    var10 = (&(*(((unsigned int*)(var0)) + (var7 | 2))));
    (*var10) = ((*var10) ^ ((word[2])[var6_phi]));
    var11 = (&(*(((unsigned int*)(var0)) + (var7 | 3))));
    (*var11) = ((*var11) ^ ((word[3])[var6_phi]));
    var12 = (((long)var6_phi) + ((long)1));
    if (var12 == var5_phi) {
        if (((int)round_val) < ((int)-8)) {
            var15_phi = 1;
            goto block13;
        } else {
            var13_phi = 1;
            goto block12;
        }
    } else {
        var6_phi = var12;
        goto block10;
    }
    block13:
    ByteSub_ShiftRow(var0, nb);
    switch (var2) {
        case 128192:
            goto block14;
        case 128256:
            goto block15;
        case 192192:
            goto block14;
        case 192256:
            goto block15;
        case 256192:
            goto block14;
        case 256256:
            goto block15;
        default:
            goto block16;
}
    block12:
    ByteSub_ShiftRow(var0, nb);
    MixColumn_AddRoundKey(var0, nb, var13_phi);
    var14 = (((int)var13_phi) + ((int)1));
    if (((int)var13_phi) < (((int)round_val) + ((int)9))) {
        var13_phi = var14;
        goto block12;
    } else {
        var15_phi = var14;
        goto block13;
    }
    block16:
    var17 = ((unsigned long)(((int)var16_phi) * ((int)var15_phi)));
    var18 = ((unsigned long)var16_phi);
    var19_phi = 0;
    goto block17;
    block15:
    var16_phi = 8;
    goto block16;
    block14:
    var16_phi = 6;
    goto block16;
    block17:
    var20 = (((long)var19_phi) + ((long)var17));
    var21 = (((long)var19_phi) << ((long)((unsigned long)((long)2))));
    var22 = (&(*(((unsigned int*)(var0)) + var21)));
    (*var22) = ((*var22) ^ ((word[0])[var20]));
    var23 = (&(*(((unsigned int*)(var0)) + (var21 | 1))));
    (*var23) = ((*var23) ^ ((word[1])[var20]));
    var24 = (&(*(((unsigned int*)(var0)) + (var21 | 2))));
    (*var24) = ((*var24) ^ ((word[2])[var20]));
    var25 = (&(*(((unsigned int*)(var0)) + (var21 | 3))));
    (*var25) = ((*var25) ^ ((word[3])[var20]));
    var26 = (((long)var19_phi) + ((long)1));
    if (var26 == var18) {
        var27_phi = 0;
        goto block18;
    } else {
        var19_phi = var26;
        goto block17;
    }
    block18:
    main_result = (((int)main_result) + ((int)((unsigned int)((*(((unsigned int*)(var0)) + var27_phi)) != (__const_encrypt_out_enc_statemt[var27_phi])))));
    var28 = (((long)var27_phi) + ((long)1));
    if (var28 == 16) {
        return 0;
    } else {
        var27_phi = var28;
        goto block18;
    }
}

int main(void){
    block0:
    main_result = 0;
    encrypt(&(statemt[0]), &(key[0]), 128128);
    return main_result;
}

