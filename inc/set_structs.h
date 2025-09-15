/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:48:58 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/29 10:29:22 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_STRUCTS_H
# define SET_STRUCTS_H

# include "structs.h"

void	set_args_values(t_args *args, char *argv[], char *envp[]);
void	set_cmd_values(t_cmd *cmd, char *envp[]);

#endif
