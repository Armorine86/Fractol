# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 15:27:16 by mmondell          #+#    #+#              #
#    Updated: 2021/08/30 10:05:16 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c $\
			ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcmp.c $\
			ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_calloc.c $\
			ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c $\
			ft_tolower.c ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c $\
			ft_strlcat.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memccpy.c $\
			ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c ft_calloc.c $\
			ft_memalloc.c ft_putchar.c ft_strnew.c ft_putnbr.c ft_putstr.c $\
			ft_strcpy.c ft_putunsnbr.c ft_putnbr_base.c ft_nbrlen.c ft_strcmp.c $\
			ft_putnchar.c ft_numlen.c ft_str_to_lower.c ft_isupper.c $\
			ft_str_to_upper.c ft_isspace.c ft_atol.c ft_free.c get_next_line.c$\

BONUS_S	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c $\
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c $\

BONUS_O = 	$(BONUS_S:.c=.o)
OBJS	= 	${SRCS:.c=.o}
INCL	= 	includes
NAME	= 	libft.a
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror -g

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : 		${NAME}

$(NAME) :	${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus : 	${NAME} ${BONUS_O} 
			ar rcs ${NAME} ${OBJS} ${BONUS_O}
		
clean :
			${RM} -f ${OBJS} ${BONUS_O}

fclean :	clean
			${RM} -f ${NAME} $(BONUS_O)

re :		fclean all

rebonus :	fclean bonus

.PHONY: all clean fclean re bonus rebonus