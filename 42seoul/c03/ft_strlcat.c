/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:03 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/01 21:54:52 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

int main()
{
	char src[40] = "gaeon";
	char src1[40] = "42";
	char dest[40] = "hello";
	char dest1[40] = "hello";
	char dest2[40] = "hi";
	char dest3[40] = "hi";
	printf("%lu %u\n", strlcat(dest, src, 3), ft_strlcat(dest1, src, 3));
	printf("%lu %u\n", strlcat(dest, src, 20), ft_strlcat(dest1, src, 20));
	printf("%lu %u\n", strlcat(dest2, src1, 5), ft_strlcat(dest3, src1, 5));
}