#include "ttt.h"

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

int     tet_to_lst(t_tetris **a, t_tetris **b)
{

    //char gab[9] = {'0', '1', '0', '2', '1', '2', '2', '2', '\0'};
    //char gab2[9] = {'1', '1', '1', '2', '2', '2', '2', '3', '\0'};
    char    gab[9] = {'0', '0', '0', '1', '1', '0', '2', '0', '\0'};
    //char    gab2[9] = {'0', '1', '0', '2', '1', '0', '1', '1', '\0'};
    char    gab3[9] = {'0', '0', '1', '0', '1', '1', '2', '0', '\0'};
    char    gab4[9] = {'0', '0', '0', '1', '1', '1', '1', '2', '\0'};

    char letter;

    letter = 'A';
	shift_tet(a, b, gab, letter);
	letter++;
	shift_tet(a, b, gab3, letter);
	letter++;
    shift_tet(a, b, gab4, letter);
	letter++;
    //shift_tet(a, b, gab4, letter);
	//letter++;

    /*
	int i = 0;
	while (a)
    {
        i = 0;
        while (i < 8)
        {
            printf("%c, ", a->data[i]);
            i++;
        }
		printf("%c", a->c);
        a = a->next;
        printf("\n");
    }
    */
	printf("tttvalidate_to succes!\n");

    return (0);
}

