/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:04:10 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/01 18:33:04 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"
#include "libft.h"

void	*ft_free_return(void **ptrs, int n_ptrs, void *ret)
{
	int	i;

	i = 0;
	while (i < n_ptrs)
		free(ptrs[i++]);
	return (ret);
}
