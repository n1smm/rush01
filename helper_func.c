/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:24:27 by tjuvan            #+#    #+#             */
/*   Updated: 2023/07/30 18:41:05 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_func.h"

void	print_grid(int **grid, int size)
{
	char	buf[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			buf[0] = '0' + grid[i][j];
			buf[1] = ' ';
			write(STDOUT_FILENO, buf, 2);
			j++;
		}
		j = 0; 
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

void	free_grid(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	parse_arguments(char *argv, int *views)
{
	int	i;
	int	size;

	i = 0; 
	while (argv[i] != '\0')
	{
		if ((argv[i] >= '0' && argv[i] <= '9'))
			views[i / 2] = argv[i] - '0' - 0;
		i++;
	}
	size = (i + 1) / 8;
	return (size);
}

int	**make_grid(int size)
{
	int	i;
	int	n;
	int	**grid;

	**grid = malloc(size * sizeof(int *));
	i = 0;
	n = 0;
	while (i < size)
	{
		grid[i] = malloc(size * sizeof(int));
		while (n < size)
		{
			grid[i][n] = 0;
			n++;
		}
		n = 0;
		i++;
	}
	return (grid);
}

void	array_zero(int *array, int size)
{
	int	c;

	c = 0;
	while (c < size)
	{
		array[c] = 0;
		c++;
	}
}
