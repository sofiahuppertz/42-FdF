/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:50:24 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 14:55:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void			*string;
	unsigned char	*ch;
	int				total_length;
	int				i;

	total_length = ft_strlen(s) + 1;
	string = (char *)malloc(total_length * sizeof(char));
	if (!string)
	{
		return (NULL);
	}
	i = 0;
	ch = (unsigned char *)string;
	while (i < total_length)
	{
		ch[i] = s[i];
		i++;
	}
	return (string);
}
