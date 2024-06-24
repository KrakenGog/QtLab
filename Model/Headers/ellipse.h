#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <Model/Headers/figure.h>

class Ellipse : public Figure
{
public:
    Ellipse();
    Ellipse(int rX, int rY);

    FigureType GetType() const override {return FigureType::Ellipse;}
    QPoint GetSize() const {return {_rX,_rY};}

    QRect GetRect() override;

    friend QDataStream& operator << (QDataStream& stream, Ellipse& figure);
    friend QDataStream& operator >> (QDataStream& stream, Ellipse& figure);

private:
    int _rX;
    int _rY;
};

#endif // ELLIPSE_H
