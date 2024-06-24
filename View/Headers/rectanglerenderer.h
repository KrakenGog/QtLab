#ifndef HUIRENDERER_H
#define HUIRENDERER_H

#include <View/Headers/figurerenderer.h>
#include <Model/Headers/rectangle.h>
#include <QRect>

class RectangleRenderer : public FigureRenderer
{
public:
    RectangleRenderer(QPixmap* m) : FigureRenderer(m){}

    void Render(Figure &figure) override;
};

#endif // HUIRENDERER_H
