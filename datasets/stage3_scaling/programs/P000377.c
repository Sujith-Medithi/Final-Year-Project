#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_76;

int branch_kernel_76(int s, int u) {
    int flag = 0;
    if (s > 1155) {
        flag = 765;
    } else {
        flag = 780;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_76(sec_pw, pub_user);
    glob_branch_76 = branch_out;
    return 0;
}
