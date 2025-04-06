/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:04:20 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:04:22 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_dup(t_game *game)
{
	int		i;
	char	**map_dup;

	i = 0;
	map_dup = ft_calloc(sizeof(char *), (game->map_height + 1));
	if (!map_dup)
		return (0);
	while (i < game->map_height)
	{
		map_dup[i] = ft_strdup(game->map[i]);
		if (!map_dup[i])
			return (free_map(map_dup), 0);
		i++;
	}
	flood_fill(game->playery, game->playerx, map_dup);
	i = 0;
	if (check_flood_fill(map_dup) == 0)
	{
		return (free_map(map_dup), 0);
	}
	return (free_map(map_dup), 1);
}

int	flood_fill(int x, int y, char **map)
{
	if (map[x][y] == '1' || map[x][y] == 'A' || map[x][y] == 'E')
	{
		map[x][y] = 'A';
		return (0);
	}
	map[x][y] = 'A';
	if (flood_fill(x, y - 1, map) || flood_fill(x, y + 1, map) || flood_fill(x
			- 1, y, map) || flood_fill(x + 1, y, map))
		return (1);
	return (0);
}

int	check_flood_fill(char **map_dup)
{
	int	i;
	int	j;

	i = 0;
	while (map_dup[i])
	{
		j = 0;
		while (map_dup[i][j])
		{
			if (map_dup[i][j] == 'E' || map_dup[i][j] == 'C')
			{
				ft_printf("Error\nInvalid map please take another\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
