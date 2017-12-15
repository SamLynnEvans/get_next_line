#include "get_next_line.h"

int	read_from_file(int fd, char **line)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (*line == NULL)
			*line = ft_strdup(buff);
		else
			*line = ft_strjoin_free(*line, buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	if (*line == NULL && ret == 0)
		return (0);
	return (1);
}

t_gets *find_gets(int	fd, t_list **list)
{
	t_gets	*gets;
	t_list	*new;

	new = *list;
	while (new != NULL)
	{
		if (((t_gets *)new->content)->fd == fd)
			return ((t_gets *)new->content);
		new = new->next; 
	}
	gets = malloc(sizeof(t_gets));
	gets->leftover = NULL;
	gets->fd = fd;
	new = malloc(sizeof(t_list));
	new->content = (void *)gets;
	ft_lstadd(list, new);
	return (gets);
}

void	split_string_at_nl(char **line, t_gets *gets)
{
	int	i;
	int	len;
	char *tmp;

	if (*line == NULL)
		return ;
	len = ft_strlen(*line);
	i = 0;
	tmp = *line;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			gets->leftover = ft_strsub(*line, i + 1, len + 1);
			*line = ft_strsub(*line, 0, i);
			free(tmp);
			return ;
		}
		i++;
	}
}

int		check_leftover(char **leftover, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*leftover == NULL || **leftover == '\0')
		return (1);
	tmp = *leftover;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			*line = ft_strsub(*leftover, 0, i);
			*leftover = ft_strsub(*leftover, i + 1, ft_strlen(*leftover));
			free(tmp);
			return (0);
		}
		i++;
	}
	*line = *leftover;
	*leftover = NULL;
	return (1);
}

int get_next_line(int fd, char **line)
{
	static t_list	*list;
	int				end;
	t_gets			*gets;
	
	end = 1;
	if (line == NULL || fd == -1)
		return (-1);
	*line = NULL;
	gets = find_gets(fd, &list);	
	if (check_leftover(&(gets->leftover), line))
		end = read_from_file(fd, line);
	split_string_at_nl(line, gets);
	return (end);
}
