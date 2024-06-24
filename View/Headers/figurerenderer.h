#ifndef FIGURERENDERER_H
#define FIGURERENDERER_H

#include <Model/Headers/figure.h>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPixmap>

class FigureRenderer
{
public:
    FigureRenderer();
    FigureRenderer(QPixmap* pixmap);


    void SetPixmap(QPixmap* pixmap);
    virtual void Render(Figure& figure) = 0;
    void RenderToPixmap(Figure &figure, QPixmap* pixmap);

    void SetupPainterByTransform(Transform& transform);
    void SetupPainterByFigureData(Figure& figure);

protected:
    QPainter* _painter;
    QPixmap* _pixmap;
};

#endif // FIGURERENDERER_H
