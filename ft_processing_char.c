/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:05:26 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 17:05:27 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_processing_char(t_mod *mod, const char *fmt)
{
	char	c;
	size_t	count_space;

	if (*fmt == '%')
		c = '%';
	else
		c = va_arg(mod->arg, int);
	count_space = 0;
	if (mod->width > 1)
		count_space = mod->width - 1;
	if (!mod->flag_minus)
		ft_print_space(count_space, mod);
	ft_putchar_fd(c, 1);
	if (mod->flag_minus)
		ft_print_space(count_space, mod);
	mod->return_lenght++;
	return (++fmt);
}
