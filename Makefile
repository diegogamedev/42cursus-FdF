CC = clang

NAME = fdf

LIBFT = libft/

MLX = mlx_linux/

FLAGS = -Wall -Wextra -Werror

LIBS = -lm -lbsd -lmlx -lXext -lX11

INCLUDE_PATH = includes/

SRCS = srcs/color.c srcs/fdf.c \
	srcs/free.c srcs/ft_atoi_base.c \
	srcs/get_next_line.c srcs/inputs.c \
	srcs/map_aux.c srcs/map.c srcs/math_extensions.c \
	srcs/project.c srcs/render.c srcs/vector_aux.c srcs/params.c

OBJ = color.o fdf.o free.o ft_atoi_base.o get_next_line.o inputs.o map_aux.o \
	map.o math_extensions.o project.o render.o vector_aux.o params.o

RM = rm -rf

all: $(NAME)
	make feiradafruta

$(NAME): $(OBJ)
		@printf "\n$(CY)Compiling Feira da Fruta\n"
		make -C $(LIBFT) -s
		@printf "\n$(YE)Libft Ready\n"
		make -C $(MLX) -s
		@printf "\n$(YE)MLX Ready\n"
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -L $(MLX) -lft $(LIBS)
		@printf "\n$(GR)Everything compiled\n"
		@printf "\nSorting out the mess\n"
		mkdir tmp
		mv $(OBJ) tmp
		@printf "\nDone!\n$(YE)"

$(OBJ): $(SRCS)
		$(CC) $(FLAGS) -c -I $(INCLUDE_PATH) $(SRCS)

clean:
		@printf "$(RE)\nINCINERATING ALL THE .o\n"
		$(RM) tmp
		make -C $(LIBFT) clean

fclean: clean
		@printf "$(RE)\nSENDING FDF STRAIGHT TO HELL\n"
		$(RM) $(NAME)
		@printf "$(RE)\nDELETING ALL .a FROM EXISTENCE\n"
		make -C $(MLX) clean -s
		make -C $(LIBFT) fclean -s
		@printf "it is done..."

re: fclean all

bonus: all

norm:
	norminette $(INCLUDE_PATH) $(LIBFT) srcs/

instructions:
	@printf "$(RE)(You need to have X11, XShm and bsd installed to run this software)"
	@printf "\n$(CY)Usage: ./fdf [valid fdf file] (check project pdf for more info about fdf files)\n"
	@printf "$(CY)Use WASD to move the camera on the x and y axis\n"
	@printf "$(CY)Use Left Shift and Left Control to move the camera on the z axis\n"
	@printf "$(CY)Use Q and E to perform a yaw on the projection\n"
	@printf "$(CY)Use Left and Right arrows to perform a roll on the projection\n"
	@printf "$(CY)Use Up and Down arrows to perform a pitch on the projection\n\n"

