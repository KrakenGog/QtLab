#include "View/Headers/figurerenderer.h"

FigureRenderer::FigureRenderer() {}

FigureRenderer::FigureRenderer(QPixmap *pixmap)
{
    _pixmap = pixmap;
}



void FigureRenderer::SetPixmap(QPixmap *pixmap)
{
    _pixmap = pixmap;
}

void FigureRenderer::RenderToPixmap(Figure &figure, QPixmap *pixmap)
{
    QPixmap* old = _pixmap;
    SetPixmap(pixmap);
    Render(figure);
    SetPixmap(old);
}

void FigureRenderer::SetupPainterByTransform(Transform &transform)
{
    _painter->resetTransform();
    _painter->translate(transform.GetPosition());
    _painter->scale(transform.GetScale().x(), transform.GetScale().y());
    _painter->rotate(transform.GetRotation());
}

void FigureRenderer::SetupPainterByFigureData(Figure &figure)
{
    _painter->setPen(QPen(figure.GetOutlineColor(),2));
    if(!figure.HasOutline())
        _painter->setPen(Qt::NoPen);
    if(figure.Selected())
        _painter->setPen(QPen(figure.GetOutlineColor(),5));
    if(figure.HasFill())
        _painter->setBrush(QBrush(figure.GetFillingColor()));

    _painter->setRenderHint(QPainter::Antialiasing);
}

