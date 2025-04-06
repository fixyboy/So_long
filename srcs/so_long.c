/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:05:05 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:05:06 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	posplayer(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->playerx = j;
				game->playery = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	destroyimages(t_game *game, int error)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->mohaimage[i])
			mlx_destroy_image(game->mlx, game->mohaimage[i]);
	i = -1;
	while (++i < 6)
		if (game->texture[i + 10])
			mlx_destroy_image(game->mlx, game->texture[i + 10]);
	i = 0;
	while (++i < 4)
		if (game->texture[i])
			mlx_destroy_image(game->mlx, game->texture[i]);
	if (error)
		ft_printf("Error\nInvalid image!\n");
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_map(game->map),
			ft_printf("Error\nInitialization mlx failed\n"));
	game->win = mlx_new_window(game->mlx, ft_so_strlen(game->map[0]) * 60,
			strlen_tab(game->map) * 60, "fix it");
	if (!game->win)
		return (free(game->mlx), free_map(game->map),
			ft_printf("Error\nWindow opening failed\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	static t_game	game_state = {0};

	game_state.direction = 3;
	if (argc == 2)
	{
		game_state.map = build_map(&game_state, argv[1]);
		if (!game_state.map)
			return (1);
		if (check_map_all(&game_state, argv[1]) == 0)
			return (free_map(game_state.map), 0);
		if (init_game(&game_state))
			return (1);
		make_image(&game_state);
		start_game(&game_state);
		mlx_hook(game_state.win, KeyPress, KeyPressMask, &touch_key,
			&game_state);
		mlx_hook(game_state.win, 17, 0, close_window, game_state.mlx);
		mlx_loop(game_state.mlx);
		destroyimages(&game_state, 0);
	}
	else
		return (ft_printf("Error\nWrong number of arguments\n"));
	return (0);
}
