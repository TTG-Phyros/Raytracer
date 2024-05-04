##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## RayTracer
##

NAME    =   RayTracer

IFLAGS  =   -I ./src/

CPPFLAGS    =   -std=c++20 -W -Wall -Wextra $(IFLAGS)

PATH_SRC    =   ./src/

PATH_CORE   = $(PATH_SRC)Core/

PATH_LOADER =   $(PATH_CORE)Loader/

PATH_COLOR  =   $(PATH_CORE)Color/

PATH_COORDINATES    =   $(PATH_CORE)Coordinates/

PATH_PLUGINS    =   $(PATH_SRC)Plugins/

PATH_PRIMITIVES =   $(PATH_PLUGINS)Primitives/

PATH_SPHERE =   $(PATH_PRIMITIVES)Sphere/

all: generateSo core

generateSo:
	g++ -shared -fPIC -o ./lib/raytracer_sphere.so ./src/Plugins/Primitives/Sphere/Sphere.cpp $(PATH_COLOR)Color.cpp $(PATH_COORDINATES)Coordinates.cpp -fno-gnu-unique

core:
	g++ $(PATH_CORE)*.cpp $(PATH_COLOR)*.cpp $(PATH_COORDINATES)*.cpp -ldl -o $(NAME) -fno-gnu-unique

clean:
	rm -f ./plugins/*.so

fclean: clean
	rm -rf $(NAME)

re: fclean all
