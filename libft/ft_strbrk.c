/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:55:03 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/16 17:24:19 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strbrk(const char *str, const char *search)
{
	const char	*searchptr;

	while (*str != '\0')
	{
		searchptr = search;
		while (*searchptr != '\0')
		{
			if (*str == *searchptr)
			{
				return (str);
			}
			searchptr++;
		}
		str++;
	}
	return (0);
}
