/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:42:01 by ataboada          #+#    #+#             */
/*   Updated: 2023/10/06 10:56:29 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ---------------------------------- INCLUDES ---------------------------------

# include <unistd.h>
# include <stdlib.h>

// ---------------------------------- DEFINES ----------------------------------

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// ---------------------------------- PROTOTYPES -------------------------------

// get_next_line.c
char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *storage);
char	*ft_get_current_line(char *storage);
char	*ft_update_storage(char *storage);

// get_next_line_utils.c
size_t	ft_strclen(const char *str, int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_merge_strs(char *s1, char const *s2);
char	*ft_dupstr(const char *s, size_t n);

#endif
