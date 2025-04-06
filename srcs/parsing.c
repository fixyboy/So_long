/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:04:59 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:05:00 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_so_strlen(game->map[i]) != game->map_width)
		{
			ft_printf("Error\nMap is not rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_line_content(char *line, int *exit_count, int *player_count,
		int *collectible_count)
{
	int		index;
	char	current_char;

	index = 0;
	while (line[index] != '\0' && line[index] != '\n')
	{
		current_char = line[index];
		if (current_char != '0' && current_char != '1' && current_char != 'C'
			&& current_char != 'P' && current_char != 'E')
		{
			ft_printf("Error\nInvalid character in the map\n");
			return (0);
		}
		if (current_char == 'E')
			(*exit_count)++;
		if (current_char == 'P')
			(*player_count)++;
		if (current_char == 'C')
			(*collectible_count)++;
		index++;
	}
	return (1);
}

int	validate_counts(int count_exit, int count_playeur, int count_collect)
{
	if (count_exit != 1)
	{
		ft_printf("Error\nThere must be exactly one 'E' int the map\n");
		return (0);
	}
	if (count_playeur != 1)
	{
		ft_printf("Error\nThere must be exactly one 'P' in the map\n");
		return (0);
	}
	if (count_collect < 1)
	{
		ft_printf("Error\nThere must be one or more 'C' in the map\n");
		return (0);
	}
	return (1);
}

int	check_interior(t_game *game)
{
	int	row_index;
	int	exit_count;
	int	player_count;
	int	collectible_count;

	row_index = 1;
	exit_count = 0;
	player_count = 0;
	collectible_count = 0;
	game->map_height = game->nb_line;
	while (row_index < game->map_height - 1)
	{
		if (!check_line_content(game->map[row_index], &exit_count,
				&player_count, &collectible_count))
		{
			return (0);
		}
		row_index++;
	}
	game->item = collectible_count;
	return (validate_counts(exit_count, player_count, collectible_count));
}
