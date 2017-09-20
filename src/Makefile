# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubedat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/23 17:07:31 by adubedat          #+#    #+#              #
#    Updated: 2017/09/20 17:39:11 by adubedat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SYMB_LINK = libft_malloc.so

SRC_PATH = .
ROOT = ..
OBJ_FOLDER = obj
INC_PATH = $(ROOT)/includes \
		   $(ROOT)/libft \

OBJ_PATH = $(ROOT)/$(OBJ_FOLDER)
DST_PATH = $(ROOT)
LFT_PATH = $(ROOT)/libft

CC = gcc -shared
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I ,$(INC_PATH))
LDFLAGS = -L$(LFT_PATH)
LDLIBS = -lft

SRC_NAME =	main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
DST = $(addprefix $(DST_PATH)/,$(NAME))

all: $(ROOT)/libft/libft.a $(DST)

$(DST):
	$(CC) $(SRC) $(LDFLAGS) $(LDLIBS) -o $(DST)
	ln -s $(NAME) $(ROOT)/$(SYMB_LINK)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

$(ROOT)/libft/libft.a:
	make -C $(ROOT) libft/libft.a

clean:
	printf "\e[36m"
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) $(ROOT)/obj 2> /dev/null || true
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	printf "\e[36m"
	@rm -fv $(DST)
	@rm -fv $(ROOT)/$(SYMB_LINK)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

ac: all clean

norme:
	norminette $(SRC)

.PHONY: all clean fclean re
