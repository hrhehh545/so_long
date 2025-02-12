/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:42:16 by yomoumen          #+#    #+#             */
/*   Updated: 2024/12/13 15:42:18 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		check_new_line(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_end(char *buffer);
char	*ft_check(char **buffer, char *line);
char	*ft_get_line(char **buffer);

#endif
