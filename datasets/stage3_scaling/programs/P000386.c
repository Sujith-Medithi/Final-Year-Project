#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_85;

int branch_kernel_85(int s, int u) {
    int flag = 0;
    if (s > 1290) {
        flag = 855;
    } else {
        flag = 870;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_85(sec_pw, pub_user);
    glob_branch_85 = branch_out;
    return 0;
}
