/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2 test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:37:07 by juhulee           #+#    #+#             */
/*   Updated: 2022/05/23 18:32:32 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_putchar (a / 10 + '0');
			ft_putchar (a % 10 + '0');
			ft_putchar (' ');
			ft_putchar (b / 10 + '0');
			ft_putchar (b % 10 + '0');
			if (a / 10 != 9 || a % 10 != 8)
				write(1, ", ", 2);
			if (a / 10 == 9 && a % 10 == 8 && b / 10 == 9 && b % 10 == 9)
				return ;
			b++;
		}
		a++;
	}
}
