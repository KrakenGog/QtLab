#include "View/Headers/ellipserenderer.h"

EllipseRenderer::EllipseRenderer() {}

void EllipseRenderer::Render(Figure &figure)
{
    _painter = new QPainter(_pixmap);
    if(figure.GetType() != FigureType::Ellipse)
        throw std::invalid_argument("Argument dont math type Ellipse");

    Ellipse* ellipse = dynamic_cast<Ellipse*>(&figure);

    SetupPainterByTransform(ellipse->GetTransform());
    SetupPainterByFigureData(figure);

    _painter->drawEllipse({0,0},ellipse->GetSize().x(), ellipse->GetSize().y());

    _painter->end();
}
