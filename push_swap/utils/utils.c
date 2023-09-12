/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:16:18 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/12 20:22:59 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (*str)
		i++;
	while (i >= 0)
		free(str[i--]);
}
