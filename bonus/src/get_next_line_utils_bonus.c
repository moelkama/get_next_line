/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:24:59 by moelkama          #+#    #+#             */
/*   Updated: 2023/01/25 13:40:51 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_checkb(char *str)
{
	while (str && *str)
		if (*(str++) == '\n')
			return (1);
	return (0);
}

void	ft_bezerob(char *str)
{
	int	i;

	i = 0;
	while (str && i < BUFFER_SIZE)
		str[i++] = '\0';
}

char	*ft_freeb(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char	*ft_linkb(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlenf(s1, '\0') + ft_strlenf(s2, '\n');
	str = (char *)malloc(len * sizeof(char ) + sizeof(char ));
	if (str)
	{
		i = 0;
		j = 0;
		while (s1 && s1[j])
			str[i++] = s1[j++];
		j = 0;
		while (s2 && i < len)
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*get_next_line2b(char **ptr, int fd, char **str, char **swp)
{
	char	*swp1;
	char	*swp2;
	int		number;

	number = read(fd, *str, BUFFER_SIZE);
	swp1 = ft_link(NULL, *str);
	*swp = ft_link(*ptr, swp1);
	free(swp1);
	if (ft_strlenf(*swp, '\0') == 0)
		return (ft_free(*swp, *str));
	while (!ft_check(*str) && number == BUFFER_SIZE)
	{
		ft_bezero(*str);
		number = read(fd, *str, BUFFER_SIZE);
		swp1 = *swp;
		swp2 = ft_link(NULL, *str);
		*swp = ft_link(swp1, swp2);
		ft_free(swp1, swp2);
	}
	free(*ptr);
	*ptr = ft_link(*str + ft_strlenf(*str, '\n'), NULL);
	free(*str);
	if (ft_strlenf(*ptr, '\0') == 0)
		*ptr = ft_free(*ptr, NULL);
	return (*swp);
}
