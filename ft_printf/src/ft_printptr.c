/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:03:32 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/31 20:08:14 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO
void	ft_putptr(uintptr_t num)
{

}

// TODO
int	ft_ptrlen(uintptr_t num)
{

}

int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		count += ft_ptrlen(ptr);
	}
	return (count);
}
