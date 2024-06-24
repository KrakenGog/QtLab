#include "View/Headers/ellipsesetupview.h"

EllipseSetupView::EllipseSetupView() {}

void EllipseSetupView::OpenDialog(std::function<void (Ellipse *)> endFunc)
{
    _dialog->show();
    _endFunc = endFunc;
}
