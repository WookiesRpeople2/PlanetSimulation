#include "TextField.h"

TextField::TextField(const string& text, Vector2f pos, int size, Color color): m_text(text), m_pos(pos), m_size(size), m_color(color)
{
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        return;
    }
    textField.setString(m_text);
    textField.setFont(font);
    textField.setCharacterSize(m_size);
    textField.setFillColor(m_color);
    textField.setPosition(pos);
}

Text TextField::getTextField() const
{
    return textField;
}
