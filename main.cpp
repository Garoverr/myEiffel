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
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void myDrawer(sf::RenderWindow &window)
{

    sf::Vector2f newLineStart(533.333, 300.f);
    sf::Vector2f newLineEnd(400.f, 433.333);
    Segment seg1(newLineStart, newLineEnd);


    sf::Vector2f newLineStart1(600.f, 300.f);
    sf::Vector2f newLineEnd1(400.f, 366.666);


    sf::Vector2f newLineStart2(466.666, 300.f);
    sf::Vector2f newLineEnd2(400.f, 500.f);


    sf::Vector2f horizontalStart(200.f, 300.f);
    sf::Vector2f horizontalEnd(600.f, 300.f);
    sf::Vector2f verticalStart(400.f, 100.f);
    sf::Vector2f verticalEnd(400.f, 500.f);
    sf::Color segmentColor = sf::Color::Red;

    float horizontalSegmentLength = horizontalEnd.x - horizontalStart.x;
    float verticalSegmentLength = verticalEnd.y - verticalStart.y;
    int numSegments = 6;
    float horizontalSegmentWidth = horizontalSegmentLength / numSegments;
    float verticalSegmentWidth = verticalSegmentLength / numSegments;

    sf::VertexArray horizontalSegment(sf::LinesStrip, 2);
        horizontalSegment[0].position = horizontalStart;
        horizontalSegment[0].color = segmentColor;
        horizontalSegment[1].position = horizontalEnd;
        horizontalSegment[1].color = segmentColor;

        window.draw(horizontalSegment);

    sf::VertexArray verticalSegment(sf::LinesStrip, 2);
        verticalSegment[0].position = verticalStart;
        verticalSegment[0].color = segmentColor;
        verticalSegment[1].position = verticalEnd;
        verticalSegment[1].color = segmentColor;

    sf::VertexArray newSef(sf::LinesStrip, 2);
        newSef[0].position = newLineStart;
        newSef[0].color = sf::Color::Blue;
        newSef[1].position = newLineEnd;
        newSef[1].color = sf::Color::Red;

        window.draw(newSef);



    sf::VertexArray newSef2(sf::LinesStrip, 2);
        newSef2[0].position = newLineStart1;
        newSef2[0].color = sf::Color::Blue;
        newSef2[1].position = newLineEnd1;
        newSef2[1].color = sf::Color::Red;

        window.draw(newSef2);




    sf::VertexArray newSef3(sf::LinesStrip, 2);
        newSef3[0].position = newLineStart2;
        newSef3[0].color = sf::Color::Blue;
        newSef3[1].position = newLineEnd2;
        newSef3[1].color = sf::Color::Red;

        window.draw(newSef3);



        window.draw(verticalSegment);

        for (int i = 0; i <= numSegments; ++i) {
            sf::CircleShape horizontalCircle(4.f);
            horizontalCircle.setFillColor(sf::Color::Black);
            // printf("horizonX : %f, horizonY : %f\n", (horizontalStart.x + i * horizontalSegmentWidth), horizontalStart.y);
            horizontalCircle.setPosition(horizontalStart.x + i * horizontalSegmentWidth - horizontalCircle.getRadius(), horizontalStart.y - horizontalCircle.getRadius());
            window.draw(horizontalCircle);

            sf::CircleShape verticalCircle(4.f);
            // printf("verticaX : %f, verticaY : %f\n", verticalStart.x, (verticalStart.y + i * verticalSegmentWidth));
            verticalCircle.setFillColor(sf::Color::Black);
            verticalCircle.setPosition(verticalStart.x - verticalCircle.getRadius(), verticalStart.y + i * verticalSegmentWidth - verticalCircle.getRadius());
            window.draw(verticalCircle);
        }
}



int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Cross with Circles");
    
    sf::Vector2f horizontalStart(200.f, 300.f);
    sf::Vector2f horizontalEnd(600.f, 300.f);

    sf::Vector2f verticalStart(400.f, 100.f);
    sf::Vector2f verticalEnd(400.f, 500.f);

    Segment seg1(horizontalStart, horizontalEnd);

    Segment seg2(verticalStart, verticalEnd);

    Segment seg3(533.333, 300.f, 400.f, 433.333);

    seg3.rotate90();

    Segment seg4 = seg3;

    seg3.rotate90();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        seg1.drawSeg(window);
        seg2.drawSeg(window);
        seg3.drawSeg(window);
        seg4.drawSeg(window);
        // myDrawer(window);
        window.display();
    }

    return 0;
}

