/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:15:05 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/04 19:15:06 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t n)
{
	void	*ret;

	ret = b;
	while (n--)
		*(char *)b++ = (unsigned char)c;
	return (ret);
}
