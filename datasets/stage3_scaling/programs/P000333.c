#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_32;

int branch_kernel_32(int s, int u) {
    int flag = 0;
    if (s > 495) {
        flag = 325;
    } else {
        flag = 340;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_32(sec_pw, pub_user);
    glob_branch_32 = branch_out;
    return 0;
}
