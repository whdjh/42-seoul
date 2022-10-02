/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:32:49 by juhulee           #+#    #+#             */
/*   Updated: 2022/05/28 22:18:37 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		j = i - 1;
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] += 32;
		if ((str[j] <= 47) && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		if ((str[j] >= 58 && str[j] <= 64) && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		if ((str[j] >= 91 && str[j] <= 96) && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		if ((str[j] >= 123) && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		i++;
	}
	return (str);
}
