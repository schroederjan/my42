/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:33:55 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/30 09:21:14 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_input(int argc, char **argv, t_game *game)
{
	int	argv_len;

	game->map_alloc = false;
	if (argc > 2)
		error("Too many arguments. (>2)", game);
	if (argc < 2)
		error("No map file provided.", game);
	argv_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][argv_len - 4], ".ber", 4))
		error("Invalid map file extention. (!= '.ber')", game);
}

int	error(char *message, t_game *game)
{
	if (game->map_alloc == true)
		free_map(game);
	free(game);
	ft_printf("Error: %s\n", message);
	exit (EXIT_FAILURE);
}

