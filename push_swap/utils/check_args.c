/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:53:45 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/13 19:39:46 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**get_args(int argc, char **argv, int *start_index)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*start_index = 0;
	}
	else
	{
		args = argv;
		*start_index = 1;
	}
	return (args);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	args = get_args(argc, argv, &i);
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!is_num(args[i]))
			error_handler("Error: Argument not a number.");
		if (contains(tmp, args, i))
			error_handler("Error: Argument has duplicates.");
		if (tmp < -2147483648 || tmp > 2147483647)
			error_handler("Error: Argument out of INT range.");
		i++;
	}
	if (argc == 2)
		free_tab(args);
}
