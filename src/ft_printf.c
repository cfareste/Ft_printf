/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:19:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/17 00:43:52 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_parameter(char const *str, int *pos, va_list args)
{
	char	specifier;

	*pos = *pos + 1;
	specifier = str[*pos];
	if (specifier == 'c')
		return (print_character(va_arg(args, int)));
	else if (specifier == 's')
		return (print_string(va_arg(args, char *)));
	else if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_number(va_arg(args, int)));
	else if (specifier == 'u')
		return (print_unsigned_number(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (print_hex_number(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (print_character('%'));
	else
		return (print_character(specifier));
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		final_length;
	int		bytes_written;
	va_list	args;

	i = 0;
	final_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			bytes_written = handle_parameter(str, &i, args);
		else
			bytes_written = print_character(str[i]);
		if (bytes_written == -1)
			return (va_end(args), -1);
		final_length += bytes_written;
		i++;
	}
	va_end(args);
	return (final_length);
}
