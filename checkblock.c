#include "fillit.h"

static int countfreinds(char *tetri, int i)
{
    int    freinds;

    freinds = 0;
    if (tetri[i + 1] == '#')
        freinds++;
    if (tetri[i - 1] == '#')
        freinds++;
    if (tetri[(i - 5 >= 0 ? i - 5 : 4)] == '#')
        freinds++;
    if (tetri[(i + 5 < 19 ? i + 5 : 4)] == '#')
        freinds++;
    return (freinds);
}

static int blockchecker(char *tetri)
{
    int i;
    int blocks;
    int freinds;

    i = 0;
    blocks = 0;
    freinds = 0;

    i = 0;
    blocks = 0;
    freinds = 0;
    while (i < 20)
    {
        if (tetri[i] == '#')
        {
            freinds += countfreinds(tetri, i);
            blocks++;
        }
        i++;
    }
    if (blocks != 4 || freinds < 6)
        return (0);
    return (1);
}

int         checkblock(char *tetri, int ret)
{
    int     i;
    int     line;

    i = 0;
    line = 0;
    if (ret != 21 && ret != 20)
        return (0);
    while (i < 20)
    {
        while (tetri[i] == '.' || tetri[i] == '#')
            i++;
        if ((i - 4) % 5 != 0 || tetri[i] != '\n')
            return (0);
        line++;
        i++;
    }
    if ((tetri[i] != '\n' && tetri[i] != '\0') || line != 4)
        return (0);
    if (!(blockchecker(tetri)))
        return (0);
    return (1);
}

