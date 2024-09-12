/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:22:42 by moelkama          #+#    #+#             */
/*   Updated: 2023/01/26 16:15:32 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlenf(char *str, char c)
{
	int	len;

	len = 0;
	while (str && str[len])
	{
		if (str[len] == c)
			return (len + 1);
		len++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*ptr[OPEN_MAX];
	char		*str;
	char		*swp1;
	char		*swp;

	str = (char *)malloc(BUFFER_SIZE * sizeof(char ) + sizeof(char ));
	if (str && BUFFER_SIZE > 0)
	{
		str[BUFFER_SIZE] = '\0';
		if (ptr[fd] && ft_check(ptr[fd]))
		{
			swp = ft_link(NULL, ptr[fd]);
			swp1 = ptr[fd];
			ptr[fd] = ft_link(ptr[fd] + ft_strlenf(ptr[fd], '\n'), NULL);
			ft_free(str, swp1);
			if (ft_strlenf(ptr[fd], '\0') == 0)
				*ptr = ft_free(ptr[fd], NULL);
			return (swp);
		}
		ft_bezero(str);
		return (get_next_line2(&ptr[fd], fd, &str, &swp));
	}
	return (NULL);
}
