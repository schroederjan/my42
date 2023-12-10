/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:45:23 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/10 10:30:33 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}
