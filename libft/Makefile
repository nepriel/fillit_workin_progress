# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huszalew <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:50:20 by huszalew          #+#    #+#              #
#    Updated: 2018/12/10 21:55:54 by huszalew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH := ./
OBJ_PATH := ./
HDR_PATH := ./

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_ctostr.c \
	  ft_freetab.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_islower.c \
	  ft_isprint.c \
	  ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstcount.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstrev.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strrev.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtabdup.c \
	  ft_strtrim.c \
	  ft_tablen.c \
	  ft_tolower.c \
	  ft_toupper.c

HDR := libft.h

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LFLAGS := -L$(LIB_PATH) -lft

OBJ := $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
SRC := $(addprefix $(SRC_PATH), $(SRC))
HDR := $(addprefix $(HDR_PATH), $(HDR))

C_NO		=	"\033[00m"
C_OK		=	"\033[36m"
C_GOOD		=	"\033[32m"

SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Compile" [ $(NAME) ] $(SUCCESS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	@$(CC) $(CFLAGS) -I$(HDR_PATH) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "Clean" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] "..." $(OK)

re: fclean all

.PHONY: all clean fclean re
