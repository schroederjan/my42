/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:02:20 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/21 09:49:19 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			render_map_sprite(game, y, x);
			x++;
		}
		y++;
	}
	print_movements(game);
	return (0);
}

void	render_map_sprite(t_game *game, int y, int x)
{
	char	param;

	param = game->map.full[y][x];
	if (param == '1')
		render_sprite(game, game->wall, y, x);
	else if (param == '0')
		render_sprite(game, game->floor, y, x);
	else if (param == 'C')
		render_sprite(game, game->treasures, y, x);
	else if (param == 'E')
	{
		if (game->map.treasures == 0)
			render_sprite(game, game->exit_opened, y, x);
		else
			render_sprite(game, game->exit_closed, y, x);
	}
	else if (param == 'P')
		render_player(game, y, x);
}

void	render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(\
			game->mlx_ptr, \
			game->win_ptr, \
			sprite.xpm_ptr, \
			column * sprite.x, \
			line * sprite.y \
			);
}

void	render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		render_sprite(game, game->player_front, y, x);
	else if (game->player_sprite == BACK)
		render_sprite(game, game->player_back, y, x);
	else if (game->player_sprite == LEFT)
		render_sprite(game, game->player_left, y, x);
	else if (game->player_sprite == RIGHT)
		render_sprite(game, game->player_right, y, x);
}
