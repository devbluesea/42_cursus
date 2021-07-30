NAME = libasm.a
ASMSRCS = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
ASMOBJS = $(ASMSRCS:.s=.o)

%.o : %.s
	nasm -f macho64 $<

all: $(NAME)

$(NAME) : $(ASMOBJS)
	ar rc $(NAME) $(ASMOBJS)

clean:
		rm -f $(ASMOBJS)

fclean: clean
		rm -f $(NAME)
		rm -f test_result

re:	fclean all

test: all
	gcc -Wall -Werror -Wextra -lasm -L. -I. main.c -o test_result
	./test_result
