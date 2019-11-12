/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:35:57 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 19:59:42 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include "ttt.h"

int     comming(char **map, t_tetris *tetro, int i, int j, int count, int *edge)
{
    int a = edge[0];
    int b = a - max_of_four(tetro->data[0], tetro->data[2], tetro->data[4], tetro->data[6]);
    int c = a - max_of_four(tetro->data[1], tetro->data[3], tetro->data[5], tetro->data[7]);
    printf("final=%d %d\n", i, edge[0] - edge[1]);
    while (i < b)
    {
        if (j < c)
        {
            j++;
            printf("the last i=%d, j=%d, edge[0]=%d, edge[1]=%d\n", i, j, edge[1], edge[2]);
            if (is_fitt(map, tetro, i, j))
            {
                print_map(map, edge[0]);
                printf("%c\n", tetro->c);
                if (count)
                {
                    if (rec(map, tetro->next, 0, 0, count-1, edge))
                        return (1);
                }
                else
                    return (1);
            }
        }
        else if (i < b)
        {
            i++;
            j = -1;
        }
    }
    return (0);
}

int     rec(char **map, t_tetris *tetro, int i, int j, int count, int *edge)
{
    //printf("%d %d %d\n", edge[0], edge[1], edge[2]);
    if (is_fitt(map, tetro, i, j))
    {
        print_map(map, edge[0]);
        printf("%c\n", tetro->c);
        if (count)
        {
            if (rec(map, tetro->next, 0, 0, count-1, edge))
                return (1);
            else if (comming(map, tetro, i, j, count, edge))
                    return (1);
        }
        else
            return (1);
    }
    else if (comming(map, tetro, i, j, count, edge))
        return (1);
    free_cells(map, tetro->c+1);
    print_map(map, edge[0]);
    return (0);
}
