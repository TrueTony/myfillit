/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:16:29 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 11:22:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

#include <stdio.h>


typedef	struct 		s_tetris
{
	char			*data;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

int     	connect_check(char *str);
int     	checks(char *str, int count);
int     	min_map(int n);
char    	**make_map(int size);
void    	print_map(char **map, int count);
t_tetris	*newlist_with_c(char *data, char letter);
void		ft_lstadd_tet(t_tetris **alst, t_tetris *new);
int     	min_of_four(char a, char b, char c, char d);
int     	tet_to_lst(int fd, t_tetris **a, t_tetris **b);
int     	max_of_four(char a, char b, char c, char d);
void     	fitting(char **grid, char *figure, int i, int j, char c);
int     	is_fitt(char **grid, char *figure, int i, int j, char c);
void     	free_cells(char **grid, char c);
int 		rec(char **grid, char arr[5][8], int i, int j, int x, char c);

#endif
