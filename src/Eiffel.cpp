/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#include "../include/Eiffel.hpp"
#include <SFML/System/Vector2.hpp>

Eiffel::Eiffel(sf::Vector2f start, sf::Vector2f end)
{
    _xStart = start.x;
    _yStart = start.y;

    _xEnd = end.x;
    _yEnd = end.y;
}

Eiffel::~Eiffel()
{
}


sf::Vector2f Eiffel::getStart() const
{
    return (sf::Vector2f(_xStart, _yStart));
}


sf::Vector2f Eiffel::getEnd() const
{
    return (sf::Vector2f(_xEnd, _yEnd));
}
