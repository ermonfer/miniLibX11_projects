/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:18:53 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/04 19:20:25 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

static void	swap(int *a, int *b);
static int	partition(int array[], int low, int high);

/**
 * @brief Implements the QuickSort algorithm to sort an array.
 *
 * This function sorts an array using the QuickSort algorithm, which is a
 * divide-and-conquer sorting algorithm. It works by selecting a 'pivot'
 * element from the array and partitioning the other elements into two
 * sub-arrays, according to whether they are less than or greater than the
 * pivot. The sub-arrays are then recursively sorted. This process continues
 * until the entire array is sorted.
 *
 * @param array[] The (sub)array to be sorted.
 * @param low The starting index of the subarray to be sorted.
 * @param high The ending index of the subarray to be sorted.
 */
void	ft_quicksort(int array[], int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		ft_quicksort(array, low, pivot_index - 1);
		ft_quicksort(array, pivot_index + 1, high);
	}
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief Partitions the array around a pivot element.
 *
 * This function takes an array and partitions it such that all elements less
 * than the pivot are moved before the pivot, and all elements greater than
 * the pivot are moved after it. The pivot element is chosen as the last
 * element of the array. Throughout the execution of the algorithm, 'low'
 * indicates the final position of the pivot, assuming no further elements
 * greater than the pivot are found.
 *
 * @param array[] The array to be partitioned.
 * @param low The starting index of the subarray to be partitioned.
 * @param high The ending index of the subarray to be partitioned.
 * @return The index of the pivot element after partitioning.
 */
static int	partition(int array[], int low, int high)
{
	int	pivot;
	int	current;

	pivot = array[high];
	current = low;
	while (current < high)
	{
		if (array[current] < pivot)
			swap(&array[low++], &array[current]);
		current++;
	}
	swap(&array[low], &array[high]);
	return (low);
}
