/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:39:13 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 16:39:14 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_processing(t_mod *mod, const char *fmt)
{
	if (*fmt == 'c' || *fmt == '%')
		fmt = ft_processing_char(mod, fmt);
	else if (*fmt == 's')
		fmt = ft_processing_string(mod, fmt);
	else if (*fmt == 'p')
		fmt = ft_processing_pointer(mod, fmt);
	else if (*fmt == 'd' || *fmt == 'i')
		fmt = ft_processing_numbers(mod, fmt);
	else if (*fmt == 'u')
		fmt = ft_processing_uns_numbers(mod, fmt);
	else if (*fmt == 'x' || *fmt == 'X')
		fmt = ft_processing_hexidecimal(mod, fmt);
	else
		return (NULL);
	return (fmt);
}
