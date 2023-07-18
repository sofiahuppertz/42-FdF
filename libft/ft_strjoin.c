/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:00 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:51 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		newstr[i] = s1[i];
		i++;
	}
	j = i;
	while (s2[i - j] != 0)
	{
		newstr[i] = s2[i - j];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
