/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:59:20 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/15 14:46:04 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# define OPEN_MAX 1000
# define EMPTY_LINE 2
# define GET_NEXT_LINE 3
# define NO_NL -1

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_gets
{
	char		*leftover;
	int			fd;
}					t_gets;

int					get_next_line(int fd, char **line);

#endif
