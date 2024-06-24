#include "Model/Headers/transform.h"

Transform::Transform() : _scale({1,1}) {


}

void Transform::SetPositon(QPoint pos)
{
    _position = pos;
}

void Transform::SetRotation(float angle)
{
    _rotation = angle;
}

void Transform::SetScale(QPoint scale)
{
    _scale = scale;
}

void Transform::Translate(QPoint dir)
{
    _position += dir;
}

void Transform::Rotate(float angle)
{
    _rotation += angle;
}

void Transform::AddScale(QPoint value)
{
    _scale += value;
}

QDataStream& operator <<(QDataStream &stream, Transform &transform)
{
    return stream << transform._position << transform._rotation << transform._scale;
}

QDataStream&  operator >>(QDataStream &stream, Transform &transform)
{
    return  stream >> transform._position >> transform._rotation >> transform._scale;
}



