/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:12 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/09 20:20:34 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* char	**call_awk(char *av) */
/* { */
/*     char	**cmd; */
/*     size_t	i; */
/*     size_t	k; */
/*  */
/*     cmd = (char **)malloc(3 * sizeof(char *)); */
/*     cmd[0] = ft_strdup("awk"); */
/*     if (av[4] == av[ft_strlen(av) - 1]) */
/*     { */
/*         if (av[4] == '\'' && av[5] == '\"') */
/*         { */
/*             cmd[1] = ft_strdup("-e"); */
/*             cmd[2] = ft_strdup("{ print }"); */
/*             cmd[3] = NULL; */
/*             return (cmd); */
/*         } */
/*         i = 5; */
/*         k = 0; */
/*         cmd[1] = (char *)malloc(sizeof(char) * (ft_strlen(av) - 4)); */
/*         while (av[i] && i < (ft_strlen(av) - 1)) */
/*             cmd[1][k++] = av[i++]; */
/*         cmd[1][k] = 0; */
/*         cmd[2] = NULL; */
/*         return (cmd); */
/*     } */
/*     handle_err("pipex: The provided awk command has a syntax issue.", 2); */
/*     return (NULL); */
/* } */

static char	**handle_default_cmd(void)
{
	char	**cmd;

	cmd = (char **)malloc(3 * sizeof(char *));
	cmd[0] = ft_strdup("awk");
	cmd[1] = ft_strdup("-e");
	cmd[2] = ft_strdup("{ print }");
	cmd[3] = NULL;
	return (cmd);
}

static char	**create_cmd_from_av(char *av)
{
	char	**cmd;
	size_t	i;
	size_t	k;

	cmd = (char **)malloc(3 * sizeof(char *));
	cmd[0] = ft_strdup("awk");
	i = 5;
	k = 0;
	cmd[1] = (char *)malloc(sizeof(char) * (ft_strlen(av) - 4));
	while (av[i] && i < (ft_strlen(av) - 1))
		cmd[1][k++] = av[i++];
	cmd[1][k] = 0;
	cmd[2] = NULL;
	return (cmd);
}

char	**call_awk(char *av)
{
	char	**cmd;

	cmd = (char **)malloc(3 * sizeof(char *));
	cmd[0] = ft_strdup("awk");
	if (av[4] == av[ft_strlen(av) - 1])
	{
		if (av[4] == '\'' && av[5] == '\"')
			return (handle_default_cmd());
		return (create_cmd_from_av(av));
	}
	handle_err("pipex: The provided awk command has a syntax issue.", 2);
	return (NULL);
}
