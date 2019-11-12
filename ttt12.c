int     min_map(t_tetris *tetro, int count)
{
    int     i;
    char    res;
    int     size;

    i = 0;
    res = '2';
    size = 2;
    if (count == 1)
    {
        while (i < 8)
        {
            if (tetro->data[i] > res)
                res = tetro->data[i];
            i++;
        }
        return (res-47);
    }
    else
    {
        while (((size-48) * (size-48) < (count * 4))
            size++;
        return (size);
    }
}
