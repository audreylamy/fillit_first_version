/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:10:44 by alamy             #+#    #+#             */
/*   Updated: 2017/12/01 14:54:27 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_strlen(char const *str)
{
	unsigned int	i;
	char			*str1;

	str1 = (char *)str;
	i = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	return (i);
}
