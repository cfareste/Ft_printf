/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_primitive_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:20:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/15 21:27:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_raw_char(char c)
{
	return (write(1, &c, 1));
}

int	print_raw_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_raw_string("(null)"));
	while (str[i])
	{
		if (print_raw_char(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_number(int n, t_flags *flags)
{
	char	*num_str;
	int		num_length;

	num_str = ft_itoa(n);
	if (!num_str)
		return (-1);
	num_length = print_sig_number_string(num_str, flags, n);
	free(num_str);
	return (num_length);
}

int	print_unsigned_number(unsigned int n, t_flags *flags)
{
	char	*num_str;
	int		num_length;

	num_str = ft_uitoa(n);
	if (!num_str)
		return (-1);
	num_length = print_uns_number_string(num_str, flags, n);
	free(num_str);
	return (num_length);
}
