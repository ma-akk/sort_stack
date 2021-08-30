/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:26:35 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 15:30:03 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_intpart(const char *str, int *zn)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-')
		*zn = 1;
	else
		*zn = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	return (i);
}

double	ft_atof(const char *str)
{
	int		i;
	int		zn;
	int		grade;
	double	nbr;
	double	tmp;

	tmp = 0.0;
	grade = 1;
	nbr = (double)ft_atoi(str);
	i = skip_intpart(str, &zn);
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]) && str[i] != '\0')
		{
			tmp = tmp * 10 + (str[i] - '0');
			grade *= 10;
			i++;
		}
		if (nbr >= 0 && !zn)
			nbr = nbr + tmp / grade;
		else
			nbr = nbr - tmp / grade;
	}
	return (nbr);
}
