#include "Model/Headers/figure.h"

Figure::Figure() {}

void Figure::SetFillingColor(QColor color)
{
    _fillingColor = color;
}

void Figure::SetOutlineColor(QColor color)
{
    _outlineColor = color;
}

void Figure::SetFillingEnabled(bool b)
{
    _fill = b;
}

void Figure::SetOutlineEnabled(bool b)
{
    _outline = b;
}

QDataStream &operator <<(QDataStream &stream, Figure &figure)
{
    return stream << figure.GetType() << figure._outlineColor << figure._fillingColor << figure._fill << figure._outline << figure._transform;
}

QDataStream &operator >>(QDataStream &stream, Figure &figure)
{
    return stream >> figure._outlineColor >> figure._fillingColor >> figure._fill >> figure._outline >>  figure._transform;
}
