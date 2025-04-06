/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:04:15 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:04:16 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_map_name(char *str)
{
	int	len;
	int	i;

	len = ft_strlen_name(str) - 1;
	i = 0;
	if (str[len] == 'r')
		i++;
	if (str[len - 1] == 'e')
		i++;
	if (str[len - 2] == 'b')
		i++;
	if (str[len - 3] == '.')
		i++;
	if (i == 4)
		return (1);
	else
	{
		ft_printf("Error\nFile's name is not valid !\n");
		return (0);
	}
}

int	check_big_map(t_game *game)
{
	if (game->nb_line > 17)
		return (ft_printf("Error\nMap is bigger than \n"), 0);
	return (1);
}
