# COLORS

BLUE			=	\x1b[0m\x1b[38;2;0;165;255m
LIGHT_BLUE		=	\x1b[0m\x1b[38;2;179;228;255m
DARK_BLUE		=	\x1b[1m\x1b[38;2;0;99;153m
DARK_GREEN		=	\x1b[1m\x1b[38;2;51;133;26m

# TARGET

NAME			=	libftprintf.a

LIBFT			=	libft.a
LIBFT_DIR		=	libft
LIBFT_PATH		=	$(LIBFT_DIR)/$(LIBFT)

# FLAGS

MAKEFLAGS		+=	-s
CFLAGS			=	-Wall -Werror -Wextra -g -Ilibft
ARFLAGS			=	rcs

# FILES

FILES			=	ft_printf						\
\
					ft_printf_struct_init			\
					ft_printf_str_utils				\
\
					ft_printf_identifiers			\
					ft_printf_identifier_str		\
					ft_printf_identifier_nbr		\
					ft_printf_identifier_address	\
\
					ft_printf_field_str				\
					ft_printf_field_int				\
					ft_printf_field_adress			\
					ft_printf_write_flag			\

OBJ				=	$(addsuffix .o, $(FILES))	
SRC				=	$(addsuffix .c, $(FILES))

# RULES

all				:	$(NAME)

$(LIBFT_PATH)	:
					$(MAKE) -C $(LIBFT_DIR) $(LIBFT) -j $$(nproc)

$(NAME)			:	$(OBJ) | $(LIBFT_PATH)
					$(AR) $(ARFLAGS) $@ $^
					echo -e '$(LIGHT_BLUE) \tCompiled$(DARK_BLUE) $@$(LIGHT_BLUE) that include$(BLUE) $(FILES)'
					printf 'OPEN $@\nADDLIB $(LIBFT_PATH)\nSAVE\nEND' | $(AR) -M
					echo -e '$(LIGHT_BLUE) \tIncluded$(DARK_GREEN) $(LIBFT)$(LIGHT_BLUE) to$(DARK_BLUE) $@'

clean			:
					$(RM) $(OBJ)
					$(MAKE) -C $(LIBFT_DIR) f$@
					echo -e '$(LIGHT_BLUE) \tCleaned$(BLUE) $(OBJ)'

fclean			:	clean
					$(RM) $(NAME)
					echo -e '$(LIGHT_BLUE) \tCleaned$(DARK_BLUE) $(NAME)'

re				:	fclean all

bonus			:	re

.PHONY			=	all clean fclean re