/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <pkunze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/22 14:12:11 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(float *result, float *sign, int *point, const char **s)
{
	*result = 0;
	*sign = 1;
	if (**s == '-')
	{
		*s += 1;
		*sign = -1;
	}
	*point = 0;
}

float		ft_atof(const char *s)
{
	float	result;
	float	sign;
	int		point;
	int		d;

	init(&result, &sign, &point, &s);
	while (ft_isdigit(*s) || (*s == '.' && !point))
	{
		if (*s == '.')
		{
			point = 1;
			s++;
		}
		d = *s - '0';
		if (d >= 0 && d <= 9)
		{
			if (point)
				sign /= 10.0f;
			result = result * 10.0f + (float)d;
		}
		s++;
	}
	return (result * sign);
}
