/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/

#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * Copies a string from source to destination.
 *
 * This function copies the string pointed to by `src` (including the
 * null-terminator) to the buffer pointed to by `dst`.
 *
 * @param dst Pointer to the destination buffer where the string will be copied
 * to.
 * @param src Pointer to the source string that will be copied.
 */
void ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

/**
 * Duplicate a string.
 *
 * This function takes a string as input and creates a duplicate of it in a new
 * memory location.
 *
 * @param src The string to be duplicated.
 * @return A pointer to the duplicated string, or NULL if memory allocation
 * fails.
 */
char *ft_strdup(const char *src)
{
	int len;
	char *dst;

	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

/**
 * Concatenates two strings together and returns the result.
 *
 * @param s1 The first string to concatenate
 * @param s2 The second string to concatenate
 * @return A new string that is the result of concatenating s1 and s2
 * @throws NULL if either s1 or s2 is NULL, or if memory allocation fails
 */
char *ft_strjoin(char *s1, char const *s2)
{
	int s1_len;
	int s2_len;
	char *join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = malloc(s1_len + s2_len + 1);
	if (!s1 || !s2)
		return (NULL);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + s1_len), s2);
	free(s1);
	return (join);
}

/**
 * Reads the next line from a file descriptor and returns it as a string.
 *
 * This function reads from the file descriptor `fd` and returns the next line
 * of text as a dynamically allocated string. The function reads data into a
 * static buffer `buf` and appends it to the current line until a newline
 * character is encountered or the end of the file is reached.
 *
 * @param fd The file descriptor to read from.
 * @return A dynamically allocated string containing the next line of text,
 *         or NULL if the end of the file is reached or an error occurs.
 */
char *get_next_line(int fd)
{
	static char buf[BUF + 1];
	char *line;
	char *newline;
	int count;
	int len;

	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (count = read(fd, buf, BUF)))
	{
		buf[count] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (newline != NULL)
	{
		len = newline - line + 1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		len = ft_strlen(line);
		buf[0] = '\0';
	}
	line[len] = '\0';
	return (line);
}


#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("testfile.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
