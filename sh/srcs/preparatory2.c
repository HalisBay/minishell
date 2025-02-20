/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparatory2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaka <msaka@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:02:40 by hbay              #+#    #+#             */
/*   Updated: 2024/01/31 11:02:54 by msaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_path(char **cmd, int *ex_err)
{
	struct stat	sb;

	errno = 0;
	stat(*cmd, &sb);
	if (errno)
	{
		free(*cmd);
		*cmd = NULL;
		return (0);
	}
	else if (S_ISDIR(sb.st_mode))
	{
		free(*cmd);
		*cmd = NULL;
		return (0);
	}
	else if (access(*cmd, X_OK))
	{
		err(errno, *cmd);
		*ex_err = 126;
	}
	return (1);
}

void	if_path(t_main *shell, size_t _)
{
	struct stat	sb;

	errno = 0;
	stat(shell->cmds[_].cmd, &sb);
	if (errno)
	{
		err(errno, shell->cmds[_].cmd);
		free(shell->cmds[_].cmd);
		shell->cmds[_].cmd = NULL;
		shell->cmds[_].ex = 127;
	}
	else if (S_ISDIR(sb.st_mode))
	{
		err(IS_A_DIR, shell->cmds[_].cmd);
		free(shell->cmds[_].cmd);
		shell->cmds[_].cmd = NULL;
		shell->cmds[_].ex = 126;
	}
	else if (access(shell->cmds[_].cmd, X_OK))
	{
		err(errno, shell->cmds[_].cmd);
		free(shell->cmds[_].cmd);
		shell->cmds[_].cmd = NULL;
		shell->cmds[_].ex = 126;
	}
}
