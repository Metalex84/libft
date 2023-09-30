/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:31:38 by alejango          #+#    #+#             */
/*   Updated: 2023/09/20 23:15:28 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * my_log10: returns base-10 logarithm of given integer
*/
static int	my_log10(int num)
{
	int	result;

	result = 0;
	while (num > 0)
	{
		num /= 10;
		result++;
	}
	return (result);
}

/**
 * my_abs: returns absolute value of given integer
*/
static int	my_abs(int num)
{
	if (num < 0)
		return (num * (-1));
	else
		return (num);
}

/**
 * my_allocation: returns a char-array sized by 'digits' and depending of sign
*/
static char	*my_allocation(int digits, int n)
{
	char	*ret;

	if (n < 0)
		ret = (char *) malloc (sizeof(char) * (my_log10(digits) + 2));
	else
		ret = (char *) malloc (sizeof(char) * (my_log10(digits) + 1));
	return (ret);
}

/**
 * my_putnbr: creates 'ret' string itself and returns its last index
*/
static int	my_putnbr(char *ret, int n, int digits, int start)
{
	int	tmp;

	if (start == 1)
		ret[0] = '-';
	tmp = 0;
	while (digits > 0)
	{
		tmp = my_abs(n) / digits;
		ret[start] = tmp + '0';
		n %= digits;
		digits /= 10;
		start++;
	}
	return (start);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		digits;

	if (n == -2147483648)
	{
		ret = ft_strdup((char *) "-2147483648");
		if (!ret)
			return (NULL);
	}
	else
	{
		digits = 1;
		while (my_abs(n) / digits >= 10)
			digits *= 10;
		ret = my_allocation(digits, n);
		if (!ret)
			return (NULL);
		if (n < 0)
			ret[my_putnbr(ret, n, digits, 1)] = '\0';
		else
			ret[my_putnbr(ret, n, digits, 0)] = '\0';
	}
	return (ret);
}
