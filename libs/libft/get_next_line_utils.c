/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:31:06 by sait-alo          #+#    #+#             */
/*   Updated: 2023/12/24 13:31:14 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

int	gnl_strchr(const char *s, char c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// char	*ft_strdup(const char *s)
// {
// 	size_t	i;
// 	char	*new;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	new = (char *)malloc(ft_strlen(s) + 1);
// 	if (!new)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		new[i] = s[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	else if (!s2)
// 		return (ft_strdup(s1));
// 	i = 0;
// 	j = 0;
// 	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!new)
// 		return (NULL);
// 	while (s1[i])
// 		new[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		new[j++] = s2[i++];
// 	new[j] = '\0';
// 	return (new);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*sub;

// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s + start))
// 		len = ft_strlen(s + start);
// 	sub = malloc((len + 1) * sizeof(char));
// 	if (!sub)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		sub[i] = s[start + i];
// 		i++;
// 	}
// 	sub[i] = 0;
// 	return (sub);
// }
