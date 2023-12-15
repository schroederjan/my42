/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:39:22 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/15 19:38:06 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

int victory_game(t_game *game)
{
	ft_printf("Movements: %d\n", ++game->movements);
	// TODO: to be implemented.
	/* cleanup(game); */
	ft_printf("YOU WIN!\n");
	exit(EXIT_FAILURE);
}

int close_game(t_game *game)
{
	ft_printf("Movements: %d\n", game->movements);
	// TODO: to be implemented.
	/* cleanup(game); */
	ft_printf("CLOSED GAME\n");
	exit(EXIT_FAILURE);
}
