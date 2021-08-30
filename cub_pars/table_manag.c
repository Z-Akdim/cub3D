/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:27:25 by zakdim            #+#    #+#             */
/*   Updated: 2021/01/09 19:32:34 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_table(char **tab)
{
	int i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	free_table(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_remplir_tab(char **tab,
int the_longest_line, int nbr_rows, int i)
{
	char	**new_tab;
	int		cpt;

	cpt = -1;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (nbr_rows + 1))))
		return (0);
	while (++cpt < nbr_rows)
		if (!(new_tab[cpt] = (char *)malloc(sizeof(char)
		* (the_longest_line + 1))))
			return (0);
	while (++i < nbr_rows)
	{
		cpt = -1;
		while (++cpt < the_longest_line)
			if (cpt < (int)ft_strlen(tab[i]))
				new_tab[i][cpt] = tab[i][cpt];
			else
				new_tab[i][cpt] = ' ';
		new_tab[i][cpt] = '\0';
	}
	new_tab[i] = NULL;
	return (new_tab);
}

char	**new_table(void)
{
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * 1);
	tab[0] = NULL;
	return (tab);
}

char	**ft_join_to_table(char **tab, char *str)
{
	int		len;
	char	**new_t;
	int		i;

	i = 0;
	len = count_table(tab);
	new_t = (char**)malloc(sizeof(char*) * (len + 2));
	while (tab[i] != NULL)
	{
		new_t[i] = ft_strdup(tab[i]);
		i++;
	}
	new_t[i] = ft_strdup(str);
	new_t[++i] = NULL;
	free_table(tab);
	return (new_t);
}
