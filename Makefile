NAME    =   libftprintf.a

SRC		=		 	ft_printf.c \
					ft_parse.c \
					ft_processing.c \
					ft_processing_char.c \
					ft_processing_string.c \
					ft_processing_numbers.c \
					ft_processing_pointer.c \
					ft_processing_uns_numbers.c \
					ft_print_space.c ft_print_str_of_numbers.c \
					ft_processing_hexidecimal.c \
					ft_itoa_hexidecimal.c \

LIB     =   libft.a

LIB_DIR =   ./libft

OBJ     =   $(SRC:%.c=%.o)

HEADER  =   ft_printf.h

CC      =   gcc

CFLAGS  =   -Wall -Wextra -Werror

.PHONY  =   all clean fclean re bonus

all     :   $(LIB) $(NAME)

bonus	:	all

$(NAME) :   $(OBJ) $(HEADER) $(LIB_DIR)/$(LIB)
	ar rcs $(NAME) $? $(LIB_DIR)/*.o

$(LIB)  :
	cd $(LIB_DIR) && $(MAKE) all

%.o     :   %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean   :
	cd $(LIB_DIR) && $(MAKE) clean
	$(RM) $(OBJ)

fclean  : clean
	cd $(LIB_DIR) $(MAKE) fclean
	$(RM) $(NAME)

re      : fclean all
