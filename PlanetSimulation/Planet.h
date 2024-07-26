#ifndef PLANET_HPP
#define PLANET_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "TextField.h"
using namespace std;
using namespace sf;

class Planet {
public:
    Planet(const string& name, float radius, float distance, float orbitalSpeed, Color color, int numOfRings = 0);

    void update(float deltaTime);
    void draw(RenderWindow& window) const;
    float getSize() const;

    

private:
    string m_name;
    float m_radius;
    float m_distance;
    float m_orbitalSpeed;
    float m_angle;
    int m_numOfRings;
    vector<CircleShape> m_ringSystem;

    CircleShape m_shape;
    CircleShape m_orbit;
};



#endif // PLANET_HPP