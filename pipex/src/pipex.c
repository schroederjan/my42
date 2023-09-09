/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:26 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/09 19:45:41 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	/* split_cmd = parse_cmd(cmd); */
	path = get_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: Command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_tab(split_cmd);
		/* free_args(split_cmd); */
		exit(127);
	}
	free(path);
	ft_free_tab(split_cmd);
	/* free_args(split_cmd); */
	handle_err("pipex: Replacing process with cmd failed.", 2);
}

void	child(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	close(fd);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	exec(av[2], env);
}

void	parent(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	close(fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (ac != 5)
	{
		write(2, "./pipex file1 cmd1 cmd2 file2\n", 31);
		exit (1);
	}
	if (pipe(pipe_fd) == -1)
		handle_err("pipex: Failed to create pipe", 2);
	pid = fork();
	if (pid == -1)
		handle_err("pipex: Failed to create a new process", 2);
	if (!pid)
		child(av, pipe_fd, env);
	wait(&status);
	parent(av, pipe_fd, env);
}
