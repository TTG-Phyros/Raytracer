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

PATH_PARSER =	$(PATH_SRC)Parser/

PATH_UTILS  = $(PATH_SRC)Utils/

PATH_LOADER =   $(PATH_UTILS)Loader/

PATH_COLOR  =   $(PATH_UTILS)Color/

PATH_POINT    =   $(PATH_UTILS)Points/

PATH_VECTOR    =   $(PATH_UTILS)Vectors/

PATH_EXCEPTION    =   $(PATH_UTILS)Exception/

PATH_PLUGINS    =   $(PATH_SRC)Plugins/

PATH_PRIMITIVES =   $(PATH_PLUGINS)Primitives/

PATH_SPHERE =   $(PATH_PRIMITIVES)Sphere/

PATH_CUBE =   $(PATH_PRIMITIVES)Cube/

all: generateSo core

generateSo:
	g++ -shared -fPIC -o ./plugins/raytracer_sphere.so $(PATH_SPHERE)*.cpp $(PATH_COLOR)*.cpp $(PATH_POINT)*.cpp $(PATH_VECTOR)*.cpp -fno-gnu-unique
	g++ -shared -fPIC -o ./plugins/raytracer_cube.so $(PATH_CUBE)*.cpp $(PATH_COLOR)*.cpp $(PATH_POINT)*.cpp $(PATH_VECTOR)*.cpp -fno-gnu-unique

core:
	g++ $(PATH_SRC)*.cpp $(PATH_PARSER)Parser.cpp $(PATH_EXCEPTION)*.cpp $(PATH_COLOR)*.cpp $(PATH_POINT)*.cpp $(PATH_VECTOR)*.cpp -ldl -o $(NAME) -fno-gnu-unique -lconfig++

clean:
	rm -f ./plugins/*.so

fclean: clean
	rm -rf $(NAME)

re: fclean all
