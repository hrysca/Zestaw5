#include "Figure.h"
#include <cmath>

// Implementacja klasy Rectangle
Rectangle::Rectangle(int x, int y, int width, int height, char symbol)
    : x(x), y(y), width(width), height(height), symbol(symbol) {}

void Rectangle::draw(Canvas &canvas) const
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            canvas.draw_pixel(x + j, y + i, symbol);
        }
    }
}

// Implementacja klasy Circle
Circle::Circle(int x, int y, int radius, char symbol)
    : x(x), y(y), radius(radius), symbol(symbol) {}

void Circle::draw(Canvas &canvas) const
{
    for (int i = -radius; i <= radius; ++i)
    {
        for (int j = -radius; j <= radius; ++j)
        {
            if (i * i + j * j <= radius * radius)
            {
                canvas.draw_pixel(x + j, y + i, symbol);
            }
        }
    }
}

// Implementacja klasy Triangle
Triangle::Triangle(int x, int y, int height, char symbol)
    : x(x), y(y), height(height), symbol(symbol) {}

void Triangle::draw(Canvas &canvas) const
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = -i; j <= i; ++j)
        {
            canvas.draw_pixel(x + j, y + i, symbol);
        }
    }
}
