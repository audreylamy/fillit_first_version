/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:43:55 by alamy             #+#    #+#             */
/*   Updated: 2017/12/08 18:32:57 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 1000

/*
** On check le nombre de bloc dans le fichier
*/

static int ft_nb_block(int nb, char *buffer)
{
	int i;
	int nb_block_tetri;

	i = 0;
	nb_block_tetri = 1;
	while (i < nb)
	{
		if (buffer[i] == '\n' && ((buffer[i + 1] == '\n') || (buffer[i + 1] == '\0')))
			nb_block_tetri++;
			
		i++;
	}
	return (nb_block_tetri);
}

/*
** On cree un tableau avec le nombre de bloc et on obtient les tetri separes
* */

static char ***create_tab_tab(char *buffer, int nb_block)
{	
	int block;
	int k;
	int x;
	int y;
	char ***tab_tab;

	block = 0;
	k = 0;
	tab_tab = (char***)malloc(sizeof(char**) * (nb_block));
	if (tab_tab == NULL)
		return (0);
	while (block < nb_block)
	{
		x = 0;
		tab_tab[block] = (char**)malloc(sizeof(char*) * 4);
		if (tab_tab[block] == NULL)
			return (NULL);
		while (x < 4)
		{
			y = 0;
			tab_tab[block][x] = (char*)malloc(sizeof(char) * 4);
			if (tab_tab[block][x] == NULL)
				return (NULL);
			while (y < 4)
			{
				if (buffer[k] == '#')
					tab_tab[block][x][y] = 'A' + block;
				else 
					tab_tab[block][x][y] = '.';
				y++;
				k++;
			}
			x++;
			k++;
		}
		k++;
		block++;
	} 
	return(tab_tab); 
} 

char	**ft_read(char *argv)
{
	int		fd;
    int		nb;
    char	buffer[BUF_SIZE + 1];
	char 	***tab_tab;
	char 	***tab_arrange;
	char 	**map;
	int		nb_block;
	int num_block = 0;
	int size_map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		write(1, "open() failed\n", 15);
	while ((nb = read(fd, buffer, BUF_SIZE)) > 0)
	{
		if (check_validation(nb, buffer) == -1)
			write(2, "error validation\n", 18);
		else
		{
			nb_block = ft_nb_block(nb, buffer);
			tab_tab = create_tab_tab(buffer, nb_block);
			tab_arrange = tab_tab_arrange(tab_tab, nb_block);
			size_map = ft_sqrt(nb_block * 4);
			map = map_create(size_map);
			map = resolution(tab_arrange, nb_block, size_map);
		}
	}
	return(0);
}