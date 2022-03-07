#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		counter;

	fd = open("brodsky.txt", O_RDONLY);
	counter = 0;

	while (counter < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		counter++;
	}
}
