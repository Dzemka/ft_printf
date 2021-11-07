/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_hexidecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:51:41 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 17:04:07 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_processing_hexidecimal(t_mod *mod, const char *fmt)
{
	char	*str;
	size_t	len_arg;
	size_t	i;
	int		c;

	i = -1;
	c = *fmt;
	str = ft_itoa_hexidecimal(va_arg(mod->arg, unsigned int));
	if (!str)
		return (NULL);
	len_arg = ft_strlen(str);
	if (c == 'X')
	{
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	}
	if (mod->flag_oct && *str != '0')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(c, 1);
		mod->return_lenght += 2;
	}
	ft_print_str_of_numbers(str, len_arg, mod);
	free(str);
	return (++fmt);
}
