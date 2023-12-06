SRCS= 			main.c \
				$(SRCS_WINDOW) \
				$(SRCS_PARSING) \
				$(SRCS_ERRORS) \
				$(SRCS_UTILS) \
				$(SRCS_GNL) \
				$(SRCS_FREE) \
				$(SRCS_DRAW)
				

SRCS_WINDOW=	window/create_window.c \
				window/close.c

SRCS_DRAW=		draw/draw_line.c \
				draw/transformations.c \
				draw/scale.c \
				draw/offset.c \
				draw/isometric.c \
				draw/resize_wip.c

SRCS_PARSING=	parsing/parsing.c

SRCS_ERRORS=	errors/errors.c

SRCS_GNL=		./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c

SRCS_UTILS=		utils/ft_split.c \
				utils/ft_strjoin.c \
				utils/ft_substr.c \
				utils/ft_strlen.c \
				utils/ft_strdup.c \
				utils/ft_atoi.c

SRCS_FREE=		free/free_init.c

TEST= test.c