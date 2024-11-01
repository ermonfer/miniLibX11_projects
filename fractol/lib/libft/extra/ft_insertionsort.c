/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:29:57 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/04 19:27:49 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

/**
 * @brief Sorts an array using the Insertion Sort algorithm.
 *
 * This function implements the Insertion Sort algorithm to sort an array
 * of integers in ascending order. This algorithm is recommended for arrays
 * with length less than 20.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */

void	ft_insertionsort(int arr[], int n)
{
	int	i;
	int	j;
	int	current;

	i = 1;
	while (i < n)
	{
		current = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > current)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
		i++;
	}
}
