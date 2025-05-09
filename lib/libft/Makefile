# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 17:19:18 by jodougla          #+#    #+#              #
#    Updated: 2025/02/06 17:27:31 by jodougla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################################
#																	#
#		INGREDIENTS													#
#																	#
#####################################################################
include srcs/sources.mk

NAME 		:= 	libft.a

CC 			:= 	cc
CFLAGS 		:= 	-Wall -Werror -Wextra
IFLAGS		:= -I ./headers

DIR_SRCS	:=	srcs
DIR_OBJS   	:=	.objs

OBJS 			:= $(addprefix $(DIR_OBJS)/, $(SRCS:%.c=%.o))

RM				:= rm -rf
DIR_DUP			:= mkdir -p $(@D)
AR				:= ar -rc

#####################################################################
#																	#
#			RULES													#
#																	#
#####################################################################

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 

clean :
	@$(RM) $(DIR_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

BOLD			=	\033[1m
ITALIC			=	\033[3m

RED				=	\033[31m
GREEN			=	\033[32m
CYAN			=	\033[36m
GRAY			=	\033[90m

RESET			=	\033[0m

LINE_CLR		=	\33[2K\r
