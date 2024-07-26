#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Events
{
public:
    void handleMouseScroll(const Event::MouseWheelScrollEvent& event, View& view);
    void handleMouseButtonPressed(const Event::MouseButtonEvent& event);
    void handleMouseButtonReleased(const Event::MouseButtonEvent& event);
    void handleMouseMoved(const Event::MouseMoveEvent& event, View& view);

private:
    bool isDragging = false;
    Vector2f initialMousePosition;
    Vector2f initialViewCenter;
};

#endif // EVENTS_HPP
