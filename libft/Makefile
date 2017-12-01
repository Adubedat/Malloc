# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubedat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 19:30:56 by adubedat          #+#    #+#              #
#    Updated: 2017/12/01 15:00:00 by adubedat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c ft_strdup.c \
	  ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	  ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_puttab2d.c \
	  ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_lstmap.c ft_intlen.c ft_swap.c ft_rrange.c ft_power.c \
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memalloc.c \
	  ft_memdel.c ft_malloctab2d.c ft_itoa_lli.c ft_itoa_ulli.c \
	  ft_lli_len.c ft_ulli_len.c ft_itoa_base_lli.c ft_itoa_base_ulli.c \
	  ft_ulli_len_base.c ft_addr.c ft_strjoin_free_s2.c ft_strsub_free.c \
	  ft_strjoin_free_s1.c ft_putwchar.c ft_atoi_base.c ft_putwstr.c \
	  ft_strdup_free.c get_next_line.c ft_strjoin_free_both.c char.c string.c \
	  pointer.c signed_decimal.c unsigned_decimal.c check_flags.c apply_flags.c \
	  ft_printf.c ft_hexdump.c ft_putnbr_hexa.c

OBJ = $(SRC:.c=.o)

WFLAGS = -Wall -Werror -Wextra

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

%.o: %.c
	$(CC) $(WFLAGS) -c -o $@ $^
	printf "\e[32m[✔]\e[36m $@"
	printf "\033[0m\n"

clean:
	rm -f $(OBJ)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	rm -f $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

.PHONY: all fclean clean re
