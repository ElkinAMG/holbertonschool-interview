#include "sandpiles.h"

/**
 * sandpiles_sum - it's a function that computes the sum of two sandpiles
 * @grid1: first grid.
 * @grid2: second grid.
 *
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

    int col, row;

    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++)
        {
            grid1[row][col] += grid2[row][col];
            grid1 = check_stability(grid1);
        }

}

/**
 * check_stability - it's a function that checks stability of grid
 * @grid: first grid.
 *
 * Return: The new stable grid.
*/
int *check_stability(int grid[3][3])
{
    int x, y;

    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            if (grid[y][x] > 3)
            {
                if (grid[y][x + 1])
                    grid[y][x + 1] += 1;
                if (grid[y][x - 1])
                    grid[y][x - 1] += 1;
                if (grid[y + 1][x])
                    grid[y + 1][x] += 1;
                if (grid[y - 1][x])
                    grid[y + 1][x] += 1;
            }
        }
    }

    return (grid);
}