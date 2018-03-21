# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2018/03/21 14:02:59 by rnugroho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= checker
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
CFLAGS:=-Wall -Wextra -Werror $(IFLAGS)
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

all: $(NAME_PW) $(NAME)

$(NAME): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRCPATH)$(FILE_C).c -o $(NAME)
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
	@rm -f $(NAME)
	@rm -f $(NAME_PW)
	@rm -rf $(NAME).dSYM/
	@rm -rf $(NAME_PW).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

test: $(NAME) $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@./push_swap $(ARG) | ./checker $(OPT) $(ARG)

test_ch: $(NAME)
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

debug: $(NAME) $(NAME_PW)
	@$(COMPILER) -g $(IFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g $(IFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap

check: check_leak check_error check_ko check_ok check_pw

check_leak: $(NAME) $(NAME_PW)
	valgrind ./push_swap 2>&1 | grep lost
	valgrind ./push_swap "1 2" 2>&1 | grep lost
	valgrind ./push_swap "2 2" 2>&1 | grep lost
	valgrind ./push_swap "a 2" 2>&1 | grep lost
	valgrind ./push_swap "2147483649" 2>&1 | grep lost
	echo "sa" | valgrind ./checker 2>&1 | grep lost
	echo "sa" | valgrind ./checker 1 2 2>&1 | grep lost
	echo "sa" | valgrind ./checker "2 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker "a 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker "2147483649" 2>&1 | grep lost
	echo "sa " | valgrind ./checker "1 2" 2>&1 | grep lost
	echo "  sa" | valgrind ./checker "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -v "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -vact "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -g "1 2" 2>&1 | grep lost
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | valgrind ./checker -t $$ARG 2>&1 | grep lost
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; valgrind ./push_swap $$ARG 2>&1 | grep lost

check_error: $(NAME) $(NAME_PW)
	./checker a 2>&1 | cat -e
	./checker 1 1 2>&1 | cat -e
	./checker 2147483649 2>&1 | cat -e
	./checker 2>&1 | cat -e
	echo "swap" | ./checker "1 2" 2>&1 | cat -e
	echo "sa  " | ./checker "1 2" 2>&1 | cat -e
	echo "  sa" | ./checker "1 2" 2>&1 | cat -e
	./checker -g 2>&1 | cat -e
	./checker -catgv 2>&1 | cat -e
	./push_swap a 2>&1 | cat -e
	./push_swap 1 1 2>&1 | cat -e
	./push_swap -2147483649 2>&1 | cat -e
	./push_swap 2>&1 | cat -e

check_ko: $(NAME)
	echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5
	echo "sa\npb\nrrr" | ./checker "3 2 5 1"

check_ok: $(NAME) $(NAME_PW)
	echo "\0" | ./checker 0 1 2
	echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2
	echo "sa" | ./checker 1 0 2

check_pw:
	./push_swap 42
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	ARG="2 1 0"; ./push_swap $$ARG | ./checker -t $$ARG
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker -t $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l

check_bonus:
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -vcat $$ARG
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -t $$ARG

norm:
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test norme test_ch test_pw debug check
