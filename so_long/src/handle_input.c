/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:21:16 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/21 19:47:49 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		move_player(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_S)
		move_player(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_A)
		move_player(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_D)
		move_player(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_Q)
		close_game(game);
	return (0);
}

void	move_player(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == 'E' && game->map.treasures == 0)
		victory_game(game);
	else if ((game->map.full[new_y][new_x] == '0')
			|| (game->map.full[new_y][new_x] == 'C'))
	{
		game->map.full[last_y][last_x] = '0';
		if (game->map.full[new_y][new_x] == 'C')
			game->map.treasures--;
		game->map.player.y = new_y;
		game->map.player.x = new_x;
		game->map.full[new_y][new_x] = 'P';
		game->movements++;
		render_map(game);
	}
}
