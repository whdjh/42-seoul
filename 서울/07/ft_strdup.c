/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:24:34 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/08 11:34:21 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*src1;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	src1 = malloc(sizeof(char) * (len + 1));
	if (!(src1))
		return (0);
	while (src[i])
	{
		src1[i] = src[i];
		i++;
	}
	src1[i] = '\0';
	return (src1);
}
