NAME		= libfts.a

NAME_MAIN	= ret

SRCS		= ft_isascii.s\
			  ft_isalpha.s\
			  ft_isalnum.s\
			  ft_isdigit.s\
			  ft_isprint.s\
			  ft_tolower.s\
			  ft_toupper.s\
			  ft_bzero.s\
			  ft_puts.s\
			  ft_strcat.s\
			  ft_memset.s\
			  ft_memcpy.s\
			  ft_strdup.s\
			  ft_strlen.s\
			  ft_cat.s\

SRCS_MAIN	= main.c\
			  test_bzero.c\
			  test_toupper.c\
			  test_isalnum.c\
			  test_isalpha.c\
			  test_isascii.c\
			  test_isdigit.c\
			  test_isprint.c\
			  test_strcat.c\
			  test_tolower.c\
			  test_puts.c\
			  test_memset.c\
			  test_memcpy.c\
			  test_strdup.c\
			  test_strlen.c\
			  test_cat.c\


OBJS		= $(SRCS:.s=.o)

OBJS_MAIN	= $(SRCS_MAIN:.c=.o)

COMPILER	= gcc

CFLAG		= -Wall -Wextra -Werror

NASM		= nasm

NFLAG		= -f macho64

all: $(NAME) $(NAME_MAIN)

$(NAME): $(OBJS)
	@echo "compiling objs"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(NAME_MAIN): $(NAME) $(OBJS_MAIN)
	$(COMPILER) -Wl,-no_pie -o $@ $^ -L. -lfts 

%.o: %.s
	@echo "compiling nasm"
	$(NASM) $(NFLAG) $^

%.o: %.c
	@echo "compiling gcc"
	$(COMPILER) $(CFLAG) -c $^

clean:
	rm -f $(OBJS) $(OBJS_MAIN)

fclean: clean
	rm -f $(NAME) $(NAME_MAIN)
	rm -f a.out

re: fclean all