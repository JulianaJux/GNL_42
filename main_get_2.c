#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // O_RDONLY
int main()
{
int fd = open("teste.txt", O_RDONLY);
printf("->%s", get_next_line(0));
printf("->%s", get_next_line(fd));
printf("->%s", get_next_line(fd));
printf("->%s", get_next_line(fd));
printf("->%s", get_next_line(fd));
}