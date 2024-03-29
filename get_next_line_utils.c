/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:40:37 by ataboada          #+#    #+#             */
/*   Updated: 2023/10/06 11:08:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *str, int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_merge_strs(char *s1, char const *s2);
char	*ft_dupstr(const char *s, size_t n);

size_t	ft_strclen(const char *str, int c)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0' && str[len] != c)
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s;
	char		*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_merge_strs(char *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*merged;

	len_1 = 0;
	if (s1)
		len_1 = ft_strclen(s1, '\0');
	len_2 = ft_strclen(s2, '\0');
	merged = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!merged)
		return (NULL);
	if (s1)
		ft_memcpy(merged, s1, len_1);
	ft_memcpy(merged + len_1, s2, len_2);
	merged[len_1 + len_2] = '\0';
	if (s1)
		free(s1);
	return (merged);
}

char	*ft_dupstr(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
