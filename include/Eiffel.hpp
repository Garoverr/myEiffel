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
        Eiffel(Segment initSeg);
        ~Eiffel();


        void createCross();
        
        float getIntersectNB() const;
        std::vector<float> getIntersectionsArr() const;
        float getSegSize() const;

        // taille d'une intersection
        float getIntersectSize() const;

        Segment _segPrincipal;
        Segment _segPrinPerpendicular;


    private:
        // Segment _segY;

        int _nbIntersections;
        std::vector<float> _intersections;

        float _segmentSize;

};
