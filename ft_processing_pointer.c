/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:50:49 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 20:54:05 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_processing_pointer(t_mod *mod, const char *fmt)
{
	size_t	p;
	char	*str;
	int		len;

	p = va_arg(mod->arg, unsigned long);
	str = ft_itoa_hexidecimal(p);
	if (!str)
		return (NULL);
	len = ft_strlen(str) + 2;
	if (!mod->flag_minus && mod->width > len)
		ft_print_space(mod->width - len, mod);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	if (mod->flag_minus && mod->width > len)
		ft_print_space(mod->width - len, mod);
	mod->return_lenght += len;
	free(str);
	return (++fmt);
}
