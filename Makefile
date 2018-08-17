# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 13:15:33 by dlinkin           #+#    #+#              #
#    Updated: 2017/11/09 13:15:35 by dlinkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = calculator.c coder.c main.c \
		mem_manager.c reader.c utilities.c \
		validator.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = fillit

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME)

calculator.o: calculator.c
	$(CC) $(CFLAGS) -c calculator.c -o calculator.o

coder.o: coder.c
	$(CC) $(CFLAGS) -c coder.c -o coder.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

mem_manager.o: mem_manager.c
	$(CC) $(CFLAGS) -c mem_manager.c -o mem_manager.o

reader.o: reader.c
	$(CC) $(CFLAGS) -c reader.c -o reader.o

utilities.o: utilities.c
	$(CC) $(CFLAGS) -c utilities.c -o utilities.o

validator.o: validator.c
	$(CC) $(CFLAGS) -c validator.c -o validator.o
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
