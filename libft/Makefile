# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:41:12 by roliveir          #+#    #+#              #
#    Updated: 2019/07/01 17:39:25 by oboutrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c\
	   ft_memcpy.c\
	   ft_memset.c\
	   ft_memccpy.c\
	   ft_abs.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strdup.c\
	   ft_strcpy.c\
	   ft_strncpy.c\
	   ft_strcat.c\
	   ft_strncat.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_strnstr.c\
	   ft_strcmp.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_memalloc.c\
	   ft_memdel.c\
	   ft_strnew.c\
	   ft_strdel.c\
	   ft_strclr.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strequ.c\
	   ft_strnequ.c\
	   ft_strsub.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_strsplit.c\
	   ft_itoa.c\
	   ft_putchar.c\
	   ft_putcharz.c\
	   ft_putstr.c\
	   ft_putendl.c\
	   ft_putnbr.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_is_prime.c\
	   ft_find_next_prime.c\
	   ft_atoi_base.c\
	   ft_putnbr_base.c\
	   ft_print_words_tables.c\
	   ft_convert_base.c\
	   ft_del_words_tables.c\
	   get_next_line.c\
	   ft_strjoinf.c\
	   ft_print_digit_tables.c\
	   ft_print_digit.c\
	   ft_strclen.c\
	   ft_count_nb.c\
	   ft_atoip.c\
	   ft_sort_tab.c\
	   ft_tab_reverse.c\
	   ft_swap.c\
	   ft_swap_int.c\
	   ft_isquote.c\
	   get_line.c\
	   ft_tablen.c\
	   ft_isalnum_tab.c\
	   ft_tabstr.c\
	   ft_getenv.c\
	   ft_intdel.c\
	   ft_mgerror.c\
	   ft_putendlnb.c\
	   ft_delc.c\
	   ft_diff_abs.c\
	   ft_get_vector.c\
	   ft_normalize.c\
	   ft_dot.c\
	   ft_vdist.c\
	   ft_vdiv.c\
		ft_divv.c\
	   ft_vvmul.c\
		ft_vvdiv.c\
	   ft_vsub.c\
	   ft_vadd.c\
	   ft_vmul.c\
	   ft_2nd_degree.c\
	   ft_3rd_degree.c\
	   ft_3rd_degree_cardan.c\
	   ft_vrotate.c\
	   ft_fmat.c\
	   ft_clamp.c\
	   ft_cross.c\
	ft_print_vector.c	\
	ft_max.c		\
	vec3.c			\
	ft_readFile.c
PRINTF = ft_printf/ft_caster.c\
		 ft_printf/ft_conv_base.c\
		 ft_printf/ft_flag.c\
		 ft_printf/ft_flag2.c\
		 ft_printf/ft_float.c\
		 ft_printf/ft_iscase.c\
		 ft_printf/ft_manager.c\
		 ft_printf/ft_nbrtoa.c\
		 ft_printf/ft_print.c\
		 ft_printf/ft_search.c\
		 ft_printf/ft_putchar_p.c\
		 ft_printf/ft_putstr_p.c\
		 ft_printf/printf.c

INC_PATH = includes/
OBJ_PATH = objs/
OBJ_PATH_P = objs/ft_printf

OBJ_NAME = $(SRCS:.c=.o)
OBJ_NAME_P = $(PRINTF:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_P = $(addprefix $(OBJ_PATH), $(OBJ_NAME_P))

all: $(NAME)

$(OBJ_PATH)%.o : %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)

$(NAME): $(OBJ_PATH) $(OBJ) $(OBJ_P)
	@ar rc $(NAME) $(OBJ) $(OBJ_P)
	@ranlib $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2>&-
	@mkdir -p $(OBJ_PATH_P) 2>&-

noprintf : $(OBJ) $(INC_PATH)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ_P)
	@rm -rf $(OBJ_PATH) 2>&-

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re noprintf
