/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:25:41 by tjuvan            #+#    #+#             */
/*   Updated: 2023/07/30 18:41:42 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // for write
#include <stdlib.h> // for malloc and free

void	print_grid(int **grid, int size);
void	free_grid(int **grid, int size);
int		parse_arguments(char *argv, int *views);
int		**make_grid(int size);
void	array_zero(int *array, int size);
