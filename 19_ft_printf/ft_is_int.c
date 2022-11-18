/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:54:17 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/10/21 15:59:25 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_int(int nb, int fd, int *rtn)
{
	unsigned int	unb;

	unb = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd, rtn);
		unb = -nb;
	}
	if (unb < 10)
	{
		unb += '0';
		ft_putchar_fd(unb, 1, rtn);
	}
	else
	{
		ft_is_int(unb / 10, fd, rtn);
		ft_is_int(unb % 10, fd, rtn);
	}
}
