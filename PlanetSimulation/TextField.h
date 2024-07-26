#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class TextField
{
public:
	TextField(const string& text, Vector2f pos, int size, Color color);
	Text getTextField() const;

private:
	Font font;
	Text textField;
	string m_text;
	Vector2f m_pos;
	int m_size;
	Color m_color;

};

#endif //TEXT_HPP


//Font font;
//if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
//    return;
//}
//Text text;
//text.setString(m_name);
//text.setFont(font);
//text.setCharacterSize(12);
//text.setFillColor(sf::Color::White);
//text.setPosition(m_shape.getPosition().x + m_radius + 5, m_shape.getPosition().y);