# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 17:30:53 by ppatil            #+#    #+#              #
#    Updated: 2016/11/15 14:49:54 by ppatil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf

CC		:= cc
C_FLAGS	:= -Wall -Wextra -Werror -O3

SRC_DIR := ./src
INC_DIR	:= ./inc
OBJ_DIR	:= ./obj

# Including source files.
# Variable should be named C_FILES
-include sources.mk

# Including include directories.
# Appends to INC_DIR
-include includes.mk

# Including libraries to link.
# Variable should be called LIBRARIES
# Library directories should be called lib<name>/
-include libraries.mk

SOURCES	:= $(addprefix $(SRC_DIR)/, $(C_FILES))
INCUDES	:= $(addprefix -I , $(INC_DIR))
OBJECTS	:= $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(C_FILES)))

LIB_FLG	:= $(addprefix -l, $(LIBRARIES))
LIB_DIR := $(addprefix ./lib, $(LIBRARIES))
LIB_PTH	:= $(addprefix -L , $(LIB_DIR))

LIB_TGT	:= $(patsubst %, lib%.a, $(LIBRARIES))

all : $(NAME)

# Implicit rule for object files
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@ $(INCUDES)

# Implicit rule for library files
%.a :
	@echo "Making $(@)..."
	@$(MAKE) -C $(patsubst %.a, ./%, $(@));

$(NAME) : $(OBJECTS) $(LIB_TGT)
	@echo "Compiling $(@)..."
	$(CC) $(C_FLAGS) $(OBJECTS) -o $@ $(INCUDES) $(LIB_PTH) $(LIB_FLG) -framework OpenGL -framework AppKit
	@echo "Done."

fclean : clean
	@echo "Cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "Done."

clean :
	@echo "Cleaning $(OBJ_DIR)..."
	@rm -rf $(OBJ_DIR)
	@echo "Done."

re : fclean all

.PHONY : re fclean clean
