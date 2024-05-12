/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-maxime.coustabeau
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../IDisplay.hpp"
#include "../../../Camera/Camera.hpp"

class Sfml : public IDisplay {
    public:
        Sfml();
        Sfml(int xSize, int ySize);
        void setPixel(int x, int y, double red, double green, double blue);
        void display();
        void clear();
        void close();
        bool isOpen();
        void move(Camera *camera);
        void setResolution(int xSize, int ySize);
        ~Sfml();

    protected:
    private:
        sf::RenderWindow _window;
        int _xSize;
        int _ySize;
};

#endif /* !SFML_HPP_ */
