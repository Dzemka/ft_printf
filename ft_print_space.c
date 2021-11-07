/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:22:32 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 17:22:33 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space(size_t count_space, t_mod *mod)
{
	mod->return_lenght += count_space;
	while (count_space--)
		ft_putchar_fd(' ', 1);
}
