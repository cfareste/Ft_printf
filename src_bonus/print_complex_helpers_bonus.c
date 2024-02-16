/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_complex_helpers_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:33:49 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/09 21:36:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	calculate_total_hex_num_length(unsigned long n)
{
	int	num_length;

	if (n == 0)
		return (1);
	num_length = 0;
	while (n != 0)
	{
		num_length++;
		n /= 16;
	}
	return (num_length);
}

void static	num_to_hex_in_str(char *num_str, unsigned long n, int idx)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		num_to_hex_in_str(num_str, n / 16, idx - 1);
	num_str[idx] = base[n % 16];
}

void	puthex_in_str(char *num_str, unsigned long n, int idx)
{
	num_to_hex_in_str(num_str, n, idx - 1);
	num_str[idx] = '\0';
}

void	transform_hex_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}