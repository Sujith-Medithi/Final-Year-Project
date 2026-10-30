#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_implicit_4 = 0;

int branch_kernel_4(int secret, int pub_id) {
    int flag = 0;
    if (secret > 100) {
        flag = 1;
    } else {
        flag = 2;
    }
    return flag + pub_id;
}

int main()
{
    int sec_pw;
    int pub_user;
    int outcome;
    outcome = branch_kernel_4(sec_pw, pub_user);
    glob_implicit_4 = outcome;
    return 0;
}
