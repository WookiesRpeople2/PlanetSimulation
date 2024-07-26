#include <SFML/Graphics.hpp>
#include "SolarSystem.h"
#include "Events.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode::getDesktopMode(), "Solar System Simulation");

    SolarSystem solarSystem;
    Clock clock;
    View view = window.getView();
    Events events;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
            case Event::MouseWheelScrolled:
                events.handleMouseScroll(event.mouseWheelScroll, view);
                break;
            case Event::MouseButtonPressed:
                events.handleMouseButtonPressed(event.mouseButton);
                break;
            case Event::MouseButtonReleased:
                events.handleMouseButtonReleased(event.mouseButton);
                break;
            case Event::MouseMoved:
                events.handleMouseMoved(event.mouseMove, view);
                break;
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }


        window.setView(view);

        float deltaTime = 100.0f;

        solarSystem.update(deltaTime);

        window.clear();
        solarSystem.draw(window);
        window.display();
    }

    return 0;
}
