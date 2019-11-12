/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:35:57 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:01 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include "ttt.h"

int    comming(char **map, t_tetris *tetro, int i, int j, int count, int edge, int maxi, int maxj)
{
    while (i < edge - maxi)
    {
        if (j < edge - maxj)
        {
            j++;
            if (is_fitt(map, tetro, i, j))
            {
                //print_map(map, edge);
                if (count)
                {
                    if (rec(map, tetro->next, 0, 0, count-1, edge))
                        return (1);
                }
                else
                    return (1);
            }
        }
        else if (i < edge - maxi)
        {
            i++;
            j = -1;
        }
    }
    return (0);
}

int     rec(char **map, t_tetris *tetro, int i, int j, int count, int edge)
{
    //printf("start rec, count=%d\n", count);
    int     maxi;
    int     maxj;

    maxi = max_of_four(tetro->data[0], tetro->data[2], tetro->data[4],tetro->data[6]);
    maxj = max_of_four(tetro->data[1], tetro->data[3], tetro->data[5], tetro->data[7]);
    if (is_fitt(map, tetro, i, j))
    {
        //print_map(map, edge);
        if (count)
        {
            if (rec(map, tetro->next, 0, 0, count-1, edge))
                return (1);
            else
                return (comming(map, tetro, i, j, count, edge, maxi, maxj));
        }
        else
            return (1);
    }
    else
        return (comming(map, tetro, i, j, count, edge, maxi, maxj));
    printf("this map is too small for this shit\n");
    free_cells(map, tetro->c+1);
    print_map(map, edge);
    return (0);
}
