#include "Canvas.h"

Canvas::Canvas(int width, int height) : width(width), height(height) {}

ASCIICanvas::ASCIICanvas(int width, int height) : Canvas(width, height)
{
    canvas.resize(height, std::string(width, ' '));
}

void ASCIICanvas::draw_pixel(int x, int y, char symbol)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        canvas[y][x] = symbol;
    }
}

void ASCIICanvas::render(std::ostream &out) const
{
    for (const auto &line : canvas)
    {
        out << line << '\n';
    }
}
