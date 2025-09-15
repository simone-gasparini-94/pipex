/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:04:06 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/29 14:21:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "run_processes.h"
#include "structs.h"
#include "set_structs.h"
#include "ft_printf.h"
#include "ft_fprintf.h"
#include "errors.h"
#include "clean.h"

#define NUM_ARGS 5

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;
	int		fd[2];
	int		pid[2];

	check_argc(argc, NUM_ARGS);
	set_args_values(&args, argv, envp);
	check_syscall(pipe(fd), "pipe");
	pid[0] = fork();
	check_syscall(pid[0], "fork");
	if (pid[0] == 0)
		run_first_child_process(fd, &args, envp);
	else
	{
		pid[1] = fork();
		check_syscall(pid[1], "fork");
		if (pid[1] == 0)
			run_second_child_process(fd, &args, envp);
		else
			run_parent_process(fd);
	}
	clean(&args);
	return (0);
}
