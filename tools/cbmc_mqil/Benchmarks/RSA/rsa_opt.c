// function declarations

// global variable definitions
unsigned char _str[18] = {77,101,115,115,97,103,101,32,100,97,116,97,32,61,32,37,100,0,};
unsigned char _str_1[21] = {10,69,110,99,114,121,112,116,101,100,32,100,97,116,97,32,61,32,37,100,0,};
unsigned char _str_2[28] = {10,79,114,105,103,105,110,97,108,32,77,101,115,115,97,103,101,32,83,101,110,116,32,61,32,37,100,0,};

int main(void){
    unsigned int var0_phi;
    unsigned int var1_phi;
    unsigned int var3_phi;
    unsigned int var5_phi;
    unsigned int var6_phi;
    unsigned int var7_phi;
    unsigned int var12_phi;
    unsigned int var13_phi;
    unsigned int var17_phi;
    int var2;
    int var4;
    int var8;
    int var9;
    unsigned int var10;
    int var11;
    int var14;
    int var15;
    int var16;
    block0:
    var0_phi = 2;
    goto block1;
    block1:
    var1_phi = var0_phi;
    goto block2;
    block2:
    if ((((int)var0_phi) % ((int)var1_phi)) == 0) {
        if ((((int)12) % ((int)var1_phi)) == 0) {
            var3_phi = var1_phi;
            goto block5;
        } else {
            goto block4;
        }
    } else {
        goto block4;
    }
    block4:
    var2 = (((int)var1_phi) + ((int)-1));
    if (((int)var1_phi) > ((int)1)) {
        var1_phi = var2;
        goto block2;
    } else {
        var3_phi = 0;
        goto block5;
    }
    block5:
    if (var3_phi == 1) {
        var5_phi = var0_phi;
        goto block7;
    } else {
        var4 = (((int)var0_phi) + ((int)1));
        if (var4 == 12) {
            var5_phi = 12;
            goto block7;
        } else {
            var0_phi = var4;
            goto block1;
        }
    }
    block7:
    printf(&(_str[0]), 12);
    var6_phi = 0;
    var7_phi = 1;
    goto block8;
    block8:
    var8 = (((int)var7_phi) * ((int)12));
    var9 = (((int)var6_phi) + ((int)1));
    if (var9 == var5_phi) {
        var10 = (25 / var5_phi);
        var11 = (((unsigned int)var8) % 21);
        printf(&(_str_1[0]), var11);
        if (var5_phi > 25) {
            var17_phi = 1;
            goto block12;
        } else {
            var12_phi = 0;
            var13_phi = 1;
            goto block10;
        }
    } else {
        var6_phi = var9;
        var7_phi = var8;
        goto block8;
    }
    block12:
    printf(&(_str_2[0]), var17_phi);
    return 0;
    block10:
    var14 = (((int)var13_phi) * ((int)var11));
    var15 = (((int)var12_phi) + ((int)1));
    if (var15 == var10) {
        var16 = (((unsigned int)var14) % 21);
        var17_phi = var16;
        goto block12;
    } else {
        var12_phi = var15;
        var13_phi = var14;
        goto block10;
    }
}
