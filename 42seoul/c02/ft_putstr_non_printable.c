/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:51:56 by juhulee           #+#    #+#             */
/*   Updated: 2022/05/28 16:54:05 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	j;

	i = 0;
	while (str[i] != '\0')
	{	
		if ((str[i] >= 32 && str[i] <= 126))
			write(1, &str[i], 1);
		else
		{
			j = str[i];
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[j / 16], 1);
			write(1, &"0123456789abcdef"[j % 16], 1);
		}
		i++;
	}
}
