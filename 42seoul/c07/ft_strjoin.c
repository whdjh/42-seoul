/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:27:03 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/09 16:35:26 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		get_sum_len(char **strs, int size);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_sum_len(char **str, int size)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			result++;
		}
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	const int		s_l = get_sum_len(strs, size);
	char			*result;
	int				i;

	if (size == 0)
	{
		result = malloc(1);
		if (!result)
			return (0);
	}
	else
	{
		result = malloc(sizeof(char) * (s_l + ft_strlen(sep) * (size - 1) + 1));
		if (!result)
			return (0);
		*result = '\0';
		i = -1;
		while (++i < size)
		{
			ft_strcat(result, strs[i]);
			if (i < size - 1)
				ft_strcat(result, sep);
		}
	}
	return (result);
}
