#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nested_7 = 0;

int classify_kernel_7(int score, int flag) {
    int cat = 0;
    if (score > 50) {
        if (score > 80) { cat = 3; } else { cat = 2; }
    } else {
        if (score > 20) { cat = 1; } else { cat = 0; }
    }
    return cat + flag;
}

int main()
{
    int sec_score;
    int pub_flag;
    int level;
    level = classify_kernel_7(sec_score, pub_flag);
    glob_nested_7 = level;
    return 0;
}
