#include "Model/Headers/ellipse.h"

Ellipse::Ellipse() {}

Ellipse::Ellipse(int rX, int rY)
{
    _rX = rX;
    _rY = rY;
}

QRect Ellipse::GetRect()
{
    return QRect(_transform.GetPosition().x() - _rX * _transform.GetScale().x(),_transform.GetPosition().y() - _rY * _transform.GetScale().y(),_rX * 2 * _transform.GetScale().x(), _rY * 2 * _transform.GetScale().y());
}

QDataStream &operator <<(QDataStream &stream, Ellipse &figure)
{
    return stream << *static_cast<Figure*>(&figure) << figure._rX << figure._rY;
}

QDataStream &operator >>(QDataStream &stream, Ellipse &figure)
{
    return stream >> *static_cast<Figure*>(&figure) >> figure._rX >> figure._rY;
}


