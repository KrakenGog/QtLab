#include "View/Headers/rectanglerenderer.h"



void RectangleRenderer::Render(Figure &figure)
{
    if(figure.GetType() != FigureType::Rectangle)
        throw std::invalid_argument("Argument dont math type Rectangle");

    _painter = new QPainter(_pixmap);
    Rectangle* rectangle = dynamic_cast<Rectangle*>(&figure);

    SetupPainterByFigureData(figure);
    SetupPainterByTransform(figure.GetTransform());

    _painter->drawRect(QRect(0,0, rectangle->GetWidth(), rectangle->GetHeight()));

    _painter->end();
}
