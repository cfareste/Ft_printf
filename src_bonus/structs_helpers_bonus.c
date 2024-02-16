/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/13 13:22:25 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -2;
}

t_flags	*initialize_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	reset_flags(flags);
	return (flags);
}

int	free_flags_struct(t_flags *flags, int final_length)
{
	if (flags)
		free(flags);
	return (final_length);
}
