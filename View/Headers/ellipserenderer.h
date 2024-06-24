#ifndef ELLIPSERENDERER_H
#define ELLIPSERENDERER_H

#include <View/Headers/figurerenderer.h>
#include <Model/Headers/ellipse.h>

class EllipseRenderer : public FigureRenderer
{
public:
    EllipseRenderer();
    EllipseRenderer(QPixmap* map) : FigureRenderer(map){}

    void Render(Figure &figure) override;
};

#endif // ELLIPSERENDERER_H
