/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Eiffel
*/

#pragma once
#include "Segment.hpp"
#include <SFML/System/Vector2.hpp>
#include <vector>
class Eiffel {
    public:
        Eiffel();
        ~Eiffel();

        
        float getIntersectNB() const;
        std::vector<float> getIntersectionsArr() const;
        float getSegSize() const;

        // taille d'une intersection
        float getIntersectSize() const {return (_segmentSize / _nbIntersections);}

    private:
        // Segment _segX;
        // Segment _segY;

        int _nbIntersections;
        std::vector<float> _intersections;

        float _segmentSize;

};
