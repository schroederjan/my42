/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
#include <stdio.h>
#include <stdint.h>

int main() {
    printf("SIZE_MAX = %zu\n", SIZE_MAX);
    return 0;
}

