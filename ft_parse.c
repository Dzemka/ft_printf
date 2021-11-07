/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:07:42 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 17:08:22 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

static const char	*ft_parse_flags(const char *fmt, t_mod *mod)
{
	while (ft_isflag(*fmt))
	{
		if (*fmt == '0')
			mod->flag_zero = 1;
		if (*fmt == '-')
			mod->flag_minus = 1;
		if (*fmt == '+')
			mod->flag_plus = 1;
		if (*fmt == ' ')
			mod->flag_space = 1;
		if (*fmt == '#')
			mod->flag_oct = 1;
		fmt++;
	}
	if (mod->flag_minus)
		mod->flag_zero = 0;
	return (fmt);
}

static const char	*ft_parse_width(t_mod *mod, const char *fmt)
{
	mod->width = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	mod->flag_space = 0;
	return (fmt);
}

static const char	*ft_parse_precision(const char *fmt, t_mod *mod)
{
	if (ft_isdigit(*fmt))
	{
		mod->precision = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
	}
	if (mod->precision == 0)
		mod->precision = -1;
	mod->flag_zero = 0;
	return (fmt);
}

const char	*ft_parse(const char *fmt, t_mod *mod)
{
	if (ft_isflag(*fmt))
		fmt = ft_parse_flags(fmt, mod);
	if (ft_isdigit(*fmt) && *fmt != '0')
		fmt = ft_parse_width(mod, fmt);
	if (*fmt == '.')
		fmt = ft_parse_precision(fmt + 1, mod);
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd' || \
		*fmt == 'i' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X' || *fmt == '%')
		fmt = ft_processing(mod, fmt);
	return (fmt);
}
