/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_complex_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:58:27 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/15 21:50:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_pointer(void *ptr, t_flags *flags)
{
	unsigned long	ptr_value;
	int				num_length;
	char			*num_str;

	if (!ptr)
		return (print_string("0x0", flags));
	ptr_value = (unsigned long) ptr;
	num_length = calculate_total_hex_num_length(ptr_value) + ft_strlen("0x");
	num_str = malloc(num_length + 1);
	if (!num_str)
		return (-1);
	ft_memcpy(num_str, "0x", 2);
	puthex_in_str(num_str, ptr_value, num_length);
	num_length = print_string(num_str, flags);
	free(num_str);
	return (num_length);
}

int	print_hex_number(unsigned int n, char parameter, t_flags *flags)
{
	char	*num_str;
	int		num_length;

	num_length = calculate_total_hex_num_length(n);
	num_str = malloc(num_length + 1);
	if (!num_str)
		return (-1);
	puthex_in_str(num_str, n, num_length);
	if (parameter == 'X')
		transform_hex_toupper(num_str);
	num_length = print_hex_nb_str(num_str, flags, parameter, n);
	free(num_str);
	return (num_length);
}
