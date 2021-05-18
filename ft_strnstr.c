/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:39:00 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/14 21:22:02 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	cmp_len;
	size_t	nd_len;

	i = 0;
	if (nd[i] == '\0')
		return ((char*)hs);
	nd_len = ft_strlen(nd);
	while (hs[i] && i < len)
	{
		cmp_len = ((len > nd_len + i) ? nd_len : (len - i));
		if (hs[i] == nd[0] && (len >= ft_strlen(nd) + i)
				&& ft_strncmp(hs + i, nd, cmp_len) == 0)
			return ((char*)hs + i);
		else
			i++;
	}
	return (0);
}
