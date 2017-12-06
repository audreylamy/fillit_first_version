/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:05:27 by alamy             #+#    #+#             */
/*   Updated: 2017/11/17 18:56:03 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		main(int argc, char **argv);
char	**ft_read(char *argv);
int		check_validation(int nb, char *buffer);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(const char *s);
char 	***tab_tab_arrange(char ***tab_tab, int nb_block);
char  	**create_tetri_map();
char	**fill_map_tetri(char **map, char ***tab_arrange, int nb_block);
char	**ft_strsplit(const char *str, char c);
size_t	ft_strlen(char const *str);
int             ft_sqrt(int nb);

char **solve(char ***tab_arrange, int nb_block);
char **map_solve(char **map, char ***tab_arrange, int nb_block, int num_block, int size_map);
int ou_est_le_premier_diese(char ***tab_arrange, int num_block);
void ft_impression(char **map, int size_map);
char **map_create(int size_map);
void ft_impression(char **map, int size_map);
#endif
