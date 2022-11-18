/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:40:11 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/10/21 16:00:04 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_unsigned(unsigned int unb, int fd, int *rtn)
{
	if (unb < 10)
	{
		unb += '0';
		ft_putchar_fd(unb, fd, rtn);
	}
	else
	{
		ft_is_unsigned(unb / 10, fd, rtn);
		ft_is_unsigned(unb % 10, fd, rtn);
	}
}
