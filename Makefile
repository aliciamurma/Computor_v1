# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 12:36:39 by amurcia-          #+#    #+#              #
#    Updated: 2023/09/09 19:21:18 by amurcia-         ###   ########.fr        #
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
# NAME_BONUS
NAME_B 			= computor_v1_bonus

# SOURCES
MAIN			= main.c
GETTERS			= getters.c
SETTERS			= setters.c
ERRORS			= check.c
SRC_UTILS 		= ft_split.c ft_strlen.c ft_strncmp.c ft_substr.c ft_free.c ft_free_zeros.c ft_trim.c
SRC		 		= $(SRC_UTILS) $(SETTERS) $(GETTERS) $(ERRORS)
# SOURCES_BONUS
MAIN_B				= main_bonus.c
GETTERS_B			= getters_bonus.c
SETTERS_B			= setters_bonus.c
ERRORS				= check_bonus.c
THIRD				= third_degree_bonus.c
SRC_UTILS_B 		= ft_split_bonus.c ft_strlen_bonus.c ft_strncmp_bonus.c ft_substr_bonus.c ft_free_bonus.c ft_free_zeros_bonus.c ft_trim_bonus.c
SRC_B		 		= $(SRC_UTILS_B) $(SETTERS_B) $(GETTERS_B) $(ERRORS) $(THIRD)

# FOLDERS
OBJ_DIR			:= obj
BIN_DIR			:= bin

#INCLUDES
INCLUDES 		:= inc/mandatory
INC				= $(addprefix -I , $(INCLUDES))
#INCLUDES_BONUS
INCLUDES_B 		:= inc/bonus
INC_B				= $(addprefix -I , $(INCLUDES_B))

# OBJECTS
OBJ_MAIN		= $(addprefix $(OBJ_DIR)/, $(MAIN:.c=.o))
OBJ_SRC			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ				= $(OBJ_MAIN) $(OBJ_SRC)
# OBJECTS_BONUS
OBJ_MAIN_B		= $(addprefix $(OBJ_DIR)/, $(MAIN_B:.c=.o))
OBJ_SRC_B			= $(addprefix $(OBJ_DIR)/, $(SRC_B:.c=.o))
OBJ_B				= $(OBJ_MAIN_B) $(OBJ_SRC_B)

# DEPENDENCIES
DEPS			= $(patsubst %.o, %.d, $(OBJ)) 
# DEPENDENCIES_bonus
DEPS_B			= $(patsubst %.o, %.d, $(OBJ_B)) 

# BINARY PATH
BIN 			= $(BIN_DIR)/$(NAME)
# BINARY PATH_BONUS
BIN_B 			= $(BIN_DIR)/$(NAME_B)

RM  			=  rm -f
RM_DIR 			=  rmdir

vpath %.c src/mandatory src/mandatory/utils src/bonus src/bonus/utils_bonus

.SECONDEXPANSION:

all: $(BIN)

bonus: $(BIN_B)

$(OBJ_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 
	@echo "$(BLUE)Compiling... $(NC)" $@

$(BIN): $(OBJ) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(BIN)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

$(BIN_B): $(OBJ_B) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJ_B) -o $(BIN_B)
	@echo "$(GREEN)$(NAME_B) compiled!$(NC)"

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	$(RM) $(OBJ_B)
	$(RM) $(DEPS_B)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(BIN)
	@$(RM) $(BIN_B)

re : fclean all

run1: all
	@./$(BIN) "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"

run1b: all
	@./$(BIN_B) "5 - 1 + 4 * X^1 - 9.3 * X^2 = 0"

run2: all
	@./$(BIN) "5 * X^0 + 4 * X^1 = 4 * X^0"

run3: all
	@./$(BIN) "5 * X^0 + 4 * X^1 + 4 * X^2 = 4 * X^0 + 4 * X^2"

run4: all
	@./$(BIN) "5 * X^0 = 5 * X^0"

run5: all
	@./$(BIN) "5 * X^0 = 4 * X^0 + 7 * X^1"

run6: all
	@./$(BIN) "6 * X^0 + 11 * X^1 - 5 * X^2 = 1 * X^0 + 1 * X^1"

run7: all
	@./$(BIN) "5 * X^0 + 3 * X^1 + 5 * X^5 = 1 * X^0 + 0 * X^1 + 5 * X^5"

run8: all
	@./$(BIN) "5 * X^0 = 4 * X^0 + 7 * X^1"

leaks: $(BIN)
	@leaks -atExit -- ./$(BIN) "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"

norm:
	@norminette src/* 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY : all clean fclean re run1 run2 run3 run4 run5 run6 leaks
