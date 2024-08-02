#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <unistd.h>
# include <stdlib.h>

#ifndef BUF
# define BUF 42
#endif

char *get_next_line(int fd);

#endif

