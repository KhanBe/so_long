/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:38:10 by jaewoo            #+#    #+#             */
/*   Updated: 2022/07/13 01:00:08 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i < 5)
		return (0);
	if (filename[i - 4] != '.' || filename[i - 3] != 'b'
		|| filename[i - 2] != 'e' || filename[i - 1] != 'r')
		return (0);
	return (1);
}

int	validate_map(char *filename, t_mlx *mlx)
{
	int		i;
	char	**map;

	if (!check_extention(map))
		return (0);
	map = (char **)malloc(sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	map[i] = (char *)malloc(sizeof(char));
	if (!map[i])
		return (free_map(map, i), 0);
	map[i][0] = '\0';
	i = read_to_map(filename, &map);
	if (i < 3)
		return (free_map(map, i), 0);
	mlx->assets = (t_assets *)malloc(sizeof(t_assets));
	mlx->assets->map_height = i;
	mlx->assets->map_width = ft_strlen(map[0]);
	if (mlx->assets->map_width < 3 || !check_validity(mlx, map))
		return (free_map(map, i), 0);
	if (!check_borders(mlx, map) || !check_elements(mlx, map))
		return (free_map(map, i), 0);
	mlx->assets->map = map;
	return (1);
}
