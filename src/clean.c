/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:50:20 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/29 14:21:35 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"

void	clean(t_args *args)
{
	int	i;

	free(args->cmd1.path);
	free(args->cmd2.path);
	i = 0;
	while (args->cmd1.argv[i] != NULL)
		free(args->cmd1.argv[i++]);
	free(args->cmd1.argv);
	i = 0;
	while (args->cmd2.argv[i] != NULL)
		free(args->cmd2.argv[i++]);
	free(args->cmd2.argv);
}
