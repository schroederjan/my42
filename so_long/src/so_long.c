/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:46:44 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/17 18:37:13 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	//TODO: check if malloc check needed
	check_input(argc, argv, game);
	init_map(game, argv[1]);
	init_vars(game);
	init_objects(game);
	check_map(game);
	init_mlx(game);
	init_sprites(game);
	render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, ButtonPressMask, close_game, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, render_map, game);
	mlx_loop(game->mlx_ptr);
	cleanup_game(game);
}
