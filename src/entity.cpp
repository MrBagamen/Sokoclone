#include "entity.hpp"

Entity::Entity(const sf::Texture& texture, int x, int y) :
    x(x),
    y(y),
    tex(texture)
{
    w = tex.getSize().x;
    h = tex.getSize().y;
    rect[0] = -w / 2;
    rect[1] = -h / 2;
    rect[2] = w / 2;
    rect[3] = -h / 2;
    rect[4] = w / 2;
    rect[5] = h / 2;
    rect[6] = -w / 2;
    rect[7] = h / 2;
}

void Entity::Draw() const
{
    constexpr GLfloat texCoord[8] =
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };
    glPushMatrix();
    sf::Texture::bind(&tex);
    glTranslatef(x + (w / 2), y + (h / 2), 0.0f);
    glVertexPointer(2, GL_INT, 0, rect);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
    glDrawArrays(GL_QUADS, 0, 4);
    glPopMatrix();
}
