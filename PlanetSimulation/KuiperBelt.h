#ifndef KUIPERBELT_HPP
#define KUIPERBELT_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <thread>
#include <random>
using namespace std;
using namespace sf;

class KuiperBelt
{
public:
    KuiperBelt(float innerRadius, float outerRadius, int numObjects);

    void update(float deltaTime);
    void draw(RenderWindow& window) const;

private:
    void updateSegment(int start, int end, float deltaTime);

    VertexArray m_objects;
    vector<float> m_angles;
    vector<float> m_distances;
    float m_innerRadius;
    float m_outerRadius;
    long float m_PI = 3.14159265358979323846f;
};

#endif //KUIPERBELT_HPP