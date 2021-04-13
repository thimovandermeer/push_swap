NAME = checker
FLAGS = -Wall -Werror -Wextra
SDIR = srcs
ODIR = objs
_OBJS = checker \
		check_operators \
		operators \
		solve_hundred \
		utils
OBJS =	$(addsuffix .o, $(addprefix $(ODIR)/, $(_OBJS)))
LIBFT = libft.a
LIBFTMAP = libft
INC = includes
CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTMAP)/$(LIBFT)
	gcc $(OBJS) -L$(LIBFTMAP) -lft -o $(NAME)

$(LIBFTMAP)/$(LIBFT):
	make -C $(LIBFTMAP)

test: all
	./minishell

$(ODIR)/%.o: $(SDIR)/%.c $(INC)/$(HEADER)
	@mkdir -p $(ODIR)/$(dir $*)
	gcc $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT)
	make clean -C $(LIBFTMAP)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTMAP)

re: fclean all