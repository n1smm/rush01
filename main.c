/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilla-d <dvilla-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:06:43 by robgutie          #+#    #+#             */
/*   Updated: 2023/07/30 18:44:45 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>// for write
#include <stdlib.h>// for malloc and free
#include "helper_func.h"
#include <stdio.h>

int	check_views(int *views, int **grid, int size)
{
	int	i;
	int	j;
	int	current_max_height[size]; 
	int	counter_height[size];

	i = 0;
	j = 0;
	while (i < size)
	{
		array_zero (counter_height, size);
		array_zero (current_max_height, size);
		j = 0;
		while (j < size)
		{
			if (grid[i][j] > current_max_height[2])
			{
				counter_height[2]++;
				current_max_height[2] = grid[i][j];
			}
			if ((grid[i][size - j - 1] > current_max_height[3]))
			{
				counter_height[3]++;
				current_max_height[3] = grid[i][size - j - 1];
			}
			if (grid[j][i] > current_max_height[0])
			{
				counter_height[0]++;
				current_max_height[0] = grid[j][i];
			}
			if (grid[size - j - 1][i] > current_max_height[1])
			{
				counter_height[1]++;
				current_max_height[1] = grid[size - j - 1][i];
			}
			j++;
		}
		if ((views[i] != counter_height[0] 
				|| views[i + size] != counter_height[1]))
			return (0);
		if ((views[i + size * 2] != counter_height[2] 
				|| views[i + size * 3] != counter_height[3]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_placement(int *views, int **grid, int index, int size)
{
	int	row;
	int	col;
	int	i;

	col = index % size;
	row = index / size;
	i = 0;
	while (i < size)
	{
		if ((grid[row][i] == grid[row][col] && i != col))
			return (0);
		if ((grid[i][col] == grid[row][col] && i != row))
			return (0);
		i++;
	}
	return (1);
}

int	backtrack(int *views, int **grid, int index, int size)
{
	int	row;
	int	col;
	int	height;
	int	valid;

	height = 1;
	row = index / size;
	col = index % size;
	if (index == (size * size))
	{
		if (!check_views(views, grid, size))
			return (0);
		return (1);
	}
	while (height <= size) 
	{
		grid[row][col] = height;
		valid = is_valid_placement(views, grid, index, size);
		if (valid)
		{
			if (backtrack(views, grid, index + 1, size))
				return (1);
		}
		height++;
	}
	grid[row][col] = 0; 
	return (0);
}

int	main(int argc, char *argv[])
{
	int	size;
	int	views[16];
	int	**grid;

	if (argc != 2) 
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
	size = parse_arguments(argv[1], views);
	size = 4; 
	grid = make_grid(size);
	print_grid(grid, size);
	printf("length %i", size);
	if (!backtrack(views, grid, 0, size))
		write(STDOUT_FILENO, "Error\n", 6);
	print_grid(grid, size);
	free_grid(grid, size);
	return (0);
}
/*
	 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	"2 6 3 3 1 3 4 3 2 2 2 1 4 3 3 2 3 3 2 1 3 3 3 2 4 3 2 2 5 1 4 2 4 2 3 4"
*/
