/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:31:35 by juhulee           #+#    #+#             */
/*   Updated: 2022/05/31 15:15:24 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*i;
	char	*j;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			i = str + 1;
			j = to_find + 1;
			while (*j != '\0' && *i != '\0' && *i == *j)
			{
				i++;
				j++;
			}
			if (*j == '\0')
				return (str);
			if (*i == '\0')
				break ;
		}
		str++;
	}
	return (0);
}
