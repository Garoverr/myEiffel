/*
** PERSO PROJECT, 2024
** myEiffel
** File description:
** main
*/
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void myDrawer(sf::RenderWindow &window)
{
    sf::Vector2f horizontalStart(200.f, 300.f);
    sf::Vector2f horizontalEnd(600.f, 300.f);
    sf::Vector2f verticalStart(400.f, 100.f);
    sf::Vector2f verticalEnd(400.f, 500.f);
    sf::Color segmentColor = sf::Color::Red;

    float horizontalSegmentLength = horizontalEnd.x - horizontalStart.x;
    float verticalSegmentLength = verticalEnd.y - verticalStart.y;
    int numSegments = 5;
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

        window.draw(verticalSegment);

        for (int i = 0; i <= numSegments; ++i) {
            sf::CircleShape horizontalCircle(5.f);
            horizontalCircle.setFillColor(sf::Color::Black);
            horizontalCircle.setPosition(horizontalStart.x + i * horizontalSegmentWidth - horizontalCircle.getRadius(), horizontalStart.y - horizontalCircle.getRadius());
            window.draw(horizontalCircle);

            sf::CircleShape verticalCircle(5.f);
            verticalCircle.setFillColor(sf::Color::Black);
            verticalCircle.setPosition(verticalStart.x - verticalCircle.getRadius(), verticalStart.y + i * verticalSegmentWidth - verticalCircle.getRadius());
            window.draw(verticalCircle);
        }
}



int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Cross with Circles");

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        myDrawer(window);
        window.display();
    }

    return 0;
}

