/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:12 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/09 19:40:21 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	count_args(char *cmd)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (cmd[i] && cmd[i] != ' ')
		{
			count++;
			while (cmd[i] && cmd[i] != ' ')
				i++;
		}
	}
	return (count);
}

int	set_args(char **args, char *cmd)
{
	int	i;
	int	arg_index;

	i = 0;
	arg_index = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (cmd[i] && cmd[i] != ' ')
		{
			args[arg_index] = &cmd[i];
			while (cmd[i] && cmd[i] != ' ')
				i++;
			cmd[i++] = '\0';
			arg_index++;
		}
	}
	return (arg_index);
}

char	**parse_cmd(char *cmd)
{
	char	**args;
	int		arg_count;

	arg_count = count_args(cmd);
	args = (char **)malloc((arg_count + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	args[set_args(args, cmd)] = NULL;
	return (args);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
