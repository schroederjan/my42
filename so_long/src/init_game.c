/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:00:27 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/11 20:58:37 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_vars(t_game *game)
{
	game->map.treasures = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	game->player_sprite = RIGHT;
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		error("No mlx pointer found.", game);
	}
	game->win_ptr = mlx_new_window(\
			game->mlx_ptr, \
			game->map.columns * IMG_WIDTH, \
			game->map.rows * IMG_HEIGHT, \
			"so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		error("Error creating window.", game);
	}
}

void	init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = load_sprite(mlx, WALL_XPM, game);
	game->floor = load_sprite(mlx, FLOOR_XPM, game);
	game->treasures = load_sprite(mlx, TREASURE_XPM, game);
	game->player_front = load_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_back = load_sprite(mlx, PLAYER_BACK_XPM, game);
	game->player_left = load_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = load_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->exit_opened = load_sprite(mlx, EXIT_OPENED_XPM, game);
	game->exit_closed = load_sprite(mlx, EXIT_CLOSED_XPM, game);
}

t_image	load_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error("Error loading sprite.", game);
	return (sprite);
}
