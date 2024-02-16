/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags_helpers_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:04:18 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/16 18:10:26 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void static	set_flag(char flag, t_flags *flags)
{
	if (flag == '-')
		flags->minus = 1;
	else if (flag == '+')
		flags->plus = 1;
	else if (flag == ' ')
		flags->space = 1;
	else if (flag == '#')
		flags->hashtag = 1;
	else if (flag == '0')
		flags->zero = 1;
}

int static	get_number(char const *str, int *pos)
{
	int		start_pos;
	int		final_num;
	char	*num_substr;

	start_pos = *pos;
	while (ft_isdigit(str[*pos]))
		(*pos)++;
	num_substr = ft_substr(str, start_pos, *pos - start_pos);
	if (!num_substr)
		return (-1);
	final_num = ft_atoi(num_substr);
	free(num_substr);
	return (final_num);
}

int	count_flags(char const *str, int *pos, t_flags *flags)
{
	int	start_pos;

	start_pos = *pos;
	while (str[*pos] == '-' || str[*pos] == '+' || str[*pos] == ' '
		|| str[*pos] == '#' || str[*pos] == '0')
	{
		set_flag(str[*pos], flags);
		(*pos)++;
	}
	if (ft_isdigit(str[*pos]))
		flags->width = get_number(str, pos);
	if (str[*pos] == '.')
	{
		(*pos)++;
		flags->precision = get_number(str, pos);
	}
	if (flags->width == -1 || flags->precision == -1)
		return (-1);
	return (0);
}
