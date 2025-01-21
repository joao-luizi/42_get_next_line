/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:41:32 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/21 11:45:33 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Reads a line from a file descriptor.
 *
 * This function reads from the given file 
 * descriptor (or standard input) line by line.
 * It considers the end of a line to be either 
 * the newline character (`'\n'`) or the
 * null terminator (`'\0'`). The function uses
 *  a static buffer to maintain the state
 * between successive calls for the same file 
 * descriptor, allowing it to handle lines
 * that span multiple buffer reads.
 *
 * @param fd The file descriptor to read from.
 *  This can be a file or standard input.
 * @return A dynamically allocated string c
 * ontaining the next line read from the file
 *         descriptor, or NULL if an error 
 * occurs or if there are no more lines to read.
 *         The caller is responsible for 
 * freeing the returned string.
 *
 * @note This function does not handle binary 
 * files and assumes the input is text.
 * @note The function uses a static buffer 
 * indexed by file descriptor, which limits the
 *       number of simultaneous file descriptors 
 * it can handle to `FOPEN_MAX`.
 * @note If the BUFFER_SIZE is set to 0 or less, 
 * the function will return NULL.
 */
char	*get_next_line(int fd)
{
	char		*result;
	int			i;
	static char	bf[BUFFER_SIZE + 1];

	if (fd > FOPEN_MAX || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	result = NULL;
	while (bf[0] || read(fd, bf, BUFFER_SIZE) > 0)
	{
		result = join_strings(result, bf);
		if (result == NULL)
			return (NULL);
		i = 0;
		while (result && result[i])
		{
			if (result[i] == '\n')
				return (result);
			i++;
		}
	}
	return (result);
}
// int main(void)
// {
//     int		fd;
//     char	*newline;

//     // fd = open("./examples/1char.txt", O_RDONLY);
//     // fd = open("./examples/empty.txt", O_RDONLY);
//     //fd = open("./examples/giant_line_nl.txt", O_RDONLY);
//      //fd = open("./examples/giant_line.txt", O_RDONLY);
//     // fd = open("./examples/lines_around_10.txt", O_RDONLY);
//     // fd = open("./examples/multiple_nl.txt", O_RDONLY);
//     // fd = open("./examples/mytest.txt", O_RDONLY);
//     // fd = open("./examples/one_line_no_nl.txt", O_RDONLY);
//     // fd = open("./examples/only_nl.txt", O_RDONLY);
//     // fd = open("./examples/read_error.txt", O_RDONLY);
// 	 fd = open("./examples/variable_nls.txt", O_RDONLY);
//     while (1)
//     {
//         newline = get_next_line(fd);
//         if (newline == NULL)
//             break;
//         printf("---------------->%s", newline);
// 		free(newline);
//     }
// 	close(fd);
//     return (0);
// }
