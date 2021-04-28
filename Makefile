NAME = libftprintf.a
PART_BASE = ft_printf.o
PART_BONUS = 
HEADER_FILES = ft_printf.h
CFLAGS = -Wall -Werror -Wextra

ifdef WITH_BONUS
OBJ_FILES = $(PART_BASE) $(PART_BONUS)
else
OBJ_FILES = $(PART_BASE)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ_FILES)
	#TODO FINISH UP THIS MAKEFILE BASED ON https://github.com/rchallie/ft_printf/blob/master/Makefile

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./libft
	rm -f $(PART_BASE) $(PART_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

run:
	make && $(CC) $(CFLAGS) main.c libftprintf.a -o a.out && ./a.out

so: $(OBJ_FILES)
	$(LINK.c) $(CFLAGS) -o $(NAME).so -shared $(OBJ_FILES) $(PART_BONUS)

.PHONY: all clean fclean re bonus run so
