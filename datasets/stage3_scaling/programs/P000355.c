#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_54;

int branch_kernel_54(int s, int u) {
    int flag = 0;
    if (s > 825) {
        flag = 545;
    } else {
        flag = 560;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_54(sec_pw, pub_user);
    glob_branch_54 = branch_out;
    return 0;
}
