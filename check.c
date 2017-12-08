/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:50:17 by alamy             #+#    #+#             */
/*   Updated: 2017/12/08 19:04:53 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_nb_lines_and_char_not_wanted(int nb, char *buffer)
{
	int ctr;
	int ct_lines;

	ctr = 0;
	ct_lines = 1;
	while (ctr < nb)
	{
		if (buffer[ctr] != '\n' && buffer[ctr] != '.' &&
			buffer[ctr] != '#' && buffer[ctr] != '\0')
			return (-1);
		if (buffer[ctr] == '\n')
			ct_lines++;
		ctr++;
	}
	if (ct_lines > 129 || ct_lines < 4 || (ct_lines + 1) % 5 != 0)
		return (-1);
	return (ct_lines);
}

static int		ft_check_width_lines(int nb, char *buffer)
{
	int ctr;
	int ct_line;
	int ct_chara_ligne;
	int d;

	ct_line = 1;
	ctr = 0;
	d = 0;
	while (ctr < nb)
	{
		ct_chara_ligne = 0;
		while (buffer[ctr] != '\n' && ctr < nb)
		{
			if (buffer[ctr] == '#')
				d++;
			ct_chara_ligne++;
			ctr++;
		}
		if ((ct_line % 5 == 0 && ct_chara_ligne > 0) ||
			(ct_line % 5 != 0 && ct_chara_ligne != 4))
			return (-1);
		ctr++;
		ct_line++;
	}
	return (0);
}

static int		ft_check_nb_pt(int nb, char *buffer)
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
			return (-1);
		ctr++;
	}
	return (0);
}

static int		ft_check_is_valid(int nb, char *buffer)
{
	int i;

	i = 1;
	while (i < nb)
	{
		if (buffer[i] == '#' && (buffer[i - 1] != '#' &&
			buffer[i + 1] != '#' && buffer[i + 5] != '#' &&
			buffer[i - 5] != '#'))
			return (-1);
		i++;
	}
	return (0);
}

int				check_validation(int nb, char *buffer)
{
	if (ft_nb_lines_and_char_not_wanted(nb, buffer) == -1)
		return (-1);
	if (ft_check_width_lines(nb, buffer) == -1)
		return (-1);
	if (ft_check_nb_pt(nb, buffer) == -1)
		return (-1);
	if (ft_check_is_valid(nb, buffer) == -1)
		return (-1);
	return (0);
}
