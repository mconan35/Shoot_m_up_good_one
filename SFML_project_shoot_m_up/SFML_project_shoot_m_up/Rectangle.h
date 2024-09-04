#pragma once

struct Rectangle2 {
    float x;       // Coordonn�e x du coin sup�rieur gauche
    float y;       // Coordonn�e y du coin sup�rieur gauche
    float width;   // Largeur du rectangle
    float height;  // Hauteur du rectangle

    Rectangle2() : x(0), y(0), width(0), height(0) {}
    Rectangle2(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

    void SetRectangle(float newX, float newY, float newWidth, float newHeight) {
        x = newX;
        y = newY;
        width = newWidth;
        height = newHeight;
    }

    // M�thode pour v�rifier si un point est � l'int�rieur du rectangle
    bool Contains(float px, float py) const {
        return (px >= x) && (px <= x + width) &&
            (py >= y) && (py <= y + height);
    }

    // M�thode pour v�rifier si ce rectangle intersecte un autre rectangle
    bool Intersects(const Rectangle2& other) const {
        return (x <= other.x + other.width) &&
            (x + width >= other.x) &&
            (y <= other.y + other.height) &&
            (y + height >= other.y);
    }
};
