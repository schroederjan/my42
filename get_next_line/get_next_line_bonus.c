/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:45:23 by jschroed          #+#    #+#             */
/*   Updated: 2023/08/14 20:04:51 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		num_bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	num_bytes_read = 1;
	while (!ft_strchr(stash, '\n') && num_bytes_read != 0)
	{
		num_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (num_bytes_read == -1)
		{
			free(buff);
			free(stash); 
			return (NULL);
		}
		buff[num_bytes_read] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_update_stash(stash[fd]);
	return (line);
}


/* Temp */
int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		eof1 = 0, eof2 = 0, eof3 = 0;

	fd1 = open("test.txt", O_RDONLY);;
	fd2 = open("test1.txt", O_RDONLY);
	fd3 = open("test2.txt", O_RDONLY);

	while (!(eof1 && eof2 && eof3))
	{
		line = get_next_line(fd1);
		if (line == NULL)
		{
			free(line);
			close(fd1);
			eof1 = 1;
		}
		else
		{
			printf("%s", line);
			free(line);
		}

		line = get_next_line(fd2);
		if (line == NULL)
		{
			free(line);
			close(fd2);
			eof2 = 1;
		}
		else
		{
			printf("%s", line);
			free(line);
		}

		line = get_next_line(fd3);
		if (line == NULL)
		{
			free(line);
			close(fd3);
			eof3 = 1;
		}
		else
		{
			printf("%s", line);
			free(line);
		}

		line = get_next_line(fd3);
		if (line == NULL)
		{
			free(line);
			close(fd3);
			eof3 = 1;
		}
		else
		{
			printf("%s", line);
			free(line);
		}

		line = get_next_line(fd2);
		if (line == NULL)
		{
			free(line);
			close(fd2);
			eof2 = 1;
		}
		else
		{
			printf("%s", line);
			free(line);
		}

		line = get_next_line(fd1);
		if (line == NULL)
		{
			free(line);
			close(fd1);
			eof1 = 1;
		}
		else
		{
			printf("%s", line);
			free(line);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
