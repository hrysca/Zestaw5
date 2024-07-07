#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include "Canvas.h"
#include "Figure.h"

void parse_config(const std::string &filename, int &width, int &height, std::string &output_file, char &empty_pixel, std::vector<std::shared_ptr<Figure>> &figures)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string keyword;
        iss >> keyword;

        if (keyword == "canvas")
        {
            iss >> width >> height;
        }
        else if (keyword == "output")
        {
            iss >> output_file;
        }
        else if (keyword == "empty_pixel")
        {
            iss >> empty_pixel;
        }
        else if (keyword == "rectangle")
        {
            int x, y, w, h;
            char symbol;
            iss >> x >> y >> w >> h >> symbol;
            figures.push_back(std::make_shared<Rectangle>(x, y, w, h, symbol));
        }
        else if (keyword == "circle")
        {
            int x, y, r;
            char symbol;
            iss >> x >> y >> r >> symbol;
            figures.push_back(std::make_shared<Circle>(x, y, r, symbol));
        }
        else if (keyword == "triangle")
        {
            int x, y, h;
            char symbol;
            iss >> x >> y >> h >> symbol;
            figures.push_back(std::make_shared<Triangle>(x, y, h, symbol));
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
        return 1;
    }

    int width, height;
    std::string output_file;
    char empty_pixel;
    std::vector<std::shared_ptr<Figure>> figures;

    parse_config(argv[1], width, height, output_file, empty_pixel, figures);

    ASCIICanvas canvas(width, height);

    for (const auto &figure : figures)
    {
        figure->draw(canvas);
    }

    std::ofstream outfile(output_file);
    canvas.render(outfile);

    return 0;
}
