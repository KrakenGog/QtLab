#ifndef HUI_H
#define HUI_H

#include <Model/Headers/figure.h>

class Rectangle : public Figure
{
public:
    Rectangle(){}
    Rectangle(int width, int height);
    FigureType GetType() const override {return FigureType::Rectangle;}

    int GetWidth() const {return _width;}
    int GetHeight() const {return _height;}
private:
    int _width;
    int _height;
};

#endif // HUI_H
