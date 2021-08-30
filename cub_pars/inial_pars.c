/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inial_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:27:25 by zakdim            #+#    #+#             */
/*   Updated: 2021/01/09 19:32:27 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_parse(t_mlx *m)
{
	m->ccolor.r = -1;
	m->ccolor.g = -1;
	m->ccolor.b = -1;
	m->ccolor.f = -1;
	m->ccolor.c = -1;
	m->witdth = -1;
	m->height = -1;
}

char	**new_tab(void)
{
	char **tab;

	tab = (char **)malloc(sizeof(char *));
	tab[0] = NULL;
	return (tab);
}
