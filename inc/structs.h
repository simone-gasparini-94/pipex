/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:26:47 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/06 10:39:50 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cmd
{
	char	*s;
	char	*path;
	char	**argv;
}	t_cmd;

typedef struct s_args
{
	char	*file1;
	t_cmd	cmd1;
	t_cmd	cmd2;
	char	*file2;
}	t_args;

#endif
