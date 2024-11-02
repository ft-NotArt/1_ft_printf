NAME			=	libftprintf.a

MAKEFLAGS		+=	-s
CFLAGS			=	-Wall -Werror -Wextra -g

FILES			=	ft_printf		\
				ft_printf_pars	\

OBJ				=	$(addsuffix .o, $(FILES))
SRC				=	$(addsuffix .c, $(FILES))

LIBFT			=	libft.a
LIBFT_DIR		=	libft
LIBFT_PATH		=	$(LIBFT_DIR)/$(LIBFT)

ARFLAGS			=	rcs

all				:	$(NAME)

$(LIBFT_PATH)	:
					$(MAKE) -C $(LIBFT_DIR) $(LIBFT) -j $$(nproc)

$(NAME)			:	$(OBJ) | $(LIBFT_PATH)
					$(AR) $(ARFLAGS) $@ $^
					printf 'OPEN $@\nADDLIB $(LIBFT_PATH)\nSAVE\nEND' | $(AR) -M
					echo -e '\x1b[38;2;182;229;168m \tCompiled\x1b[38;2;51;133;26m $@\x1b[38;2;182;229;168m that include\x1b[38;2;73;190;37m $(FILES)'

clean			:
					$(RM) $(OBJ)
					$(MAKE) -C $(LIBFT_DIR) $@
					echo -e '\x1b[38;2;182;229;168m \tCleaned\x1b[38;2;73;190;37m $(OBJ)'

fclean			:	clean
					$(RM) $(NAME)
					$(MAKE) -C $(LIBFT_DIR) $@
					echo -e '\x1b[38;2;182;229;168m \tCleaned\x1b[38;2;51;133;26m $(NAME)'

re				:	fclean all

.PHONY			= all clean fclean re