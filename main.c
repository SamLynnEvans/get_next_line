#include "get_next_line.h"

int	test(int fd, char **line);

int main(int ac, char **argv)
{
	int     fd;
	int     i;
	char    *line;
	int		fd2;

	i = 1;
	if (ac)
	{
		fd = open(argv[i], O_RDONLY);
/*		get_next_line(fd, &line);
		if (*line == '\0')
			ft_putstr("EMPTY LINE\n");
		else
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		free(line);
		
		get_next_line(fd, &line);
		if (*line == '\0')
			ft_putstr("EMPTY LINE\n");
		else
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		free(line);
		
		get_next_line(fd, &line);
		if (*line == '\0')
			ft_putstr("EMPTY LINE\n");
		else
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		free(line);
		
		get_next_line(fd, &line);
		if (*line == '\0')
			ft_putstr("EMPTY LINE\n");
		else
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		free(line);
		
 		get_next_line(fd, &line);
		if (*line == '\0')
			ft_putstr("EMPTY LINE\n");
		else
		{
			ft_putstr(line);
			ft_putchar('\n');
		}*/
//		free(line);
//		get_next_line(fd, &line);
//		ft_putstr(line);
//		ft_putchar('\n');
//		free(line);
				
/*		fd2 = open(argv[2], O_RDONLY);
		get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
*/
		while (get_next_line(fd, &line) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
		}
	}
}
