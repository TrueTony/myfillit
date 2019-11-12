/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:16:29 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 15:11:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTT_H
# define TTT_H

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

void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
int     	min_map(int n);
char    	**make_map(int size);
void    	print_map(char **map, int count);
t_tetris	*newlist_with_c(char *data, char letter);
void		ft_lstadd_tet(t_tetris **alst, t_tetris *new);
int     	min_of_four(int a, int b, int c, int d);
int     	tet_to_lst(t_tetris **a, t_tetris **b);
int     	max_of_four(char a, char b, char c, char d);
void     	fitting(char **map, t_tetris *tetro, int i, int j);
int     	is_fitt(char **map, t_tetris *tetro, int i, int j);
void     	free_cells(char **grid, char c);
int 		rec(char **map, t_tetris *tetro, int i, int j, int x, int edge);
int			count_of_tet(t_tetris *a);

#endif
