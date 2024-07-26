#include "Planet.h"
#include <cmath>

Planet::Planet(const string& name, float radius, float distance, float orbitalSpeed, Color color, int numOfRings)
    :m_name(name), m_radius(radius), m_distance(distance), m_orbitalSpeed(orbitalSpeed), m_angle(0.0f), m_numOfRings(numOfRings)
{
    m_shape.setRadius(m_radius);
    m_shape.setFillColor(color);
    m_shape.setOrigin(m_radius, m_radius);

    m_orbit.setRadius(m_distance);
    m_orbit.setPointCount(100);
    m_orbit.setOrigin(m_distance, m_distance);
    m_orbit.setPosition(400, 300);
    m_orbit.setFillColor(Color::Transparent);
    m_orbit.setOutlineColor(Color(255, 255, 255, 50));
    m_orbit.setOutlineThickness(1);

    if (m_numOfRings > 0) {
        for (int i = 0; i < m_numOfRings; i++) {
            CircleShape ring;
            float ringRadius = m_radius + (20.0f * (i + 1));
            ring.setRadius(ringRadius);
            ring.setFillColor(Color::Transparent);
            ring.setOutlineColor(Color(255, 255, 255, 50));
            ring.setPointCount(100);
            ring.setOrigin(ringRadius, ringRadius);
            ring.setOutlineThickness(1);
            m_ringSystem.push_back(ring);
        }
    }
}


void Planet::update(float deltaTime) {
    m_angle += m_orbitalSpeed * deltaTime;
    float x = m_distance * cos(m_angle);
    float y = m_distance * sin(m_angle);
    m_shape.setPosition(400 + x, 300 + y);

    for (auto& ring : m_ringSystem) {
        ring.setPosition(m_shape.getPosition());
    }
    
}

void Planet::draw(RenderWindow& window) const {
    window.draw(m_shape);
    window.draw(m_orbit);

    for (const auto& ring : m_ringSystem) {
        window.draw(ring);
    }

    TextField textFiled = TextField(m_name, Vector2f(m_shape.getPosition().x + m_radius + 5, m_shape.getPosition().y), 12, Color::White);
    Text text = textFiled.getTextField();
    window.draw(text);
}


float Planet::getSize() const
{
    return m_shape.getRadius();
}

