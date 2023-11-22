/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/23 00:11:04 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(void)
{
    int				fd;
	char			buffer[2000];
	int				p[2];
	pid_t			pid;
	pid_t			childs[22];
	char			**args;
	
	args = malloc(2 * sizeof(char *));
	args[0] = strdup("/bin/ls");
	args[1] = strdup("-la");
	args[2] = 0;
	// printf("prog started\n");
	fd = open("program.c", O_RDONLY);
	pipe(p);
		
	
	// execve("/bin/ls", args, 0);


	while (1)fork();
	

	bzero(childs, 11);
	// exit(0);
	for (size_t i = 0; i < 11; i++)
	{
		// usleep(1000);
		childs[i] = fork();
		
		if(!childs[i])
		{
			printf("%d\n", getpid());
			// child
			// exec
			while(1);
			exit(0);
		}
		else
		{
			// parent
			printf("olusturdum %d \n", getpid());
			// while(1);	
		}
	}
	sleep(1111);
	exit(0);
	// while("");
	if (pid)
	{
		// parent
		// close(p[0]);
		printf("parent started\n");
		usleep(1000000);
		write(p[1], "ahmet", 5);
		usleep(1000000);
		write(p[1], "mehme", 5);
		// close(p[1]);
		while(1);
	}
	else
	{
		// child
		// close(p[1]);
		read(p[0], buffer, 100);
		printf("%s\n", buffer);
		read(p[0], buffer, 100);
		printf("%s\n", buffer);
		printf("readed\n");
		while(1);	
	}
	printf("son\n");
	while(1);
}

/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */
