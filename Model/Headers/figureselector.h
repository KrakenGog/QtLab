#ifndef FIGURESELECTOR_H
#define FIGURESELECTOR_H

#include <Model/Headers/figure.h>
#include <vector>
#include <QRect>

class FigureSelector
{
public:
    FigureSelector(std::vector<Figure*>* figures);

    void SelectFromRect(QRect rect);

    bool IsPointInRect(QRect rect, double rot, QPoint point);
    bool IsRectCross(QRect first,double fRot, QRect second, double sRot);

private:
    std::vector<Figure*>* _figures;
};

#endif // FIGURESELECTOR_H
