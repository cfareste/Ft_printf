/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_parsed_primitive_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:06:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/16 18:02:05 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_character(char c, t_flags *flags)
{
	int	byte_to_print;
	int	bytes_written;

	byte_to_print = ' ';
	if (flags->minus)
	{
		if (print_raw_char(c) == -1
			|| print_width(flags->width - 1, byte_to_print) == -1)
			return (-1);
	}
	else
	{
		if (flags->zero)
			byte_to_print = '0';
		if (print_width(flags->width - 1, byte_to_print) == -1
			|| print_raw_char(c) == -1)
			return (-1);
	}
	bytes_written = flags->width;
	if (!bytes_written)
		return (1);
	return (bytes_written);
}

int	print_string(char *str, t_flags *flags)
{
	int	bytes_written;
	int	spaces_written;

	if (!str)
		return (print_string("(null)", flags));
	process_precision(str, flags);
	if (flags->minus)
	{
		bytes_written = print_precised_string(str, flags->precision);
		if (bytes_written == -1)
			return (-1);
		spaces_written = print_width(flags->width - bytes_written, ' ');
		if (spaces_written == -1)
			return (-1);
	}
	else
	{
		spaces_written = print_width(calculate_width(str, flags), ' ');
		if (spaces_written == -1)
			return (-1);
		bytes_written = print_precised_string(str, flags->precision);
		if (bytes_written == -1)
			return (-1);
	}
	return (spaces_written + bytes_written);
}

int	print_sig_number_string(char *num_str, t_flags *flags, int n)
{
	int	byt_wri;
	int	wdt_wri;

	if (flags->minus)
	{
		if (check_for_signs_flags(n, flags) == -1)
			return (-1);
		byt_wri = print_precised_number(num_str, flags, n);
		if (byt_wri == -1)
			return (-1);
		wdt_wri = print_width(calc_total_width(num_str, flags, byt_wri), ' ');
		if (wdt_wri == -1)
			return (-1);
		return (byt_wri + wdt_wri);
	}
	wdt_wri = 0;
	if ((!flags->zero && flags->width)
		|| (flags->zero && flags->precision != -2 && flags->width))
		wdt_wri = print_width(calc_total_width(num_str, flags, 0), ' ');
	if (wdt_wri == -1 || check_for_signs_flags(n, flags) == -1)
		return (-1);
	byt_wri = print_precised_number(num_str, flags, n);
	if (byt_wri == -1)
		return (-1);
	return (byt_wri + wdt_wri);
}

int	print_uns_number_string(char *num_str, t_flags *flags, unsigned int n)
{
	int	byt_wri;
	int	wdt_wri;

	if (flags->minus)
	{
		byt_wri = print_precised_number(num_str, flags, n);
		if (byt_wri == -1)
			return (-1);
		wdt_wri = print_width(calc_total_width(num_str, flags, byt_wri), ' ');
		if (wdt_wri == -1)
			return (-1);
		return (byt_wri + wdt_wri);
	}
	wdt_wri = 0;
	if ((!flags->zero && flags->width)
		|| (flags->zero && flags->precision != -2 && flags->width))
		wdt_wri = print_width(calc_total_width(num_str, flags, 0), ' ');
	if (wdt_wri == -1)
		return (-1);
	byt_wri = print_precised_number(num_str, flags, n);
	if (byt_wri == -1)
		return (-1);
	return (byt_wri + wdt_wri);
}

int	print_hex_nb_str(char *n_str, t_flags *flags, char pm, unsigned int n)
{
	int	byt_wri;
	int	wdt_wri;

	if (flags->minus)
	{
		if (flags->hashtag && print_hex_prefix(n, pm) == -1)
			return (-1);
		byt_wri = print_precised_number(n_str, flags, n);
		if (byt_wri == -1)
			return (-1);
		wdt_wri = print_width(calc_total_width(n_str, flags, byt_wri), ' ');
		if (wdt_wri == -1)
			return (-1);
		return (byt_wri + wdt_wri + ((n && flags->hashtag) * 2));
	}
	wdt_wri = 0;
	if ((!flags->zero && flags->width)
		|| (flags->zero && flags->precision != -2 && flags->width))
		wdt_wri = print_width(calc_total_width(n_str, flags, 0), ' ');
	if (wdt_wri == -1 || (flags->hashtag && print_hex_prefix(n, pm) == -1))
		return (-1);
	byt_wri = print_precised_number(n_str, flags, n);
	if (byt_wri == -1)
		return (-1);
	return (byt_wri + wdt_wri + ((n && flags->hashtag) * 2));
}