feiradafruta:
		@echo "...........................*VV*:.................::..........*.................:*VMMV*............................"
		@echo ".........................*VNNNNMI*...............*MI********FV...............*IMNNNNNNV*:........................."
		@echo ".......................*VNNNNNNNNNMI*:...........*NVIIFSVSIIVV:..........:*IVNNNNNNNNNNNMI:......................."
		@echo ".....................*VNNNNNNNNNNNNNNMVI*::......*NVVMNNNNNMMM:....::**IVMNNNNNNNNNNNNNNNNMI:....................."
		@echo "...................:FMNNNNNNNNNNNNNNNNNNNNMVVFII*VNNNNNNNNNNNNVFSVMMNNNNNNNNNNNNNNNNMMNNNNNNV*...................."
		@echo ".................:IMNNNNNNMMVSFII*IFMNNNNNNNNNNNNNNNNMMNNNMVMNNNNNNNNNNNNNNNNNMNNNMS**MNNNNNNNV:.................."
		@echo "................:VNNNNNNNMVS*********MNMNNNNNNNNNNNMVVVMNNMMMMNNNNNNNNNNNNNNNNSMNNNV***VNNNNNNNM*................."
		@echo "...............*MNNNNNNNNMV**********VMVNNNNNMMNNNNM****III*IMNNNNNNNMMNNNNNNNIMNNNNMI**SMNNNNNNMF:..............."
		@echo "..............*MNNNNNNNNMF****IV*****VMIMMMMMFMNNNNMS*******VNNNNNNNNVVMMNNNNNIVNNNNNMI**IMNNNNNNNV:.............."
		@echo ".............IMNNNNNNNNMI****VMNF****MI*******MNNNNNNVI**IIVNNNNNNNNNISNIVMSII*INNNMMNMI***VNNNNNNNM:............."
		@echo "...........:VNNNNNNNNNV*****VNMF***FMV**II***IMMNNNNNNNNNNNNNNMMNNNNM*VNI*******MNNMIMNMS***SMNNNNNNMI............"
		@echo "..........:MNNNNNNNNNV****IMVI***SMNM**IMNI**VVVNNNNNNNNNNNNNVVMMNNNV*VNV*******SNM***MNNV***FMNNNNNNNF:.........."
		@echo ".........:MNNNNNNNNMS*********FVMNNMI**MNNF**MF*II***IIIIFSSISMVNNNMI*SNV***F****MNV***IVMV***FMNNNNNNNV:........."
		@echo "........:MNNNNNNNNMS**********SNNNMS**VNNNI*IM**************IMFFNNNV**SNM***SV***SNMI*****SI***FMNNNNNNNV:........"
		@echo ".......:VNNNNNNNNMF****SVV*****MNNS**SNNNM**VMVVVV****IVVMMMMS*INNM***FNM***SNV***MNV***********FMNNNNNNNF........"
		@echo "......:VNNNNNNNNMS****MNNNV****MMS**IMMMV***MNNNNMI***MNNNNMS***MMI***INM***VNM***IMNS***********SMNNNNNNNI......."
		@echo ".....:VNNNNNNNNMI***FMNNNNV***IMF**********SNNNNNV***SNNNNMI****VS*****MM***VVV****SNM***IVS******IMNNNNNNNI......"
		@echo ".....FNNNNNNNNNF***IMNNNNM****VI***ISF*****MNNNNM****VNNNM*************MM****III****MNV***VNMVI****INNNNNNNM*....."
		@echo "....*MNNNNNNNNV****MNNNNMF***VI**FMNNNI****NNNNNV***IMNNM***I*****SS***MM***VNNNV***IMNF**IMNNNMI***VNNNNNNNM:...."
		@echo "...:MNNNNNNNNM****INNNNMS**IVI**VNNNNNI***FNNNNMI***SNNMI*IMNV***FMS***MM**INNNNNV***SNM***FNNNNMV***VMNNNNNNF...."
		@echo "...SNNNNNNNNM******VMMV***SMM**MNNNNNM****MNNNNV****MNMI*IMNNMI*IMNF***VNI*IMNNNNM****MNS***VNNNNNMI**FMNNNNNM*..."
		@echo "..*NNNNNNNNMIVS********IVMNNNMMNNNNNNF***INNNNMIIVVVNM***MNNNNMVMNNI***VNMMVMNNNNNI**IMNMIVMMNNNNNNNMMMVMNNNNNV:.."
		@echo ".:VNNNNNNNNMMNNMSIIISVMNNNNNNNNNNNNNM****VNNNNVVMNNNNS**VNNNNNNNNNNI***VNNNNNNNNNNV*SNNNNNNNNNNNNNNNNNNNNNNNNNN*.."
		@echo ".*NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNF****MNNNNNNNNNNNMSSMNNNNNNNNNNI***VNNNNNNNNNNMFVNNNNNNNNNNNNNNNMMMMMMMNNNNV:."
		@echo ".IVSSSVVMNNNNNNNNNNNNNNNNNNNNNNNNNNMIII*FNNNNNNNNNNNNNNNNNNNNNNNNNNVVVVMNNNNNNNNNNNMMNNNNNNNNNNNNMS*:.....::*IVM*."
		@echo "........:*SMNNNNNNNNNNNNNNNNNNNNNNNNNNNMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNV:.............::."
		@echo "...........:VNNNNNNMVVVVMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMVFII***I:................."
		@echo ".............IMVI*:.......:*IMNNNNNMVSI****IFVMNNNNNNNNNNNNNNNNMVI**:::.:::*ISMNNNNMI:............................"
		@echo "..............:..............:IMMF*:..........:*IVMNNNNNNNNNMS*:...............:*S*:.............................."
		@echo "..................................................:IMNNNNNMI:....................................................."
		@echo "....................................................:IMNMI:......................................................."
		@echo "......................................................:I*........................................................."

#this was generated by https://cloudapps.herokuapp.com/imagetoascii/
#manually formatted tho, ouch

#colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m
