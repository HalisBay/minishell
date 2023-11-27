/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/27 14:46:23 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

covid	ctrl_c(int sig)
{
	// printf("\n%s", GREEN PROMT RESET);
	write(1, "\n"GREEN PROMT RESET, 22);
	// rl_redisplay();
	// fflush(stdout);
}

int	sh_exit(t_com *coms)
{
	printf("goodbye");
	exit(0);
}

int	exe(t_com *coms, char *cmd)
{
	int		_;

	_ = 0;
	while (_ < CMD_COUNT)
	{
		if (!strcmp(cmd, coms[_].name))
		{
			(free(cmd), coms[_].func(coms));
			return(0);
		}
		_++;
	}
	free(cmd);
	printf("command not found\n");
	return (0);
}

int	main(void)
{
    int				fd;
	char			buffer2[2000];
	int				p[2][2];
	pid_t			pid;
	char			**args;
	t_main			data;

	data.coms[0] = (t_com){"echo", 0, 1};
	data.coms[1] = (t_com){"cd", 0, 1};
	data.coms[2] = (t_com){"pwd", 0, 1};
	data.coms[3] = (t_com){"export", 0, 1};
	data.coms[4] = (t_com){"unset", 0, 1};
	data.coms[5] = (t_com){"env", 0, 1};
	data.coms[6] = (t_com){"exit", sh_exit, 1};
	data.coms[7] = (t_com){"x", sh_exit, 1};
	printf("prog started\n");
	signal(SIGINT, ctrl_c);
	args = malloc(2 * sizeof(char *));
	args[0] = strdup("/bin/ls");
	args[1] = strdup("-la");
	args[2] = 0;
	fd = open("program.c", O_RDONLY);
	pipe(p[0]);
	pipe(p[1]);

	// read(0, data.line, 99999);
	// printf("00000000000\n");
	data.line = readline(GREEN PROMT RESET);
	exe(data.coms, data.line);
	while (1)
	{
		data.line = readline(GREEN PROMT RESET);
		exe(data.coms, );
		rl_on_new_line();
		free(data.line);
	}
	// if (fork())
	// {

	// }
	// else
	// {
		
	// }
}

/**2.
 *  in pipe 
 * out ft_değisken
*/
// <file grep | cat >"ft_$out"
/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */
