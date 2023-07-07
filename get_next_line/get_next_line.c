/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:45:23 by jschroed          #+#    #+#             */
/*   Updated: 2023/07/07 18:18:47 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_get_more(left_str);
	return (line);
}

/* [> Temp <] */
/* #include <stdio.h> */
/* #include <fcntl.h> */
/* int	main(void) */
/* { */
/*     char *line; */
/*     int i; */
/*     int fd; */
/*  */
/*     fd = open("test.txt", O_RDONLY); */
/*     i = 1; */
/*     while ( i < 7) */
/*     { */
/*         line = get_next_line(fd); */
/*         printf("line [%02d]: %s",i, line); */
/*         free(line); */
/*     } */
/*     close(fd); */
/* } */
