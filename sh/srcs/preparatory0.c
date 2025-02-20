/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparatory0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaka <msaka@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:32:24 by hbay              #+#    #+#             */
/*   Updated: 2024/01/31 11:02:25 by msaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*resolve_cmd(t_main *shell, char *string, size_t _)
{
	char		*loc;
	char		*path;

	path = (get_ref(shell, "PATH"));
	loc = check_cmd(string, path, &shell->cmds[_].io_err);
	if (!loc)
	{
		err(CMD_NOTFND, string);
		shell->cmds[_].ex = 127;
	}
	return (loc);
}

char	*creat_cmd(char *path, size_t path_len, char *cmd)
{
	return (ft_strsjoin((t_merge *[]){\
		&(t_merge){path, path_len},
		&(t_merge){"/", 1},
		&(t_merge){cmd, ft_strlen(cmd)}, NULL
	}));
}

char	*check_cmd(char *cmd, char *path, int *ex_err)
{
	char		*var;
	size_t		_;

	if (!path)
		return (NULL);
	_ = 0;
	while ("")
	{
		if (path[_] == ':' || !path[_])
		{
			if (!path[_] && !_)
				break ;
			var = creat_cmd(path, _, cmd);
			if (check_path(&var, ex_err))
				break ;
			if (!path[_])
				break ;
			path += _ + 1;
			_ = 0;
		}
		if (path[_])
			_++;
	}
	return (var);
}

void	if_cmd(t_main *shell, size_t _)
{
	void		*var;

	search_builtins(shell, _);
	if (shell->cmds[_].builtin_offset)
		return ;
	var = shell->cmds[_].cmd;
	errno = 0;
	shell->cmds[_].cmd = resolve_cmd(shell, shell->cmds[_].cmd, _);
	free(var);
	return ;
}

void	set_path(t_main *shell)
{
	size_t		_;

	_ = -1;
	while (++_ < shell->cmd_ct)
	{
		if (!shell->cmds[_].args || shell->cmds[_].io_err)
			continue ;
		if (!ft_strchr(shell->cmds[_].cmd, '/'))
			if_cmd(shell, _);
		else
			if_path(shell, _);
	}
}
