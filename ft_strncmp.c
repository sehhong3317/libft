/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:49:24 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/14 15:29:20 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n)
	{
		if ((*p1 != *p2) || !*p1 || !*p2)
			return (*p1 - *p2);
		n--;
		p1++;
		p2++;
	}
	return (0);
}
