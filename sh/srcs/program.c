/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/25 05:25:16 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void (*signal2(int sig, void (*f)(int)))(int){
	// void (*f)(int)
}

int	main(void)
{
    int				fd;
	char			buffer[2000];
	char			buffer2[2000];
	int				p[2][2];
	pid_t			pid;
	char			**args;
	
	args = malloc(2 * sizeof(char *));
	args[0] = strdup("/bin/ls");
	args[1] = strdup("-la");
	args[2] = 0;
	// printf("prog started\n");
	fd = open("program.c", O_RDONLY);
	pipe(p[0]);
	pipe(p[1]);
    // void(*signal(int, void (*)(int)))(int);

	printf("%d\n", signal(SIGINT, 0));
	printf("%s", GREEN PROMT RESET);
	fflush(stdout);
	readline(buffer);
	readline(buffer);
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
