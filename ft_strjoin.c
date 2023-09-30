/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:23:20 by alejango          #+#    #+#             */
/*   Updated: 2023/09/16 12:52:29 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	string = (char *) malloc (ft_strlen(s1) + ft_strlen(s2)+ 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		string[i++] = s2[j++];
	string[i] = '\0';
	return (string);
}
