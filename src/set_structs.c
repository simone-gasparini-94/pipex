/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:32:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/29 14:26:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "set_structs.h"
#include "libft.h"
#include "structs.h"
#include "ft_fprintf.h"

void	set_args_values(t_args *args, char *argv[], char *envp[])
{
	args->file1 = argv[1];
	args->cmd1.s = argv[2];
	args->cmd2.s = argv[3];
	args->file2 = argv[4];
	set_cmd_values(&args->cmd1, envp);
	set_cmd_values(&args->cmd2, envp);
}

void	set_cmd_values(t_cmd *cmd, char *envp[])
{
	cmd->argv = ft_split(cmd->s, ' ');
	cmd->path = ft_strjoin("/bin/", cmd->argv[0]);
	(void)envp;
}
