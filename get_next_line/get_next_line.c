/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:45:23 by jschroed          #+#    #+#             */
/*   Updated: 2023/07/07 18:59:37 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_rest_str(int fd, char *rest_str)
{
	char	*buff;
	int		num_bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	num_bytes_read = 1;
	while (!ft_strchr(rest_str, '\n') && num_bytes_read != 0)
	{
		num_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (num_bytes_read == -1)
		{
			free(buff);
			free(rest_str);
			return (NULL);
		}
		buff[num_bytes_read] = '\0';
		rest_str = ft_strjoin(rest_str, buff);
	}
	free(buff);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_str = ft_read_to_rest_str(fd, rest_str);
	if (!rest_str)
		return (NULL);
	line = ft_get_line(rest_str);
	rest_str = ft_update_rest_str(rest_str);
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
