#ifndef FIGURE_H
#define FIGURE_H

#include "Model/Headers/transform.h"
#include <QColor>
#include <QRect>
#include <QFile>
#include <QDataStream>

enum class FigureType{
    Ellipse,
    Rectangle
};

class Figure
{
public:
    Figure();

    void SetFillingColor(QColor color);
    void SetOutlineColor(QColor color);
    void SetFillingEnabled(bool b);
    void SetOutlineEnabled(bool b);
    void Select(){_selected = true;}
    void Deselect(){_selected = false;}

    Transform& GetTransform() {return _transform;}
    const Transform& GetTransform() const {return _transform;}
    QColor GetFillingColor() const {return _fillingColor;}
    QColor GetOutlineColor() const {return _outlineColor;}
    bool Selected() const {return _selected;}
    bool HasOutline() const {return _outline;}
    bool HasFill() const {return _fill;}
    virtual QRect GetRect() = 0;

    virtual FigureType GetType() const = 0;

    friend QDataStream& operator << (QDataStream& stream, Figure& figure);
    friend QDataStream& operator >> (QDataStream& stream, Figure& figure);

protected:
    Transform _transform;
    QColor _fillingColor;
    QColor _outlineColor = Qt::red;
    bool _outline;
    bool _fill;
    bool _selected = false;

};



#endif // FIGURE_H
