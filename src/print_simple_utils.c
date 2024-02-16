/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simple_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:20:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/16 21:57:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(char c)
{
	return (write(1, &c, 1));
}

int	print_number(int n)
{
	char	*num_str;
	int		num_length;

	num_str = ft_itoa(n);
	if (!num_str)
		return (-1);
	num_length = print_string(num_str);
	free(num_str);
	return (num_length);
}

int	print_unsigned_number(unsigned int n)
{
	char	*num_str;
	int		num_length;

	num_str = ft_uitoa(n);
	if (!num_str)
		return (-1);
	num_length = print_string(num_str);
	free(num_str);
	return (num_length);
}
