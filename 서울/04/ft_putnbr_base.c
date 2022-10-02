/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:24:05 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/02 17:43:26 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	pl_putchar(long long int nbr, char *base, int i)
{
	if (nbr / i != 0)
		pl_putchar (nbr / i, base, i);
	write(1, &base[nbr % i], 1);
}

void	print_base(long long int nbr, char *base, int i)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= i)
		pl_putchar(nbr, base, i);
	if (nbr < i)
		write(1, &base[nbr % i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return ;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i = j + 1;
		while (j < i)
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	print_base((long long int)nbr, base, i);
}
