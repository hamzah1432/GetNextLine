/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:40:03 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/18 20:06:08 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len++] != '\0');
	return (len);
}

char	*get_next_line(int fd)
{
    static t_node rem ;


}

int main()
{
    int fd;

    fd = open("text.txt",O_RDONLY);
    printf("%s\n",get_next_line(fd));
}