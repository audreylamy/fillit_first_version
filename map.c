/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:21:47 by alamy             #+#    #+#             */
/*   Updated: 2017/12/06 18:38:02 by alamy            ###   ########.fr       */
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
		return(0);
	a = 0;
	while (a < t_size[0])
	{
		b = 0;
		while (b < t_size[1]) 
		{
			if ((tab_arrange[num_block][a][b] != '.') && (map[a + position[0]][b + position[1]] != '.'))
				return(0);
			b++;
		}
		a++;
	}
	return(1);
}

void on_essaie_ttes_les_positions(char **map, char ***tab_arrange, int num_block, int size_map, int position[2])
{
	while (is_posible_position(map, tab_arrange, num_block, position, size_map) == 0)
	{
		is_posible_position(map, tab_arrange, num_block, position, size_map); // on teste une case 
		if (position[1] < (size_map - 1))
			position[1]++;
		else 
		{
			position[1] = 0;
			position[0]++;
			if (position[0] >= size_map)
			{
				position[0] = -1; // cas d erreur
				position[1] = -1;
				break;
			}
		}
	}
}

static char **placer_tetri_ds_map(char **map, char ***tab_arrange, int num_block, int position[2], int size_map)
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
				map[x][y] = tab_arrange[num_block][a][b];
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

static char **enlever_tetri_ds_map(char **map, char ***tab_arrange, int num_block, int size_map, int save_position[2])
{
	int x;
	int y;
	int a;
	int b;
	int t_size[2];
	int position[2];

	position[0] = 0;
	position[1] = 0;
	t_size[0] = 0;
	t_size[1] = 0;
	get_tetra_size(tab_arrange, num_block, t_size);
	on_essaie_ttes_les_positions(map, tab_arrange, num_block, size_map, position);
	printf("%d", position[0]);
	printf("%d", position[0]);
	x = position[0];
	a = 0; while (a < 4)
	{
		y = position[1] - t_size[1];
		b = 0;
		while (b < 4)
		{
			if (tab_arrange[num_block][a][b] != '.')
				map[x][y] = '.';
			b++;
			y++;
		}
		a++;
		x++;
	}
	return(map);
}

char **map_solve(char **map, char ***tab_arrange, int nb_block, int num_block, int size_map)
{
	int position[2];
	int save_position[2];

	position[0] = 0;
	position[1] = 0;
	//map[2][3] = (char)'#';
//	map[0][1] = (char)'#';

	on_essaie_ttes_les_positions(map, tab_arrange, num_block, size_map, position);
	printf("position[0] = %d\nposition[1] = %d\n\n", position[0], position[1]);
	if (position[0] != -1 && num_block < 2) // si on peut placer le tetri
	{
		map = placer_tetri_ds_map(map, tab_arrange, num_block, position, size_map);
		map_solve(map, tab_arrange, nb_block, num_block + 1, size_map);
		save_position[0] = position[0];
		save_position[1] = position[1];
	}
	if (position[0] == -1) // si on peut pas placer le tetri
	{
		map = enlever_tetri_ds_map(map, tab_arrange, (num_block - 1), size_map, save_position);
	}
	return(map);
}
		
void ft_impression(char **map, int size_map)
{
	int a = 0;
	int b = 0;
	while (map[a] && a < size_map)
	{
		while (map[a][b])
		{
			printf("%c", map[a][b]);
			b++;
		}
		printf("\n");
		b = 0;
		a++;
	} 
}


//	map[0][0] = (char)'#';
//	map[0][1] = (char)'#';
/*	map[0][2] = (char)'#';
	map[0][3] = (char)'#';
	map[1][3] = (char)'#';
	map[1][0] = (char)'#';
	map[1][1] = (char)'#';
	map[1][2] = (char)'#';
	map[2][0] = (char)'#';
	map[3][0] = (char)'#';
	map[3][1] = (char)'#';
	map[3][3] = (char)'#';
	map[3][2] = (char)'#'; 
*/	