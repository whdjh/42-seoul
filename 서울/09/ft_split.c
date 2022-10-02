/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:28:13 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/09 14:24:09 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_sep(char c, char *charset)
{
	int i;

	i = 0;

	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int count_words(char *str, char *charset)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_sep(str[i], charset))
			i++;
		if (str[i] && !ft_sep(str[i], charset))
		{
			while (str[i] && !ft_sep(str[i], charset))
				i++;
			count++;
		}
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset)
{
	char*	word;
	int	i;

	i = 0;
	while (str[i] && !ft_sep(str[i], charset))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int	i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && ft_sep(*str, charset))
			str++;
		if (*str && !ft_sep(*str, charset))
			{
				tab[i] = ft_strdup(str, charset);
				i++;
				while (*str && !ft_sep(*str, charset))
					str++;
			}
	}
	tab[i] = 0;
	return (tab);
}
