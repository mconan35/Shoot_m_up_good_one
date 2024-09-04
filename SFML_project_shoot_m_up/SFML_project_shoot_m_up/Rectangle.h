#pragma once

struct Rectangle2 {
    float x;       // Coordonnée x du coin supérieur gauche
    float y;       // Coordonnée y du coin supérieur gauche
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

    // Méthode pour vérifier si un point est à l'intérieur du rectangle
    bool Contains(float px, float py) const {
        return (px >= x) && (px <= x + width) &&
            (py >= y) && (py <= y + height);
    }

    // Méthode pour vérifier si ce rectangle intersecte un autre rectangle
    bool Intersects(const Rectangle2& other) const {
        return (x <= other.x + other.width) &&
            (x + width >= other.x) &&
            (y <= other.y + other.height) &&
            (y + height >= other.y);
    }
};
