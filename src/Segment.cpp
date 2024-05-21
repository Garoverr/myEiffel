/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Segment
*/

#include "../include/Segment.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

Segment::Segment(sf::Vector2f start, sf::Vector2f end)
{
    _xStart = start.x;
    _yStart = start.y;

    _xEnd = end.x;
    _yEnd = end.y;
}


Segment::Segment(float xS, float yS, float xE, float yE)
{
    _xStart = xS;
    _yStart = yS;
    _xEnd = xE;
    _yEnd = yE;
}


Segment::~Segment()
{
}


sf::Vector2f Segment::getStart() const
{
    return (sf::Vector2f(_xStart, _yStart));
}


sf::Vector2f Segment::getEnd() const
{
    return (sf::Vector2f(_xEnd, _yEnd));
}


float Segment::getXStart() const
{
    return (_xStart);
}   

float Segment::getYStart() const
{
    return (_yStart);
}

float Segment::getXEnd() const
{
    return (_xEnd);
}

float Segment::getYEnd() const
{
    return (_yEnd);
}


Segment &Segment::operator=(const Segment &other)
{
    if (this == &other)
        return (*this);
    _xStart = other._xStart;
    _yStart = other._yStart;
    _xEnd = other._xEnd;
    _yEnd = other._yEnd;

    return (*this);
}


void Segment::drawSeg(sf::RenderWindow &win)
{
    sf::VertexArray line(sf::LinesStrip, 2);
    
    sf::Vector2f segStart = sf::Vector2f(_xStart, _yStart);
    sf::Vector2f segEnd = sf::Vector2f(_xEnd, _yEnd);

    sf::Color segColor = sf::Color::Black;

    line[0].position = segStart;
    line[1].position = segEnd;
    line[0].color = segColor;
    line[1].color = segColor;

    win.draw(line);
}


void Segment::rotate90()
{
    float centerX = (_xStart + _xEnd) / 2;
    float centerY = (_yStart + _yEnd) / 2;

    // Translation des points
    float startX = _xStart - centerX;
    float startY = _yStart - centerY;
    float endX = _xEnd - centerX;
    float endY = _yEnd - centerY;

    float rotatedStartX = -startY;
    float rotatedStartY = startX;
    float rotatedEndX = -endY;
    float rotatedEndY = endX;

    _xStart = rotatedStartX + centerX;
    _yStart = rotatedStartY + centerY;
    _xEnd = rotatedEndX + centerX;
    _yEnd = rotatedEndY + centerY;
}
