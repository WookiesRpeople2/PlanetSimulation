#include "SolarSystem.h"

SolarSystem::SolarSystem() {
    // distance from the sun 10 to the power of 6
    m_planets.emplace_back("Sun", 10.0f, 0.0f, 0.0000f, sf::Color(255, 255, 0));
    float x = m_planets.back().getSize();
    m_planets.emplace_back("Mercury", 10.0f, x + 57.9f, 0.0001f, sf::Color(139, 69, 19));
    m_planets.emplace_back("Venus", 12.0f, x + 108.2f, 0.00007f, sf::Color(255, 215, 0));
    m_planets.emplace_back("Earth",13.0f, x + 149.6f, 0.00005f, sf::Color(0, 191, 255));
    m_planets.emplace_back("Mars", 7.0f, x + 228.0, 0.00003f, sf::Color(255, 0, 0));
    m_planets.emplace_back("Jupiter", 15.0f, x + 778.5, 0.00002f, sf::Color(255, 165, 0), 3);
    m_planets.emplace_back("Saturn", 13.0f, x + 1432.0, 0.00001f, sf::Color(255, 255, 0), 7);
    m_planets.emplace_back("Uranus", 10.0f, x + 2867.0, 0.000007f, sf::Color(0, 255, 255), 13);
    m_planets.emplace_back("Neptune", 10.0f, x + 4515.0, 0.000005f, sf::Color(0, 0, 255), 5);
    m_kuiperBelt = std::make_unique<KuiperBelt>(4700.0f, 5000.0f, 10000);
}

void SolarSystem::update(float deltaTime) {
    for (auto& planet : m_planets) {
        planet.update(deltaTime);
    }

    m_kuiperBelt->update(deltaTime);
}

void SolarSystem::draw(RenderWindow& window) const {
    for (const auto& planet : m_planets) {
        planet.draw(window);
    }
    m_kuiperBelt->draw(window);
}
