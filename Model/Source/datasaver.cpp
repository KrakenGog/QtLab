#include "Model/Headers/datasaver.h"

DataSaver::DataSaver() {}

void DataSaver::Save(AppData data, QString path)
{
    qDebug() << path;
    QFile file(path + ".kr");
    file.open(QIODevice::WriteOnly);


    QDataStream stream(&file);

    int s = data.Figures.size();
    stream << s;

    for (int i = 0; i < data.Figures.size(); ++i) {
        switch (data.Figures[i]->GetType()) {
        case FigureType::Ellipse:
            stream << *dynamic_cast<Ellipse*>(data.Figures[i]);
            break;
        default:
            break;
        }

    }

    stream << data.c1 << data.c2 << data.c3;

    file.close();
}
