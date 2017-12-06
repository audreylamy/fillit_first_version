/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:44:12 by Deydou            #+#    #+#             */
/*   Updated: 2017/11/30 15:05:13 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 4096

int main(int argc, char **argv)
{
	char	**tab;

	tab = NULL;
    if (argc < 2)
		write(2, "usage: \n", 7);
    if (argc == 2)
	{
		tab = ft_read(argv[1]);
	// ft_putstr(&tab[0][0]);
	// ft_putchar('\n');
	// ft_putstr(&tab[1][0]);
	// ft_putchar('\n');
	// ft_putstr(&tab[2][0]);
	// ft_putchar('\n');
	// ft_putstr(&tab[3][0]);
	}
	return (0);
}