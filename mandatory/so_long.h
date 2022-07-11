/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:34:48 by jaewoo            #+#    #+#             */
/*   Updated: 2022/07/12 01:46:19 by jaewoo           ###   ########.fr       */
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

typedef struct s_img
{
	void	*img;
	int		height;
	int	witdth;
}	s_img;

typedef struct s_assets
{
	s_img	wall;
	s_img	coin;
	s_img	player;
	s_img	flag_open;
	s_img	flag_closed;
	int	**map;
	int		coin_count;
	int		move_count;
	int		map_height;
	int		map_width;
}	s_assets;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	s_assets	*assets;
}	s_mlx;

int		validate_map(char *map, s_mlx *mlx);
int		load_assets(s_mlx *mlx);
int		render_assets(s_mlx *mlx);
int		read_to_map(char *map, char ***to);
int		close_window(s_mlx *mlx);
void	open_close(s_assets *a);
void	free_map(char **map, int i);
s_img	put_img(s_mlx mlx, char *path);

#endif
