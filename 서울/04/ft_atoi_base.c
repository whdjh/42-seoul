/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhulee <juhulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:24:31 by juhulee           #+#    #+#             */
/*   Updated: 2022/06/02 21:43:11 by juhulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	error_case(char *base);
int	get_digit(char c, char *base);
int	in_base(char c, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int				result;
	long long int	positive;
	int				notation;

	result = 0;
	positive = 1;
	notation = error_case(base);
	if (notation)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' \
				|| *str == '\v' || *str == '\f' || *str == '\r')
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				positive *= -1;
			str++;
		}
		while (in_base(*str, base))
				result = result * notation + get_digit(*str++, base);
	}
	return ((int)(positive * result));
}

int	get_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	error_case(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' \
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r' \
			|| base[i] == '\t' || base[i] == '\n')
			return (0);
		i = j + 1;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
		{
			return (1);
		}
		base++;
	}
	return (0);
}
