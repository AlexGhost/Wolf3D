/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:02:12 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/12 11:03:00 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrl(int n)
{
	long taille;
	long nb;

	taille = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (taille <= nb)
	{
		taille = taille * 10;
	}
	taille = taille / 10;
	while (taille > 1)
	{
		ft_putchar((nb / taille) + '0');
		nb = nb % taille;
		taille = taille / 10;
	}
	ft_putchar((nb % 10) + '0');
	ft_putchar('\n');
}
