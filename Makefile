# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2018/03/12 18:23:52 by rnugroho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C:= checker
NAME_PW:= push_swap
FILE_C:= ft_checker
FILE_PW:= ft_push_swap 
FILES:= pw_helper_1 pw_helper_2 pw_sort_data \
		pw_operators pw_print pw_sort_simple ch_operators \
		pw_sort_backtrack_1 pw_sort_backtrack_2

# ----- Libft ------
LFTDIR:=./libft
# ==================

# ------------------
COMPILER:=clang
LINKER:=ar rc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_PW:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_PW)))
SRC_C:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_C)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ_C:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_C)))
OBJ_PW:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_PW)))
# ==================
CCHF:=.cache_exists

all: $(NAME_PW) $(NAME_C)

$(NAME_C): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRCPATH)$(FILE_C).c -o $(NAME_C)
	@echo $(GREEN) " - OK" $(EOC)

$(NAME_PW): $(OBJ) $(OBJ_PW)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_PW) -o $(NAME_PW)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME_C)
	@rm -f $(NAME_PW)
	@rm -rf $(NAME_C).dSYM/
	@rm -rf $(NAME_PW).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

test: $(NAME_C) $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@./push_swap $(ARG) | ./checker $(OPT) $(ARG)

test_ch: $(NAME_C)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@./push_swap $(ARG) | ./checker $(ARG)

test_pw: $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@ ./push_swap $(ARG)
	@ echo $(ARG) > input.txt
	
debug_pw: $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@ ./push_swap $(OPT) $(ARG)
	@ echo $(ARG) > input.txt

debug: $(NAME_C) $(NAME_PW)
	@$(COMPILER) -g $(IFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g $(IFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap

norm:
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test norme test_ch test_pw debug
