# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 15:18:00 by Tdechand          #+#    #+#              #
#    Updated: 2023/04/28 14:59:29 by tdechand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	gcc
CCFLAG			=	-Wall -Wextra -Werror -g

HDR_DIR			=	-I includes

SRC_DIR			=	./src/

SUB_SRC_DIR		=	char io memory print print/printf_utils string string_tab list

SRC_FILE		=	char/ft_isalpha.c \
					char/ft_isdigit.c \
					char/ft_isalnum.c \
					char/ft_isascii.c \
					char/ft_isprint.c \
					char/ft_toupper.c \
					char/ft_tolower.c \
					\
					io/ft_putchar_fd.c \
					io/ft_putstr_fd.c \
					io/ft_putendl_fd.c \
					io/ft_putnbr_fd.c \
					io/get_next_line.c \
					\
					list/ft_lstnew.c \
					list/ft_lstadd_front.c \
					list/ft_lstsize.c \
					list/ft_lstlast.c \
					list/ft_lstadd_back.c \
					list/ft_lstdelone.c \
					list/ft_lstclear.c \
					list/ft_lstiter.c \
					list/ft_lstiter_param.c \
					list/ft_lstmap.c \
					list/ft_lstclear_nc.c \
					list/ft_lstiter_rev.c \
					list/ft_lstfirst.c \
					list/ft_lstiter_rev_ref.c \
					list/ft_lstiter_ref.c \
					list/ft_lstfind_ref.c \
					list/ft_lstmixtadd_back.c \
					list/ft_lstmixtclear.c \
					list/ft_lstmixtdelone.c \
					list/ft_lstmixtiter.c \
					list/ft_lstmixtlast.c \
					list/ft_lstmixtnew.c \
					\
					memory/ft_memset.c \
					memory/ft_bzero.c \
					memory/ft_memcpy.c \
					memory/ft_memmove.c \
					memory/ft_calloc.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c \
					\
					print/ft_printf.c \
					print/printf_utils/ft_putchar_pf.c \
					print/printf_utils/ft_putstr_pf.c \
					print/printf_utils/ft_putnbr_pf.c \
					print/printf_utils/ft_putunbr_pf.c \
					print/printf_utils/ft_putullnbrb_pf.c \
					print/printf_utils/ft_putnbrb_pf.c \
					print/printf_utils/ft_putnbrbcap_pf.c \
					print/ft_printtab.c \
					print/ft_printlist_str.c \
					\
					string/ft_strlen.c \
					string/ft_strlcpy.c \
					string/ft_strlcat.c \
					string/ft_strchr.c \
					string/ft_strrchr.c \
					string/ft_strncmp.c \
					string/ft_strcmp.c \
					string/ft_strnstr.c \
					string/ft_atoi.c \
					string/ft_atod.c \
					string/ft_strdup.c \
					string/ft_substr.c \
					string/ft_strjoin.c \
					string/ft_strtrim.c \
					string/ft_itoa.c \
					string/ft_strmapi.c \
					string/ft_striteri.c \
					\
					string_tab/ft_split.c \
					string_tab/ft_strtab_dup.c \
					string_tab/ft_strtab_len.c \
					string_tab/ft_strtab_clear.c \
					string_tab/ft_new_strtab.c \
					
SOURCES			=	$(addprefix $(SRC_DIR), $(SRC_FILE))


OBJ_DIR			=	./obj/
OBJ_FILE		=	$(patsubst %.c, %.o, $(SRC_FILE))
OBJECTS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))


all				:	$(NAME)

$(NAME)			:	obj $(OBJ_DIR) $(OBJECTS)
					@ar rc ${NAME} ${OBJECTS}
					@echo "\033[0;92m\n* $(NAME) was created *\033[0m"

$(OBJ_DIR)%.o 	: 	$(SRC_DIR)%.c
					@$(CC) $(CCFLAGS) ${HDR_DIR} -c $< -o $@
					@echo "\033[0;96m* $(notdir $<) -> $(notdir $@) * \033[0m: \033[0;92mOK\033[0m"

clean			:	
					@rm -rf $(OBJ_DIR)
					@echo "\033[0;91m* $(NAME) object files were deleted *\033[0m"

fclean			:	clean
					@rm -rf $(NAME)
					@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re				:	fclean $(NAME)

obj				:	
					@mkdir -p obj && cd obj && mkdir -p ${SUB_SRC_DIR}

.PHONY			:	all clean fclean re obj
