#include "fillit.h"
//#include "ttt.h"

int     max_of_four(char a, char b, char c, char d)
{
    if (a >= b && a >= c && a >= d)
        return (a - 48);
    if (b >= a && b >= c && b >= d)
        return (b - 48);
    if (c >= a && c >= b && c >= d)
        return (c - 48);
    return (d - 48);
}

void     fitting(char **map, t_tetris *tetro, int i, int j)
{
    map[tetro->data[0] - 48 + i][tetro->data[1] - 48 + j] = tetro->c;
    map[tetro->data[2] - 48 + i][tetro->data[3] - 48 + j] = tetro->c;
    map[tetro->data[4] - 48 + i][tetro->data[5] - 48 + j] = tetro->c;
    map[tetro->data[6] - 48 + i][tetro->data[7] - 48 + j] = tetro->c;
}

int     is_fitt(char **map, t_tetris *tetro, int i, int j)
{
    if (map[tetro->data[0] - 48 + i][tetro->data[1] - 48 + j] == '.' && \
     map[tetro->data[2] - 48 + i][tetro->data[3] - 48 + j] == '.' \
        && map[tetro->data[4] - 48 + i][tetro->data[5] - 48 + j] == '.' && \
        map[tetro->data[6] - 48 + i][tetro->data[7] - 48 + j] == '.')
    {
        fitting(map, tetro, i, j);
        return (1);
    }
    else
        return (0);
}

void     free_cells(char **map, char c)
{
    int i;
    int j;
    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == c)
                map[i][j] = '.';
            j++;
        }
        i++;
    }
}

