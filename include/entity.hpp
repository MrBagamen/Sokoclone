#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(const sf::Texture& texture, int x = 0, int y = 0);
    void Draw() const;
//protected:
    int x, y, w, h;
private:
    const sf::Texture& tex;
    GLint rect[8];
    friend class Map;
};

#endif // ENTITY_HPP
