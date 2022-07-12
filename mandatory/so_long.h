/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:34:48 by jaewoo            #+#    #+#             */
/*   Updated: 2022/07/13 00:18:25 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define X_EVENT_KEY_EXIT	17
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct t_img
{
	void	*img;
	int		height;
	int		witdth;
}		t_img;

typedef struct t_assets
{
	t_img	wall;
	t_img	coin;
	t_img	player;
	t_img	flag_open;
	t_img	flag_closed;
	int		**map;
	int		coin_count;
	int		move_count;
	int		map_height;
	int		map_width;
}		t_assets;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_assets	*assets;
}	t_mlx;

int		validate_map(char *map, t_mlx *mlx);
int		load_assets(t_mlx *mlx);
int		render_assets(t_mlx *mlx);
int		read_to_map(char *map, char ***to);
int		close_window(t_mlx *mlx);
void	open_close(t_assets *a);
void	free_map(char **map, int i);
s_img	put_img(t_mlx mlx, char *path);

#endif
