/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#include "../include/Eiffel.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <cmath>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <thread>

Eiffel::Eiffel(Segment initSeg, sf::RenderWindow &win) : _segPrincipal(initSeg), _segPrinPerpendicular(0,0,0,0), _win(win)
{
}

Eiffel::~Eiffel()
{
}

void Eiffel::createCross()
{
    Segment temp(_segPrincipal);

    _segPrincipal.rotate90();
    _segPrinPerpendicular = _segPrincipal;
    _segPrincipal = temp;
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
        
        _segPrincipal._intersectionPoints.push_back(sf::Vector2f(x, y));
        
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


void Eiffel::createIntersections(int nbIntersects, Segment &seg)
{
    float step = 1.0f / (nbIntersects);

    for (int i = 1; i <= nbIntersects; ++i) {
        float t = step * i;
        float x = seg.getXStart() + t * (seg.getXEnd() - seg.getXStart());
        float y = seg.getYStart() + t * (seg.getYEnd() - seg.getYStart());
        
        seg._intersectionPoints.push_back(sf::Vector2f(x, y));
        
        sf::CircleShape intersectionCircle(4.f);
        intersectionCircle.setFillColor(sf::Color::Black);
        intersectionCircle.setPosition(x - intersectionCircle.getRadius(), y - intersectionCircle.getRadius());
        _win.draw(intersectionCircle);
    }

    sf::CircleShape startCircle(4.f);
    startCircle.setFillColor(sf::Color::Black);
    startCircle.setPosition(seg.getXStart() - startCircle.getRadius(), seg.getYStart() - startCircle.getRadius());
    _win.draw(startCircle);
    sf::CircleShape endCircle(4.f);
    endCircle.setFillColor(sf::Color::Black);
    endCircle.setPosition(seg.getXEnd() - endCircle.getRadius(), seg.getYEnd() - endCircle.getRadius());
    _win.draw(endCircle);
}

void Eiffel::createIntersectionsForCross(int nbIntersects)
{
    _nbIntersections = nbIntersects;

    float step = 1.0f / (nbIntersects);

    for (int i = 1; i <= nbIntersects; ++i) {
        float t = step * i;
        float xX = _segPrincipal.getXStart() + t * (_segPrincipal.getXEnd() - _segPrincipal.getXStart());
        float yX = _segPrincipal.getYStart() + t * (_segPrincipal.getYEnd() - _segPrincipal.getYStart());

        float xY = _segPrinPerpendicular.getXStart() + t * (_segPrinPerpendicular.getXEnd() - _segPrinPerpendicular.getXStart());
        float yY = _segPrinPerpendicular.getYStart() + t * (_segPrinPerpendicular.getYEnd() - _segPrinPerpendicular.getYStart());
        
        _segPrincipal._intersectionPoints.push_back(sf::Vector2f(xX, yX));
        _segPrinPerpendicular._intersectionPoints.push_back(sf::Vector2f(xY, yY));

        // std::cout << "oui   " << _segPrincipal._intersectionPoints[i].x << std::endl;
        // std::cout << "onon   " << _segPrinPerpendicular._intersectionPoints[i].x << std::endl;

        sf::CircleShape intersectionCircleX(4.f);
        sf::CircleShape intersectionCircleY(4.f);

        intersectionCircleX.setFillColor(sf::Color::Black);
        intersectionCircleX.setPosition(xX - intersectionCircleX.getRadius(), yX - intersectionCircleX.getRadius());
        // _win.draw(intersectionCircleX);

        intersectionCircleY.setFillColor(sf::Color::Black);
        intersectionCircleY.setPosition(xY - intersectionCircleX.getRadius(), yY - intersectionCircleX.getRadius());
        // _win.draw(intersectionCircleY);

    }

    sf::CircleShape startCircleX(4.f);
    startCircleX.setFillColor(sf::Color::Black);
    startCircleX.setPosition(_segPrincipal.getXStart() - startCircleX.getRadius(), _segPrincipal.getYStart() - startCircleX.getRadius());
    // _win.draw(startCircleX);
    
    sf::CircleShape endCircleX(4.f);
    endCircleX.setFillColor(sf::Color::Black);
    endCircleX.setPosition(_segPrincipal.getXEnd() - endCircleX.getRadius(), _segPrincipal.getYEnd() - endCircleX.getRadius());
    // _win.draw(endCircleX);


    sf::CircleShape startCircleY(4.f);
    startCircleY.setFillColor(sf::Color::Black);
    startCircleY.setPosition(_segPrinPerpendicular.getXStart() - startCircleY.getRadius(), _segPrinPerpendicular.getYStart() - startCircleY.getRadius());
    // _win.draw(startCircleY);
    
    sf::CircleShape endCircleY(4.f);
    endCircleY.setFillColor(sf::Color::Black);
    endCircleY.setPosition(_segPrinPerpendicular.getXEnd() - endCircleY.getRadius(), _segPrinPerpendicular.getYEnd() - endCircleY.getRadius());
    // _win.draw(endCircleY);
}



void Eiffel::createInterCross(int nbIntersects)
{
    createIntersections(nbIntersects, _segPrincipal);
    createIntersections(nbIntersects, _segPrinPerpendicular);
}


void Eiffel::drawEiffel()
{
    // int limit = 0;
    std::vector<sf::Vector2f> segPrinIts = _segPrincipal._intersectionPoints;
    // std::vector<sf::Vector2f> segPrinItsHalf(segPrinIts.begin(), segPrinIts.begin() + segPrinIts.size() / 2);

    std::vector<sf::Vector2f> segPerpIts = _segPrinPerpendicular._intersectionPoints;
    // std::vector<sf::Vector2f> segPerpItsHalf(segPerpIts.begin(), segPerpIts.begin() + segPerpIts.size() / 2);

    // if (_nbIntersections % 2 != 0)
    //     limit = (_nbIntersections - 1) / 2;
    // else
    //     limit = _nbIntersections / 2;
    // int y = _nbIntersections / 2;
    // int y2 = y;

    // int l1 = _nbIntersections * 2;
    // int l2 = segPerpIts.size();

    // for (int i = -1; i != limit ; i++) {
    //     // std::cout << "x = " <<segPerpIts[l1].x << "    y = " << segPerpIts[l1].y << std::endl;
    //     Segment tempSeg(segPrinItsHalf[i], segPerpItsHalf[y]);
    //     tempSeg.drawSeg(_win);
    //     y--;
    // }

    int numConnections = std::min(segPrinIts.size(), segPerpIts.size() / 2); // Nombre de connexions possibles

    for (int i = 0; i < numConnections; ++i) {
        // Point d'extrémité du segment principal
        sf::Vector2f pointA = segPrinIts[i];

        // Point de la perpendiculaire (avant le centre)
        sf::Vector2f pointB = segPerpIts[segPerpIts.size() / 2 - 1 - i];

        // Dessiner une ligne entre pointA et pointB
        sf::Vertex line[] = {
            sf::Vertex(pointA, sf::Color::Black),
            sf::Vertex(pointB, sf::Color::Black)
        };
        _win.draw(line, 2, sf::Lines);
    }
}
