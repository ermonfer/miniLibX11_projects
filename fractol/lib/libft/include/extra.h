/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:15:55 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/01 18:07:06 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H
# include <limits.h>
# include <stdbool.h>
# include "./libft.h"

void	ft_insertionsort(int arr[], int n);
void	ft_quicksort(int array[], int low, int high);
int		ft_maxint(int a, int b);
int		ft_minint(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi_signal(const char *str, int *out_of_range);
void	ft_free_split(char **split);
void	*ft_free_return(void **ptrs, int n_ptrs, void *ret);
double	ft_atod_signal(char str[], int *format_error);

#endif
