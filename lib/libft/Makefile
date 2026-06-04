
# Flags
CC = cc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = src
OBJDIR = obj

# Source and Object Files
SRCS =	ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_count_words.c \
		ft_free_and_null.c \
		ft_free_char_array.c \
		ft_free_n_char_array.c \
		ft_get_hex_value.c \
		ft_hex_len.c \
		ft_hex_to_uint.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_ishex.c \
		ft_isnl.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_istab.c \
		ft_iswhitespace.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printf.c \
		ft_put_address.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_puthex.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_put_unum.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strndup.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		get_next_line_utils.c
	
#OBJS = $(SRCS:.c=.o)
SRCS	:= $(addprefix $(SRCDIR)/,$(SRCS))
OBJS	= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = libft.a

# set default target
all: $(NAME)

# build archive/library
$(NAME) : $(OBJS)
	@echo "making Libft..."
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

# clean up
clean:
	@echo "Cleaning Libft..."
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus