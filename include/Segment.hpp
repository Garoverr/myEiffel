/*
** EPITECH PROJECT, 2024
** myEiffel
** File description:
** Segment
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Segment {
    
    public:
    
        Segment(sf::Vector2f start, sf::Vector2f end);
        Segment(Segment &other);
        Segment(float xS, float yS, float xE, float yE);
        ~Segment();

        sf::Vector2f getStart() const;
        sf::Vector2f getEnd() const;

        float getXStart() const;
        float getYStart() const;
        float getXEnd() const;
        float getYEnd() const;

        std::vector<sf::Vector2f> getIntersectionsArr() const;
        void setIntersectionsArr(std::vector<sf::Vector2f> points);

        void drawSeg(sf::RenderWindow &win);
        void rotate90();


        Segment& operator=(const Segment &other);

        bool isNull() const;
        bool operator==(const Segment &other);

        std::vector<sf::Vector2f> _intersectionPoints;
    
    private:
        
        float _xStart;
        float _yStart;

        float _xEnd;
        float _yEnd;

};
