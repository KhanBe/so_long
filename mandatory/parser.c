/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:38:10 by jaewoo            #+#    #+#             */
/*   Updated: 2022/07/13 23:47:53 by jaewoo           ###   ########.fr       */
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

int	check_validity(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'p' ||
				map[i][j] == 'C' || map[i][j] == 'E'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_elements(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	count_c;
	int	count_e;
	int	count_p;

	i = ((count_c = 0, count_e = 0, count_p = 0), 0);
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (map[i][j] == 'C')
				count_c++;
			if (map[i][j] == 'E')
				count_e++;
			if (map[i][j] == 'P')
				count_p++;
			j++;
		}
		i++;
	}
	if (count_c < 1 || count_e < 1 || 1 != count_p)
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
