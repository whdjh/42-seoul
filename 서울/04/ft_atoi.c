/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:23:28 by juhulee           #+#    #+#             */
/*   Updated: 2022/05/30 17:31:38 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	positive;

	result = 0;
	positive = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' \
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + *str - '0';
			str++;
	}
	return (positive * result);
}
