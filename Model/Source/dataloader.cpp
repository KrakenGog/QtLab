#include "Model/Headers/dataloader.h"

DataLoader::DataLoader() {}

AppData DataLoader::Load(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    QDataStream stream(&file);

    qint32 n;
    stream >> n;
    std::vector<Figure*> figures;

    for (int i = 0; i < n; ++i) {
        FigureType type;

        stream >> type;
        switch (type) {
        case FigureType::Ellipse:
            figures.push_back(new Ellipse());
            stream >> *dynamic_cast<Ellipse*>(figures[i]);
            break;
        default:
            break;
        }

    }



    AppData data;

    stream >> data.c1 >> data.c2 >> data.c3;

    data.Figures = figures;
    return data;
}
