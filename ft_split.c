/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:24:41 by alejango          #+#    #+#             */
/*   Updated: 2023/09/20 18:49:00 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * fields_count: returns the number of words
*/
static size_t	fields_count(char const *str, char token)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str != token)
		{
			count++;
			while (*str != '\0' && *str != token)
				str++;
		}
		else
			str++;
	}
	return (count);
}

/**
 * field_length: returns the length of a single word
*/
static size_t	field_length(char const *s, char delim)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != delim)
		i++;
	return (i);
}

/**
 * field_next: returns a pointer to the next word within 's'
*/
static const char	*field_next(char const *s, char delim)
{
	while (*s != delim && *s != '\0')
		s++;
	while (*s == delim && *s != '\0')
		s++;
	return (s);
}

/**
 * field_free: frees allocated memory if anything goes wrong
 */

static void	field_free(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(str[i++]);
	free(str);
}

char	**ft_split(const char *s, char c)
{
	int			i;
	int			length;
	char		**table;
	const char	*current;

	table = (char **)malloc(sizeof(char *) * (fields_count(s, c) + 1));
	if (!table || !s)
		return (NULL);
	if (*s != c)
		current = s;
	else
		current = field_next(s, c);
	i = 0;
	while (*current)
	{
		length = field_length(current, c);
		table[i] = (char *)malloc(sizeof(char) * (length + 1));
		if (!table[i])
			return (field_free(table, i), NULL);
		ft_strlcpy(table[i], (char *)current, length + 1);
		current = field_next(current, c);
		++i;
	}
	table[i] = NULL;
	return (table);
}
