/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#include "../include/Eiffel.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

Eiffel::Eiffel(Segment initSeg, sf::RenderWindow &win) : _segPrincipal(initSeg), _segPrinPerpendicular(0,0,0,0), _win(win)
{
}

Eiffel::~Eiffel()
{
}

void Eiffel::createCross()
{
    float centerX = (_segPrincipal.getXStart() + _segPrincipal.getXEnd()) / 2;
    float centerY = (_segPrincipal.getYStart() + _segPrincipal.getYEnd()) / 2;

    float dx = (_segPrincipal.getXEnd() - _segPrincipal.getXStart()) / 2;
    float dy = (_segPrincipal.getYEnd() - _segPrincipal.getYEnd()) / 2;

    float perpStartX = centerX - dy;
    float perpStartY = centerY + dx;
    float perpEndX = centerX + dy;
    float perpEndY = centerY - dx;

    Segment newSeg(perpStartX, perpStartY, perpEndX, perpEndY);

    _segPrinPerpendicular = newSeg;
}

float Eiffel::getIntersectSize() const
{
    return (_segmentSize / _nbIntersections);
}

void Eiffel::drawCross()
{
    if (_segPrinPerpendicular.isNull())
        createCross();
    else {
        _segPrincipal.drawSeg(_win);
        _segPrinPerpendicular.drawSeg(_win);
    }
}

void Eiffel::createIntersections(int nbIntersects)
{
    float step = 1.0f / (nbIntersects);

    for (int i = 1; i <= nbIntersects; ++i) {
        float t = step * i;
        float x = _segPrincipal.getXStart() + t * (_segPrincipal.getXEnd() - _segPrincipal.getXStart());
        float y = _segPrincipal.getYStart() + t * (_segPrincipal.getYEnd() - _segPrincipal.getYStart());
        sf::CircleShape intersectionCircle(4.f);
        intersectionCircle.setFillColor(sf::Color::Black);
        intersectionCircle.setPosition(x - intersectionCircle.getRadius(), y - intersectionCircle.getRadius());
        _win.draw(intersectionCircle);
    }

    sf::CircleShape startCircle(4.f);
    startCircle.setFillColor(sf::Color::Black);
    startCircle.setPosition(_segPrincipal.getXStart() - startCircle.getRadius(), _segPrincipal.getYStart() - startCircle.getRadius());
    _win.draw(startCircle);
    sf::CircleShape endCircle(4.f);
    endCircle.setFillColor(sf::Color::Black);
    endCircle.setPosition(_segPrincipal.getXEnd() - endCircle.getRadius(), _segPrincipal.getYEnd() - endCircle.getRadius());
    _win.draw(endCircle);
}


void Eiffel::createIntersectionsForCross(int nbIntersects)
{
    float step = 1.0f / (nbIntersects);

    for (int i = 1; i <= nbIntersects; ++i) {
        float t = step * i;
        float xX = _segPrincipal.getXStart() + t * (_segPrincipal.getXEnd() - _segPrincipal.getXStart());
        float yX = _segPrincipal.getYStart() + t * (_segPrincipal.getYEnd() - _segPrincipal.getYStart());

        float xY = _segPrinPerpendicular.getXStart() + t * (_segPrinPerpendicular.getXEnd() - _segPrinPerpendicular.getXStart());
        float yY = _segPrinPerpendicular.getYStart() + t * (_segPrinPerpendicular.getYEnd() - _segPrinPerpendicular.getYStart());
        
        sf::CircleShape intersectionCircleX(4.f);
        sf::CircleShape intersectionCircleY(4.f);

        intersectionCircleX.setFillColor(sf::Color::Black);
        intersectionCircleX.setPosition(xX - intersectionCircleX.getRadius(), yX - intersectionCircleX.getRadius());
        _win.draw(intersectionCircleX);

        intersectionCircleY.setFillColor(sf::Color::Black);
        intersectionCircleY.setPosition(xY - intersectionCircleX.getRadius(), yY - intersectionCircleX.getRadius());
        _win.draw(intersectionCircleY);

    }

    sf::CircleShape startCircleX(4.f);
    startCircleX.setFillColor(sf::Color::Black);
    startCircleX.setPosition(_segPrincipal.getXStart() - startCircleX.getRadius(), _segPrincipal.getYStart() - startCircleX.getRadius());
    _win.draw(startCircleX);
    sf::CircleShape endCircleX(4.f);
    endCircleX.setFillColor(sf::Color::Black);
    endCircleX.setPosition(_segPrincipal.getXEnd() - endCircleX.getRadius(), _segPrincipal.getYEnd() - endCircleX.getRadius());
    _win.draw(endCircleX);


    sf::CircleShape startCircleY(4.f);
    startCircleY.setFillColor(sf::Color::Black);
    startCircleY.setPosition(_segPrinPerpendicular.getXStart() - startCircleY.getRadius(), _segPrinPerpendicular.getYStart() - startCircleY.getRadius());
    _win.draw(startCircleY);
    sf::CircleShape endCircleY(4.f);
    endCircleY.setFillColor(sf::Color::Black);
    endCircleY.setPosition(_segPrinPerpendicular.getXEnd() - endCircleY.getRadius(), _segPrinPerpendicular.getYEnd() - endCircleY.getRadius());
    _win.draw(endCircleY);
}