#include "Events.h"

void Events::handleMouseScroll(const Event::MouseWheelScrollEvent& event, View& view) {
    Vector2f viewportSize = view.getSize();
    if (event.delta > 0) {
        view.setSize(viewportSize * 0.9f); // Zoom in
    }
    else if (event.delta < 0) {
        view.setSize(viewportSize * 1.1f); // Zoom out
    }
}

void Events::handleMouseButtonPressed(const Event::MouseButtonEvent& event) {
    if (event.button == Mouse::Left) {
        isDragging = true;
        initialMousePosition = Vector2f(event.x, event.y);
    }
}

void Events::handleMouseButtonReleased(const Event::MouseButtonEvent& event) {
    if (event.button == Mouse::Left) {
        isDragging = false;
    }
}

void Events::handleMouseMoved(const Event::MouseMoveEvent& event, View& view) {
    if (isDragging) {
        Vector2f newMousePosition(event.x, event.y);
        Vector2f delta = initialMousePosition - newMousePosition;
        view.move(delta);
        initialMousePosition = newMousePosition;
    }
}
