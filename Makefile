CC =					clang

libs	=					libs
libr	=					# -L./libft -lft
parrent_dir	=				sh
incl	=					$(parrent_dir)/incs
tests	=					$(parrent_dir)/testing
incs	=					-I $(incl) -I ./libultift -I $(tests)/incs

wflags	=				# -Wall -Wextra -Werror
sanitize =				#-fsanitize=thread #-fsanitize=address
CFLAGS =				-D BUFFER_SIZE=65535 -std=c99 -g $(incs) $(wflags) $(sanitize)

os =					${shell uname -s}

ifeq '$(os)' 'Darwin'
# 	mlxLinkFlags =		-framework OpenGL -framework AppKit -L$(libs)/minilibx_opengl_20191021 -lmlx
# 	incs +=				-I $(libs)/minilibx_opengl_20191021
else ifeq '$(os)' 'Linux'
# 	mlxLinkFlags =		-L minilibx-linux -L$(libs)/minilibx-linux -lmlx -lXext -lX11
# 	incs +=				-I $(libs)/minilibx-linux
endif

src_dir = $(parrent_dir)/srcs
b_src_dir = $(parrent_dir)/srcs

S_SRC =					# $(src_dir)/shared.c \
						# $(tests)/testing.c

B_SRC =					$(b_src_dir)/checker.c \
						$(S_SRC)

SRC =					$(src_dir)/program.c \
						$(S_SRC)

OBJ =					$(SRC:.c=.o)
B_OBJ =					$(B_SRC:.c=.o)
NAME =					program
BNAME =					checker
MAKEFLAGS +=			-j$(NPROCS)
murmurc				=	./libultift/libft.a
depend				=	r_murmurc
# $(src_dir)%.o: $(src_dir)%.c
# 	gcc -c $< -o $@ > /dev/null

all:	$(depend) #bonus
	$(MAKE) $(NAME)
	@echo "===================================program======================================\n"

b: bonus

m: mandatory

mandatory: all

bonus:		$(depend) $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BNAME) $(libr)

$(NAME):	$(murmurc) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(libr)

r_murmurc:
	make -C ./libultift -j$(NPROCS)


# mlx:
# ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 -j$(NPROCS) &> /dev/null
# else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux -j$(NPROCS) &> /dev/null
# endif

run: all
	./$(NAME)

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean:					clean
ifeq "$(os)" "Darwin"
# 	make -C $(libs)/minilibx_opengl_20191021 clean
else ifeq ($(os),Linux)
# 	make -C $(libs)/minilibx-linux clean
endif
	make -C ./libft clean &
	rm -f $(NAME) $(BNAME) & wait

re:						fclean
	$(MAKE) all
	# $(MAKE) bonus

.PHONY:					re fclean clean all murmurc
