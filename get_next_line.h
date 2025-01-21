/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:43:38 by joaomigu          #+#    #+#             */
/*   Updated: 2024/06/03 16:43:38 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

enum	e_bool
{
	TRUE = 1,
	FALSE = 0
};

char	*get_next_line(int fd);
char	*join_strings(char *original, char *bf);
size_t	custom_strlen(char *s);
void	reset_buffer(char *bf);

#endif
