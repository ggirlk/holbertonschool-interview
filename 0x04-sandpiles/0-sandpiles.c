#include <stdio.h>

#include "sandpiles.h"

/**
 * topple - to topple grid
 * @grid: grid
 * @k: tester
 *
 * Return: grid
 */

int topple(int grid[3][3], int k)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if ((i - 1) >= 0)
				{
					grid[i - 1][j] += 1;
				}
				if ((j - 1) >= 0)
				{
					grid[i][j - 1] += 1;
				}
				if ((j + 1) < 3)
				{
					grid[i][j + 1] += 1;
				}
				if ((i + 1) < 3)
				{
					grid[i + 1][j] += 1;
				}
				k = 1;
			}
		}
	}

	if (k == 1)
	{
		grid[3][3] = topple(grid, 0);
	}
	return (grid[3][3]);
}

/**
 * sandpiles_sum - to add grids
 * @grid1: grid
 * @grid2: grid
 *
 * Return: nothing
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int k = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	grid1[3][3] = topple(grid1, k);
}
