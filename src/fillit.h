/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:16:29 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/14 18:19:25 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

typedef	struct		s_tetris
{
	char			*data;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

int					connect_check(char *str);
int					checks(char *str, int count);
int					min_map(t_tetris *tetro, int count);
char				**make_map(int size);
void				print_map(char **map, int count);
t_tetris			*newlist_with_tet(char *data, char letter);
void				ft_lstadd_tet(t_tetris **alst, t_tetris *new);
void				to_lst(t_tetris **a, t_tetris **b, char *gab, char letter);
int					min_of_four(int a, int b, int c, int d);
int					read_tet(int fd, t_tetris **a, t_tetris **b);
int					mof(char a, char b, char c, char d);
void				fitting(char **map, t_tetris *tetro, int i, int j);
int					is_fitt(char **map, t_tetris *tetro, int i, int j);
void				free_cells(char **map, char c);
int					rec(char **ma, t_tetris *t, int i, int j);
int					comming(char **ma, t_tetris *t, int i, int j);
int					count_of_tet(t_tetris *a);

#endif
