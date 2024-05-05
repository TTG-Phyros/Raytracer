##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## RayTracer
##

NAME    =   raytracer

IFLAGS  =   -I ./src/

CPPFLAGS    =   -std=c++20 -W -Wall -Wextra $(IFLAGS)

PATH_SRC    =   ./src/

PATH_CORE   = $(PATH_SRC)Core/

PATH_UTILS  = $(PATH_SRC)Utils/

PATH_LOADER =   $(PATH_UTILS)Loader/

PATH_COLOR  =   $(PATH_UTILS)Color/

PATH_COORDINATES    =   $(PATH_UTILS)Coordinates/

PATH_EXCEPTION    =   $(PATH_UTILS)Exception/

PATH_PLUGINS    =   $(PATH_SRC)Plugins/

PATH_PRIMITIVES =   $(PATH_PLUGINS)Primitives/

PATH_SPHERE =   $(PATH_PRIMITIVES)Sphere/

all: generateSo core

generateSo:
	g++ -shared -fPIC -o ./plugins/raytracer_sphere.so $(PATH_SPHERE)*.cpp $(PATH_COLOR)*.cpp $(PATH_COORDINATES)*.cpp -fno-gnu-unique

core:
	g++ $(PATH_SRC)*.cpp $(PATH_EXCEPTION)*.cpp $(PATH_COLOR)*.cpp $(PATH_COORDINATES)*.cpp -ldl -o $(NAME) -fno-gnu-unique

clean:
	rm -f ./plugins/*.so

fclean: clean
	rm -rf $(NAME)

re: fclean all
