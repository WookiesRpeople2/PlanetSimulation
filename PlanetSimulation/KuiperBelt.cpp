#include "KuiperBelt.h"

KuiperBelt::KuiperBelt(float innerRadius, float outerRadius, int numObjects)
    : m_innerRadius(innerRadius), m_outerRadius(outerRadius), m_objects(Points, numObjects),
    m_distances(numObjects), m_angles(numObjects)
{
    static const float centerX = 400.0f;
    static const float centerY = 300.0f;
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<float> dist(innerRadius, outerRadius);
    float deltaAngle = 2 * m_PI / numObjects;

    for (int i = 0; i < numObjects; ++i) {
        float distance = dist(gen);
        float angle = i * deltaAngle;

        m_distances[i] = distance;
        m_angles[i] = angle;

        float x = centerX + distance * cos(angle);
        float y = centerY + distance * sin(angle);

        m_objects[i].position = Vector2f(x, y);
        m_objects[i].color = Color(255, 255, 255, 50);
    }
}

void KuiperBelt::updateSegment(int start, int end, float deltaTime) {
    static const float centerX = 400.0f;
    static const float centerY = 300.0f;
    static const float angleSpeed = 0.000001f;

    for (int i = start; i < end; ++i) {
        m_angles[i] += angleSpeed * deltaTime;
        float distance = m_distances[i];
        float angle = m_angles[i];

        float x = centerX + distance * cos(angle);
        float y = centerY + distance * sin(angle);

        m_objects[i].position = Vector2f(x, y);
    }
}

void KuiperBelt::update(float deltaTime) {
    unsigned int numThreads = thread::hardware_concurrency();
    unsigned int vertexCount = m_objects.getVertexCount();
    vector<thread> threads;
    unsigned int segmentSize = (vertexCount + numThreads - 1) / numThreads;

    for (unsigned int i = 0; i < numThreads; ++i) {
        unsigned int start = i * segmentSize;
        unsigned int end = min((i + 1) * segmentSize, vertexCount);
        threads.emplace_back(&KuiperBelt::updateSegment, this, start, end, deltaTime);
    }

    for (auto& th : threads) {
        th.join();
    }
}

void KuiperBelt::draw(RenderWindow& window) const {
    window.draw(m_objects);
}