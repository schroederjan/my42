/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:42 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/05 19:36:40 by jschroed         ###   ########.fr       */
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

void	handle_err(char *str);
char	*get_path(char *cmd, char **env);
char	*get_env_var(char *name, char **env);
void	ft_free_tab(char **tab);
void	exec(char *cmd, char **env);
void	exit_handler(int exit_number);
int		open_file(char *file, int io);

#endif
