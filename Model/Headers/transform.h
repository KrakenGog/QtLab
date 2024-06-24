#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QPoint>
#include <QFile>
#include <QDataStream>

class Transform
{
public:
    Transform();

    void SetPositon(QPoint pos);
    void SetRotation(float angle);
    void SetScale(QPoint scale);

    void Translate(QPoint dir);
    void Rotate(float angle);
    void AddScale(QPoint value);


    QPoint GetPosition() const {return _position;}
    float GetRotation() const {return _rotation;}
    QPoint GetScale() const {return _scale;}

    friend QDataStream& operator << (QDataStream& stream, Transform& transform);
    friend QDataStream& operator >> (QDataStream& stream, Transform& transform);

private:
    QPoint _position;
    double _rotation;
    QPoint _scale;
};

//QDataStream& operator <<(QDataStream& stream, QPoint point){
//    return stream << point.x() << point.y();
//}

#endif // TRANSFORM_H
