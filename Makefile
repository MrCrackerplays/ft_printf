# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pdruart <pdruart@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/28 14:41:56 by pdruart       #+#    #+#                  #
#    Updated: 2021/04/21 17:09:53 by pdruart       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
PART_MANDATORY = iets.o
PART_BONUS = anders.o
HEADER_FILES = ft_printf.h
CFLAGS = -Wall -Werror -Wextra

ifdef WITH_BONUS
OBJ_FILES = $(PART_MANDATORY) $(PART_BONUS)
else
OBJ_FILES = $(PART_MANDATORY)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(PART_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

so: $(OBJ_FILES)
	$(LINK.c) $(CFLAGS) -o $(NAME).so -shared $(OBJ_FILES) $(PART_BONUS)

.PHONY: all clean fclean re bonus so
