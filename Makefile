NAME = Fractal

FLAGS =
INCLUDES = -I includes/ -I includes/includes_SDL2/

LIB_DIR = libs/
LIBRARIES = $(LIB_DIR)libSDL2.dylib $(LIB_DIR)libSDL2_ttf.dylib $(LIB_DIR)libSDL2_image.dylib
STATIC_LIB = -L -l $(LIB_DIR)libSDLX.a $(LIB_DIR)libMT.a 

LERP_DIR = Lerp/
GRADIENT_DIR = Gradient/
SRCS_DIR = srcs/
BIN_DIR = bin/


GRADIENT_NAMES =		\
	gradient			\
	utils				\

LERP_NAMES=				\
	lerp				\

SRCS_NAMES =			\
	colors				\
	fractal				\
	input_handler		\
	render				\
	main 				\

C_FILES =				\
	$(addprefix $(LERP_DIR), $(LERP_NAMES))		\
	$(addprefix $(GRADIENT_DIR), $(GRADIENT_NAMES))	\
	$(SRCS_NAMES) 		\

SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(C_FILES)))
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBRARIES) -L -l $(STATIC_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re clean
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all