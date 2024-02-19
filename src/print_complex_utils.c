/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_complex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:58:27 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/19 10:17:24 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_string("(null)"));
	while (str[i])
	{
		if (print_character(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_pointer(void *ptr)
{
	unsigned long	ptr_value;
	int				num_length;
	char			*num_str;

	if (!ptr)
		return (print_string("0x0"));
	ptr_value = (unsigned long) ptr;
	num_length = calculate_total_hex_num_length(ptr_value) + ft_strlen("0x");
	num_str = malloc(num_length + 1);
	if (!num_str)
		return (-1);
	ft_memcpy(num_str, "0x", 2);
	puthex_in_str(num_str, ptr_value, num_length);
	num_length = print_string(num_str);
	free(num_str);
	return (num_length);
}

int	print_hex_number(unsigned int n, char specifier)
{
	char	*num_str;
	int		num_length;

	num_length = calculate_total_hex_num_length(n);
	num_str = malloc(num_length + 1);
	if (!num_str)
		return (-1);
	puthex_in_str(num_str, n, num_length);
	if (specifier == 'X')
		transform_hex_toupper(num_str);
	num_length = print_string(num_str);
	free(num_str);
	return (num_length);
}
