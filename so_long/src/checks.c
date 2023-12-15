/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:33:55 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/15 20:04:52 by jschroed         ###   ########.fr       */
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

void debug_print(t_game *game, int keysym)
{
	ft_printf("Key pressed: %d\n", keysym); // Debug print
	ft_printf("Player position: x=%d, y=%d\n", 
			game->map.player.x, game->map.player.y);
	ft_printf("Treasures left: %d\n", game->map.treasures);
}

void check_for_empty_line_in_map(char *map, t_game *game)
{
	int i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error("Invalid map. (Empty line at beginning)", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error("Invalid map. (Empty line in the middle)", game);
		}
		i++;
	}
}
