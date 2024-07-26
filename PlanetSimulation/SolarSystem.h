#ifndef SOLARSYSTEM_HPP
#define SOLARSYSTEM_HPP

#include <vector>
#include "KuiperBelt.h"
#include "Planet.h"
using namespace std;
using namespace sf;

class SolarSystem {
public:
    SolarSystem();

    void update(float deltaTime);
    void draw(RenderWindow& window) const;

private:
    vector<Planet> m_planets;
    unique_ptr<KuiperBelt> m_kuiperBelt;
};

#endif // SOLARSYSTEM_HPP
