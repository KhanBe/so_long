/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:23:56 by jaewoo            #+#    #+#             */
/*   Updated: 2022/07/13 00:32:50 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (ft_putstr("CANNOT FOUND MAP"), 0);
	mlx.mlx = mlx_init();
	if (!validate_map(argv[1], &mlx))
		return (ft_putstr("INVALID MAP"), 0);
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "so_long");
	load_assets(&mlx);
	render_assets(&mlx);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
}
