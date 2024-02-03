/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:30:32 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/03 11:37:20 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!*s1 || !s2)
		return (NULL);
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	str = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	free(*s1);
	return (str);
}

void	print_movements(t_game *game)
{
	char	*movements;
	char	*text;

	movements = ft_itoa(game->movements);
	text = ft_strjoin("Movements: ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, text);
	free(movements);
	free(text);
}

int	error(char *message, t_game *game)
{
	if (game->map_alloc == true)
		free_map(game);
	free(game);
	ft_printf("Error: %s\n", message);
	exit (EXIT_FAILURE);
}

void	debug_print(t_game *game, int keysym)
{
	ft_printf("Key pressed: %d\n", keysym);
	ft_printf("Player position: x=%d, y=%d\n", \
			game->map.player.x, game->map.player.y);
	ft_printf("Treasures left: %d\n", game->map.treasures);
}
