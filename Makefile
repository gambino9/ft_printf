# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:lboutry <marvin@42.fr>                    	+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 00:57:49 by  lboutry          #+#    #+#              #
#    Updated: 2019/09/04 03:23:18 by clboutry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_OPRINTF = ./libftprintf/
PATH_SPRINTF = ./libftprintf/
PATH_IPRINTF = ./libftprintf/
PATH_OLIBFT = ./libft/
PATH_SLIBFT = ./libft/
PATH_ILIBFT = ./libft/
FILESLIBFT = ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
			 ft_strchr ft_strrchr ft_isalpha ft_isdigit ft_isalnum ft_isascii\
			 ft_isprint ft_toupper ft_tolower ft_strstr ft_strnstr ft_strcmp\
			 ft_strncmp ft_atoi ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove\
			 ft_memchr ft_memcmp ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr\
			 ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub\
			 ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl\
			 ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew\
			 ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap
FILESPRINTF = ft_printf\
			  ft_itoa_base_printf\
			  ft_nbr_len_base\
			  ft_padding\
			  ft_print_decimal\
			  ft_parsing\
			  ft_print_char\
			  ft_print_string\
			  ft_print_pointer\
			  ft_uitoa_base_printf\
			  ft_unsigned_nbr_len_base\
			  ft_print_percent\
			  ft_print_hex\
			  ft_print_oct\
			  ft_print_unsigned\
			  ft_print_zero\
			  ft_print_oct_z
SLIBFT = $(addprefix $(PATH_SLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OLIBFT = $(addprefix $(PATH_OLIBFT), $(addsuffix .o, $(FILESLIBFT:.c=.o)))
	ILIBFT = $(addprefix $(PATH_ILIBFT), libft.h)
	SPRINTF = $(addprefix $(PATH_SPRINTF), $(addsuffix .c, $(FILESPRINTF)))
	OPRINTF = $(addprefix $(PATH_OPRINTF), $(addsuffix .o, $(FILESPRINTF:.c=.o)))
	IPRINTF = $(addprefix $(PATH_IPRINTF), libft_printf.h)

all : $(NAME)

$(NAME) : $(OLIBFT) $(OPRINTF)
	ar rcs $(NAME) $(OPRINTF) $(OLIBFT)

$(PATH_OLIBFT)%.o : $(PATH_SLIBFT)%.c $(ILIBFT)
	$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_ILIBFT)

$(PATH_OPRINTF)%.o : $(PATH_SPRINTF)%.c $(IPRINTF)
	$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_IPRINTF)

clean :
	rm -f $(OLIBFT) $(OPRINTF)

fclean : clean
	rm -f $(NAME)

re : fclean all
