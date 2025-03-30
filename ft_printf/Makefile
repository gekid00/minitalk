NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -gdwarf-4

SRCS = srcs/ft_printf.c \
		srcs/conversions.c \
		srcs/conversions2.c \
		srcs/ft_bzero.c \
		srcs/ft_itoa.c \
		srcs/ft_strchr.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_utoa_base.c \
		srcs/ft_utoa.c \
		srcs/ft_atoi.c \

OBJS = $(SRCS:.c=.o)

AR = ar

all: $(NAME)

$(NAME): $(OBJS)
	   $(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	   $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re