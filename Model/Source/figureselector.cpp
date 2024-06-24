#include "Model/Headers/figureselector.h"



FigureSelector::FigureSelector(std::vector<Figure *> *figures)
{
    _figures = figures;
}

void FigureSelector::SelectFromRect(QRect rect)
{
    for (Figure* figure : *_figures) {
        if(IsRectCross(figure->GetRect(),figure->GetTransform().GetRotation(),rect,0))
        {
            figure->Select();
        }
    }
}

bool FigureSelector::IsPointInRect(QRect rect, double rot, QPoint point)
{
    int x = point.x() * std::cos(rot) + point.y() * std::sin(rot);
    int y = point.y() * std::cos(rot) - point.x() * std::sin(rot);
    point = QPoint(x,y);

    if(point.x() >= rect.left() && point.x() <= rect.left() + rect.width())
        if(point.y() > rect.top() && point.y() < rect.top() + rect.height())
            return true;

    return false;
}

bool FigureSelector::IsRectCross(QRect first,double firstRot, QRect second, double secondRot)
{
    return IsPointInRect(first, firstRot, second.topLeft()) ||  IsPointInRect(first, firstRot, second.topRight())
        || IsPointInRect(first, firstRot, second.bottomLeft()) || IsPointInRect(first, firstRot, second.bottomRight())
        || IsPointInRect(second, secondRot, first.topLeft()) ||  IsPointInRect(second, secondRot, first.topRight())
        || IsPointInRect(second, secondRot, first.bottomLeft()) || IsPointInRect(second, secondRot, first.bottomRight());
}
