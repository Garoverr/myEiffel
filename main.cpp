/*
** PERSO PROJECT, 2024
** myEiffel
** File description:
** main
*/

#include "include/Eiffel.hpp"
#include "include/Segment.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <thread>
#include <chrono>



int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Cross with Circles");
    
    sf::Vector2f horizontalStart(200.f, 300.f);
    sf::Vector2f horizontalEnd(600.f, 300.f);

    Segment seg1(horizontalStart, horizontalEnd);
    Segment sex(400, 200, 200, 200);

    Eiffel newEiff(seg1, window);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
       
        window.clear(sf::Color::White);
        newEiff.createCross();
        newEiff.createIntersectionsForCross(5); // si je retire ici, qui fait la meme chose que au dessus, ça crash..
        newEiff.drawCross();
        newEiff.drawEiffel();
        window.display();
        }
    }

    // newEiff.createCross();
    // newEiff.createIntersectionsForCross(4);

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

