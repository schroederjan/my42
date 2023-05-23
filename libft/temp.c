/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	else 
		while (n--)
			*d++ = *s++;
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char dest[4];
	const char *src = "abc";
	char *result;

	result = ft_memmove(dest, src, 5);
	printf("%s\n", result);
}
