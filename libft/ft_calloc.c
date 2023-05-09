/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:15:52 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/09 19:09:11 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	ret = malloc(size * num);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}

// only temp for main
// TODO
ft_bzero
