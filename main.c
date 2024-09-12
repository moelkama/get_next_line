#include "src/get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main(int c, char **v)
{
    char    *str;
    int     fd;

    if (c == 2)
    {
        fd = open(v[1], O_RDONLY);
        while ((str = get_next_line(fd)))
            printf("%s", str);
    }
    else
        write(2, "Please set one file to read as parrameter", strlen("Please set one file to read as parrameter"));
}