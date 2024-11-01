/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:56 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/01 18:09:52 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"
#include "libft.h"

void	ft_free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}
