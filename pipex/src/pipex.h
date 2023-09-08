/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:28:42 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/08 17:39:39 by jschroed         ###   ########.fr       */
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

/**
 * @brief Resolves the full path for a given command using the PATH environment
 * variable.
 *
 * This function attempts to determine the absolute path of a given command by
 * searching through the directories listed in the PATH environment variable.
 * The function iterates over each directory in PATH, appending the command
 * to each directory, and checks if the resulting path points to an executable
 * file. If a valid path is found, it's returned; otherwise, the original
 * command string is returned.
 *
 * For instance, if the command is "ls" and "/usr/bin" is in PATH, and
 * "/usr/bin/ls" is a valid executable, the function would return "/usr/bin/ls".
 *
 * @note The function assumes that the PATH environment variable uses ':' as
 * a delimiter between different directories.
 *
 * @param cmd The command for which the path needs to be resolved.
 * @param env The array of environment strings, typically provided to the main
 * function.
 * @return The absolute path for the command if found, otherwise the original
 * command string.
 */
char	*get_path(char *cmd, char **env);

/**
 * @brief Retrieves the value of a specified environment variable.
 *
 * This function searches for the environment variable with the provided name
 * within the provided environment array. If found, it returns the value
 * associated with the environment variable (i.e., everything after the "="
 * sign). If the environment variable is not found, the function returns NULL.
 *
 * For example, if the environment contains "PATH=/usr/bin:/bin" and
 * the function is called with "PATH" as the name, it will return
 * "/usr/bin:/bin".
 *
 * @param name The name of the environment variable to search for.
 * @param env The array of environment strings, typically provided to the main
 * function.
 * @return A pointer to the value of the environment variable, or NULL if not
 * found.
 */
char	*get_env_var(char *name, char **env);

/**
 * @brief Opens a file for reading or writing based on the specified mode.
 *
 * This function is used to open a file either for reading (if `io` is 0)
 * or for writing (if `io` is 1). If the file is opened for writing,
 * and the file does not exist, it will be created. If it does exist,
 * its contents will be truncated.
 *
 * In case of any errors during opening the file, the function will
 * call the handle_err function with an appropriate error message.
 *
 * @param file The path to the file to be opened.
 * @param io The mode in which the file should be opened: 0 for reading, 1 for
 * writing.
 * @return The file descriptor associated with the opened file.
 */
int		open_file(char *file, int io);

/**
 * @brief Frees a dynamically allocated array of strings (2D char array).
 * 
 * This function is used to deallocate memory that has been previously 
 * allocated for a 2D character array (or array of strings). It iterates 
 * over each string in the array, freeing each one, and finally frees 
 * the array itself.
 * 
 * @param tab The 2D character array (array of strings) to be freed.
 */
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

/**
 * @brief Executes the child process operations for a pipex-like program.
 *
 * This function handles the operations expected to be performed by the child
 * in a pipex implementation. It opens a file for reading, duplicates the
 * standard input to read from this file, and then duplicates the write end of
 * the pipe to be the standard output. After setting up the necessary
 * redirections, it then executes a specified command.
 *
 * @param av The array of command-line arguments.
 * @param pipe_fd The file descriptors for the read and write ends of the pipe.
 * @param env The environment variables.
 */
void	child(char **av, int *pipe_fd, char **env);

/**
 * @brief Executes the parent process operations for a pipex-like program.
 *
 * This function handles the operations expected to be performed by the parent
 * in a pipex implementation. It
 * to this file, duplicates the standard input to the read end of the pipe,
 * and then closes the write end of the pipe. Finally, it executes the command
 * provided in the arguments.
 *
 * @param av The array of command line arguments, where av[3] is the command to
 *           be executed and av[4] is the file to which the output will be
 * written.
 * @param pipe_fd A file descriptor array representing the read (index 0) and
 *                write (index 1) ends of the pipe.
 * @param env The environment variable array.
 */
void	parent(char **av, int *pipe_fd, char **env);

#endif
