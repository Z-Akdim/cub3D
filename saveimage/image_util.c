/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:27:25 by zakdim            #+#    #+#             */
/*   Updated: 2021/01/09 19:29:07 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

int		cast_all_rays2(t_cube *cube)
{
	int		i;
	double	wall_strip_hieght;

	i = 0;
	cube->ray.angle = cube->player.angle - (30 * M_PI) / 180;
	while (i < (int)cube->m.witdth)
	{
		cast_ray(cube);
		cube->ray.angle += (FOV * ANGLE_TO_RAD) / cube->m.witdth;
		cube->ray.dist_tab[i] = cube->ray.distance;
		cube->ray.distance = cube->ray.distance *
		cos(cube->ray.angle - cube->player.angle);
		wall_strip_hieght = (cube->tile_size / cube->ray.distance)
		* (cube->dest_project_plane);
		if (!cube->ray.was_hit_vert)
			fill_image(cube, i, wall_strip_hieght, cube->ray.wall_hit_x);
		else
			fill_image(cube, i, wall_strip_hieght, cube->ray.wall_hit_y);
		i++;
	}
	find_sprits(cube);
	return (0);
}
