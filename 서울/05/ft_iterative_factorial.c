/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:09:06 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/04 19:22:38 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = nb;
	result = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i >= 1)
	{
		result *= i;
		i--;
	}
	return (result);
}
