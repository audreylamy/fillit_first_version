/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:21:47 by alamy             #+#    #+#             */
/*   Updated: 2017/12/08 18:43:18 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// On cree la map la plus petite possible

char **map_create(int size_map)
{
	char **map;
	int x;
	int y;

	x = 0;
	y = 0;
	map = (char **)malloc(sizeof(char*) * size_map);
	if (map == NULL)
		return (0);
	while (x < size_map)
	{
		map[x] = (char *)malloc(sizeof(char) * size_map);
		if (map == NULL)
			return (0);
		while (y < size_map)
		{
			map[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	return (map);
}

void	get_tetra_size(char ***tab_arrange, int num_block, int size[2])
{
	int a;
	int b;

	size[0] = 0;
	size[1] = 0;

	a = 0;
	while(a < 4)
	{
		b = 0;
		while(b < 4)
		{
			if (tab_arrange[num_block][a][b] != '.' && b > size[1])
				size[1] = b;
			if (tab_arrange[num_block][a][b] != '.' && a > size[0])
				size[0] = a;
			b++;
		}
		a++;
	}
	size[0]++;
	size[1]++;
}

static int is_posible_position(char **map, char ***tab_arrange, int num_block, int position[2], int size_map)
{
	int t_size[2];
	int a;
	int b;

	get_tetra_size(tab_arrange, num_block, t_size);
	if ((t_size[0] + position[0] > size_map) || (t_size[1] + position[1] > size_map))
	{
		return(0);
	}
	a = 0;
	while (a < (t_size[0]))
	{
		b = 0;
		while (b < (t_size[1])) 
		{
			if ((tab_arrange[num_block][a][b] != '.') && (map[a + position[0]][b + position[1]] != '.'))
			{
				return(0);
			}
			b++;
		}
		a++;
	}
	return(1);
}

static int on_essaie_ttes_les_positions(char **map, char ***tab_arrange, int num_block, int size_map, int position[2])
{
	while (is_posible_position(map, tab_arrange, num_block, position, size_map) == 0)
	{
		if (position[1] < (size_map - 1))
		{
			position[1]++;
		}
		else 
		{
			position[1] = 0;
			position[0]++;
			if (position[0] >= size_map)
			{
				return(0);
			}
		}
		
	}
	return(1);
}

static char **placer_tetri_ds_map(char **map, char ***tab_arrange, int num_block, int position[2])
{
	int x;
	int y;
	int a;
	int b;

	x = position[0];
	y = position[1];
	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			if (tab_arrange[num_block][a][b] != '.')
			{
				map[x][y] = tab_arrange[num_block][a][b];
			}
			b++;
			y++;
		}
		y = position[1];
		b = 0;
		a++;
		x++;
	}
	return(map);
}

static char **map_retour_en_arriere(char **map, int num_block, int size_map)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (map[a] && a < (size_map))
	{
		while (map[a][b] && b < (size_map))
		{
			if (map[a][b] == 'A' + num_block)
				map[a][b] = '.';
			b++;
		}
		a++;
		b = 0;
	}
	return(map);
}

char **map_solve(char **map, char ***tab_arrange, int nb_block, int num_block, int size_map)
{
	char **tmp;
	int position[2];

	position[0] = 0;
	position[1] = 0;

	if (num_block == nb_block)
	{
		return(map);
	}
	while (position[0] <= size_map)
	{
		while (position[1] <= (size_map)) 
		{
			while (is_posible_position(map, tab_arrange, num_block, position, size_map) == 1)
			{
				map = placer_tetri_ds_map(map, tab_arrange, num_block, position);
				tmp = map_solve(map, tab_arrange, nb_block, num_block + 1, size_map);
				if (tmp)
					return (tmp);
			}
			map_retour_en_arriere(map, num_block, size_map);
			position[1]++;
		}	
		position[1] = 0;
		position[0]++;
	}
	return(NULL);
} 

static char **print_map(char **map, int size_map)
{
	int a = 0;
	int b = 0;
	while (map[a] && a < size_map)
	{
		while (map[a][b] && b < size_map)
		{
			ft_putchar(map[a][b]);
			b++;
		}
		ft_putchar('\n');
		b = 0;
		a++;
	} 
	return(NULL);
}

char **resolution(char ***tab_arrange, int nb_block, int size)
{
	char **solve;
	int num_block;
	char **map;

	map = map_create(size);
	num_block = 0;
	solve = map_solve(map, tab_arrange, nb_block, num_block, size);
	if (solve == NULL)
	{
		return (resolution(tab_arrange, nb_block, size + 1));
	}
	else
	{
		print_map(map, size);
	}
	return(NULL);
}

