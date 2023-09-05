/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:12 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/05 20:27:13 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_err(char *str, int exit_num)
{
	perror(str);
	exit(exit_num);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_file(char *file, int io)
{
	int	ret;

	if (io == 0)
		ret = open(file, O_RDONLY, 0644);
	if (io == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		handle_err("pipex: Error opening file", 1);
	return (ret);
}

char	*get_env_var(char *name, char **env)
{
	int		i;
	int		j;
	char	*env_var_name;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		env_var_name = ft_substr(env[i], 0, j);
		if (ft_strcmp(env_var_name, name) == 0)
		{
			free(env_var_name);
			return (env[i] + j + 1);
		}
		free(env_var_name);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**paths;
	char	*path_part;

	i = -1;
	paths = ft_split(get_env_var("PATH", env), ':');
	while (paths[i++])
	{
		path_part = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_free_tab(paths);
	return (cmd);
}
