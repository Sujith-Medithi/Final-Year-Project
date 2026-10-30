#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_97;

int branch_kernel_97(int s, int u) {
    int flag = 0;
    if (s > 1470) {
        flag = 975;
    } else {
        flag = 990;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_97(sec_pw, pub_user);
    glob_branch_97 = branch_out;
    return 0;
}
