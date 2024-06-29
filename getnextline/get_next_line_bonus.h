/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:39:29 by esozbalt          #+#    #+#             */
/*   Updated: 2024/03/03 18:40:42 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*ft_read(int fd, char *buffer);

char	*ft_line(char *buffer);

char	*ft_newline(char *buffer);

int		ft_strlen(char *s);

char	*ft_strchr(char *s, char c);

char	*ft_strjoin(char *s1, char *s2);

#endif
