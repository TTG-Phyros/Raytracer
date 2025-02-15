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

## TREE CAMERA
PATH_CAMERA   = $(PATH_SRC)Camera/*.cpp
## END CAMERA

## TREE OUTPUT
PATH_OUTPUT =	$(PATH_SRC)Output/*.cpp
## END OUTPUT

## TREE PARSER
PATH_PARSER =	$(PATH_SRC)Parser/*.cpp
## END PARSER

## TREE PLUGINS
PATH_PLUGINS    =   $(PATH_SRC)Plugins/
## TREE DISPLAY
PATH_DISPLAY	=	$(PATH_PLUGINS)Display/
FLAGS_DISPLAY	=	-lsfml-graphics -lsfml-window -lsfml-system
## TREE SFML
PATH_SFML	=	$(PATH_DISPLAY)SFML/*.cpp
## END SFML
## END DISPLAY
## TREE LIGHTS
PATH_LIGHTS	=	$(PATH_PLUGINS)Lights/
## TREE DIRECTIONAL
PATH_DIRECTIONAL	=	$(PATH_LIGHTS)Directional/*.cpp
## END DIRECTIONAL
## END LIGHTS
## TREE LIGHTS
PATH_LIGHTS	=	$(PATH_PLUGINS)Lights/
## TREE DIRECTIONAL
PATH_DIRECTIONAL	=	$(PATH_LIGHTS)Directional/*.cpp
## END DIRECTIONAL
## END LIGHTS
## TREE PRIMITIVES
PATH_PRIMITIVES =   $(PATH_PLUGINS)Primitives/
## TREE SPHERE
PATH_SPHERE =   $(PATH_PRIMITIVES)Sphere/*.cpp
## END SPHERE

## TREE PLANE
PATH_PLANE =   $(PATH_PRIMITIVES)Planes/*.cpp
## END PLANE

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
	g++ -shared -fPIC -o ./plugins/raytracer_directional_light.so $(PATH_DIRECTIONAL) $(FLAGS_UTILS) -fno-gnu-unique
	g++ -shared -fPIC -o ./plugins/raytracer_sfml.so $(PATH_SFML) $(PATH_CAMERA) $(FLAGS_UTILS) $(FLAGS_DISPLAY) -fno-gnu-unique
	g++ -shared -fPIC -o ./plugins/raytracer_plane.so $(PATH_PLANE) $(FLAGS_UTILS) -fno-gnu-unique

core:
	g++ $(PATH_SRC)main.cpp $(PATH_PARSER) $(PATH_CAMERA) $(PATH_CORE) $(PATH_OUTPUT) $(FLAGS_UTILS) -ldl -o $(NAME) -fno-gnu-unique -lconfig++ -g3
	g++ $(PATH_SRC)main.cpp $(PATH_PARSER) $(PATH_CAMERA) $(PATH_CORE) $(PATH_OUTPUT) $(FLAGS_UTILS) -ldl -o $(NAME) -fno-gnu-unique -lconfig++ -g3

clean:
	rm -f ./plugins/*.so

fclean: clean
	rm -rf $(NAME)
	rm -rf html
	rm -rf latex

re: fclean all
