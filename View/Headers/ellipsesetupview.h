#ifndef ELLIPSESETUPVIEW_H
#define ELLIPSESETUPVIEW_H

#include <ellipsesetupdialog.h>
#include <Model/Headers/ellipse.h>
#include <functional>

class EllipseSetupView
{
public:
    EllipseSetupView();

    void OpenDialog(std::function<void(Ellipse*)> endFunc);

private:
    EllipseSetupDialog* _dialog;
    std::function<void(Ellipse*)> _endFunc;
};

#endif // ELLIPSESETUPVIEW_H
