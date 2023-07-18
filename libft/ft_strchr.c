/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:48:34 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 17:31:58 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	char			*result;
	unsigned char	ch;

	i = 0;
	len = ft_strlen(s);
	ch = c;
	result = NULL;
	while (i <= len)
	{
		if (s[i] == ch)
		{
			result = (char *)&s[i];
			return (result);
		}
		i++;
	}
	return (result);
}
