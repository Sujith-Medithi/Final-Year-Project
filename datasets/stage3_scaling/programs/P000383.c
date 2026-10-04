#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_82;

int branch_kernel_82(int s, int u) {
    int flag = 0;
    if (s > 1245) {
        flag = 825;
    } else {
        flag = 840;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_82(sec_pw, pub_user);
    glob_branch_82 = branch_out;
    return 0;
}
