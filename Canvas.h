#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>
#include <iostream>

// Abstrakcyjna klasa Canvas
class Canvas
{
public:
    Canvas(int width, int height);
    virtual void draw_pixel(int x, int y, char symbol) = 0;
    virtual void render(std::ostream &out) const = 0;
    virtual ~Canvas() = default;

protected:
    int width;
    int height;
};

// Klasa ASCIICanvas dziedzicząca z Canvas
class ASCIICanvas : public Canvas
{
public:
    ASCIICanvas(int width, int height);
    void draw_pixel(int x, int y, char symbol) override;
    void render(std::ostream &out) const override;

private:
    std::vector<std::string> canvas;
};

#endif // CANVAS_H
