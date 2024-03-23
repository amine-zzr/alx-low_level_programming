#!/usr/bin/python3
'''
Function island_perimeter(grid) calculates the perimeter of an island
'''


def island_perimeter(grid):
    '''
    Calculate the perimeter of the island described in grid.

    Args:
        grid (list of list of int): Grid representing the island.

    Returns:
        int: Perimeter of the island.
    '''

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
