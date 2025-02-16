/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaka <msaka@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:38:18 by hbay              #+#    #+#             */
/*   Updated: 2024/01/31 10:59:24 by msaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_dollar(char *str)
{
	return (
		str[0] == '$' && \
		is_var(str[1])
	);
}

int	start_with(char *str, char c)
{
	return (
		*str == c
	);
}

int	end_with(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
		str++;
	return (
		*--str == c
	);
}

int	check(t_list *node, void *cmp)
{
	if (strccmp(node->content, cmp, '='))
		return (1);
	return (0);
}

int	i_space(char character)
{
	return (
		' ' == character || \
		'\t' == character || \
		'\v' == character || \
		'\f' == character || \
		'\r' == character
	);
}
