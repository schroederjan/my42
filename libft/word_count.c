#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#define STOP '|'

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

bool    is_space(char c)
{
    return(c == ' ' || c == '\t' || c == '\n');
}

int     main(void)
{
    char    c;
    char    prev;
    long    n_chars = 0L;
    
}
