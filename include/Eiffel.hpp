/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
class Eiffel {
    public:
        Eiffel(sf::Vector2f start,  sf::Vector2f end);
        ~Eiffel();

        sf::Vector2f getStart() const;
        sf::Vector2f getEnd() const;
        
        
        float getXS() const;
        float getXE() const;
        float getYS() const;
        float getYE() const;
        
        float getIntersectNB() const;
        std::vector<float> getIntersectionsArr() const;
        float getSegSize() const;

        // taille d'une intersection
        float getIntersectSize() const {return (_segmentSize / _nbIntersections);}

    private:
        float _xStart;
        float _yStart;

        float _xEnd;
        float _yEnd;

        int _nbIntersections;
        std::vector<float> _intersections;

        float _segmentSize;

};
