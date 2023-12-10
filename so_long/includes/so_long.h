/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:02:09 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/10 14:32:38 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
// =========

# include <unistd.h>
# include <fcntl.h> // file control options 
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
// # include <stdbool.h> //TODO: needed?

// Variables
// =========

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define TREASURE  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_Q				113
# define KEY_ESC  			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define WALL_XPM			"resources/sprites/wall.xpm"
# define FLOOR_XPM			"resources/sprites/floor.xpm"
# define TREASURE_XPM		"resources/sprites/treasure.xpm"
# define PLAYER_FRONT_XPM	"resources/sprites/player/player_front.xpm"
# define PLAYER_BACK_XPM	"resources/sprites/player/player_back.xpm"
# define PLAYER_LEFT_XPM	"resources/sprites/player/player_left.xpm"
# define PLAYER_RIGHT_XPM	"resources/sprites/player/player_right.xpm"
# define EXIT_CLOSED_XPM	"resources/sprites/exit_closed.xpm"
# define EXIT_OPENED_XPM	"resources/sprites/exit_opened.xpm"

// Structs
// =======

// no bool type in c98, so create own
typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			treasures;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		treasures;
	t_image		exit_opened;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

// Functions
// =========

// checks
void	check_input(int argc, char **argv, t_game *game);

// utils
int		error(char *message, t_game *game);
char	*ft_strappend(char **s1, const char *s2);
void	free_map(t_game *game);
void	print_movements(t_game *game);

// inits
void	init_map(t_game *game, char *argv);
void	init_vars(t_game *game);
void	init_mlx(t_game *game);
void	init_sprites(t_game *game);
t_image load_sprite(void *mlx, char *path, t_game *game);

// render
int render_map(t_game *game);
void render_map_sprite(t_game *game, int y, int x);
void render_sprite(t_game *game, t_image sprite, int y, int x);
void render_player(t_game *game, int y, int x);

#endif