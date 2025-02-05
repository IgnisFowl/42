/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:00:19 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/20 11:51:24 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/include/ft_printf.h"
# include "libft/include/libft.h"

void		error(char *str);
void		execute(char *argv, char **envp);
void		free_paths(char **paths);
char		*find_path(char *cmd, char **envp);
size_t		ft_countwords(const char *s, char c);
char		**ft_custom_split(char const *s, char c);

#endif