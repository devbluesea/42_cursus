NAME	=	libft.a

OPTION	=	-I ${HEADER}

SRCS	=	ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_memset.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strncmp.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strmapi.c\
			ft_strdup.c\
			ft_substr.c\
			ft_split.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_lstnew.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_strndup.c\
			ft_strncpy.c\
			ft_strcpy.c\

B_SRCS	=	ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\

CFLAGS	=	-Wall -Werror -Wextra

OBJS	=	${SRCS:%.c=%.o}

B_OBJS	=	${B_SRCS:%.c=%.o}

all : $(NAME)

$(NAME):
		gcc ${CFLAGS} -c ${SRCS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

bonus:	${NAME}
		gcc ${CFLAGS} -c ${B_SRCS}
		ar rc ${NAME} ${B_OBJS}
		ranlib ${NAME}

clean:
		rm -f ${OBJS} ${B_OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all
