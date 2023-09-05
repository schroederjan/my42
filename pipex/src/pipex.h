/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:42 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/05 20:30:44 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

/**
* @brief Handle errors and exit the program with a specified code.
* @param str The error message to print.
* @param exit_num The exit code to use when terminating the program.
*/
void	handle_err(char *str, int exit_num);

char	*get_path(char *cmd, char **env);

char	*get_env_var(char *name, char **env);

void	ft_free_tab(char **tab);

/**
 * @brief Execute a command within the pipex context.
 * 
 * This function attempts to execute a given command, and will exit with
 * an error message if the command is not found. The function uses the `execve`
 * syscall to replace the current process image with a new one, specified
 * by the command.
 *
 * @param cmd The command string to be executed, e.g., "ls -l".
 * @param env A pointer to the environment variables.
 * 
 * @note On failure, this function exits the program with a status code of 127.
 */
void	exec(char *cmd, char **env);

void	exit_handler(int exit_number);

int		open_file(char *file, int io);

#endif
