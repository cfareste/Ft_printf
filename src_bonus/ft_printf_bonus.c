/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:19:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/16 17:34:13 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_parameter(char const *str, int *pos, va_list args, t_flags *flags)
{
	char	hit;

	hit = str[*pos];
	if (hit == 'c')
		return (print_character(va_arg(args, int), flags));
	else if (hit == 's')
		return (print_string(va_arg(args, char *), flags));
	else if (hit == 'p')
		return (print_pointer(va_arg(args, void *), flags));
	else if (hit == 'd' || hit == 'i')
		return (print_number(va_arg(args, int), flags));
	else if (hit == 'u')
		return (print_unsigned_number(va_arg(args, unsigned int), flags));
	else if (hit == 'x' || hit == 'X')
		return (print_hex_number(va_arg(args, unsigned int), hit, flags));
	else if (hit == '%')
		return (print_character('%', flags));
	else
		return (print_raw_char(hit));
}

int	handle_flag(char const *str, int *pos, va_list args, t_flags *flags)
{
	(*pos)++;
	reset_flags(flags);
	if (count_flags(str, pos, flags) == -1)
		return (-1);
	return (handle_parameter(str, pos, args, flags));
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		final_length;
	int		bytes_written;
	va_list	args;
	t_flags	*flags;

	flags = initialize_flags();
	if (!flags)
		return (free_flags_struct(flags, -1));
	i = 0;
	final_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			bytes_written = handle_flag(str, &i, args, flags);
		else
			bytes_written = print_raw_char(str[i]);
		if (bytes_written == -1)
			return (free_flags_struct(flags, -1));
		final_length += bytes_written;
		i++;
	}
	va_end(args);
	return (free_flags_struct(flags, final_length));
}
