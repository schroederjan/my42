/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_various.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:33:55 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/03 12:16:27 by jschroed         ###   ########.fr       */
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
		error("Invalid map. File extention != '.ber'.", game);
}

void	check_for_empty_line_in_map(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error("Invalid map. Empty line at beginning", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error("Invalid map. Empty line in the middle", game);
		}
		i++;
	}
}

void	check_map_rectangular(t_game *game)
{
	int		i;
	size_t	row_length;

	i = 0;
	if (game->map.rows > 0)
		row_length = ft_strlen(game->map.full[0]);
	while (i < game->map.rows) 
	{
		if (ft_strlen(game->map.full[i]) != row_length)
			error("Invalid map. The map is not rectangular.", game);
		i++;
	}
}
