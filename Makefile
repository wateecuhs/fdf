NAME				=	fdf

include config/srcs.mk
SRC_PATH			=	srcs/
DIR_BUILD			=	.build/
OBJS				=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS				=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
DEPS_FLAGS			=	-MMD -MP
BASE_CFLAGS			=	-Wall -Wextra -Werror
BASE_DEBUG_CFLAGS	=	-g3
DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=address
# DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=memory -fsanitize-memory-track-origins
# FLAGS				=	$(BASE_CFLAGS) -g3
# FLAGS				=	$(BASE_CFLAGS) -g3
# FLAGS				=	$(BASE_CFLAGS) $(BASE_DEBUG_CFLAGS)
FLAGS				=	$(BASE_CFLAGS)
# FLAGS			=	$(BASE_CFLAGS) $(DEBUG_CLFAGS)
# FLAGS				=	$(BASE_CFLAGS) $(DEBUG_CLFAGS)
RM					=	rm -rf
AR					=	ar rcs

MINILIBX_PATH		=	minilibx/
MINILIBX_INCLUDES	=	$(MINILIBX_PATH)
MINILIBX_L			=	-L $(MINILIBX_PATH) -l mlx
MINILIBX_A			=	$(MINILIBX_PATH)libmlx.a
MAKE_MINILIBX		=	$(MAKE) -C $(MINILIBX_PATH)

DIR_INCS =\
	include/			\
	$(MINILIBX_INCLUDES)
INCLUDES =\
	$(addprefix -I , $(DIR_INCS))

LIBS = \
	-lm	\
	$(MINILIBX_L)	\
	-lXext	\
	-lX11

DEPENDENCIES =\
	$(MINILIBX_A)

.PHONY:		all
all:
			$(MAKE_MINILIBX)
			$(MAKE) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

.PHONY:	clean
clean:
			$(MAKE_MINILIBX) clean
			$(RM) $(DIR_BUILD)

.PHONY:	fclean
fclean:	clean
			$(RM) $(NAME)

.PHONY:	debug
debug:
			$(MAKE) -j FLAGS="$(DEBUG_CLFAGS)"

.PHONY:	re
re:		fclean
			$(MAKE) all

-include $(DEPS)
$(DIR_BUILD)%.o : $(SRC_PATH)%.c $(LIBFT_A)
			@mkdir -p $(shell dirname $@)
			$(CC) $(FLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@
