/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:04:10 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:04:12 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_number_of_lines(char *str, t_game *game)
{
	int		fd;
	int		count;
	char	*line;
	int		i;

	count = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	line = "f";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			count++;
		if (i == 0)
			game->map_width = ft_so_strlen(line);
		i++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**build_map(t_game *game, char *str)
{
	int		fd;
	char	**tab;
	int		i;

	i = 0;
	game->nb_line = count_number_of_lines(str, game);
	if (game->nb_line == 0)
		return (ft_printf("Error\nThe file is invalide\n"), exit(1), NULL);
	tab = malloc(sizeof(char *) * (game->nb_line + 1));
	if (!tab)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nFile invalide\n"), exit(1), NULL);
	while (i < game->nb_line)
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
			return (NULL);
		i++;
	}
	tab[i] = 0;
	free(get_next_line(fd));
	close(fd);
	return (tab);
}
