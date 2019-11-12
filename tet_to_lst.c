/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:15:18 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 11:09:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     min_of_four(int a, int b, int c, int d)
{
    if (a <= b && a <= c && a <= d)
        return (a);
    if (b <= a && b <= c && b <= d)
        return (b);
    if (c <= a && c <= b && c <= d)
        return (c);
    return (d);
}

void    to_lst(t_tetris **a, t_tetris **b, char *gab, char letter)
{
    if (letter == 'A')
    {
        *a = newlist_with_c(gab, letter);
        letter++;
        printf("a created\n");
    }
    else
    {
        *b = newlist_with_c(gab, letter);
        letter++;
        ft_lstadd_tet(a, *b);
        printf("b- created and linked\n");
    }
}

void    shift_tet(t_tetris **a, t_tetris **b, char *gab, char letter)
{
    int x;
    int y;
    int i;
    //printf("%s\n", gab);
    x = min_of_four(gab[0]-48, gab[2]-48, gab[4]-48, gab[6]-48);
    y = min_of_four(gab[1]-48, gab[3]-48, gab[5]-48, gab[7]-48);
    printf("shift x %d, shift y %d\n", x, y);
    i = 0;
    while (i < 8)
    {
        gab[i] -= x;
        i++;
        gab[i] -= y;
        i++;
    }
    //printf("%s\n", gab);
    to_lst(a, b, gab, letter);
}

void    to_gab(t_tetris **a, t_tetris **b, char *str, char letter)
{
    char    x;
    char    y;
    int     i;
    char    gab[8];
    i = 0;
    x = '0';
    y = '0';
    while (*str)
    {
        if (*str == '\n')
        {
            x = '0';
            y++;
        }
        else if (*str == '#')
        {
            gab[i++] = y;
            gab[i++] = x++;
        }
        else
            x++;
        str++;
    }
    //gab[8] = '\0';
    shift_tet(a, b, gab, letter);
}

int     read_tet(int fd, t_tetris **a, t_tetris **b)
{
    char str[20];
    char letter;
    letter = 'A';
    while ((read(fd, str, 21)))
    {
        str[19] = '\0';
        to_gab(a, b, str, letter);
        letter++;
    }
    return (0);
}
