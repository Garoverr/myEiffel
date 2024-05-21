/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#include "../include/Eiffel.hpp"
#include <SFML/System/Vector2.hpp>

Eiffel::Eiffel(Segment initSeg) : _segPrincipal(initSeg), _segPrinPerpendicular(0,0,0,0)
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