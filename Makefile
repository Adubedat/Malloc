# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2017/09/20 17:44:44 by adubedat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

SUB_MAKEFILES = libft \
				src \

all:
	@make -C libft all
	@make -C src all

libft.a:
	@make -C libft all

ft_ls:
	@make -C src all

clean:
	@-for i in $(SUB_MAKEFILES) ; do \
		make -C $$i clean; \
	done
	@rmdir obj 2> /dev/null || true

fclean:
	@for i in $(SUB_MAKEFILES) ; do \
		make -C $$i fclean; \
	done

re: fclean all

ac: all clean

norme:
	@for i in $(SUB_MAKEFILES) ; do \
		make -C $$i norme; \
	done
	@norminette include/*.h

.PHONY: all clean fclean re
