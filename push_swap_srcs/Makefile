# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: thvan-de <thvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/22 09:05:57 by thvan-de      #+#    #+#                  #
#    Updated: 2021/05/03 11:39:27 by thvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

CC 			= gcc
CFLAGS 		= -Wuninitialized -O3

SRCEXT 		= c
SRCDIR 		= src
HEADERDIR	= include
OBJEXT 		= o
BUILDDIR	= obj

LIBS 		= ../lib/shared_srcs/libs/Libft.a
INCLUDES 	= -I$(HEADERDIR) -I../lib/

HEADERS 	= $(shell find $(HEADERDIR) -type f -name '*.h')

include sources.mk

OBJ	= $(foreach src,$(SRC),$(BUILDDIR)/$(notdir $(src:.$(SRCEXT)=.$(OBJEXT))))
VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -E 's/(.*):/\1/')
SILECE_MAKE = | grep -v -E ".*Leaving directory|.*Entering directory"

$(NAME): $(BUILDDIR)/ $(OBJ) $(HEADERS) $(SETTINGS)
	cp ../lib/shared_srcs/obj/*.o $(BUILDDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(BUILDDIR)/*.$(OBJEXT) $(LIBS) -o $(NAME)

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS) $(SETTINGS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(BUILDDIR)/$(notdir $@) $(LINKSRC)

clean:
ifneq ($(BUILDDIR),.)
	/bin/rm -rf $(BUILDDIR)/
endif

fclean:
	$(MAKE) clean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

findsources:
	echo "# SRC = \$$(shell find $(SRCDIR) -type f -name '*.c')" > sources.mk
	echo "SRC = \\" >> sources.mk
	find src/ -name "*.c" -exec echo "{} \\" \; >> sources.mk

silent:
	@$(MAKE) > /dev/null

.PHONY: all clean fclean re findsources silent
