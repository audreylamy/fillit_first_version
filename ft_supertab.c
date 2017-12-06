/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supertab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:54:30 by alamy             #+#    #+#             */
/*   Updated: 2017/12/05 09:18:34 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* On met les tetris en haut a gauche de chaque case du tableau */

static int ft_ymin(char ***tab_tab, int num_block)
{
	int x;
	int y;
	int result;

	x = 0;
	y = 0;
	result = 3;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tab_tab[num_block][x][y] != (char)'.' && y < result)
				result = y;
			y++;
		}
		y = 0;
		x++;
	}
	return(result);
}

static int ft_xmin(char ***tab_tab, int num_block)
{
	int x;
	int y;
	int result;

	x = 0;
	y = 0;
	result = 3;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tab_tab[num_block][x][y] != (char)'.' && x < result)
				result = x;
			y++;
		}
		y = 0;
		x++;
	}
	return(result);
}

static char ***tetrisagauche(char ***tab_tab, int nb_block)
{	
	int block;
	int x;
	int xmin;
	int y;

	block = 0;
	x = 0;
	y = 0;
	while (block < nb_block)
	{
		xmin = ft_xmin(tab_tab, block);
		if (ft_xmin(tab_tab, block) == 3)
		{
			while (y < 4)
			{
				tab_tab[block][x][y] = tab_tab[block][3][y];
				y++;
			}
		}
		else while (xmin < 4)
		{
			while (y < 4)
			{
				tab_tab[block][x][y] = tab_tab[block][xmin][y];
				y++;
			}
			y = 0;
			x++;
			xmin++;
		}
	    while (x < 4)
		{
			while (y < 4)
			{
				tab_tab[block][x][y] = (char)'.';
				y++;
			}
			y = 0;
			x++;
		} 
		block++;
		x = 0;
	} 
	return(tab_tab); 
} 

static char ***tetrisenhaut(char ***tab_tab, int nb_block)
{	
	int block;
	int x;
	int ymin;
	int y;

	block = 0;
	while (block < nb_block)
	{
		x = 0;
		y = 0;
		ymin = ft_ymin(tab_tab, block);
		if (ft_ymin(tab_tab, block) == 3)
		{
			while (x < 4)
			{
				tab_tab[block][x][y] = tab_tab[block][x][3];
				tab_tab[block][x][3] = (char)'.';
				x++;
			}
		}
		else while (ymin < 4)
		{
			while (x < 4)
			{
				tab_tab[block][x][y] = tab_tab[block][x][ymin];
				x++;
			}
			x = 0;
			y++;
			ymin++;
		} 
	    while (y < 4)
		{
			while (x < 4)
			{
				tab_tab[block][x][y] = (char)'.';
				x++;
			}
			x = 0;
			y++;
		} 
		block++;
	}
	return(tab_tab); 
} 

/*
** fonction qui supprime les points
*/

// static char ***suppr_point(char ***tab_tab, int nb_block)
// {
// 	int x;
// 	int y;
// 	int num_block;

// 	x = 0;
// 	y = 0;
// 	num_block = 0;

// 	while (num_block < nb_block)
// 	{
// 		while (x < 4)
// 		{
// 			if (tab_tab[num_block][x][y + 1] == 'A' + num_block && tab_tab[num_block][x][y] == '.')
// 			{
// 				tab_tab[num_block][x][y] = ' ';
// 			}
// 			tab_tab[num_block][x] = *ft_strsplit(tab_tab[num_block][x], '.');
// 			// ft_putstr(tab_tab[num_block][x]);
// 			// ft_putchar('\n');
// 			x++;
// 		}
// 		x = 0;
// 		num_block++;
// 	}
// 	return (tab_tab);
// }

char  ***tab_tab_arrange(char ***tab_tab, int nb_block)
{	
	int block;
	int x;
	int y;

	block = 0;
	x = 0;
	y = 0;
	tab_tab = tetrisagauche(tab_tab, nb_block);
	tab_tab = tetrisenhaut(tab_tab, nb_block);
	// tab_tab = suppr_point(tab_tab, nb_block);
	return(tab_tab); 
} 