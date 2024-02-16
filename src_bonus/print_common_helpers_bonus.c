/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_common_helpers_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:29:07 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/16 16:42:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	process_precision(char *str, t_flags *flags)
{
	if (flags->precision == -2)
		flags->precision = ft_strlen(str);
}

int	calculate_width(char *str, t_flags *flags)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen > flags->precision)
		return (flags->width - flags->precision);
	else
		return (flags->width - strlen);
}

int	print_width(int bytes, char byte_to_print)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		if (print_raw_char(byte_to_print) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_precised_string(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && precision > 0)
	{
		if (print_raw_char(str[i]) == -1)
			return (-1);
		i++;
		precision--;
	}
	return (i);
}

int	check_for_signs_flags(int n, t_flags *flags)
{
	if (flags->plus && n >= 0 && print_raw_char('+') == -1)
		return (-1);
	if (!flags->plus && flags->space && n >= 0 && print_raw_char(' ') == -1)
		return (-1);
	return (0);
}
