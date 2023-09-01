# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 12:36:39 by amurcia-          #+#    #+#              #
#    Updated: 2023/09/01 20:26:28 by amurcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			:= \033[32m
NC				:= \033[m
BLUE			:= \033[34m

# FLAGS
CC = gcc
FLAGS  = -Wextra -Wall -Werror
DEPFLAGS = -MMD -MF

# NAME
NAME 			= computor_v1

# SOURCES
MAIN			= main.c
GETTERS			= getters.c
SETTERS			= setters.c
SRC_UTILS 		= ft_split.c ft_strlen.c ft_strncmp.c ft_substr.c
SRC		 		= $(SRC_UTILS) $(SETTERS) $(GETTERS)

# FOLDERS
OBJ_DIR			:= obj
BIN_DIR			:= bin

#INCLUDES
INCLUDES 		:= inc
INC				= $(addprefix -I , $(INCLUDES))

# OBJECTS
OBJ_MAIN		= $(addprefix $(OBJ_DIR)/, $(MAIN:.c=.o))
OBJ_SRC			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ				= $(OBJ_MAIN) $(OBJ_SRC)

# DEPENDENCIES
DEPS			= $(patsubst %.o, %.d, $(OBJ)) 

# BINARY PATH
BIN 			= $(BIN_DIR)/$(NAME)

RM  			=  rm -f
RM_DIR 			=  rmdir

vpath %.c src src/utils 

.SECONDEXPANSION:

all: $(BIN)

$(OBJ_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 
	@echo "$(BLUE)Compiling... $(NC)" $@

$(BIN): $(OBJ) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(BIN)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(BIN)

re : fclean all

run: all
	@./$(BIN) "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"

leaks: $(BIN)
	@leaks -atExit -- ./$(BIN) "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"

norm:
	@norminette src/* 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY : all clean fclean re run leaks
