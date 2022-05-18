#include <stdio.h>
#include <fcntl.h>
#include "./libft/get_next_line.h"

int main(void)
{
	int fd;
	char	*str;

	fd = open("maps/map1.ber", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
}
