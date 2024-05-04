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

PATH_PLUGINS    =   $(PATH_SRC)Plugins/

PATH_PRIMITIVES =   $(PATH_PLUGINS)Primitives/

PATH_SPHERE =   $(PATH_PRIMITIVES)Sphere/

all: plugins core

plugins:
	g++ -shared -fPIC -o ./plugins/sphere.so $(PATH_SPHERE)*.cpp -fno-gnu-unique

core:
	g++ $(PATH_CORE)*.cpp -ldl -o $(NAME) -fno-gnu-unique

clean:
	rm -f ./plugins/*.so

fclean: clean
	rm -rf $(NAME)

re: fclean all
