#ifndef APP_H
#define APP_H
#include <Model/Headers/ellipse.h>
#include <vector>
#include <unordered_map>
#include <View/Headers/figurerenderer.h>
#include <View/Headers/ellipserenderer.h>
#include <View/Headers/rectanglerenderer.h>
#include <Model/Headers/figureselector.h>
#include <Model/Headers/dataloader.h>
#include <Model/Headers/datasaver.h>


class App
{
public:
    App(QPixmap*);
    ~App();

    int c1 = 1,c2 = 1,c3 = 1;

    void StartUp(QPixmap*);
    void EllipseAdded(Ellipse* ellipse);

    void RenderLoop();
    void Tick();
    void Select(QRect rect);
    void Open(QString& file);
    void Save();
    void SaveAs(QString path);
    bool HasOpenedProject() {return _projectOpened;}

    std::vector<Figure*>* GetFigures(){return &_figures;}



    std::unordered_map<FigureType, FigureRenderer*>& GetRenderers();

private:
    std::vector<Figure*> _figures;
    std::unordered_map<FigureType, FigureRenderer*> _renderers;
    FigureSelector* _selector;
    DataSaver* _saver;
    DataLoader* _loader;
    bool _projectOpened;
    QString _currentProjectPath;
};

#endif // APP_H
