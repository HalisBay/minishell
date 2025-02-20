/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaka <msaka@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:57:47 by msaka             #+#    #+#             */
/*   Updated: 2024/01/31 10:57:52 by msaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	sh_exit(t_main *shell, t_execd *execd)
{
	int			ato;

	printf(EXIT_MSG);
	if (shell->cmds[execd->_].args->next)
	{
		if (shell->cmds[execd->_].args->next->next)
		{
			e2(SHELLSAY, "exit", "too many arguments");
			exit(1);
		}
		ato = ft_atoi(shell->cmds[execd->_].args->next->content);
		if ((ato == 0) && \
			(((char *)shell->cmds[execd->_].args->next->content)[0] != '0'))
		{
			e2(SHELLSAY, "exit", "numeric argument required");
			exit(255);
		}
		exit(ato);
	}
	exit(shell->ex_stat);
}

int	sh_pwd(t_main *shell, t_execd *execd)
{
	(void)execd;
	if (getcwd(shell->cwd, MAX_CWD))
		printf("%s\n", shell->cwd);
	else
		return (err(errno, "pwd"), 1);
	return (0);
}

void	echo_util(t_list const *arg)
{
	while (!0)
	{
		printf("%s", (char *)arg->content);
		arg = arg->next;
		if (!arg)
			break ;
		printf(" ");
	}
}

int	sh_echo(t_main *shell, t_execd *execd)
{
	t_list const	*arg = shell->cmds[execd->_].args->next;
	int				n_flag;

	n_flag = !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!0;
	if (arg)
	{
		if (((char *)arg->content)[0] == '-' && \
			((char *)arg->content)[1] == 'n')
		{
			arg = arg->next;
			n_flag = 1;
		}
		if (arg)
			echo_util(arg);
	}
	if (((((((((((((((((((((((((((((((((!n_flag)))))))))))))))))))))))))))))))))
		printf("\n");
	return (0);
}
