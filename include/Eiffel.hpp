/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#pragma once
#include "Segment.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
class Eiffel {
    public:
        Eiffel(Segment initSeg, sf::RenderWindow &win);
        ~Eiffel();


        void createCross();
        void createIntersections(int nbIntersects);
        void createIntersections(int nbIntersects, Segment &seg);

        void createIntersectionsForCross(int nbIntersects);
        void createInterCross(int nbIntersects);

        
        float getIntersectNB() const;
        std::vector<float> getIntersectionsArr() const;
        float getSegSize() const;

        float getIntersectSize() const;

        void drawCross();

        void drawEiffel();

        Segment _segPrincipal;
        Segment _segPrinPerpendicular;


    private:
        sf::RenderWindow & _win;
        int _nbIntersections;
        std::vector<float> _intersections;

        float _segmentSize;

};
