/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:34:32 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/21 19:46:52 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_game *game)
{
	check_columns(game);
	check_rows(game);
	check_map_elements(game);
	check_map_elements_quantity(game);
}

void	check_columns(t_game *game)
{
	int	i;
	int	last_column;

	i = 0;
	last_column = game->map.columns;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != '1')
			error("Invalid map. First column  missing wall.", game);
		else if (game->map.full[i][last_column] != '1')
			error("Invalid map. Last column missing wall.", game);
		i++;
	}
}

void	check_rows(t_game *game)
{
	int	i;
	int	last_row;

	i = 0;
	last_row = game->map.rows - 1;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != '1')
			error("Invalid map. First row missing wall.", game);
		else if (game->map.full[last_row][i] != '1')
			error("Invalid map. Last row missing wall.", game);
		i++;
	}
}

void	check_map_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				error("Invalid map. Other element than 'CEP01'.", game);
			x++;
		}
		y++;
	}
}

void	check_map_elements_quantity(t_game *game)
{
	if (game->map.treasures == 0)
		error("Invalid map. No treasure 'C' found.", game);
	else if (game->map.exit == 0)
		error("Invalid map. No map exit 'E' found.", game);
	else if (game->map.players != 1)
		error("Invalid map. More than one player 'P' found.", game);
}
