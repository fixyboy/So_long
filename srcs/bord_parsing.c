/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bord_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:03:56 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:04:04 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_and_last_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i] && game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("Error\nInvalid first line border\n");
			return (0);
		}
		i++;
	}
	while (game->map[game->nb_line - 1][j] != '\0' && game->map[game->nb_line
		- 1][j] != '\n')
	{
		if (game->map[game->nb_line - 1][j] != '1')
		{
			ft_printf("Error\nInvalid last line border\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_border_map(t_game *game)
{
	int	i;

	i = 0;
	game->len_line = ft_so_strlen(game->map[i]);
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->len_line - 1] != '1')
		{
			ft_printf("Error\nInvalid side border map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_all(t_game *game, char *str)
{
	if (check_map_name(str) == 0)
		return (0);
	if (check_first_and_last_line(game) == 0)
		return (0);
	if (check_map_rectangle(game) == 0)
		return (0);
	if (check_big_map(game) == 0)
		return (0);
	if (check_border_map(game) == 0)
		return (0);
	if (check_interior(game) == 0)
		return (0);
	posplayer(game);
	if (map_dup(game) == 0)
		return (0);
	else
		return (1);
}
