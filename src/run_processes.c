/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:35:02 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/20 13:32:02 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "run_processes.h"
#include "structs.h"
#include "errors.h"

void	run_parent_process(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

void	run_first_child_process(int *fd, t_args *args, char *envp[])
{
	int	fd_input;

	close(fd[0]);
	fd_input = open(args->file1, O_RDONLY);
	check_syscall(fd_input, "open");
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	check_syscall(access(args->cmd1.path, X_OK), "access");
	check_syscall(execve(args->cmd1.path, args->cmd1.argv, envp), "execve");
}

void	run_second_child_process(int *fd, t_args *args, char *envp[])
{
	int	fd_output;

	close(fd[1]);
	fd_output = open(args->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_syscall(fd_output, "open");
	dup2(fd_output, STDOUT_FILENO);
	close(fd_output);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	check_syscall(access(args->cmd2.path, X_OK), "access");
	check_syscall(execve(args->cmd2.path, args->cmd2.argv, envp), "execve");
}
