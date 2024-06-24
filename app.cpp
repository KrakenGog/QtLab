#include "app.h"
#include <QDebug>



App::App(QPixmap * pixmap)
{
    StartUp(pixmap);
}

App::~App()
{
    for (int i = 0; i < _figures.size(); ++i) {
        delete _figures[i];
    }

    delete _saver;
    delete _loader;
    delete _selector;
}

void App::StartUp(QPixmap* pixmap)
{
    FigureRenderer* ellipseRenderer = new EllipseRenderer(pixmap);
    RectangleRenderer* rectangleRenderer = new RectangleRenderer(pixmap);

    _renderers[FigureType::Ellipse] = ellipseRenderer;
    _renderers[FigureType::Rectangle] = rectangleRenderer;

    _selector = new FigureSelector(&_figures);
}

void App::EllipseAdded(Ellipse *ellipse)
{
    _figures.push_back(ellipse);
}

void App::RenderLoop()
{

    for (int i = 0; i < _figures.size(); ++i) {
        _renderers[_figures[i]->GetType()]->Render(*_figures[i]);
    }
}

void App::Tick()
{
    RenderLoop();
}

void App::Select(QRect rect)
{
    for (Figure* figure : _figures) {
        figure->Deselect();
    }

    _selector->SelectFromRect(rect);
}

void App::Open(QString &file)
{
    AppData data = _loader->Load(file);
    _figures = data.Figures;
    c1 = data.c1;
    c2 = data.c2;
    c3 = data.c3;

    _projectOpened = true;
    _currentProjectPath = file;
}

void App::Save()
{
    AppData data;
    data.Figures = _figures;
    data.c1 = c1;
    data.c2 = c2;
    data.c3 = c3;

    _saver->Save(data, _currentProjectPath);
}

void App::SaveAs(QString path)
{
    AppData data;
    data.Figures = _figures;
    data.c1 = c1;
    data.c2 = c2;
    data.c3 = c3;

    _saver->Save(data ,path);

    _projectOpened = true;
    _currentProjectPath = path;
}

std::unordered_map<FigureType, FigureRenderer *> &App::GetRenderers(){return _renderers;}
