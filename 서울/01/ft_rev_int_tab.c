/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:54:30 by juhulee           #+#    #+#             */
/*   Updated: 2022/05/25 18:02:09 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	temp;

	a = 0;
	while (a < size / 2)
	{
		temp = tab [a];
		tab [a] = tab [size - a - 1];
		tab [size - a - 1] = temp;
		a++;
	}
}
