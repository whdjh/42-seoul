/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:25:19 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/09 16:44:03 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*temp;
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
		return (0);
	temp = malloc(sizeof(int) * (size));
	while (min < max)
	{
		temp[i] = min;
		i++;
		min++;
	}
	return (temp);
}
