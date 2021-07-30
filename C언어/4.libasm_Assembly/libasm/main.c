/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:38:47 by seobaek           #+#    #+#             */
/*   Updated: 2020/12/29 10:42:32 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libasm.h"

#include <errno.h>

int main()
{
    char    dest1[10];
    char    dest2[10];

    printf("-------FT_STRLEN-----------\n");
    printf("length : %d\n", (int)strlen("Pizza"));
    printf("length : %d\n", (int)ft_strlen("Pizza"));
    printf("length : %d\n", (int)strlen(""));
    printf("length : %d\n", (int)ft_strlen(""));

    printf("-------FT_STRCMP-----------\n");
    printf("result of strcmp : %d\n", strcmp("\0", "\200"));
    printf("result of ft_strcmp : %d\n", ft_strcmp("\0", "\200"));
    printf("---------------------------\n");

    printf("result of strcmp : %d\n", strcmp("\200", "\0"));
    printf("result of ft_strcmp : %d\n", ft_strcmp("\200", "\0"));
    printf("---------------------------\n");

    printf("result of strcmp : %d\n", strcmp("aa", "aa"));
    printf("result of ft_strcmp : %d\n", ft_strcmp("aa", "aa"));
    printf("---------------------------\n");

    printf("result of strcmp : %d\n", strcmp("j", "a"));
    printf("result of ft_strcmp : %d\n", ft_strcmp("j", "a"));
    printf("---------------------------\n");

    printf("result of strcmp : %d\n", strcmp("a", "j"));
    printf("result of ft_strcmp : %d\n", ft_strcmp("a", "j"));
    printf("---------------------------\n");

    printf("result of strcmp : %d\n", strcmp("a\200\0", "abcd"));
    printf("result of ft_strcmp : %d\n", ft_strcmp("a\200\0", "abcd"));
    printf("---------------------------\n");

    printf("result of strcmp : %d\n", strcmp("aaa", ""));
    printf("result of ft_strcmp : %d\n", ft_strcmp("aaa", ""));
    printf("---------------------------\n");

    printf("-------FT_STRCPY-----------\n");
    printf("result of strcpy : %s\n", strcpy(dest1, ""));
    printf("result of ft_strcpy : %s\n", ft_strcpy(dest2, ""));

    printf("----- FT_WRITE -----\n");
	write(1, "hello\n", 6);
    ft_write(1, "hello\n", 6);
    printf("returned value : %zd\n", write(1, "hello\n", -3));
    printf("Error No : %d\n", errno);
    printf("returned value : %zd\n", ft_write(1, "hello\n", -3));
    printf("Error No : %d\n", errno);
    printf("returned value : %zd\n", write(-1, "hello\n", 3));
    printf("Error No : %d\n", errno);
    printf("returned value : %zd\n", ft_write(-1, "hello\n", 3));
    printf("Error No : %d\n", errno);
    printf("returned value : %zd\n", write(1, "hello\n", 6));
    printf("returned value : %zd\n", write(1, "hello\n", 6));

    printf("----- FT_READ -----\n");
    ssize_t     ret_read;
    char		buf[5000];
    int         fd;
	int			fd2;

	fd2 = open("test.txt", O_RDWR);
	ret_read = read(STDIN_FILENO, buf, 42);
	write(fd2, buf, ret_read);

    fd = open("ft_write.s", O_RDONLY);
	ret_read = ft_read(-1, buf, 42);
	buf[ret_read] = '\0';
	printf("|%s|\nreturn : %zd\n", buf, ret_read);
    close(fd);

    fd = open("ft_write.s", O_RDONLY);
	ret_read = read(-1, buf, 42);
	buf[ret_read] = '\0';
	printf("|%s|\nreturn : %zd\n", buf, ret_read);
    close(fd);

    printf("\n----- FT_STRDUP -----\n");
    printf("%s\n", strdup("TIL"));
    printf("%s\n", ft_strdup("TIL"));
    printf("%s\n", strdup(""));
    printf("%s\n", ft_strdup(""));
    printf("%s\n", strdup("Lorem ipsum dolor sit amet"));
    printf("%s\n", ft_strdup("Lorem ipsum dolor sit amet"));
    return (0);
}
