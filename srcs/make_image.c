/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:04:43 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:04:45 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_moha_image(t_game *game)
{
	int	r;

	game->mohaimage[0] = mlx_xpm_file_to_image(game->mlx, "xpm/santa_back.xpm",
			&r, &r);
	game->mohaimage[1] = mlx_xpm_file_to_image(game->mlx, "xpm/santa_front.xpm",
			&r, &r);
	game->mohaimage[2] = mlx_xpm_file_to_image(game->mlx, "xpm/santa_right.xpm",
			&r, &r);
	game->mohaimage[3] = mlx_xpm_file_to_image(game->mlx, "xpm/santa_left.xpm",
			&r, &r);
	game->texture[1] = mlx_xpm_file_to_image(game->mlx, "xpm/border_tree.xpm",
			&r, &r);
	game->texture[3] = mlx_xpm_file_to_image(game->mlx, "xpm/floor_green.xpm",
			&r, &r);
	game->texture[2] = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &r, &r);
}

void	load_texture(t_game *game)
{
	int	r;

	game->texture[10] = mlx_xpm_file_to_image(game->mlx, "xpm/collec/col1.xpm",
			&r, &r);
	game->texture[11] = mlx_xpm_file_to_image(game->mlx, "xpm/collec/col2.xpm",
			&r, &r);
	game->texture[12] = mlx_xpm_file_to_image(game->mlx, "xpm/collec/col3.xpm",
			&r, &r);
	game->texture[13] = mlx_xpm_file_to_image(game->mlx, "xpm/collec/col4.xpm",
			&r, &r);
	game->texture[14] = mlx_xpm_file_to_image(game->mlx, "xpm/collec/col5.xpm",
			&r, &r);
	game->texture[15] = mlx_xpm_file_to_image(game->mlx, "xpm/collec/col.xpm",
			&r, &r);
}

void	make_image(t_game *game)
{
	load_moha_image(game);
	load_texture(game);
	if (!game->mohaimage[0] || !game->mohaimage[1] || !game->mohaimage[2]
		|| !game->mohaimage[3] || !game->texture[1] || !game->texture[3]
		|| !game->texture[2] || !game->texture[10] || !game->texture[11]
		|| !game->texture[12] || !game->texture[13] || !game->texture[14]
		|| !game->texture[15])
		destroyimages(game, 1);
}
