##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## RayTracer
##

NAME    =   raytracer

CPPFLAGS    =   -std=c++20 -W -Wall -Wextra

## TREE SRC
PATH_SRC    =   ./src/

## TREE CORE
PATH_CORE   = $(PATH_SRC)Core/*.cpp
## END CORE

## TREE OUTPUT
PATH_OUTPUT =	$(PATH_SRC)Output/*.cpp
## END OUTPUT

## TREE PARSER
PATH_PARSER =	$(PATH_SRC)Parser/*.cpp
## END PARSER

## TREE PLUGINS
PATH_PLUGINS    =   $(PATH_SRC)Plugins/
## TREE PRIMITIVES
PATH_PRIMITIVES =   $(PATH_PLUGINS)Primitives/
## TREE SPHERE
PATH_SPHERE =   $(PATH_PRIMITIVES)Sphere/*.cpp
## END SPHERE
## TREE CUBE
PATH_CUBE =   $(PATH_PRIMITIVES)Cube/*.cpp
## END CUBE
## END PRIMITIVES
## END PLUGINS

## TREE UTILS
FLAGS_UTILS	=	$(PATH_COLOR) $(PATH_EXCEPTION) $(PATH_POINT) $(PATH_RAY) $(PATH_VECTOR)
PATH_UTILS  = $(PATH_SRC)Utils/
## TREE COLOR
PATH_COLOR  =   $(PATH_UTILS)Color/*.cpp
## END COLOR
## TREE EXCEPTION
PATH_EXCEPTION	=	$(PATH_UTILS)Exception/*.cpp
## END EXCEPTION
## TREE POINT
PATH_POINT	=	$(PATH_UTILS)Point/*.cpp
## END POINT
## TREE VECTOR
PATH_RAY	=	$(PATH_UTILS)Ray/*.cpp
## END VECTOR
## TREE VECTOR
PATH_VECTOR	=	$(PATH_UTILS)Vector/*.cpp
## END VECTOR
## END UTILS

##END SRC

all: generateSo core

generateSo:
	g++ -shared -fPIC -o ./plugins/raytracer_sphere.so $(PATH_SPHERE) $(FLAGS_UTILS) -fno-gnu-unique
	g++ -shared -fPIC -o ./plugins/raytracer_cube.so $(PATH_CUBE) $(FLAGS_UTILS) -fno-gnu-unique

core:
	g++ $(PATH_SRC)main.cpp $(PATH_PARSER) $(PATH_CORE) $(PATH_OUTPUT) $(FLAGS_UTILS) -ldl -o $(NAME) -fno-gnu-unique -lconfig++

clean:
	rm -f ./plugins/*.so

fclean: clean
	rm -rf $(NAME)

re: fclean all
