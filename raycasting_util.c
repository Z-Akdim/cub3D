/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:27:25 by zakdim            #+#    #+#             */
/*   Updated: 2021/01/09 18:22:50 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	wall_hit(t_cube *cube, double vert_distance, double horz_distance)
{
	cube->ray.wall_hit_x = (vert_distance < horz_distance) ?
	cube->ray.vert_wall_hit_x : cube->ray.horz_wall_hit_x;
	cube->ray.wall_hit_y = (vert_distance < horz_distance) ?
	cube->ray.vert_wall_hit_y : cube->ray.horz_wall_hit_y;
	cube->ray.distance = (vert_distance < horz_distance) ?
	vert_distance : horz_distance;
	cube->ray.was_hit_vert = (vert_distance < horz_distance) ? 1 : 0;
	check_texture(cube);
	cube->texture.initial_txt_data =
	(int *)mlx_get_data_addr(cube->texture.initial_txt,
	&cube->bpp, &cube->size_l, &cube->endian);
}

int		count_sprit(t_cube *cube)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	j = 0;
	while (cube->m.s_map.map[i])
	{
		j = 0;
		while (cube->m.s_map.map[i][j])
		{
			if (cube->m.s_map.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
