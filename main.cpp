/*
** PERSO PROJECT, 2024
** myEiffel
** File description:
** main
*/

#include "include/Eiffel.hpp"
#include "include/Segment.hpp"
#include <SFML/Window.hpp>
#include <iostream>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Cross with Circles");
    
    sf::Vector2f horizontalStart(800.f, 400.f);
    sf::Vector2f horizontalEnd(100.f, 700.f);

    Segment seg1(horizontalStart, horizontalEnd);
    Segment sex(400, 200, 200, 200);

    Eiffel newEiff(seg1, window);
    newEiff.createCross();
    newEiff.createIntersectionsForCross(110);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
       
        window.clear(sf::Color::White);
        newEiff.drawCross();
        newEiff.drawEiffel();
        window.display();
        }
    }


    std::vector<sf::Vector2f> points = newEiff._segPrinPerpendicular._intersectionPoints;
    std::vector<sf::Vector2f> points1 = newEiff._segPrincipal._intersectionPoints;

    int i = 0;
    for (const auto& point : points) {
    std::cout << "Point1: " << i << " (X= " << points1[i].x << ",Y= " << points1[i].y << ")\n";
    
    std::cout << "Point: " << i << " (X= " << point.x << ",Y= " << point.y << ")\n";
    i++;
    }
    return 0;
}

