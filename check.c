/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:50:17 by alamy             #+#    #+#             */
/*   Updated: 2017/11/27 17:29:09 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** On check le nombre de ligne et on renvoie une erreur si on rencontre un caractere different de "."
** ou "#" ou "\0".
*/

static int ft_nb_lignes_ou_caracteres_indesirables(int nb, char *buffer)
{
	int ctr;
	int nb_lignes;

	ctr = 0;
	nb_lignes = 1;
	while (ctr < nb)
	{		
		if (buffer[ctr] != '\n' && buffer[ctr] != '.' && buffer[ctr] != '#' && buffer[ctr] != '\0')
			return(-1);  // On renvoie une erreur si on a des caracteres indesirables
		if (buffer[ctr] == '\n')
			nb_lignes++;
		ctr++;
	}
	if (nb_lignes > 129 || nb_lignes < 4 || (nb_lignes + 1) % 5 != 0)
		return(-1);      // Il y a trop de lignes car seuls vingt six tetriminos peuvent etre proposes
	return(nb_lignes);
}

/*
** On check la largeur des lignes.
*/

static int	check_largeur_lignes(int nb, char *buffer)
{
	int ctr;
	int nb_ligne;
	int chara_ligne;
	int d;
	
	chara_ligne = 0;
	nb_ligne = 1;
	ctr = 0;
	d = 0;
	while (ctr < nb)
	{
		while (buffer[ctr] != '\n' && ctr < nb) // on verifie qu il n y a pas plus de 4 caracteres par ligne
		{
			if (buffer[ctr] == '#')
			{
				d++;
			}
			chara_ligne++;
			ctr++;
		}
		if (nb_ligne % 5 == 0 && chara_ligne > 0)
			return(-1);
		if (nb_ligne % 5 != 0 && chara_ligne != 4)
			return(-1);
		chara_ligne = 0;
		ctr++;
		nb_ligne++;
	}
	return(0);
}

/*
** On check si le nombre de points est superieur a 12.
*/

static int	check_nb_pt(int nb, char *buffer)
{
	int ctr;
	int	ctrbis;
	int i_pt;
	
	ctr = 0;
	ctrbis = 0;
	i_pt = 0;
	while (ctr < nb)
	{
		while (ctrbis < 20)
		{
			if (buffer[ctr] == '.')
				i_pt++;
			ctrbis++;
			ctr++;
		}
		if (i_pt != 12)
			return(-1);
		ctr++;
	}
	return(0);
}

/*
** On check l'agencement des caracteres "#" entre eux.
*/

static int	check_agencement(int nb, char *buffer)
{
	int i;

	i = 1;
	while (i < nb)
	{
		if (buffer[i] == '#' && (buffer[i-1] != '#' && buffer[i+1] != '#' && buffer[i+5] != '#' && buffer[i-5] != '#'))
			return(-1);
		i++;
	}
	return(0);
}

int check_validation(int nb, char *buffer)
{
	if (ft_nb_lignes_ou_caracteres_indesirables(nb, buffer) == -1)
		return(-1);
	if (check_largeur_lignes(nb, buffer) == -1)
		return(-1);
	if (check_nb_pt(nb, buffer) == -1)
		return(-1);
	if (check_agencement(nb, buffer) == -1)
		return(-1);
	return (0);
}