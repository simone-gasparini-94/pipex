/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:35:49 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/29 13:22:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_PROCESSES_H
# define RUN_PROCESSES_H

# include "structs.h"

void	run_parent_process(int *fd);
void	run_first_child_process(int *fd, t_args *args, char *envp[]);
void	run_second_child_process(int *fd, t_args *args, char *envp[]);

#endif
