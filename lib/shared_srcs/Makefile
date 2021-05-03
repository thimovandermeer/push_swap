# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: thvan-de <thvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/22 08:55:21 by thvan-de      #+#    #+#                  #
#    Updated: 2021/05/03 11:35:01 by thvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		= shared
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj
BINDIR			= bin
HEADER			= ../include/libft.h

LIBS			= ./libs/Libft.a

INCLUDES 		= -Iinclude/

include 		sources.mk

OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$\
				  $(SRC:.$(SRCEXT)=.$(OBJEXT)))

# make bs
SILECE_MAKE = | grep -v -E ".*Leaving directory|.*Entering directory"
.SUFFIXES:
VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -E 's/(.*):/\1/')

all: $(BINDIR)/$(NAME).a

$(NAME): $(BINDIR)/$(NAME).a

static: $(BINDIR)/$(NAME).a

$(BINDIR)/$(NAME).a: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	ar -cr $(BINDIR)/$(NAME).a $(BUILDDIR)/*.$(OBJEXT) $(LIBS)

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

findsources:
	echo "# SRC = \$$(shell find $(SRCDIR) -type f -name '*.c')" > sources.mk
	echo "SRC = \\" >> sources.mk
	find src/ -name "*.c" -exec echo "{} \\" \; >> sources.mk

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)


$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(BUILDDIR)/$(notdir $@)

.PHONY: all so static clean fclean re
