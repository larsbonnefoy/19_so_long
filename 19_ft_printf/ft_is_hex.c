/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:55:35 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/10/21 15:59:08 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_hex(unsigned int unb, char *base, int fd, int *rtn)
{
	if (unb < 16)
		ft_putchar_fd(base[unb], fd, rtn);
	if (unb >= 16)
	{
		ft_is_hex(unb / 16, base, fd, rtn);
		ft_is_hex(unb % 16, base, fd, rtn);
	}	
}
