#ifndef FIGURE_H
#define FIGURE_H

#include "Canvas.h"

// Abstrakcyjna klasa Figure
class Figure
{
public:
    virtual void draw(Canvas &canvas) const = 0;
    virtual ~Figure() = default;
};

// Klasa Rectangle dziedzicząca z Figure
class Rectangle : public Figure
{
public:
    Rectangle(int x, int y, int width, int height, char symbol);
    void draw(Canvas &canvas) const override;

private:
    int x, y, width, height;
    char symbol;
};

// Klasa Circle dziedzicząca z Figure
class Circle : public Figure
{
public:
    Circle(int x, int y, int radius, char symbol);
    void draw(Canvas &canvas) const override;

private:
    int x, y, radius;
    char symbol;
};

// Klasa Triangle dziedzicząca z Figure
class Triangle : public Figure
{
public:
    Triangle(int x, int y, int height, char symbol);
    void draw(Canvas &canvas) const override;

private:
    int x, y, height;
    char symbol;
};

#endif // FIGURE_H
